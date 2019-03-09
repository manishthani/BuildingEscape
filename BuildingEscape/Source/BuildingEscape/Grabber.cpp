// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get Player View Point
	UWorld* World = GetWorld();
	if (!World)
		return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotator;
	
	PlayerController->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, 
		OUT PlayerViewPointRotator
	);

	//UE_LOG(LogTemp, Log, TEXT("View Point LOCATION: %s and ROTATION: %s"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotator.ToString());

	// Draw a Debug line of player front
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotator.Vector() * REACH;
	DrawDebugLine(
		World,
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor::Red,
		false,
		0.0f,
		0,
		10.0f
	);
}

