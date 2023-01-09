// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TaskProject/Interaction/Interfaces/IInteractor.h"
#include "TaskProject/Interaction/SphereInteractor.h"
#include "MyCharacter.generated.h"

UCLASS()
class TASKPROJECT_API AMyCharacter : public ACharacter, public IInteractor
{
	GENERATED_BODY()

public:
	AMyCharacter();

	UPROPERTY(EditAnywhere, Category="Interaction")
	USphereInteractor* SphereInteractor;

	UPROPERTY(EditAnywhere, Category="Interaction")
	float InteractionRadius = 100.f;

protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interaction")
	void TriggerInteractables();
	virtual void TriggerInteractables_Implementation() override;
};
