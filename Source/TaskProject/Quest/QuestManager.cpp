// Copyright 2022-2023 Thomas Winged. All Rights Reserved.


#include "QuestManager.h"

#include "Interfaces/IObservable.h"


AQuestManager::AQuestManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AQuestManager::BeginPlay()
{
	Super::BeginPlay();

	InitializeObjectives();
}

void AQuestManager::InitializeObjectives()
{
	for (int32 i = 0; i < Objectives.Num(); i++)
	{
		Objectives[i].ID = i;

		SetEnabledObjectiveListener(i, true);
	}
}

void AQuestManager::SetEnabledObjectiveListener(int32 ID, bool bEnabled)
{
	if (const auto Subject = Objectives[ID].Subject)
	{
		if (Subject->GetClass()->ImplementsInterface(UObservable::StaticClass()))
		{
			if (bEnabled)
				IObservable::Execute_AddListener(Subject, this);
			else
				IObservable::Execute_RemoveListener(Subject, this);
		}
	}
}



void AQuestManager::OnObservableEvent_Implementation(const TScriptInterface<IObservable>& Subject, TSubclassOf<UObservableEvent> Event)
{
	FQuestObjective NextObjective;
	const bool bNextObjectiveFound = GetNextObjective(NextObjective);
	if (bNextObjectiveFound && Subject == NextObjective.Subject && Event == NextObjective.EventType)
	{
		SetObjectiveCompleted(NextObjective.ID, true);
		SetEnabledObjectiveListener(NextObjective.ID, false);

		OnObjectiveCompleted(NextObjective);
	}
}

bool AQuestManager::GetNextObjective(FQuestObjective& OutObjective) const
{
	if (Objectives.Num() > 0)
	{
		for (FQuestObjective Objective : Objectives)
		{
			if (!Objective.Completed)
			{
				OutObjective = Objective;
				return true;
			}
		}
	}

	return false;
}

void AQuestManager::SetObjectiveCompleted(const int32 ID, const bool bCompleted)
{
	for (int i = 0; i < Objectives.Num(); i++)
	{
		if (Objectives[i].ID == ID)
		{
			Objectives[ID].Completed = bCompleted;
			return;
		}
	}
	
	UE_LOG(LogTemp, Error, TEXT("%s >> Objective with ID: {%d} was not found!"), ANSI_TO_TCHAR(__FUNCTION__), ID)
}
