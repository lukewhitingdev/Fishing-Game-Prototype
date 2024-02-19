// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FG_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AFG_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

private:
	void MoveForward();
	void MoveBackward();
	void MoveRight();
	void MoveLeft();
};
