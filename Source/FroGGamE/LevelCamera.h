// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelCamera.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FROGGAME_API ULevelCamera : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULevelCamera();

	void TargetSetter(AActor* NewTarget, FVector NewCameraOffset);
	UPROPERTY(EditAnywhere)
	FVector CameraOffset = FVector(0, 1000, 300);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
	AActor* Target;
	FVector TargetLocation;
	FVector CameraLocation;
	void FocusAt();
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

};
