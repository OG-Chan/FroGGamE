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
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* TriggerBox;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	bool bRightSideAccess = true;
	UPROPERTY(EditAnywhere)
	bool bLeftSideAccess = true;
	UPROPERTY(EditAnywhere)
	bool bUnlocked = true;
	UPROPERTY(EditAnywhere)
	bool bIsElevator;

private:

	UFUNCTION()
	void Teleport(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
