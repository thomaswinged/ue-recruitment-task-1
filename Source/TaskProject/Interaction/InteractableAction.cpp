// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableAction.h"

#include "TaskProject/Quest/Interfaces/IObserver.h"


AInteractableAction::AInteractableAction()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AInteractableAction::BeginPlay()
{
	Super::BeginPlay();

	if (ActionType)
	{
		Action = NewObject<UAction>(this, ActionType);
		Action->Init();
	}
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
	{
		NotifyListeners(UInteractedEvent::StaticClass());
	}
}

void AInteractableAction::OnRangeEnter_Implementation(AActor* Actor)
{
	NotifyListeners(UEnteredRangeEvent::StaticClass());
}

void AInteractableAction::OnRangeExit_Implementation(AActor* Actor)
{
	NotifyListeners(UExitedRangeEvent::StaticClass());
}

void AInteractableAction::NotifyListeners(TSubclassOf<UGameEvent> Event)
{
	// Iterate over indices to avoid "Array has changed during ranged-for iteration!" error
	for (int32 i = 0 ; i < Listeners.Num() ; i++)
	{
		if (Listeners[i]->GetClass()->ImplementsInterface(UObserver::StaticClass()))
		{
			IObserver::Execute_OnNotify(Listeners[i], this, Event);
		}
	}
}

void AInteractableAction::AddListener_Implementation(UObject* Observer)
{
	if (!Listeners.Contains(Observer))
		Listeners.Add(Observer);
}

void AInteractableAction::RemoveListener_Implementation(UObject* Observer)
{
	if (Listeners.Contains(Observer))
		Listeners.Remove(Observer);
}
