// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IFG_MoveableCharacter.h"
#include "GameFramework/Character.h"
#include "Interfaces/FG_IUseInteracts.h"
#include "FG_Character.generated.h"

class UFG_CharacterInteractComponent;
class UBoxComponent;

UCLASS()
class AFG_Character : public ACharacter, public IFG_MoveableCharacter, public IFG_IUseInteracts
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFG_Character();

public:
	UPROPERTY(EditAnywhere, Category="Movement")
	int CharacterMovementSpeed = 10;

private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* InteractTrigger;

	UPROPERTY()
	UFG_CharacterInteractComponent* InteractComponent;

private:
	// IFG_MoveableCharacter Interface
	virtual void MoveForward(float Value) override;
	virtual void MoveBackwards(float Value) override;
	virtual void MoveLeft(float Value) override;
	virtual void MoveRight(float Value) override;
	// END IFG_MoveableCharacter Interface.

	// IFG_UseInteracts Interface
	virtual void Interact() override;
	// END IFG_UseInteracts Interface.

	// Sets the controller rotation, will assert if no controller is possesing this character.
	void SetControllerRotation(const FRotator& Rotation);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnInteractOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnInteractOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
