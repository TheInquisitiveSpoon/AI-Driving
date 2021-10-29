// AICar.cpp - Niall Starkey

#include "AICar.h"
#include "WheeledVehicleMovementComponent4W.h"
//#include "UContextSteeringComponent.h"

AAICar::AAICar()
{
	// Setup of Context steering component.
	ContextSteering = CreateDefaultSubobject<UContextSteeringComponent>(TEXT("Context Steering"));
	//ContextSteering->SetNumberOfRays(8);

	//// Setup of Spline components.
	//SP_North = CreateDefaultSubobject<USplineComponent>(TEXT("SP_North"));
	//SP_North->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));

	//SP_NorthEast = CreateDefaultSubobject<USplineComponent>(TEXT("SP_NorthEast"));
	//SP_NorthEast->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
	//SP_NorthEast->AddLocalRotation(FRotator(0.0f, 45.0f, 0.0f));

	//SP_East = CreateDefaultSubobject<USplineComponent>(TEXT("SP_East"));
	//SP_East->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
	//SP_East->AddLocalRotation(FRotator(0.0f, 90.0f, 0.0f));

	//SP_SouthEast = CreateDefaultSubobject<USplineComponent>(TEXT("SP_SouthEast"));
	//SP_SouthEast->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
	//SP_SouthEast->AddLocalRotation(FRotator(0.0f, 135.0f, 0.0f));

	//SP_South = CreateDefaultSubobject<USplineComponent>(TEXT("SP_South"));
	//SP_South->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
	//SP_South->AddLocalRotation(FRotator(0.0f, 180.0f, 0.0f));

	//SP_SouthWest = CreateDefaultSubobject<USplineComponent>(TEXT("SP_SouthWest"));
	//SP_SouthWest->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
	//SP_SouthWest->AddLocalRotation(FRotator(0.0f, 225.0f, 0.0f));

	//SP_West = CreateDefaultSubobject<USplineComponent>(TEXT("SP_West"));
	//SP_West->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
	//SP_West->AddLocalRotation(FRotator(0.0f, 270.0f, 0.0f));

	//SP_NorthWest = CreateDefaultSubobject<USplineComponent>(TEXT("SP_NorthWest"));
	//SP_NorthWest->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
	//SP_NorthWest->AddLocalRotation(FRotator(0.0f, 315.0f, 0.0f));
}

// Called every frame.
void AAICar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Degrees: %f"), ContextSteering->TargetDirectionDegrees);

	/*MoveForward(1.0f);*/
	if (ContextSteering->TargetDirectionDegrees > 0.0f)
	{
		MoveRight(1.0f);
	}
	else if (ContextSteering->TargetDirectionDegrees < 0.0f)
	{
		MoveRight(-1.0f);
	}

	// Check if car is in reverse gear.
	bInReverseGear = GetVehicleMovementComponent()->GetCurrentGear() < 0;
}