// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskProject/Core/ObservableEvent.h"
#include "UObject/Interface.h"
#include "IInteractable.generated.h"

class IInteractor;

UCLASS(BlueprintType)
class UInteractedEvent : public UObservableEvent { GENERATED_BODY() };

UCLASS(BlueprintType)
class UEnteredRangeEvent : public UObservableEvent { GENERATED_BODY() };

UCLASS(BlueprintType)
class UExitedRangeEvent : public UObservableEvent { GENERATED_BODY() };


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
	void OnRangeEnter(const TScriptInterface<IInteractor>& Interactor);
	virtual void OnRangeEnter_Implementation(const TScriptInterface<IInteractor>& Interactor)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	void OnRangeExit(const TScriptInterface<IInteractor>& Interactor);
	virtual void OnRangeExit_Implementation(const TScriptInterface<IInteractor>& Interactor)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}
};
