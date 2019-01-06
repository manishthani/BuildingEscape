// Fill out your copyright notice in the Description page of Project Settings.
#include "OpenDoor.h"
#include "Engine/World.h"
#include "Engine/Classes/GameFramework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UOpenDoor::OpenDoor() {
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenDoor::CloseDoor() {
	Owner->SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	Owner->GetActorLocation();
}


// Called when the game starts
void UOpenDoor::BeginPlay() {
	Super::BeginPlay();
	SetActorThatMoves();
	Owner = GetOwner();
}

void UOpenDoor::SetActorThatMoves() {
	UWorld* World = GetWorld();
	if (!World)
		return;
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	ActorThatMoves = PlayerController->GetPawn();
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate->IsOverlappingActor(ActorThatMoves)) {
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime> DoorCloseDelay) {
		CloseDoor();
	}
}

