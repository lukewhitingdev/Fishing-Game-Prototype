// Fill out your copyright notice in the Description page of Project Settings.


#include "FG_Character.h"

// Sets default values
AFG_Character::AFG_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFG_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFG_Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value * CharacterMovementSpeed);
	}
}

void AFG_Character::MoveBackwards(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(-GetActorForwardVector(), Value * CharacterMovementSpeed);
	}
}

void AFG_Character::MoveLeft(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(-GetActorRightVector(), Value * CharacterMovementSpeed);
	}
}

void AFG_Character::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value * CharacterMovementSpeed);
	}
}

// Called every frame
void AFG_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

