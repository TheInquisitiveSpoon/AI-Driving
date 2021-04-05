// UContextSteeringComponent.h - Niall Starkey

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UContextSteeringComponent.generated.h"

/**
 * UContextSteeringComponent class for context steering movement of an Actor.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST_API UUContextSteeringComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	/** Default UObject constructor */
	UUContextSteeringComponent();

protected:
	/** Overridable native event for when play begins for this Component. */
	virtual void BeginPlay() override;

public:	
	/** Function called every frame on this Component. */
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** How many directions to scan. */
	UPROPERTY(EditAnywhere, Category = "Rays")
		int NumberOfDirections;

	UPROPERTY(VisibleAnywhere, Category="Context Maps")
		TArray<float> interest;

	UPROPERTY(VisibleAnywhere, Category = "Context Maps")
		TArray<float> danger;
};