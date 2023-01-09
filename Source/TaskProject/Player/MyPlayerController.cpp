// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "TaskProject/Interaction/Interfaces/IInteractor.h"


AMyPlayerController::AMyPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LMB", IE_Pressed, this, &AMyPlayerController::TriggerInteractables);
}

void AMyPlayerController::TriggerInteractables()
{
	if (const auto PossesedPawn = GetPawn())
		if (PossesedPawn->GetClass()->ImplementsInterface(UInteractor::StaticClass()))
			IInteractor::Execute_TriggerInteractables(PossesedPawn);
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

