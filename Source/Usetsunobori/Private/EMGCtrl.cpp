
#include "EMGCtrl.h"

#include <string>
#include <functional>
/*
AEMGCtrl::AEMGCtrl(const class FObjectInitializer& PCIP)
    :Super(PCIP)
{
    FScriptDelegate Del;
    Del.BindUFunction(this, "NotifyPickedUpObject");
    LHSStartEvt.Add(Del);
}*/

static void* use_instance = NULL;

AEMGCtrl::AEMGCtrl() :Super() {
    emg_ctrl_ = NULL;
    use_instance = this;
}
//omg_serv_new("com1");

void AEMGCtrl::SetComPath(UPARAM(DisplayName = "Path") FString path) {
    if (this->emg_ctrl_) omg_serv_free(this->emg_ctrl_);
    std::string msg(TCHAR_TO_UTF8(*path));
    emg_ctrl_ = omg_serv_new(msg.c_str());
   // omg_serv_set_input(emg_ctrl_, &(this->emg_dispatcher));
    omg_serv_set_input(emg_ctrl_, AEMGCtrl::emg_dispatcher);
   // omg_serv_set_error(emg_ctrl_, &(this->emg_error_dispatcher));
    omg_serv_set_error(emg_ctrl_, AEMGCtrl::emg_error_dispatcher);
}

void AEMGCtrl::BeginPlay() {
    if (this->emg_ctrl_) omg_serv_start(this->emg_ctrl_);
}


void AEMGCtrl::ResetEMG(int port, bool is_high, bool reset) {
    if (!this->emg_ctrl_) return;
    if (is_high) {
        omg_serv_set_current_as_high(this->emg_ctrl_, reset, port);
    } else {
        omg_serv_set_current_as_low(this->emg_ctrl_, reset, port);
    }
}

void AEMGCtrl::emg_dispatcher(omg_serial_recv_t recv) {
    AEMGCtrl* instance = (AEMGCtrl*)use_instance;

    if ((recv.statuses_bits & (OMG_PORT_0 & OMG_PORT_1)) == (OMG_PORT_0 & OMG_PORT_1)) { // pressed both
        if (instance->l_state && instance->r_state) return;
        
        if (instance->l_state) instance->LHSStopEvt();
        if (instance->r_state) instance->RHSStopEvt();
        instance->l_state = 1;
        instance->r_state = 1;
        instance->MHSStartEvt();
    } else if ((recv.statuses_bits & (OMG_PORT_0 & OMG_PORT_1)) == OMG_PORT_0) { // left only
        if (instance->l_state && instance->r_state) {
            instance->MHSStopEvt(); 
            instance->l_state = 0;
            instance->r_state = 0;
        }
        if (instance->r_state) {
            instance->RHSStopEvt(); 
            instance->r_state = 0;
        }
        if (instance->l_state) return;
        instance->l_state = 1;
        instance->LHSStartEvt();
    } else if ((recv.statuses_bits & (OMG_PORT_0 & OMG_PORT_1)) == OMG_PORT_1) { // right only
        if (instance->l_state && instance->r_state) {
            instance->MHSStopEvt();
            instance->l_state = 0;
            instance->r_state = 0;
        }
        if (instance->l_state) {
            instance->LHSStopEvt();
            instance->l_state = 0;
        }
        if (instance->r_state) return;
        instance->r_state = 1;
        instance->RHSStartEvt();
    } else { // released all
        if (instance->l_state && instance->r_state) {
            instance->l_state = 0;
            instance->r_state = 0;
            instance->MHSStopEvt();
        }
        if (instance->l_state) {
            instance->l_state = 0;
            instance->LHSStopEvt();
        }
        if (instance->r_state) {
            instance->r_state = 0;
            instance->RHSStopEvt();
        }
    }

}

void AEMGCtrl::emg_error_dispatcher(OMGERRSTAT recv) {
    AEMGCtrl* instance = (AEMGCtrl*)use_instance;

    instance->EMGErrorEvt(recv);
}