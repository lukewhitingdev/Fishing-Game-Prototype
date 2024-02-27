// Fill out your copyright notice in the Description page of Project Settings.


#include "FG_Character.h"

#include "FG_CharacterInteractComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AFG_Character::AFG_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractComponent = CreateDefaultSubobject<UFG_CharacterInteractComponent>(TEXT("InteractComponent"));

	InteractTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractTrigger"));
	InteractTrigger->SetupAttachment(GetCapsuleComponent());
	InteractTrigger->SetCollisionResponseToAllChannels(ECR_Overlap);
	InteractTrigger->SetCollisionObjectType(ECC_Pawn);
	InteractTrigger->IgnoreActorWhenMoving(this, true);
	InteractTrigger->OnComponentBeginOverlap.AddDynamic(this, &AFG_Character::OnInteractOverlapBegin);
	InteractTrigger->OnComponentEndOverlap.AddDynamic(this, &AFG_Character::OnInteractOverlapEnd);
}

// Called when the game starts or when spawned
void AFG_Character::BeginPlay()
{
	Super::BeginPlay();
}

void AFG_Character::OnInteractOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	InteractComponent->SetInteractableActor(OtherActor);
}

void AFG_Character::OnInteractOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	InteractComponent->ClearInteractableActor();
}

void AFG_Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		SetControllerRotation(FRotator(0, 0, 0));
		AddMovementInput(FVector(1, 0, 0), Value * CharacterMovementSpeed);
	}
}

void AFG_Character::MoveBackwards(float Value)
{
	if (Value != 0.0f)
	{
		SetControllerRotation(FRotator(0, 180, 0));
		AddMovementInput(FVector(-1, 0, 0), Value * CharacterMovementSpeed);
	}
}

void AFG_Character::MoveLeft(float Value)
{
	if (Value != 0.0f)
	{
		SetControllerRotation(FRotator(0, -90, 0));
		AddMovementInput(FVector(0, -1, 0), Value * CharacterMovementSpeed);
	}
}

void AFG_Character::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		SetControllerRotation(FRotator(0, 90, 0));
		AddMovementInput(FVector(0, 1, 0), Value * CharacterMovementSpeed);
	}
}

void AFG_Character::Interact()
{
	InteractComponent->Interact();
}

void AFG_Character::SetControllerRotation(const FRotator& Rotation)
{
	AController* controller = GetController();
	checkf(controller != nullptr, TEXT("Tried to set controller rotation but we do not have a controller!"));
	controller->SetControlRotation(Rotation);
}

// Called every frame
void AFG_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

