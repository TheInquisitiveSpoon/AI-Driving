// UContextSteeringComponent.cpp - Niall Starkey


#include "UContextSteeringComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UContextSteeringComponent::UContextSteeringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentChaseTarget = 0;
}

// Called when the game starts
void UContextSteeringComponent::BeginPlay()
{
	Super::BeginPlay();

	LoadTargetsWithTag("Checkpoint");
}

// Called every frame
void UContextSteeringComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FillInterestMap();
}

// Sets the number of rays used for movement, and fills the context maps.
void UContextSteeringComponent::SetNumberOfRays(const int& Value)
{
	NumberOfRays = Value;

	Interest.Empty();
	Danger.Empty();
	Splines.Empty();

	for (int i = 0; i < Value; i++)
	{
		Interest.Add(0.0f);
		Danger.Add(0.0f);
		USplineComponent* Spline = NewObject<USplineComponent>(GetOwner());
		Spline->RegisterComponent();
	}
}

void UContextSteeringComponent::FillInterestMap()
{
	//FVector DotProduct;
	//DotProduct.DotProduct(GetOwner()->GetActorLocation(), Targets[CurrentChaseTarget]->GetActorLocation());

	//GetOwner()->
	//FVector DesiredLocation;
	//DesiredLocation.ToDirectionAndLength(Targets[CurrentChaseTarget]->GetActorLocation(), 1.0f); 



	//FVector CarLocation = GetOwner()->GetActorLocation();
	//FVector TargetLocation = Targets[CurrentChaseTarget]->GetActorLocation();
	//DrawDebugLine(GetWorld(), CarLocation, TargetLocation, FColor::Blue);
	//TargetDirectionDegrees = UKismetMathLibrary::FindLookAtRotation(CarLocation, TargetLocation).Yaw;

	FVector FacingVector = GetOwner()->GetActorForwardVector();
	FVector DirectionVector = Targets[CurrentChaseTarget]->GetActorLocation() - GetOwner()->GetActorLocation();
	TargetDirectionDegrees = GetAngleBetweenVectors(FacingVector, DirectionVector);
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), Targets[CurrentChaseTarget]->GetActorLocation(), FColor::Blue);

	//FVector FacingDirection = Targets[CurrentChaseTarget]->GetActorLocation() - GetOwner()->GetActorLocation();n
	//FVector PositionOnCircle = FacingDirection * 1.0f;
	//float targetRadians = FMath::Atan2(PositionOnCircle.Z - GetOwner()->GetActorLocation().Z, PositionOnCircle.X - GetOwner()->GetActorLocation().X);
	//TargetDirectionDegrees = FMath::RadiansToDegrees(targetRadians);
}

void UContextSteeringComponent::LoadTargetsWithTag(const FName& Tag)
{
	TArray<CheckPoint*> Checkpoints;
	//GetAllActorsOfClass();
}

float UContextSteeringComponent::GetAngleBetweenVectors(FVector A, FVector B)
{
	//float Dot = FVector::DotProduct(A, B);
	//float CosTheta = Dot / (A.Size() * B.Size());
	//return FMath::RadiansToDegrees(FMath::Acos(CosTheta));

	float 
}
