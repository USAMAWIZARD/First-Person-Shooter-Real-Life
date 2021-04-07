// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Gameframework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "opendore.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API Uopendore : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	Uopendore();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UProperty(VisibleAnywhere);
	float doorangle = 90.0f;
};
