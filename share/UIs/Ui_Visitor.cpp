#include "Ui_Visitor.h"
#ifdef U_CONTRL
Ui_Visitor::Ui_Visitor()
{

}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::DispShowCall(Calc_Addition_Leaf *caller)
{
    Calc_Add_UiRef->SetCalcLeaf_Add_Ref(caller);
}
void Ui_Visitor::SetCalcAdd_UiRef(Calc_Addition_Leaf_UI *uiRef)
{
    Calc_Add_UiRef = uiRef;
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/

void Ui_Visitor::SetCalcMult_UiRef(Calc_Multiplication_Leaf_UI* uiRef)
{
    Calc_Mult_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Calc_Multiplication_Leaf* caller)
{
    Calc_Mult_UiRef->SetCalcLeaf_Mult_Ref(caller);
}
/*********************************************/
///////////////////////////////////////////////
/*********************************************/

void Ui_Visitor::SetCompNodeUiRef(Strct_Compo_Node_UI* nju)
{
    StrctCmp_UiRef = nju;
}

void Ui_Visitor::DispShowCall(Strct_Compo_Node* caller)
{
    StrctCmp_UiRef->SetStrctCmp_Ref(caller);
}


/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetChnl_UiRef(Strct_Chnl_Node_UI* uiRef)
{
    Chnl_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Strct_Chnl_Node *caller)
{
    Chnl_UiRef->SetStrctChnl_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetChnl_UiRef(Strct_ChnlMngr_Node_UI* uiRef)
{
    StrctChnlMngr_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Strct_ChnlMngr_Node *caller)
{
    StrctChnlMngr_UiRef->SetStrctChnlMngr_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetMultSw_UiRef(StrctMultiSwNodeUI* uiRef)
{
	StrctMultSw_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Strct_MultSw_Node *caller)
{
	StrctMultSw_UiRef->SetMultSw_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetCalcFac_UiRef(Strct_CalcFactory_UI* uiRef)
{
	StrctCalcFac_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Strct_CalcFactory *caller)
{
	StrctCalcFac_UiRef->SetCalcFactory_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetPoolOwn_UiRef(Strct_PoolOwner_UI* uiRef)
{
	StrctPoolOwner_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Strct_PoolOwner_Node *caller)
{
	StrctPoolOwner_UiRef->SetPoolOwner_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetuCAdc_UiRef(Calc_uCAdc_Leaf_UI* uiRef)
{
	CalcuCAdc_UiRef = uiRef;
}
void Ui_Visitor::DispShowCall(Calc_uCAdc_Leaf *caller)
{
	CalcuCAdc_UiRef->SetuCAdc_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetCstmSw_UiRef(Src_CstmSw_Leaf_Ui* uiRef)
{
	SrcCstmSw_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Src_CstmSw_Leaf *caller)
{
	SrcCstmSw_UiRef->SetCstmSw_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetTopMen_UiRef(Strct_TopMenue_Node_UI* uiRef)
{
	StrctTopMen_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Strct_TopMenue_Node *caller)
{
	StrctTopMen_UiRef->SetTopMenue_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetSaveLoad_UiRef(Strct_SaveLoad_Node_UI* uiRef)
{
	StrctSaveLoad_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Strct_SaveLoad_Node *caller)
{
	StrctSaveLoad_UiRef->SetSaveLoad_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetInternTrim_UiRef(Src_InternTrim_Leaf_UI* uiRef)
{
	SrcInternTrim_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Src_InternTrim_Leaf* caller)
{
	SrcInternTrim_UiRef->SetInternTrim_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetJunc_UiRef(Strct_Junc_Node_UI* uiRef)
{
	StrctJunc_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Strct_Junc_Node* caller)
{
	StrctJunc_UiRef->SetJunc_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetRamp_UiRef(TimeCalc_Ramp_Leaf_UI* uiRef)
{
	TimeCalcRamp_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(TimeCalc_Ramp_Leaf* caller)
{
	TimeCalcRamp_UiRef->SetTimeCalc_Ramp_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetBlinker_UiRef(Time_Blinker_Leaf_UI* uiRef)
{
	TimeBlinker_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Time_Blinker_Leaf* caller)
{
	TimeBlinker_UiRef->SetTime_Blinker_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetScaleSwitch_UiRef(Calc_ScaleSw_Leaf_Ui* uiRef)
{
	ScaleSwitch_Uiref = uiRef;
}

void Ui_Visitor::DispShowCall(Calc_ScaleSw_Leaf *caller)
{
	ScaleSwitch_Uiref->SetScaleSw_Ref(caller);
}

/*********************************************/
///////////////////////////////////////////////
/*********************************************/
void Ui_Visitor::SetQuanti_UiRef(Calc_Quantizer_Leaf_UI* uiRef)
{
	Quanti_UiRef = uiRef;
}

void Ui_Visitor::DispShowCall(Calc_Quantizer_Leaf* caller)
{
	Quanti_UiRef->SetQuantizer_Ref(caller);
}
#endif
