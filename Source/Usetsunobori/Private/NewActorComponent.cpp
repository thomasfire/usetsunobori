// Fill out your copyright notice in the Description page of Project Settings.


#include "NewActorComponent.h"

#include <string>
#include <functional>

static void* use_instance = NULL;

//omg_serv_new("com1");

void UNewActorComponent::SetComPath(UPARAM(DisplayName = "Path") FString path) {
    if (this->emg_ctrl_) omg_serv_free(this->emg_ctrl_);
    std::string msg(TCHAR_TO_UTF8(*path));
    emg_ctrl_ = omg_serv_new(msg.c_str());
    // omg_serv_set_input(emg_ctrl_, &(this->emg_dispatcher));
    omg_serv_set_input(emg_ctrl_, UNewActorComponent::emg_dispatcher);
    // omg_serv_set_error(emg_ctrl_, &(this->emg_error_dispatcher));
    omg_serv_set_error(emg_ctrl_, UNewActorComponent::emg_error_dispatcher);
}

void UNewActorComponent::ResetEMG(int port, bool is_high, bool reset) {
    if (!this->emg_ctrl_) return;
    if (is_high) {
        omg_serv_set_current_as_high(this->emg_ctrl_, reset, port);
    }
    else {
        omg_serv_set_current_as_low(this->emg_ctrl_, reset, port);
    }
}

void UNewActorComponent::emg_dispatcher(omg_serial_recv_t recv) {
    UNewActorComponent* instance = (UNewActorComponent*)use_instance;
    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Status bits: %hu"), recv.statuses_bits));

    instance->dispatch_que = recv.statuses_bits; // там чет падает если слишком долгий ивент, так как эта функция вызывается из другого потока
    return;
}

void UNewActorComponent::emg_error_dispatcher(OMGERRSTAT recv) {
    UNewActorComponent* instance = (UNewActorComponent*)use_instance;

    instance->EMGErrorUsed.Broadcast();
} 

FString UNewActorComponent::GetEMGState() {
    UNewActorComponent* instance = (UNewActorComponent*)use_instance;
    uint16_t lband, rband;
#ifdef OMGDEVELOPEMENT_LOG
    omg_serv_get_channels(instance->emg_ctrl_, &lband, &rband, NULL, NULL, NULL);
    return FString::Printf(TEXT("L: %hu; R: %hu"), lband, rband);
#else
    return FString::Printf(TEXT(""));
#endif
}


// Sets default values for this component's properties
UNewActorComponent::UNewActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    emg_ctrl_ = NULL;
    use_instance = this;
}


UNewActorComponent::~UNewActorComponent()
{
    if (this->emg_ctrl_) omg_serv_free(this->emg_ctrl_);
    emg_ctrl_ = NULL;
    use_instance = NULL;
}

// Called when the game starts
void UNewActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UNewActorComponent::StartEMGServ() {
    if (this->emg_ctrl_) omg_serv_start(this->emg_ctrl_);
}

void UNewActorComponent::StopEMGServ() {
    if (this->emg_ctrl_) omg_serv_send_stop(this->emg_ctrl_);
}

void UNewActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    if (this->emg_ctrl_) omg_serv_send_stop(this->emg_ctrl_);
}


// Called every frame
void UNewActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    uint16_t current_que = dispatch_que; // костыльно конечно, но мы тут и не запуск ракет проектируем
    dispatch_que = 0;

    if ((current_que & (OMG_PORT_0 | OMG_PORT_1)) == (OMG_PORT_0 & OMG_PORT_1)) { // pressed both
        if (this->l_state && this->r_state) return;

        if (this->l_state) this->LHSStopUsed.Broadcast();
        if (this->r_state) this->RHSStopUsed.Broadcast();
        this->l_state = 1;
        this->r_state = 1;
        this->MHSStartUsed.Broadcast();
    }
    else if ((current_que & (OMG_PORT_0 | OMG_PORT_1)) == OMG_PORT_0) { // left only
        if (this->l_state && this->r_state) {
            this->MHSStopUsed.Broadcast();
            this->l_state = 0;
            this->r_state = 0;
        }
        if (this->r_state) {
            this->RHSStopUsed.Broadcast();
            this->r_state = 0;
        }
        if (this->l_state) return;
        this->l_state = 1;
        this->LHSStartUsed.Broadcast();
    }
    else if ((current_que & (OMG_PORT_0 | OMG_PORT_1)) == OMG_PORT_1) { // right only
        if (this->l_state && this->r_state) {
            this->MHSStopUsed.Broadcast();
            this->l_state = 0;
            this->r_state = 0;
        }
        if (this->l_state) {
            this->LHSStopUsed.Broadcast();
            this->l_state = 0;
        }
        if (this->r_state) return;
        this->r_state = 1;
        this->RHSStartUsed.Broadcast();
    }
    else { // released all
        if (this->l_state && this->r_state) {
            this->l_state = 0;
            this->r_state = 0;
            this->MHSStopUsed.Broadcast();
        }
        if (this->l_state) {
            this->l_state = 0;
            this->LHSStopUsed.Broadcast();
        }
        if (this->r_state) {
            this->r_state = 0;
            this->RHSStopUsed.Broadcast();
        }
    }
}

