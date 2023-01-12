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
		UE_LOG(LogTemp, Error, TEXT("%s >> No action specified!"), ANSI_TO_TCHAR(__FUNCTION__))
}

UAction* AInteractableAction::GetAction() const
{
	return Action;
}

void AInteractableAction::Interact_Implementation()
{
	NotifyListeners(UInteractedEvent::StaticClass());
}

void AInteractableAction::OnRangeEnter_Implementation(const TScriptInterface<IInteractor>& Interactor)
{
	NotifyListeners(UEnteredRangeEvent::StaticClass());
}

void AInteractableAction::OnRangeExit_Implementation(const TScriptInterface<IInteractor>& Interactor)
{
	NotifyListeners(UExitedRangeEvent::StaticClass());
}

void AInteractableAction::NotifyListeners(TSubclassOf<UObservableEvent> Event)
{
	// Iterate over indices to avoid "Array has changed during ranged-for iteration!" error
	for (int32 i = 0 ; i < Listeners.Num() ; i++)
	{
		IObserver::Execute_OnObservableEvent(Listeners[i].GetObject(), this, Event);
	}
}

void AInteractableAction::AddListener_Implementation(const TScriptInterface<IObserver>& Observer)
{
	if (!Listeners.Contains(Observer))
		Listeners.Add(Observer);
}

void AInteractableAction::RemoveListener_Implementation(const TScriptInterface<IObserver>& Observer)
{
	if (Listeners.Contains(Observer))
		Listeners.Remove(Observer);
}
