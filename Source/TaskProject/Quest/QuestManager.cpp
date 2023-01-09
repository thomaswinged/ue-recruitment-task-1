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

	TArray<AActor*> ObjectiveActors;
	Objectives.GetKeys(ObjectiveActors);
	for (const auto Objective : ObjectiveActors)
	{
		if (Objective->GetClass()->ImplementsInterface(UObservable::StaticClass()))
		{
			IObservable::Execute_AddListener(Objective, this);
		}
	}
}

void AQuestManager::OnNotify_Implementation(UObject* Subject, TSubclassOf<UGameEvent> Event)
{
	if (Objectives.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> No more objectives!"), ANSI_TO_TCHAR(__FUNCTION__));
	}
	
	AActor* NextSubject;
	const auto EventType = GetNextObjective(NextSubject);
	if (NextSubject && Subject == NextSubject && Event == EventType)
	{
		HandleObjectiveDone(NextSubject);
	}
	
}

TSubclassOf<UGameEvent> AQuestManager::GetNextObjective(AActor*& OutObject)
{
	TArray<AActor*> ObjectiveActors;
	Objectives.GetKeys(ObjectiveActors);

	if (ObjectiveActors.Num() > 0)
	{
		OutObject = ObjectiveActors[0];

		return Objectives.FindRef(ObjectiveActors[0]);
	}

	return nullptr;
}

void AQuestManager::HandleObjectiveDone(AActor* ObjectiveSubject)
{
	UE_LOG(LogTemp, Warning, TEXT("%s >> Check!"), ANSI_TO_TCHAR(__FUNCTION__));

	if (ObjectiveSubject->GetClass()->ImplementsInterface(UObservable::StaticClass()))
	{
		IObservable::Execute_RemoveListener(ObjectiveSubject, this);
	}

	Objectives.FindAndRemoveChecked(ObjectiveSubject);
}