#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraControlVolume.generated.h"

UCLASS()
class FROGGAME_API ACameraControlVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ACameraControlVolume();

protected:
	virtual void BeginPlay() override;

	bool ChangeCamera = false;
	AActor* Target;
	FVector CameraOffset = FVector(0, 1500, 300);

public:	
	virtual void Tick(float DeltaTime) override;

};
