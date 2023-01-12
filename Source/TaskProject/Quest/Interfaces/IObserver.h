// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskProject/Core/ObservableEvent.h"
#include "UObject/Interface.h"
#include "IObserver.generated.h"

class IObservable;

// This class does not need to be modified.
UINTERFACE(BlueprintType, Blueprintable)
class UObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TASKPROJECT_API IObserver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnObservableEvent(const TScriptInterface<IObservable>& Subject, TSubclassOf<UObservableEvent> Event);
	virtual void OnObservableEvent_Implementation(const TScriptInterface<IObservable>& Subject, TSubclassOf<UObservableEvent> Event)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}
};
