// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReporter.h"

// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();
	

	AActor* ParentActor = GetOwner();
	FString ParentName = ParentActor->GetName();

	FTransform ParentTransform = ParentActor->GetTransform();
	FVector ParentTransformPosition = ParentTransform.GetLocation();
	UE_LOG(LogTemp, Log, TEXT("PARENT NAME IS: %f %f %f"), ParentTransformPosition.X, ParentTransformPosition.Y, ParentTransformPosition.Z);

}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

