// Fill out your copyright notice in the Description page of Project Settings.


#include "positionreport.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"

#include "Gameframework/Actor.h"
// Sets default values for this component's properties
FSocket* ListenSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

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

    FString TheIP = "172.0.0.1";
    FString Name = "whogivesa";
    const int32 ThePort = 4444;
    FIPv4Address Addr;
    FIPv4Address::Parse(TheIP, Addr);

    //Create Socket
    FIPv4Endpoint Endpoint(Addr, ThePort);

    //BUFFER SIZE
    int32 BufferSize = 2 * 1024 * 1024;

     ListenSocket = FUdpSocketBuilder(*Name)
        .AsNonBlocking()
        .AsReusable()
        .BoundToAddress(Addr)
        .BoundToPort(ThePort)
        .Build();
}


// Called every frame
void Upositionreport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    FString objname = GetOwner()->GetName();
    FString position = GetOwner()->GetTransform().GetLocation().ToString();
    UE_LOG(LogTemp, Warning, TEXT("class name is %s at %s"), *objname, *position);
	// ...
    uint8* Data = 0;
    int32 tempBytesCounter;


    if (ListenSocket->Recv(Data, sizeof(Data), tempBytesCounter))
    {
 

    }

}

