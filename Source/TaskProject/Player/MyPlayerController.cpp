// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"


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
	if (MyCharacter)
		MyCharacter->InteractWithWorld();
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	MyCharacter = Cast<AMyCharacter>(GetPawn());
	if (!MyCharacter)
		UE_LOG(LogTemp, Error, TEXT("%s >> No pawn found!"), ANSI_TO_TCHAR(__FUNCTION__));
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

