// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestGameMode.h"
#include "TestPawn.h"
#include "TestHud.h"

ATestGameMode::ATestGameMode()
{
	DefaultPawnClass = ATestPawn::StaticClass();
	HUDClass = ATestHud::StaticClass();
}
