// PlayerCar.h - Niall Starkey

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Car.h"
#include "PlayerCar.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * Default class for a Player Car, inherits from ACar.
 */
UCLASS()
class TEST_API APlayerCar : public ACar
{
	GENERATED_BODY()

public:
	/** Default UObject constructor. */
	APlayerCar();

	/**	Binds functionality to input */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Binding for vertical camera control. */
	static const FName LookUpBinding;
	/** Binding for horizontal camera control. */
	static const FName LookRightBinding;

private:
	/** The Spring arm associated with this PlayerCar. */
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
	/** The main Camera associated with this PlayerCar. */
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;
};