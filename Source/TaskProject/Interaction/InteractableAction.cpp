// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableAction.h"


AInteractableAction::AInteractableAction()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AInteractableAction::BeginPlay()
{
	Super::BeginPlay();

	if (ActionType)
		Action = NewObject<UAction>(this, ActionType);
	else
		UE_LOG(LogTemp, Error, TEXT("%hs >> No action specified!"), ANSI_TO_TCHAR(__FUNCTION__))
}

UAction* AInteractableAction::GetAction() const
{
	return Action;
}

void AInteractableAction::Interact_Implementation()
{
	if (Action)
		Action->Execute(this);
}
