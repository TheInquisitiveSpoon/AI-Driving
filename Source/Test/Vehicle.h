//	Venicle.h - Basic Vehicle Class

//	TO DO:
//
//
//

//	USEFUL CODE:
//
//	Log to output:
//		UE_LOG(LogTemp, Warning, TEXT(""));

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Vehicle.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TEST_API AVehicle : public APawn
{
	GENERATED_BODY()

public:
	//	Sets default values for this pawn's properties
	AVehicle();

protected:
	//	Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//	Called every frame
	virtual void Tick(float DeltaTime) override;

	//	Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Val);
	void MoveRight(float Val);

	//static const FName LookUpBinding;
	//static const FName LookRightBinding;

private:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* VehicleMesh;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;
};
