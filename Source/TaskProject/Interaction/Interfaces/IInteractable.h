// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskProject/Core/ListenerEvent.h"
#include "UObject/Interface.h"
#include "IInteractable.generated.h"

UCLASS(BlueprintType)
class UInteractedEvent : public UListenerEvent { GENERATED_BODY() };

UCLASS(BlueprintType)
class UEnteredRangeEvent : public UListenerEvent { GENERATED_BODY() };

UCLASS(BlueprintType)
class UExitedRangeEvent : public UListenerEvent { GENERATED_BODY() };


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
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interaction")
	void Interact();
	virtual void Interact_Implementation()
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnRangeEnter(AActor* Actor);
	virtual void OnRangeEnter_Implementation(AActor* Actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnRangeExit(AActor* Actor);
	virtual void OnRangeExit_Implementation(AActor* Actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}
};
