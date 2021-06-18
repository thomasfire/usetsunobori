#pragma once

#include "omg_serv.h"

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
    AEMGCtrl();
    //AEMGCtrl(const class FObjectInitializer& PCIP);

    virtual void BeginPlay() final;

    UFUNCTION(BlueprintCallable, Category = "SetComPath")
    void SetComPath(UPARAM(DisplayName = "Path") FString path);

    UFUNCTION(BlueprintCallable, Category = "Reset")
    void ResetEMG(
        UPARAM(DisplayName = "Port_n") int port,
        UPARAM(DisplayName = "is_high") bool is_high, 
        UPARAM(DisplayName = "reset") bool reset
    );

    //virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintImplementableEvent, Category = "Interaction", meta = (DisplayName = "Left hand EMG is high"))
    void LHSStartEvt();
    UFUNCTION(BlueprintImplementableEvent, Category = "Interaction", meta = (DisplayName = "Left hand EMG is low"))
    void LHSStopEvt();
    UFUNCTION(BlueprintImplementableEvent, Category = "Interaction", meta = (DisplayName = "Right hand EMG is high"))
    void RHSStartEvt();
    UFUNCTION(BlueprintImplementableEvent, Category = "Interaction", meta = (DisplayName = "Right hand EMG is low"))
    void RHSStopEvt();

    UFUNCTION(BlueprintImplementableEvent, Category = "Interaction", meta = (DisplayName = "Both hands EMG are high"))
    void MHSStartEvt();
    UFUNCTION(BlueprintImplementableEvent, Category = "Interaction", meta = (DisplayName = "Both hands EMG are low"))
    void MHSStopEvt();

    UFUNCTION(BlueprintImplementableEvent, Category = "Interaction", meta = (DisplayName = "Error received from EMG"))
    void EMGErrorEvt(UPARAM(DisplayName = "Port_n") int errcode);

    static void emg_dispatcher(omg_serial_recv_t recv);
    static void emg_error_dispatcher(OMGERRSTAT recv);

public:
    omg_serial_serv_t *emg_ctrl_;
    unsigned l_state = 0;
    unsigned r_state = 0;
};
