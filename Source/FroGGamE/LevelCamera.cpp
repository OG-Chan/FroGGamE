// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelCamera.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
ULevelCamera::ULevelCamera()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULevelCamera::BeginPlay()
{
	Super::BeginPlay();

	Target = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void ULevelCamera::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FocusAt();
}

void ULevelCamera::FocusAt()
{
	TargetLocation = Target->GetActorLocation();
	FVector NewCameraLocation = FVector(TargetLocation.X + CameraOffset.X, CameraOffset.Y, CameraOffset.Z);
	GetOwner()->SetActorLocation(NewCameraLocation);
	GetOwner()->SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), TargetLocation));
}

void ULevelCamera::TargetSetter(AActor* NewTarget, FVector NewCameraOffset)
{
	Target = NewTarget;
	CameraOffset = NewCameraOffset;
}