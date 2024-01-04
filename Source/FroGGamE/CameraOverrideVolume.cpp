#include "CameraOverrideVolume.h"
#include "LevelCameraActor.h"
#include "Components/BoxComponent.h"

ACameraOverrideVolume::ACameraOverrideVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	SetRootComponent(TriggerVolume);
}

void ACameraOverrideVolume::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACameraOverrideVolume::OverrideCamera);
	OnActorEndOverlap.AddDynamic(this, &ACameraOverrideVolume::StopOverriding);
}

void ACameraOverrideVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACameraOverrideVolume::OverrideCamera(AActor* OverlappedActor, AActor* OverlappingActor)
{
	//.ALevelCameraActor::SetTarget(OverlappedActor);
}

void ACameraOverrideVolume::StopOverriding(AActor* OverlappedActor, AActor* OverlappingActor)
{
	//.ALevelCameraActor::SetTarget(OverlappingActor);
}
