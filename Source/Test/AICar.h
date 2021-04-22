// AICar.h - Niall Starkey

#pragma once

#include "CoreMinimal.h"
#include "Car.h"
#include "UContextSteeringComponent.h"
#include "Components/SplineComponent.h"
#include "AICar.generated.h"

class UContextSteeringComponent;
class USplineComponent;

/**
 * Default class for an AI Car, inherits from ACar.
 */
UCLASS()
class TEST_API AAICar : public ACar
{
	GENERATED_BODY()

public:
	/** Default UObject constructor. */
	AAICar();

	/** Function called every frame on this Actor. */
	virtual void Tick(float DeltaTime) override;

private:
	/** Context steering component for this actor. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UContextSteeringComponent* ContextSteering;

	///** North spline component for this actor. */
	//UPROPERTY(EditAnywhere)
	//	USplineComponent* SP_North;

	///** North East spline component for this actor. */
	//UPROPERTY(EditAnywhere)
	//	USplineComponent* SP_NorthEast;

	///** East spline component for this actor. */
	//UPROPERTY(EditAnywhere)
	//	USplineComponent* SP_East;

	///** South East spline component for this actor. */
	//UPROPERTY(EditAnywhere)
	//	USplineComponent* SP_SouthEast;

	///** South spline component for this actor. */
	//UPROPERTY(EditAnywhere)
	//	USplineComponent* SP_South;

	///** South West spline component for this actor. */
	//UPROPERTY(EditAnywhere)
	//	USplineComponent* SP_SouthWest;

	///** West spline component for this actor. */
	//UPROPERTY(EditAnywhere)
	//	USplineComponent* SP_West;

	///** North West spline component for this actor. */
	//UPROPERTY(EditAnywhere)
	//	USplineComponent* SP_NorthWest;
};
