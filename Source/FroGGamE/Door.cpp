#include "Door.h"

#include "MovieSceneSequenceID.h"
#include "Components/BoxComponent.h"

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = false;

	UStaticMeshComponent* DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	RootComponent = DoorMesh;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->SetWorldScale3D(FVector (1, 0.5, 2));
	
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ADoor::Teleport);
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


void ADoor::Teleport(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bUnlocked)
	{
		FVector OtherActorLocation = OtherActor->GetActorLocation();
	
		if (bIsElevator == false)
		{
			FVector LocationDiff = GetActorLocation() - OtherActorLocation;
			if (LocationDiff.X < 0 && bRightSideAccess)
			{
				OtherActor->SetActorLocation(OtherActor->GetActorLocation() + FVector(-100, 0, 0));
			}
			if (LocationDiff.X > 0 && bLeftSideAccess)
			{
				OtherActor->SetActorLocation(OtherActor->GetActorLocation() + FVector(100, 0, 0));
			}
		}
		else
		{
			OtherActor->SetActorLocation(OtherActorLocation + FVector(0, 0, 410));
		}
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Locked"));
	}
}