// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraControlVolume.generated.h"

UCLASS()
class FROGGAME_API ACameraControlVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraControlVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool ChangeCamera = false;
	AActor* Target;
	FVector CameraOffset = FVector(0, 1500, 300);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
