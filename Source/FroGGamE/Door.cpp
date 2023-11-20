#include "Door.h"

#include "Components/BoxComponent.h"

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	RootComponent = DoorMesh;

	LeftAccess = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftAccess"));
	RightAccess = CreateDefaultSubobject<UBoxComponent>(TEXT("RightAccess"));
	LeftAccess->SetWorldScale3D(FVector (1, 0.5, 2));
	RightAccess->SetWorldScale3D(FVector (1, 0.5, 2));
	LeftAccess->AddLocalOffset(FVector(0, -100, 0));
	RightAccess->AddLocalOffset(FVector(0, 100, 0));

	LeftAccess->OnComponentBeginOverlap.AddDynamic(this, &ADoor::Teleport);
	//OnActorBeginOverlap.AddDynamic(this, &ADoor::Teleport);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();

	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ADoor::Teleport(AActor* OverlappedActor, AActor* OtherActor)
{
	OtherActor->GetActorLocation();
	OverlappedActor->GetActorLocation();
	//FVector Distance =
	//setactortransform
//if (LeftAccess && normal<0) OtherActor->AddActorLocalOffset(FVector (0, TeleportDistance, 0));
//if (RightAccess) OtherActor->AddActorLocalOffset(FVector (0, -TeleportDistance, 0));
}

void ADoor::LockUnlock()
{
	
}
