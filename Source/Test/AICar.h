// AICar.h - Niall Starkey

#pragma once

#include "CoreMinimal.h"
#include "Car.h"
#include "UContextSteeringComponent.h"
#include "AICar.generated.h"

class UContextSteeringComponent;

/**
 * Default class for an AI Car, inherits from ACar.
 */
UCLASS()
class TEST_API AAICar : public ACar
{
	GENERATED_BODY()

public:
	AAICar();

private:
	//UPROPERTY()
	//	UContextSteeringComponent* ContextSteering;
};
