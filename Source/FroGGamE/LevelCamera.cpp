#include "LevelCamera.h"

#include "Kismet/KismetMathLibrary.h"

ULevelCamera::ULevelCamera()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}


void ULevelCamera::BeginPlay()
{
	Super::BeginPlay();
	Target = GetWorld()->GetFirstPlayerController()->GetPawn();
}


void ULevelCamera::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FocusAt(Target);
}

void ULevelCamera::FocusAt(AActor* Actor)
{

	FVector CurrentCameraLocation = GetOwner()->GetActorLocation();
	FVector CurrentTargetLocation = Target->GetActorLocation();
	FRotator LookRotation = UKismetMathLibrary::FindLookAtRotation(CurrentCameraLocation, CurrentTargetLocation);
	FRotator LookRotationInterp = UKismetMathLibrary::RInterpTo(GetOwner()->GetActorRotation(), LookRotation, FApp::GetDeltaTime(), 3);

	if (bShouldFollow) GetOwner()->SetActorLocation(Target->GetActorLocation() + CameraOffset);
	if (bShouldLookAt) GetOwner()->SetActorRotation(LookRotationInterp);
}

/*void ULevelCamera::TargetSetter(AActor* NewTarget, FVector NewCameraOffset)
{
	Target = NewTarget;
	CameraOffset = NewCameraOffset;
}*/