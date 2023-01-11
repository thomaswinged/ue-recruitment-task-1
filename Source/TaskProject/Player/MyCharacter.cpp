// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "TaskProject/Interaction/Interfaces/IInteractor.h"


AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereInteractor = CreateDefaultSubobject<USphereInteractor>(TEXT("InteractablesDetector"));
	SphereInteractor->SetupAttachment(GetRootComponent());
	SphereInteractor->SetSphereRadius(100.f);
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMyCharacter::InteractWithWorld() const
{
	for (const auto Component : GetComponentsByInterface(UInteractor::StaticClass()))
	{
		IInteractor::Execute_TriggerInteractables(Component);
	}
}
