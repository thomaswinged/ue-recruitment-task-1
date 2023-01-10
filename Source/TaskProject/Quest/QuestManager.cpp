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
	if (Objectives[ID].Subject->GetClass()->ImplementsInterface(UObservable::StaticClass()))
	{
		if (bEnabled)
			IObservable::Execute_AddListener(Objectives[ID].Subject, this);
		else
			IObservable::Execute_RemoveListener(Objectives[ID].Subject, this);
	}
}

void AQuestManager::OnNotify_Implementation(UObject* Subject, TSubclassOf<UGameEvent> Event)
{
	FQuestObjective NextObjective;
	if (GetNextObjective(NextObjective) && Subject == NextObjective.Subject && Event == NextObjective.EventType)
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
	if (Objectives.Num() > ID)
	{
		Objectives[ID].Completed = bCompleted;
	}
}
