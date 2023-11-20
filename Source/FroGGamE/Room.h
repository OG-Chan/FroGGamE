#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Room.generated.h"

UCLASS()
class FROGGAME_API ARoom : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoom();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UBoxComponent* RoomVolume;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* LeftWall;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RightWall;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BackWall;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontWall;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Floor;

	void UpdateRoom();
	float RoomWidth = 500;
};