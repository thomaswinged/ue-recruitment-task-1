// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskProject/Utils.h"
#include "UObject/Interface.h"
#include "IObserver.generated.h"

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
	void OnNotify(UObject* Subject, TSubclassOf<UGameEvent> Event);
	virtual void OnNotify_Implementation(UObject* Subject, TSubclassOf<UGameEvent> Event)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}
};
