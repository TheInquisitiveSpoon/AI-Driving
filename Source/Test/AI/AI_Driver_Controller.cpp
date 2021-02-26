// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Driver_Controller.h"

AAI_Driver_Controller::AAI_Driver_Controller()
{
	BehaviourTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behaviour Tree"));
	AddOwnedComponent(BehaviourTreeComponent);
}