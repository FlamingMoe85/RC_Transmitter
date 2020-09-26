#include "Ui_VisitorQt.h"
#ifdef QT_CREATOR
Ui_VisitorQt::Ui_VisitorQt()
{

}

void Ui_VisitorQt::SetUiArea(QStackedWidget* uiA)
{
    uiArea = uiA;
}


/*********************************************/
///////////////////////////////////////////////
/*********************************************/

void Ui_VisitorQt::SetCompNodeUiRef(Strct_Compo_Node_UI* nju)
{
     StrctCmp_UiRef = nju;
}

void Ui_VisitorQt::DispShowCall(Strct_Compo_Node* caller)
{
   uiArea->setCurrentWidget(StrctCmp_UiRef);
  StrctCmp_UiRef->SetStrctCmp_Ref(caller);
}


/*********************************************/
///////////////////////////////////////////////
/*********************************************/

void Ui_VisitorQt::SetCalcMult_UiRef(Calc_Multiplication_Leaf_UI* uiRef)
{
    calcMultUi = uiRef;
}
void Ui_VisitorQt::DispShowCall(Calc_Multiplication_Leaf* caller)
{
    uiArea->setCurrentWidget(calcMultUi);
    calcMultUi->SetRef(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetJunc_UiRef(Strct_Junc_Node_UI* uiRef)
{
    juncUiRef = uiRef;
}

void Ui_VisitorQt::DispShowCall(Strct_Junc_Node* caller)
{
    uiArea->setCurrentWidget(juncUiRef);
    juncUiRef->SetJuncRef(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetMultSw_UiRef(Strct_Multi_Sw_Node_UI* uiRef)
{
    multiSwUiRef = uiRef;
}

void Ui_VisitorQt::DispShowCall(Strct_MultSw_Node *caller)
{
    uiArea->setCurrentWidget(multiSwUiRef);
    multiSwUiRef->SetMultiSwref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetChnl_UiRef(Strct_Chnl_Node_UI* uiRef)
{
    channelUiRef = uiRef;
}

void Ui_VisitorQt::DispShowCall(Strct_Chnl_Node *caller)
{
    uiArea->setCurrentWidget(channelUiRef);
    channelUiRef->SetChnlRef(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetChnlMngr_UiRef(Strct_ChnlMngr_Node_UI* uiRef)
{
    chnlMngrUiRef = uiRef;
}

void Ui_VisitorQt::DispShowCall(Strct_ChnlMngr_Node *caller)
{
    uiArea->setCurrentWidget(chnlMngrUiRef);
    chnlMngrUiRef->SetChnlMngrRef(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetuCAdc_UiRef(Calc_uCAdc_Leaf_UI* uiRef)
{
    adcSelUiRef = uiRef;
}

void Ui_VisitorQt::DispShowCall(Calc_uCAdc_Leaf *caller)
{
    uiArea->setCurrentWidget(adcSelUiRef);
    adcSelUiRef->SetRef(caller);
}
/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetCstmSw_UiRef(Src_CstmSw_Leaf_Ui* uiRef)
{
    cstmSwUiRef = uiRef;
}

void Ui_VisitorQt::DispShowCall(Src_CstmSw_Leaf *caller)
{
    uiArea->setCurrentWidget(cstmSwUiRef);
    cstmSwUiRef->SetRef(caller);
}
/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetBlinker_UiRef(Time_Blinker_Leaf_UI* uiRef)
{
    blinkUiRef = uiRef;
}
void Ui_VisitorQt::DispShowCall(Time_Blinker_Leaf* caller)
{
    uiArea->setCurrentWidget(blinkUiRef);
    blinkUiRef->SetRef(caller);
}


/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetScaleSwitch_UiRef(Calc_ScaleSw_Leaf_Ui* uiRef)
{
    scaleSwUiRef = uiRef;
}

void Ui_VisitorQt::DispShowCall(Calc_ScaleSw_Leaf* caller)
{
    uiArea->setCurrentWidget(scaleSwUiRef);
    scaleSwUiRef->SetRef(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_VisitorQt::SetQuanti_UiRef(Calc_Quantizer_Leaf_UI* uiRef)
{
    quantUiRef = uiRef;
}
void Ui_VisitorQt::DispShowCall(Calc_Quantizer_Leaf* caller)
{
    uiArea->setCurrentWidget(quantUiRef);
    quantUiRef->SetRef(caller);
}
#endif
