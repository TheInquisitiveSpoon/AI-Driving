// Car.h - Niall Starkey

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WheeledVehicle.h"
#include "Car.generated.h"

/**
 * Default class for a Car, inherits from AWheeledVehicle
 */
UCLASS()
class TEST_API ACar : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	/** Default UObject constructor. */
	ACar();

protected:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay() override;

	/** Function called every frame on this Actor. */
	virtual void Tick(float DeltaTime) override;

public:
	/** Sets Throttle input for actor. */
	void MoveForward(float Val);

	/** Sets steering input for actor. */
	void MoveRight(float Val);

	/** Check if this actor is in reverse gear. */
	UPROPERTY(EditAnywhere)
		bool bInReverseGear;
};