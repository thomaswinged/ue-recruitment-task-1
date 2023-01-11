// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TaskProject/Interaction/SphereInteractor.h"
#include "MyCharacter.generated.h"

UCLASS()
class TASKPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

	UPROPERTY(EditAnywhere, Category="Interaction")
	USphereInteractor* SphereInteractor;

protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void InteractWithWorld() const;
};
