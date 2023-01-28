// Fill out your copyright notice in the Description page of Project Settings.


#include "positionreport.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "IPAddress.h"
#include<string.h>
#include <Math.h>
#include "Gameframework/Actor.h"

FSocket* ListenSocket;
FUdpSocketReceiver* UDPReceiver = nullptr;

Upositionreport::Upositionreport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
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

    FString TheIP = "192.168.0.105";
    FString Name = "whogivesa";
    int ThePort = 9005;
    FIPv4Address Addr; // = FIPv4Addre` ss(127,0,0,1);
    FIPv4Address::Parse(TheIP, Addr);

    //Create Socket
    FIPv4Endpoint EndPoint(Addr, ThePort);
     UE_LOG(LogTemp, Warning, TEXT("csefffffff %s "), *Addr.ToString());

    //BUFFER SIZE
    int32 BufferSize = 2 * 1024 * 1024;

    ListenSocket = FUdpSocketBuilder(*Name)
        .BoundToEndpoint(EndPoint)
        .Build();

    FTimespan ThreadWaitTime = FTimespan::FromMilliseconds(100);

    UDPReceiver = new FUdpSocketReceiver(ListenSocket, ThreadWaitTime, TEXT("Udp Receiver"));

    UDPReceiver->OnDataReceived().BindUObject(this, &Upositionreport::RecvData);

    UDPReceiver->Start();

}

void Upositionreport::RecvData(const FArrayReaderPtr& ArrayReadPrt, const FIPv4Endpoint& EndPt)
{
    //FString msg;
    GLog->Logf(TEXT("Receiver msg"));

    uint8 data[512];
    FMemory::Memzero(data, 512);
    FMemory::Memcpy(data, ArrayReadPrt->GetData(), ArrayReadPrt->Num());
    FString str = ((const char*)data);
    TArray<FString> Parsed;
    const TCHAR *divide = TEXT(",");
    str.ParseIntoArray(Parsed, divide,false);
    FString  trimed0 = Parsed[0].TrimStartAndEnd();
    if (!trimed0.Equals("s"))
    {
        UDPReceiver->Stop();
        return;
    }
    FString str_yaw = Parsed[1].TrimStartAndEnd();
    FString str_pitch = Parsed[2].TrimStartAndEnd();
    FString str_roll = Parsed[3].TrimStartAndEnd();

    yaw=FCString::Atoi(*str_yaw);
    pitch= FCString::Atoi(*str_pitch);
    roll= FCString::Atoi(*str_roll);


    //  UE_LOG(LogTemp, Warning, TEXT("%s"), *trimed);
    FRotator rotate = FRotator(pitch,yaw,roll);
    GetOwner()->SetActorRotation(rotate);
    
  
}



// Called every frame
void Upositionreport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}


