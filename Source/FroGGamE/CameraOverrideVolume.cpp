// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraOverrideVolume.h"

#include "LevelCamera.h"
#include "Components/BoxComponent.h"

// Sets default values
ACameraOverrideVolume::ACameraOverrideVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	SetRootComponent(TriggerVolume);
}

// Called when the game starts or when spawned
void ACameraOverrideVolume::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACameraOverrideVolume::OverrideCamera);
}

// Called every frame
void ACameraOverrideVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACameraOverrideVolume::OverrideCamera(AActor* OverlappedActor, AActor* OverlappingActor)
{
	//ULevelCamera::SetTarget(this);
}


