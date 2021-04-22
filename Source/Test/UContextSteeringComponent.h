// UContextSteeringComponent.h - Niall Starkey

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "CheckPoint.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SplineComponent.h"
#include "UContextSteeringComponent.generated.h"

class AActor;
class CheckPoint;
class USplineComponent;

/**
 * UContextSteeringComponent class for context steering movement of an Actor.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST_API UContextSteeringComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	/** Default UObject constructor. */
	UContextSteeringComponent();

	/** Function to change the number of rays used for context steering. */
	void SetNumberOfRays(const int& Value);

	UPROPERTY(VisibleAnywhere, Category = "Chase")
	float TargetDirectionDegrees;

protected:
	/** Overridable native event for when play begins for this Component. */
	virtual void BeginPlay() override;

private:	
	/** Function called every frame on this Component. */
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void LoadTargetsWithTag(const FName& Tag);

	void FillInterestMap();

	int CurrentChaseTarget;

	/** How many directions to scan. */
	UPROPERTY(EditAnywhere, Category = "Rays")
		int NumberOfRays;

	UPROPERTY(VisibleAnywhere, Category = "Rays")
		TArray<USplineComponent*> Splines;

	/** Context map for interest. */
	UPROPERTY(VisibleAnywhere, Category="Context Maps")
		TArray<float> Interest;

	/** Context map for danger. */
	UPROPERTY(VisibleAnywhere, Category = "Context Maps")
		TArray<float> Danger;

	/** List of objects to chase. */
	UPROPERTY(EditAnywhere, Category = "Chase")
		TArray<AActor*> Targets;
};