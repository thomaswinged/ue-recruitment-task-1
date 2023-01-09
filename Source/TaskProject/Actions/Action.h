// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Action.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class TASKPROJECT_API UAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Action")
	void Execute(const AActor* Subject);
	virtual void Execute_Implementation(const AActor* Subject)
	{
		UE_LOG(LogTemp, Error, TEXT("%hs >> Not implemented!"), ANSI_TO_TCHAR(__FUNCTION__))
	}

	UFUNCTION(BlueprintPure, Category="Action")
	FText GetDescription()
	{
		return Description;
	}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Action")
	FText Description;
};
