// Fill out your copyright notice in the Description page of Project Settings.


#include "Vehicle.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AVehicle::AVehicle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshAsset(TEXT("SkeletalMesh'/Game/Vehicle/Vehicle_SkelMesh.Vehicle_SkelMesh'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("MaterialInstanceConstant'/Game/Geometry/SolidGreen.SolidGreen'"));

	USkeletalMesh* Mesh = MeshAsset.Object;
	UMaterialInterface* Material = MaterialAsset.Object;

	// Creates folder for the vehicle mesh.
	VehicleMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Vehicle Mesh"));
	VehicleMesh->SetSkeletalMesh(Mesh);
	VehicleMesh->SetMaterial(0, Material);
	VehicleMesh->SetupAttachment(RootComponent);

	// Creates folder for the spring arm.
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(VehicleMesh);

	// Creates folder for the vehicle camera.
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AVehicle::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AVehicle::MoveRight);
	//PlayerInputComponent->BindAxis(LookUpBinding);
	//PlayerInputComponent->BindAxis(LookRightBinding);
}

void AVehicle::MoveForward(float Val)
{

}

void AVehicle::MoveRight(float Val)
{
	
}

