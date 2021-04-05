// UContextSteeringComponent.cpp - Niall Starkey


#include "UContextSteeringComponent.h"

// Sets default values for this component's properties
UUContextSteeringComponent::UUContextSteeringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UUContextSteeringComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UUContextSteeringComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}