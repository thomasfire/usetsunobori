// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EMGCtrl.generated.h"


/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class USETSUNOBORI_API AEMGCtrl : public APlayerController
{
    GENERATED_BODY()

public:
    //AEMGCtrl();

   /* virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;*/

   /* virtual void NotifyLHSStartObject(FName ObjectName);
    virtual void NotifyLHSStopObject(FName ObjectName);


    virtual void NotifyRHSStartObject(FName ObjectName);
    virtual void NotifyRHSStopObject(FName ObjectName);


    virtual void NotifyMHSStartObject(FName ObjectName);
    virtual void NotifyMHSStopObject(FName ObjectName);*/
    /*
    UFUNCTION(BlueprintImplementableEvent, Category = "Interaction", meta = (DisplayName = "On Used ~ Player wants to use this object"))
    void OnMyStuffUsed();

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMyStuffUsed);
    UPROPERTY(BlueprintAssignable, Category = "Interaction")
    FOnMyStuffUsed OnMyStuffUsed;*/
	
};
