#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class UBoxComponent;

UCLASS()
class FROGGAME_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADoor();

protected:
	virtual void BeginPlay() override;

	AActor* Player;
	UBoxComponent* LeftAccess;
	UBoxComponent* RightAccess;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	bool bRightSideAccess = true;
	UPROPERTY(EditAnywhere)
	bool bLeftSideAccess = true;
	UPROPERTY(EditAnywhere)
	bool bIsElevator;
	UPROPERTY(EditAnywhere)
	float TeleportDistance = 200;

	void LockUnlock();

private:

	void Teleport(AActor* OverlappedActor, AActor* OtherActor);
	
};
