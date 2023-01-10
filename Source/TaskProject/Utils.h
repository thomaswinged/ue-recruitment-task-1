// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utils.generated.h"

UCLASS(Abstract, BlueprintType)
class UGameEvent : public UObject { GENERATED_BODY() };


USTRUCT(BlueprintType)
struct FQuestObjective
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Subject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameEvent> EventType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool Completed = false;
};
