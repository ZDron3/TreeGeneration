// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCharacter.h"

// Sets default values
AMyPlayerCharacter::AMyPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward_Backward", this, &AMyPlayerCharacter::Forward_Backward);
	PlayerInputComponent->BindAxis("Left_Right", this, &AMyPlayerCharacter::Left_Right);
	PlayerInputComponent->BindAxis("Turn", this, &AMyPlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyPlayerCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("MouseLeftClick", IE_Pressed, this, &AMyPlayerCharacter::MouseClickLeft);

}

void  AMyPlayerCharacter::Forward_Backward(float AxisValue)
{
	if (AxisValue != 0)
	{
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}
}

void  AMyPlayerCharacter::Left_Right(float AxisValue)
{
	if (AxisValue != 0)
	{
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, AxisValue);
	}
}


void  AMyPlayerCharacter::MouseClickLeft()
{

}


