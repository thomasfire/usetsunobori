// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "omg_serv.h"

#include <atomic>

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
    ~UNewActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    UFUNCTION(BlueprintCallable, Category = "EMG Serv")
    void SetComPath(UPARAM(DisplayName = "Path") FString path);

    UFUNCTION(BlueprintCallable, Category = "EMG Serv")
    void ResetEMG(
        UPARAM(DisplayName = "Port_n") int port,
        UPARAM(DisplayName = "is_high") bool is_high,
        UPARAM(DisplayName = "reset") bool reset
    );

    UFUNCTION(BlueprintCallable, Category = "EMG Serv")
    void StartEMGServ();

    UFUNCTION(BlueprintCallable, Category = "EMG Serv")
    void StopEMGServ();


    UFUNCTION(BlueprintCallable, Category = "EMG Serv")
    static FString GetEMGState();

    static void emg_dispatcher(omg_serial_recv_t recv);
    static void emg_error_dispatcher(OMGERRSTAT recv);

    UPROPERTY(BlueprintAssignable, Category = "EMG Serv")
    FOnEMGUsed LHSStartUsed;

    UPROPERTY(BlueprintAssignable, Category = "EMG Serv")
    FOnEMGUsed LHSStopUsed;

    UPROPERTY(BlueprintAssignable, Category = "EMG Serv")
    FOnEMGUsed RHSStartUsed;

    UPROPERTY(BlueprintAssignable, Category = "EMG Serv")
    FOnEMGUsed RHSStopUsed;

    UPROPERTY(BlueprintAssignable, Category = "EMG Serv")
    FOnEMGUsed MHSStartUsed;

    UPROPERTY(BlueprintAssignable, Category = "EMG Serv")
    FOnEMGUsed MHSStopUsed;

    UPROPERTY(BlueprintAssignable, Category = "EMG Serv")
    FOnEMGUsed EMGErrorUsed;

public:
    omg_serial_serv_t* emg_ctrl_;
    unsigned l_state = 0;
    unsigned r_state = 0;
    std::atomic<uint16_t> dispatch_que = 0; // ъуъ ъука не падать нуъуъ
};
