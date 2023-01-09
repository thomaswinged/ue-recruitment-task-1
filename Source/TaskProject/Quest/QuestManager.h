// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IObserver.h"
#include "QuestManager.generated.h"

UCLASS(Abstract)
class TASKPROJECT_API AQuestManager : public AActor, public IObserver
{
	GENERATED_BODY()

public:
	AQuestManager();

	UPROPERTY(EditAnywhere)
	TMap<AActor*, TSubclassOf<UGameEvent>> Objectives;

	UFUNCTION(BlueprintCallable)
	TSubclassOf<UGameEvent> GetNextObjective(AActor*& Object);

protected:
	virtual void BeginPlay() override;

	void HandleObjectiveDone(AActor* ObjectiveSubject);

public:
	virtual void OnNotify_Implementation(UObject* Subject, TSubclassOf<UGameEvent> Event) override;
};
