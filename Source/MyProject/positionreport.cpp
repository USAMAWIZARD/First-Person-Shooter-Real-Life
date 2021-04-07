// Fill out your copyright notice in the Description page of Project Settings.


#include "positionreport.h"
#include "Gameframework/Actor.h"
// Sets default values for this component's properties
Upositionreport::Upositionreport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Upositionreport::BeginPlay()
{
	Super::BeginPlay();
	// ...
	FString objname= GetOwner()->GetName();
	FString position = GetOwner()->GetTransform().GetLocation().ToString() ;
	UE_LOG(LogTemp,Warning,TEXT("class name is %s at %s"),*objname,*position);
}


// Called every frame
void Upositionreport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

