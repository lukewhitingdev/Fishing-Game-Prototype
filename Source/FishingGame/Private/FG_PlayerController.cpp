// Fill out your copyright notice in the Description page of Project Settings.


#include "FG_PlayerController.h"

#include "IFG_MoveableCharacter.h"

void AFG_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UInputComponent* InputComp = InputComponent.Get();
	checkf(InputComp != nullptr, TEXT("Input is expected InPawnto be enabled on this player controller."))

	// Bind movement events
	InputComp->BindAxis("Move Forward", this, &AFG_PlayerController::MoveForward);
	InputComp->BindAxis("Move Backward", this, &AFG_PlayerController::MoveBackward);
	InputComp->BindAxis("Move Right", this, &AFG_PlayerController::MoveRight);
	InputComp->BindAxis("Move Left", this, &AFG_PlayerController::MoveLeft);
}

void AFG_PlayerController::MoveForward(float Value)
{
	APawn* CurrentPawn = GetPawn();
	if(CurrentPawn == nullptr)
	{
		return;
	}

	IFG_MoveableCharacter* MoveableCharacter = Cast<IFG_MoveableCharacter>(CurrentPawn);

	if(MoveableCharacter != nullptr)
	{
		MoveableCharacter->MoveForward(Value);
	}
}

void AFG_PlayerController::MoveBackward(float Value)
{
	APawn* CurrentPawn = GetPawn();
	if (CurrentPawn == nullptr)
	{
		return;
	}

	IFG_MoveableCharacter* MoveableCharacter = Cast<IFG_MoveableCharacter>(CurrentPawn);

	if (MoveableCharacter != nullptr)
	{
		MoveableCharacter->MoveBackwards(Value);
	}
}

void AFG_PlayerController::MoveRight(float Value)
{
	APawn* CurrentPawn = GetPawn();
	if (CurrentPawn == nullptr)
	{
		return;
	}

	IFG_MoveableCharacter* MoveableCharacter = Cast<IFG_MoveableCharacter>(CurrentPawn);

	if (MoveableCharacter != nullptr)
	{
		MoveableCharacter->MoveRight(Value);
	}
}

void AFG_PlayerController::MoveLeft(float Value)
{
	APawn* CurrentPawn = GetPawn();
	if (CurrentPawn == nullptr)
	{
		return;
	}

	IFG_MoveableCharacter* MoveableCharacter = Cast<IFG_MoveableCharacter>(CurrentPawn);

	if (MoveableCharacter != nullptr)
	{
		MoveableCharacter->MoveLeft(Value);
	}
}
