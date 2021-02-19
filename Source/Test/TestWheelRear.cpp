// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestWheelRear.h"
#include "TireConfig.h"
#include "UObject/ConstructorHelpers.h"

UTestWheelRear::UTestWheelRear()
{
	ShapeRadius = 36.0f;
	ShapeWidth = 30.0f;
	bAffectedByHandbrake = true;
	SteerAngle = 0.f;

	// Setup suspension forces
	SuspensionForceOffset = -4.0f;
	SuspensionMaxRaise = 16.0f;
	SuspensionMaxDrop = 24.0f;
	SuspensionNaturalFrequency = 9.0f;
	SuspensionDampingRatio = 1.05f;

	// Find the tire object and set the data for it
	static ConstructorHelpers::FObjectFinder<UTireConfig> TireData(TEXT("TireConfig'/Game/Vehicle/WheelData/Vehicle_BackTireConfig.Vehicle_BackTireConfig'"));
	TireConfig = TireData.Object;
}
