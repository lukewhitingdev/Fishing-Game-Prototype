// Fill out your copyright notice in the Description page of Project Settings.


#include "FG_CharacterInteractComponent.h"
#include "Interfaces/FG_IInteractable.h"

// Sets default values for this component's properties
UFG_CharacterInteractComponent::UFG_CharacterInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UFG_CharacterInteractComponent::SetInteractableActor(AActor* Actor)
{
	checkf(Actor != nullptr, TEXT("Tried to set interactable actor to a null actor!. If you wish to clear the actor please use ClearInteractableActor"));
	if(Actor->Implements<UFG_IInteractable>())
	{
		InteractableActor = Actor;
	}
}

void UFG_CharacterInteractComponent::ClearInteractableActor()
{
	InteractableActor = nullptr;
}

void UFG_CharacterInteractComponent::Interact() const
{
	if(InteractableActor != nullptr)
	{
		IFG_IInteractable* Interactable = Cast<IFG_IInteractable>(InteractableActor);
		if(Interactable->CanInteract())
		{
			Interactable->Interact();
		}
	}
}

// Called when the game starts
void UFG_CharacterInteractComponent::BeginPlay()
{
	Super::BeginPlay();
}


