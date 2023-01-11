﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TaskProject/Interaction/Interfaces/IInteractable.h"
#include "TaskProject/Actions/Action.h"
#include "TaskProject/Quest/Interfaces/IObservable.h"
#include "InteractableAction.generated.h"

UCLASS(Abstract, HideCategories=(Replication, Collision, HLOD, Physics, Networking, WorldPartition, Input, Actor, Cooking, DataLayers, Advanced, Rendering))
class TASKPROJECT_API AInteractableAction : public AActor, public IInteractable, public IObservable
{
	GENERATED_BODY()

public:
	AInteractableAction();

	virtual void Interact_Implementation() override;
	virtual void OnRangeEnter_Implementation(AActor* Actor) override;
	virtual void OnRangeExit_Implementation(AActor* Actor) override;

	UPROPERTY(EditAnywhere, Category="Action")
	TSubclassOf<UAction> ActionType;

	virtual void AddListener_Implementation(UObject* Observer) override;
	virtual void RemoveListener_Implementation(UObject* Observer) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure)
	UAction* GetAction() const;

	UPROPERTY(VisibleAnywhere)
	TArray<UObject*> Listeners;

private:
	UPROPERTY()
	UAction* Action;

	void NotifyListeners(TSubclassOf<UObservableEvent> Event);
};