// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IFG_MoveableCharacter.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFG_MoveableCharacter : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for any object that can move forward, right, left or backwards.
 */
class IFG_MoveableCharacter
{
	GENERATED_BODY()

public:
	void virtual MoveForward(float Value) = 0;
	void virtual MoveRight(float Value) = 0;
	void virtual MoveLeft(float Value) = 0;
	void virtual MoveBackwards(float Value) = 0;
};
