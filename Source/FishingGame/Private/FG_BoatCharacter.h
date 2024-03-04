// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IFG_MoveableCharacter.h"
#include "GameFramework/Character.h"
#include "FG_BoatCharacter.generated.h"

class UFloatingPawnMovement;

UCLASS()
class AFG_BoatCharacter : public APawn, public IFG_MoveableCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Movement")
	int TurnRate = 1;
	UPROPERTY(EditAnywhere, Category="Movement")
	int Speed = 1;

	UPROPERTY(EditAnywhere)
	UFloatingPawnMovement* MovementComponent = nullptr;

public:
	// Sets default values for this character's properties
	AFG_BoatCharacter();

	// IFG_MoveableCharacter Interface
	virtual void MoveForward(float Value) override;
	virtual void MoveRight(float Value) override;
	virtual void MoveLeft(float Value) override;
	virtual void MoveBackwards(float Value) override;
	// END IFG_MoveableCharacter Interface.

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
