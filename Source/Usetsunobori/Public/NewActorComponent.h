// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "omg_serv.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NewActorComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEMGUsed);

UCLASS(ClassGroup=(Custom), meta = (BlueprintSpawnableComponent))
class USETSUNOBORI_API UNewActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNewActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    UFUNCTION(BlueprintCallable, Category = "Set EMG ComPath")
    void SetComPath(UPARAM(DisplayName = "Path") FString path);

    UFUNCTION(BlueprintCallable, Category = "Reset EMG Level")
    void ResetEMG(
        UPARAM(DisplayName = "Port_n") int port,
        UPARAM(DisplayName = "is_high") bool is_high,
        UPARAM(DisplayName = "reset") bool reset
    );


    static void emg_dispatcher(omg_serial_recv_t recv);
    static void emg_error_dispatcher(OMGERRSTAT recv);

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEMGUsed LHSStartUsed;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEMGUsed LHSStopUsed;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEMGUsed RHSStartUsed;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEMGUsed RHSStopUsed;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEMGUsed MHSStartUsed;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEMGUsed MHSStopUsed;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEMGUsed EMGErrorUsed;

public:
    omg_serial_serv_t* emg_ctrl_;
    unsigned l_state = 0;
    unsigned r_state = 0;
};
