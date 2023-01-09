// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereInteractor.h"
#include "Interfaces/IInteractable.h"


USphereInteractor::USphereInteractor()
{
	PrimaryComponentTick.bCanEverTick = true;

	OnComponentBeginOverlap.AddDynamic(this, &USphereInteractor::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &USphereInteractor::OnEndOverlap);

	InRange = TArray<AActor*>();
}

void USphereInteractor::BeginPlay()
{
	Super::BeginPlay();
}

void USphereInteractor::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USphereInteractor::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other,
                                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!InRange.Contains(Other))
	{
		if (Other->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			InRange.Add(Other);
			IInteractable::Execute_OnRangeEnter(Other, GetOwner());
		}
	}
}

void USphereInteractor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (InRange.Contains(OtherActor))
	{
		if (OtherActor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			InRange.Remove(OtherActor);
			IInteractable::Execute_OnRangeExit(OtherActor, GetOwner());
		}
	}
		
}

void USphereInteractor::TriggerInteraction()
{
	for (const auto Actor : InRange)
	{
		if (Actor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			IInteractable::Execute_Interact(Actor);
		}
	}
}