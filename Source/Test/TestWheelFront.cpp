// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestWheelFront.h"
#include "TireConfig.h"
#include "UObject/ConstructorHelpers.h"

UTestWheelFront::UTestWheelFront()
{
	ShapeRadius = 18.f;
	ShapeWidth = 15.0f;
	bAffectedByHandbrake = false;
	SteerAngle = 40.f;

	// Setup suspension forces
	SuspensionForceOffset = -4.0f;
	SuspensionMaxRaise = 8.0f;
	SuspensionMaxDrop = 12.0f;
	SuspensionNaturalFrequency = 9.0f;
	SuspensionDampingRatio = 1.05f;

	// Find the tire object and set the data for it
	static ConstructorHelpers::FObjectFinder<UTireConfig> TireData(TEXT("TireConfig'/Game/Vehicle/WheelData/Vehicle_FrontTireConfig.Vehicle_FrontTireConfig'"));
	TireConfig = TireData.Object;
}
