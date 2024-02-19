// Fill out your copyright notice in the Description page of Project Settings.


#include "FG_PlayerController.h"

#include "IFG_MoveableCharacter.h"

void AFG_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UInputComponent* InputComp = InputComponent.Get();
	checkf(InputComp != nullptr, TEXT("Input is expected InPawnto be enabled on this player controller."))

	// Bind movement events
	InputComp->BindAction("Move Forward", IE_Pressed, this, &AFG_PlayerController::MoveForward);
	InputComp->BindAction("Move Backward", IE_Pressed, this, &AFG_PlayerController::MoveBackward);
	InputComp->BindAction("Move Right", IE_Pressed, this, &AFG_PlayerController::MoveRight);
	InputComp->BindAction("Move Left", IE_Pressed, this, &AFG_PlayerController::MoveLeft);
}

void AFG_PlayerController::MoveForward()
{
	APawn* CurrentPawn = GetPawn();
	if(CurrentPawn == nullptr)
	{
		return;
	}

	IFG_MoveableCharacter* MoveableCharacter = Cast<IFG_MoveableCharacter>(CurrentPawn);

	if(MoveableCharacter != nullptr)
	{
		MoveableCharacter->MoveForward(1);
	}
}

void AFG_PlayerController::MoveBackward()
{
	APawn* CurrentPawn = GetPawn();
	if (CurrentPawn == nullptr)
	{
		return;
	}

	IFG_MoveableCharacter* MoveableCharacter = Cast<IFG_MoveableCharacter>(CurrentPawn);

	if (MoveableCharacter != nullptr)
	{
		MoveableCharacter->MoveBackwards(1);
	}
}

void AFG_PlayerController::MoveRight()
{
	APawn* CurrentPawn = GetPawn();
	if (CurrentPawn == nullptr)
	{
		return;
	}

	IFG_MoveableCharacter* MoveableCharacter = Cast<IFG_MoveableCharacter>(CurrentPawn);

	if (MoveableCharacter != nullptr)
	{
		MoveableCharacter->MoveRight(1);
	}
}

void AFG_PlayerController::MoveLeft()
{
	APawn* CurrentPawn = GetPawn();
	if (CurrentPawn == nullptr)
	{
		return;
	}

	IFG_MoveableCharacter* MoveableCharacter = Cast<IFG_MoveableCharacter>(CurrentPawn);

	if (MoveableCharacter != nullptr)
	{
		MoveableCharacter->MoveLeft(1);
	}
}
