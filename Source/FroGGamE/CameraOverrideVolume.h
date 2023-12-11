// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraOverrideVolume.generated.h"

UCLASS()
class FROGGAME_API ACameraOverrideVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraOverrideVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class UBoxComponent* TriggerVolume;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OverrideCamera(AActor* OverlappedActor, AActor* OverlappingActor);
};