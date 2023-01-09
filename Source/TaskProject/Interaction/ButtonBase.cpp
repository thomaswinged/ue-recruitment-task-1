// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonBase.h"


AButtonBase::AButtonBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AButtonBase::BeginPlay()
{
	Super::BeginPlay();

	if (ActionType)
		Action = NewObject<UAction>(this, ActionType);
	else
		UE_LOG(LogTemp, Error, TEXT("%hs >> No action specified!"), ANSI_TO_TCHAR(__FUNCTION__))
}

UAction* AButtonBase::GetAction() const
{
	return Action;
}

void AButtonBase::Interact_Implementation()
{
	if (Action)
		Action->Execute(this);
}
