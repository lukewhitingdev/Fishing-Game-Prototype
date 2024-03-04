// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/FG_IInteractable.h"
#include "FG_BaseInteractable.generated.h"

UCLASS()
class AFG_BaseInteractable : public AActor, public IFG_IInteractable
{
	GENERATED_BODY()

private:
	UPROPERTY()
	AActor* InRangeActor = nullptr;

public:	
	// Sets default values for this actor's properties
	AFG_BaseInteractable();

public:
	// IInteracble Interface
	virtual void Interact() override;
	virtual bool CanInteract() override;
	virtual void SetActorInRange(AActor* ActorInRange) override;
	UFUNCTION(BlueprintPure, Category="Interactable")
	virtual AActor* GetActorInRange() override;
	// END - IInteracble Interface 


protected:
	UFUNCTION(BlueprintNativeEvent, Category="Interaction Extension")
	void Interact_Blueprint();
	UFUNCTION(BlueprintNativeEvent, Category = "Interaction Extension")
	bool CanInteract_Blueprint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
