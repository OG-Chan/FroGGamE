#include "CameraControlVolume.h"

#include "LevelCamera.h"

ACameraControlVolume::ACameraControlVolume()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACameraControlVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACameraControlVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
On begin overlap:
ULevelCamera::TargetSetter(NewTarget, NewCameraOffset);
*/