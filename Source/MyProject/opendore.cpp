// Fill out your copyright notice in the Description page of Project Settings.


#include "opendore.h"
#include "Gameframework/Actor.h"
// Sets default values for this component's properties
Uopendore::Uopendore()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Uopendore::BeginPlay()
{
	Super::BeginPlay();
	FRotator rotate = FRotator(0.0f,30.0f,0.0f);
	AActor* actor = GetOwner();
	actor->SetActorRotation(rotate);
	// ...
	
}


// Called every frame
void Uopendore::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...

	
}

