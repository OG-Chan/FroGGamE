// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "LevelCameraActor.generated.h"

UCLASS()
class FROGGAME_API ALevelCameraActor : public AActor
{
	GENERATED_BODY()
	
public:
	ALevelCameraActor();

	
protected:
	virtual void BeginPlay() override;

	AActor* Target;
	void FocusAt(AActor* Actor);

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	FVector CameraOffset = FVector(0, 1000, 300);
	UPROPERTY(EditAnywhere)
	bool bShouldFollow = true;
	UPROPERTY(EditAnywhere)
	bool bShouldLookAt = true;

	void SetTarget(AActor* NewTarget, FVector NewCameraOffset = FVector(0, 1000, 300));
};
