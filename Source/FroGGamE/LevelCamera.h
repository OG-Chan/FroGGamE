#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelCamera.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FROGGAME_API ULevelCamera : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULevelCamera();

	void SetTarget(AActor* NewTarget, FVector NewCameraOffset = FVector(0, 1000, 300));
	UPROPERTY(EditAnywhere)
	FVector CameraOffset = FVector(0, 1000, 300);

protected:
	virtual void BeginPlay() override;
	
	AActor* Target;
	void FocusAt(AActor* Actor);

	
	
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	bool bShouldFollow = true;
	UPROPERTY(EditAnywhere)
	bool bShouldLookAt = true;
	
private:

};
