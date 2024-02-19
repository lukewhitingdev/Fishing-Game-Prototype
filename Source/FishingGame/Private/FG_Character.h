// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IFG_MoveableCharacter.h"
#include "GameFramework/Character.h"
#include "FG_Character.generated.h"

UCLASS()
class AFG_Character : public ACharacter, public IFG_MoveableCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Movement")
	int CharacterMovementSpeed = 10;

	// Sets default values for this character's properties
	AFG_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// IFG_MoveableCharacter Interface
	virtual void MoveForward(float Value) override;
	virtual void MoveBackwards(float Value) override;
	virtual void MoveLeft(float Value) override;
	virtual void MoveRight(float Value) override;
	// END IFG_MoveableCharacter Interface.

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
