// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IObserver.h"
#include "QuestManager.generated.h"

UCLASS(Abstract, HideCategories=(Transform, Rendering, Replication, Collision, HLOD, Physics, Networking, WorldPartition, Input, Actor, Advanced, Cooking, DataLayers))
class TASKPROJECT_API AQuestManager : public AActor, public IObserver
{
	GENERATED_BODY()

public:
	AQuestManager();

	virtual void OnNotify_Implementation(UObject* Subject, TSubclassOf<UGameEvent> Event) override;
	
	UFUNCTION(BlueprintPure)
	bool GetNextObjective(FQuestObjective& OutObjective) const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	TArray<FQuestObjective> Objectives;

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveCompleted(FQuestObjective Objective);

	
private:
	void InitializeObjectives();
	
	void SetEnabledObjectiveListener(int32 ID, bool bEnabled);

	void SetObjectiveCompleted(int32 ID, bool bCompleted);
};
