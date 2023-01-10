// Fill out your copyright notice in the Description page of Project Settings.


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
		
		if (Objectives[i].Subject->GetClass()->ImplementsInterface(UObservable::StaticClass()))
		{
			IObservable::Execute_AddListener(Objectives[i].Subject, this);
		}
	}
}

void AQuestManager::OnNotify_Implementation(UObject* Subject, TSubclassOf<UGameEvent> Event)
{
	if (Objectives.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> No more objectives!"), ANSI_TO_TCHAR(__FUNCTION__));
	}

	FQuestObjective NextObjective;
	if (GetNextObjective(NextObjective) && Subject == NextObjective.Subject && Event == NextObjective.EventType)
	{
		SetObjectiveCompleted(NextObjective.ID, true);
		
		if (Objectives[NextObjective.ID].Subject->GetClass()->ImplementsInterface(UObservable::StaticClass()))
		{
			IObservable::Execute_RemoveListener(Objectives[NextObjective.ID].Subject, this);
		}

		OnObjectiveCompleted(NextObjective);
	}
}

bool AQuestManager::GetNextObjective(FQuestObjective& OutObjective)
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

void AQuestManager::SetObjectiveCompleted(int32 ID, bool bCompleted)
{
	if (Objectives.Num() > ID)
	{
		Objectives[ID].Completed = bCompleted;
	}
}
