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

    if ((recv.statuses_bits & (OMG_PORT_0 & OMG_PORT_1)) == (OMG_PORT_0 & OMG_PORT_1)) { // pressed both
        if (instance->l_state && instance->r_state) return;

        if (instance->l_state) instance->LHSStopUsed.Broadcast();
        if (instance->r_state) instance->RHSStopUsed.Broadcast();
        instance->l_state = 1;
        instance->r_state = 1;
        instance->MHSStartUsed.Broadcast();
    }
    else if ((recv.statuses_bits & (OMG_PORT_0 & OMG_PORT_1)) == OMG_PORT_0) { // left only
        if (instance->l_state && instance->r_state) {
            instance->MHSStopUsed.Broadcast();
            instance->l_state = 0;
            instance->r_state = 0;
        }
        if (instance->r_state) {
            instance->RHSStopUsed.Broadcast();
            instance->r_state = 0;
        }
        if (instance->l_state) return;
        instance->l_state = 1;
        instance->LHSStartUsed.Broadcast();
    }
    else if ((recv.statuses_bits & (OMG_PORT_0 & OMG_PORT_1)) == OMG_PORT_1) { // right only
        if (instance->l_state && instance->r_state) {
            instance->MHSStopUsed.Broadcast();
            instance->l_state = 0;
            instance->r_state = 0;
        }
        if (instance->l_state) {
            instance->LHSStopUsed.Broadcast();
            instance->l_state = 0;
        }
        if (instance->r_state) return;
        instance->r_state = 1;
        instance->RHSStartUsed.Broadcast();
    }
    else { // released all
        if (instance->l_state && instance->r_state) {
            instance->l_state = 0;
            instance->r_state = 0;
            instance->MHSStopUsed.Broadcast();
        }
        if (instance->l_state) {
            instance->l_state = 0;
            instance->LHSStopUsed.Broadcast();
        }
        if (instance->r_state) {
            instance->r_state = 0;
            instance->RHSStopUsed.Broadcast();
        }
    }

}

void UNewActorComponent::emg_error_dispatcher(OMGERRSTAT recv) {
    UNewActorComponent* instance = (UNewActorComponent*)use_instance;

    instance->EMGErrorUsed.Broadcast();
}


// Sets default values for this component's properties
UNewActorComponent::UNewActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    emg_ctrl_ = NULL;
    use_instance = this;

	// ...
}


// Called when the game starts
void UNewActorComponent::BeginPlay()
{
	Super::BeginPlay();
    if (this->emg_ctrl_) omg_serv_start(this->emg_ctrl_);
	// ...
	
}


// Called every frame
void UNewActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

