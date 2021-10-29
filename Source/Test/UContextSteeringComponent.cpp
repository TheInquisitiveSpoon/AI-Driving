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
	const FVector xAxis = Normalise(GetOwner()->GetActorRightVector());
	const FVector zAxis = Normalise(GetOwner()->GetActorForwardVector());
	const FVector target = Normalise(Targets[CurrentChaseTarget]->GetActorLocation() - GetOwner()->GetActorLocation());

	if (FVector::DotProduct(xAxis, target) > 0)
	{
		TargetDirectionDegrees = FMath::Acos(FVector::DotProduct(zAxis, target));
	}
	else
	{
		TargetDirectionDegrees = -FMath::Acos(FVector::DotProduct(zAxis, target));
	}

	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), Targets[CurrentChaseTarget]->GetActorLocation(), FColor::Blue);

	UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), FVector::Distance(GetOwner()->GetActorLocation(), Targets[CurrentChaseTarget]->GetActorLocation()));

	if (DistanceToTarget() < 1000.0f)
	{
		if (CurrentChaseTarget == Targets.Num() - 1)
		{
			CurrentChaseTarget = 0;
		}
		else
		{
			CurrentChaseTarget++;
		}
	}
}

float UContextSteeringComponent::DistanceToTarget()
{
	return FVector::Distance(GetOwner()->GetActorLocation(), Targets[CurrentChaseTarget]->GetActorLocation());
}

FVector UContextSteeringComponent::Normalise(const FVector& vector)
{
	const float x = vector.X / vector.Size();
	const float y = vector.Y / vector.Size();
	const float z = vector.Z / vector.Size();

	return FVector(x, y, z);
}

void UContextSteeringComponent::LoadTargetsWithTag(const FName& Tag)
{
	TArray<CheckPoint*> Checkpoints;
}
