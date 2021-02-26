// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WheeledVehicle.h"
#include "AI_Car.generated.h"

class UPhysicalMaterial;

UCLASS()
class TEST_API AAI_Car : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAI_Car();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Val);
	void MoveRight(float Val);

	void UpdatePhysicsMaterial();
	
private:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* VehicleMesh;

	UPROPERTY(EditAnywhere)
		bool bInReverseGear;

	UPROPERTY(EditAnywhere)
		bool bIsLowFriction;

	UPhysicalMaterial* NonSlipperyMaterial;
	UPhysicalMaterial* SlipperyMaterial;
};
