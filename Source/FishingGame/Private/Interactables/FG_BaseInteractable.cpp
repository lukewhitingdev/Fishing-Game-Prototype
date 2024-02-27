// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/FG_BaseInteractable.h"

// Sets default values
AFG_BaseInteractable::AFG_BaseInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFG_BaseInteractable::Interact()
{
	Interact_Blueprint();
}

bool AFG_BaseInteractable::CanInteract()
{
	return CanInteract_Blueprint();
}

void AFG_BaseInteractable::Interact_Blueprint_Implementation()
{

}

bool AFG_BaseInteractable::CanInteract_Blueprint_Implementation()
{
	return true;
}

// Called when the game starts or when spawned
void AFG_BaseInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFG_BaseInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

