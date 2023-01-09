// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TASKPROJECT_API IInteractable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void Interact();

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnRangeEnter(AActor* Actor);

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnRangeExit(AActor* Actor);
};
