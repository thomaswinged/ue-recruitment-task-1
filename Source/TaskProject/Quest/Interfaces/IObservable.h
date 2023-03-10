// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IObservable.generated.h"

class IObserver;

// This class does not need to be modified.
UINTERFACE(BlueprintType, Blueprintable)
class UObservable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TASKPROJECT_API IObservable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void AddListener(const TScriptInterface<IObserver>& Observer);
	virtual void AddListener_Implementation(const TScriptInterface<IObserver>& Listener)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RemoveListener(const TScriptInterface<IObserver>& Observer);
	virtual void RemoveListener_Implementation(const TScriptInterface<IObserver>& Listener)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}
};
