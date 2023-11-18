#include "Room.h"

ARoom::ARoom()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ARoom::BeginPlay()
{
	Super::BeginPlay();
}

void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

