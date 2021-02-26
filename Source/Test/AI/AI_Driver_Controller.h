// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "WheeledVehicleMovementComponent4W.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig.h"

#include "AI_Driver_Controller.generated.h"

UCLASS()
class TEST_API AAI_Driver_Controller : public AAIController
{
	GENERATED_BODY()
	
public:
	AAI_Driver_Controller();

	UPROPERTY(EditAnywhere)
		UBlackboardComponent* BlackboardComponent;

	UPROPERTY(EditAnywhere)
		UBehaviorTreeComponent* BehaviourTreeComponent;

	UPROPERTY(EditAnywhere)
		UAIPerceptionComponent* AI_PerceptionComponent;

	UPROPERTY(EditAnywhere)
		UAISenseConfig* SightComponent;
};
