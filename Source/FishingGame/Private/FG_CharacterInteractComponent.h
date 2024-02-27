// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FG_CharacterInteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UFG_CharacterInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFG_CharacterInteractComponent();

private:
	UPROPERTY()
	AActor* InteractableActor = nullptr;

public:
	UFUNCTION(BlueprintCallable, Category="Interact")
	void SetInteractableActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Interact")
	void ClearInteractableActor();

	UFUNCTION()
	void Interact() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
