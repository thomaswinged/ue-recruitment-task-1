// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"


AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereInteractor = CreateDefaultSubobject<USphereInteractor>(TEXT("InteractablesDetector"));
	SphereInteractor->SetupAttachment(GetRootComponent());
	SphereInteractor->SetSphereRadius(InteractionRadius);
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMyCharacter::TriggerInteractables_Implementation()
{
	SphereInteractor->TriggerInteraction();			
}