#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraOverrideVolume.generated.h"

UCLASS()
class FROGGAME_API ACameraOverrideVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ACameraOverrideVolume();

protected:
	virtual void BeginPlay() override;
	class UBoxComponent* TriggerVolume;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverrideCamera(AActor* OverlappedActor, AActor* OverlappingActor);

	UFUNCTION()
	void StopOverriding(AActor* OverlappedActor, AActor* OverlappingActor);
};
