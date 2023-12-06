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
	FVector CurrentTargetLocation = Actor->GetActorLocation();
	FRotator LookRotation = UKismetMathLibrary::FindLookAtRotation(CurrentCameraLocation, CurrentTargetLocation);
	FVector FollowLocation = Actor->GetActorLocation() * FVector (1, 0, 1) + CameraOffset;
	
	FRotator LookRotationInterp = UKismetMathLibrary::RInterpTo(GetOwner()->GetActorRotation(), LookRotation, FApp::GetDeltaTime(), 3);
	FVector FollowLocationInterp = UKismetMathLibrary::VInterpTo(GetOwner()->GetActorLocation(), FollowLocation, FApp::GetDeltaTime(), 3);

	if (bShouldFollow) GetOwner()->SetActorLocation(FollowLocationInterp);
	if (bShouldLookAt) GetOwner()->SetActorRotation(LookRotationInterp);
}

void ULevelCamera::SetTarget(AActor* NewTarget, FVector NewCameraOffset)
{
	Target = NewTarget;
	CameraOffset = NewCameraOffset;
}