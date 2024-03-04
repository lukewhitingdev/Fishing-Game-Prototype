// Fill out your copyright notice in the Description page of Project Settings.


#include "FG_BoatCharacter.h"

#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AFG_BoatCharacter::AFG_BoatCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
}

void AFG_BoatCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(FVector(0, 1, 0), Value * Speed);
	}
}

void AFG_BoatCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddControllerYawInput(Value * TurnRate);
	}
}

void AFG_BoatCharacter::MoveLeft(float Value)
{
	if (Value != 0.0f)
	{
		AddControllerYawInput(-Value * TurnRate);
	}
}

void AFG_BoatCharacter::MoveBackwards(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(FVector(0, -1, 0), Value * Speed);
	}
}

// Called when the game starts or when spawned
void AFG_BoatCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFG_BoatCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

