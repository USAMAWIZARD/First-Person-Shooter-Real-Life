// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IPAddress.h"
#include "Runtime/Networking/Public/Networking.h"
#include "positionreport.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API Upositionreport : public UActorComponent
{ 
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Upositionreport();
	

protected:
	// Called when the game starts
//	void Recv(const FArrayReaderPtr& ArrayReaderPtr, const FIPv4Endpoint& EndPt);
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void RecvData(const FArrayReaderPtr& ArrayReadPrt, const FIPv4Endpoint& EndPt);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
