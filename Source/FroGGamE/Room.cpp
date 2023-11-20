#include "Room.h"

ARoom::ARoom()
{
	PrimaryActorTick.bCanEverTick = false;
	
	RoomVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Room Volume"));
	LeftWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Wall"));
	RightWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Wall"));
	BackWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Back Wall"));
	FrontWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Front Wall"));
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	RootComponent = RoomVolume;
	
	LeftWall->SetupAttachment(RootComponent);
	LeftWall->SetWorldScale3D(FVector(0.1, 10, 4));
	RightWall->SetupAttachment(RootComponent);
	RightWall->SetWorldScale3D(FVector(0.1, 10, 4));
	BackWall->SetupAttachment(RootComponent);
	FrontWall->SetupAttachment(RootComponent);
	Floor->SetupAttachment(RootComponent);
	BackWall->AddLocalOffset(FVector (0, -500, 0));
	FrontWall->AddLocalOffset(FVector (0, 500, 0));
	Floor->AddLocalOffset(FVector (0, 0, -200));
}

void ARoom::BeginPlay()
{
	Super::BeginPlay();

	UpdateRoom();
}

void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoom::UpdateRoom()
{
	//update room width first
	Floor->SetWorldScale3D(FVector (RoomWidth/100, 10, 0.1));
	RoomVolume->InitBoxExtent(FVector(RoomWidth, 1000, 400));
	LeftWall->AddLocalOffset(FVector (-RoomWidth/2, 0, 0));
	RightWall->AddLocalOffset(FVector (RoomWidth/2, 0, 0));
	FrontWall->SetWorldScale3D(FVector(RoomWidth/100, 0.1, 4));
	BackWall->SetWorldScale3D(FVector(RoomWidth/100, 0.1, 4));
}
