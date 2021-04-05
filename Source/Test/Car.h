// Car.h - Niall Starkey

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WheeledVehicle.h"
#include "Car.generated.h"

class USkeletalMeshComponent;

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

public:
	/** Function called every frame on this Actor. */
	virtual void Tick(float DeltaTime) override;

	/** Sets Throttle input for actor. */
	void MoveForward(float Val);
	/** Sets steering input for actor. */
	void MoveRight(float Val);

private:
	/** Check if this actor is in reverse gear. */
	UPROPERTY(EditAnywhere)
		bool bInReverseGear;
};