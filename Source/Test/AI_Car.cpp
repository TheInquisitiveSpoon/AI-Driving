// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Car.h"
#include "UObject/ConstructorHelpers.h"

#include "WheeledVehicleMovementComponent4W.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "TestWheelFront.h"
#include "TestWheelRear.h"

// Sets default values
AAI_Car::AAI_Car()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup mesh for vehicle.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkelMesh(TEXT("SkeletalMesh'/Game/Vehicle/Vehicle_SkelMesh.Vehicle_SkelMesh'"));
	GetMesh()->SetSkeletalMesh(SkelMesh.Object);
	GetMesh()->SetupAttachment(RootComponent);
	GetMesh()->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));

	static ConstructorHelpers::FObjectFinder<UPhysicalMaterial> NonSlipperyMat(TEXT("PhysicalMaterial'/Game/Geometry/PhysicsMaterials/NonSlippery.NonSlippery'"));
	NonSlipperyMaterial = NonSlipperyMat.Object;

	static ConstructorHelpers::FObjectFinder<UPhysicalMaterial> SlipperyMat(TEXT("PhysicalMaterial'/Game/Geometry/PhysicsMaterials/Slippery.Slippery'"));
	SlipperyMaterial = SlipperyMat.Object;

	UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());
	check(Vehicle4W->WheelSetups.Num() == 4);

	Vehicle4W->WheelSetups[0].WheelClass = UTestWheelFront::StaticClass();
	Vehicle4W->WheelSetups[0].BoneName = FName("PhysWheel_FL");
	Vehicle4W->WheelSetups[0].AdditionalOffset = FVector(0.f, -16.f, 0.f);

	Vehicle4W->WheelSetups[1].WheelClass = UTestWheelFront::StaticClass();
	Vehicle4W->WheelSetups[1].BoneName = FName("PhysWheel_FR");
	Vehicle4W->WheelSetups[1].AdditionalOffset = FVector(0.f, 16.f, 0.f);

	Vehicle4W->WheelSetups[2].WheelClass = UTestWheelRear::StaticClass();
	Vehicle4W->WheelSetups[2].BoneName = FName("PhysWheel_BL");
	Vehicle4W->WheelSetups[2].AdditionalOffset = FVector(0.f, -16.f, 0.f);

	Vehicle4W->WheelSetups[3].WheelClass = UTestWheelRear::StaticClass();
	Vehicle4W->WheelSetups[3].BoneName = FName("PhysWheel_BR");
	Vehicle4W->WheelSetups[3].AdditionalOffset = FVector(0.f, 16.f, 0.f);

	Vehicle4W->MinNormalizedTireLoad = 0.0f;
	Vehicle4W->MinNormalizedTireLoadFiltered = 0.2f;
	Vehicle4W->MaxNormalizedTireLoad = 2.0f;
	Vehicle4W->MaxNormalizedTireLoadFiltered = 2.0f;

	Vehicle4W->MaxEngineRPM = 5700.0f;
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 400.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(1890.0f, 500.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(5730.0f, 400.0f);

	Vehicle4W->SteeringCurve.GetRichCurve()->Reset();
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(0.0f, 1.0f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(40.0f, 0.7f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(120.0f, 0.6f);

	Vehicle4W->DifferentialSetup.DifferentialType = EVehicleDifferential4W::LimitedSlip_4W;

	Vehicle4W->DifferentialSetup.FrontRearSplit = 0.65;

	Vehicle4W->TransmissionSetup.bUseGearAutoBox = true;
	Vehicle4W->TransmissionSetup.GearSwitchTime = 0.15f;
	Vehicle4W->TransmissionSetup.GearAutoBoxLatency = 1.0f;

	UPrimitiveComponent* UpdatedPrimitive = Cast<UPrimitiveComponent>(Vehicle4W->UpdatedComponent);
	if (UpdatedPrimitive)
	{
		UpdatedPrimitive->BodyInstance.COMNudge = FVector(8.0f, 0.0f, 0.0f);
	}

	Vehicle4W->InertiaTensorScale = FVector(1.0f, 1.333f, 1.2f);

	bIsLowFriction = false;
	bInReverseGear = false;
}

// Called when the game starts or when spawned
void AAI_Car::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAI_Car::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bInReverseGear = GetVehicleMovementComponent()->GetCurrentGear() < 0;

	UpdatePhysicsMaterial();
}

//// Called to bind functionality to input
//void AAI_Car::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//}

void AAI_Car::MoveForward(float Val)
{
	GetVehicleMovementComponent()->SetThrottleInput(Val);
}

void AAI_Car::MoveRight(float Val)
{
	GetVehicleMovementComponent()->SetSteeringInput(Val);
}

void AAI_Car::UpdatePhysicsMaterial()
{
	if (GetActorUpVector().Z < 0)
	{
		if (bIsLowFriction == true)
		{
			GetMesh()->SetPhysMaterialOverride(NonSlipperyMaterial);
			bIsLowFriction = false;
		}
		else
		{
			GetMesh()->SetPhysMaterialOverride(SlipperyMaterial);
			bIsLowFriction = true;
		}
	}
}

