// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"

#include "MyCharacter.h"
#include "TaskProject/Interaction/Interfaces/IInteractor.h"


AMyPlayerController::AMyPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LMB", IE_Pressed, this, &AMyPlayerController::HandleLMBClick);
}

void AMyPlayerController::HandleLMBClick()
{
	if (const auto MyCharacter = Cast<AMyCharacter>(GetPawn()))
		MyCharacter->InteractWithWorld();
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

