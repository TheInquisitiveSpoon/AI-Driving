// PlayerCar.cpp - Niall Starkey

#include "PlayerCar.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"

// Default axes for bindings.
const FName APlayerCar::LookUpBinding("LookUp");
const FName APlayerCar::LookRightBinding("LookRight");

APlayerCar::APlayerCar()
{
	// Creation and setup of Spring arm component.
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bInheritRoll = true;
	SpringArm->bInheritYaw = true;

	// Creation and setup of Camera component.
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->FieldOfView = 100.0f;
}

// Called to bind functionality to input.
void APlayerCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	// Bind input to axes.
	PlayerInputComponent->BindAxis("MoveForward", this, &ACar::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACar::MoveRight);
	PlayerInputComponent->BindAxis(LookUpBinding);
	PlayerInputComponent->BindAxis(LookRightBinding);
}