// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelCameraActor.h"

#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ALevelCameraActor::ALevelCameraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SetRootComponent(Camera);
}

// Called when the game starts or when spawned
void ALevelCameraActor::BeginPlay()
{
	Super::BeginPlay();

	Target = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void ALevelCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target) FocusAt(Target);
}

void ALevelCameraActor::FocusAt(AActor* Actor)
{
	FVector CurrentCameraLocation = GetActorLocation();
	FVector CurrentTargetLocation = Actor->GetActorLocation();
	FRotator LookRotation = UKismetMathLibrary::FindLookAtRotation(CurrentCameraLocation, CurrentTargetLocation);
	FVector FollowLocation = Actor->GetActorLocation() * FVector (1, 0, 1) + CameraOffset;
	
	FRotator LookRotationInterp = UKismetMathLibrary::RInterpTo(GetActorRotation(), LookRotation, FApp::GetDeltaTime(), 3);
	FVector FollowLocationInterp = UKismetMathLibrary::VInterpTo(GetActorLocation(), FollowLocation, FApp::GetDeltaTime(), 3);

	if (bShouldFollow) SetActorLocation(FollowLocationInterp);
	if (bShouldLookAt) SetActorRotation(LookRotationInterp);
}

void ALevelCameraActor::SetTarget(AActor* NewTarget, FVector NewCameraOffset)
{
	Target = NewTarget;
	CameraOffset = NewCameraOffset;
}