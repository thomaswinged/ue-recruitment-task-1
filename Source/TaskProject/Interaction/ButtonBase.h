﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TaskProject/Interaction/Interfaces/IInteractable.h"
#include "TaskProject/Actions/Action.h"
#include "ButtonBase.generated.h"

UCLASS(Abstract)
class TASKPROJECT_API AButtonBase : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	AButtonBase();

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void Interact();
	virtual void Interact_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnRangeEnter(AActor* Actor);
	virtual void OnRangeEnter_Implementation(AActor* Actor) override
	{
		UE_LOG(LogTemp, Warning, TEXT("%hs >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnRangeExit(AActor* Actor);
	virtual void OnRangeExit_Implementation(AActor* Actor) override
	{
		UE_LOG(LogTemp, Warning, TEXT("%hs >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}

	UPROPERTY(EditAnywhere, Category="Button")
	TSubclassOf<UAction> ActionType;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure)
	UAction* GetAction() const;

private:
	UPROPERTY()
	UAction* Action;
};