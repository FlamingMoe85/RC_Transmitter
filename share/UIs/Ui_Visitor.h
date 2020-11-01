#ifndef UI_VISITOR_H
#define UI_VISITOR_H


#include "Ui_Visitor_I.hpp"

#ifdef U_CONTRL
#include "../../uController/grlib_demo/UIs/CalcAdditionLeafUI.h"
#include "../../uController/grlib_demo/UIs/CalcMultiplicationLeafUI.h"
#include "../../uController/grlib_demo/UIs/Calc_uCAdc_Leaf_UI.h"
#include "../../uController/grlib_demo/UIs/StrctCompoNodeUI.h"
#include "../../uController/grlib_demo/UIs/StrctChnlNodeUI.h"
#include "../../uController/grlib_demo/UIs/StrctChnlMngrNodeUI.h"
#include "../../uController/grlib_demo/UIs/StrctMultiSwNodeUI.h"
#include "../../uController/grlib_demo/UIs/Strct_CalcFactory_UI.h"
#include "../../uController/grlib_demo/UIs/Strct_PoolOwner_UI.h"
#include "../../uController/grlib_demo/UIs/Calc_uCAdc_Leaf_UI.h"
#include "../../uController/grlib_demo/UIs/Src_CstmSw_Leaf_Ui.h"
#include "../../uController/grlib_demo/UIs/Strct_TopMenue_Node_UI.h"
#include "../../uController/grlib_demo/UIs/Strct_SaveLoad_Node_UI.h"
#include "../../uController/grlib_demo/UIs/Src_InternTrim_Leaf_UI.h"
#include "../../uController/grlib_demo/UIs/Strct_Junc_Node_UI.h"
#include "../../uController/grlib_demo/UIs/TimeCalc_Ramp_Leaf_UI.h"
#include "../../uController/grlib_demo/UIs/Time_Blinker_Leaf_UI.h"
#include "../../uController/grlib_demo/UIs/Calc_ScaleSw_Leaf_Ui.h"
#include "../../uController/grlib_demo/UIs/Calc_Quantizer_Leaf_UI.h"
#include "../../uController/grlib_demo/UIs/Calc_DeadArea_Leaf_Ui.h"
#include "../../uController/grlib_demo/UIs/Calc_MinMaxLimit_Leaf_Ui.h"



class Ui_Visitor : public UI_Visitor_I
{

public:
     Ui_Visitor();
    //~Ui_Visitor();

     void SetDeadSpanUiRef(Calc_DeadArea_Leaf_Ui* nju);
     void DispShowCall(Clac_DeadArea_Leaf* caller);

    void SetCompNodeUiRef(Strct_Compo_Node_UI* nju);
    void DispShowCall(Strct_Compo_Node* caller);

    void SetCalcAdd_UiRef(Calc_Addition_Leaf_UI* uiRef);
    void DispShowCall(Calc_Addition_Leaf* caller);

    void SetCalcMult_UiRef(Calc_Multiplication_Leaf_UI* uiRef);
    void DispShowCall(Calc_Multiplication_Leaf* caller);

    void SetChnl_UiRef(Strct_Chnl_Node_UI* uiRef);
    void DispShowCall(Strct_Chnl_Node *caller);

    void SetChnl_UiRef(Strct_ChnlMngr_Node_UI* uiRef);
    void DispShowCall(Strct_ChnlMngr_Node *caller);

    void SetMultSw_UiRef(StrctMultiSwNodeUI* uiRef);
    void DispShowCall(Strct_MultSw_Node *caller);

    void SetCalcFac_UiRef(Strct_CalcFactory_UI* uiRef);
    void DispShowCall(Strct_CalcFactory *caller);

    void SetPoolOwn_UiRef(Strct_PoolOwner_UI* uiRef);
	void DispShowCall(Strct_PoolOwner_Node *caller);

	void SetuCAdc_UiRef(Calc_uCAdc_Leaf_UI* uiRef);
	void DispShowCall(Calc_uCAdc_Leaf *caller);

	void SetCstmSw_UiRef(Src_CstmSw_Leaf_Ui* uiRef);
	void DispShowCall(Src_CstmSw_Leaf *caller);

	void SetTopMen_UiRef(Strct_TopMenue_Node_UI* uiRef);
	void DispShowCall(Strct_TopMenue_Node *caller);

	void SetSaveLoad_UiRef(Strct_SaveLoad_Node_UI* uiRef);
	void DispShowCall(Strct_SaveLoad_Node *caller);

	void SetInternTrim_UiRef(Src_InternTrim_Leaf_UI* uiRef);
	void DispShowCall(Src_InternTrim_Leaf* caller);

	void SetJunc_UiRef(Strct_Junc_Node_UI* uiRef);
	void DispShowCall(Strct_Junc_Node* caller);

	void SetRamp_UiRef(TimeCalc_Ramp_Leaf_UI* uiRef);
	void DispShowCall(TimeCalc_Ramp_Leaf* caller);

	void SetBlinker_UiRef(Time_Blinker_Leaf_UI* uiRef);
	void DispShowCall(Time_Blinker_Leaf* caller);

	void SetScaleSwitch_UiRef(Calc_ScaleSw_Leaf_Ui* uiRef);
	void DispShowCall(Calc_ScaleSw_Leaf* caller);

	void SetQuanti_UiRef(Calc_Quantizer_Leaf_UI* uiRef);
	virtual void DispShowCall(Calc_Quantizer_Leaf* caller);

	void SetLimiter_UiRef(Calc_MinMaxLimit_Leaf_Ui* uiRef);
	virtual void DispShowCall(Calc_MinMaxLimit_Leaf* caller);


private:


    Calc_Addition_Leaf_UI* Calc_Add_UiRef;
    Calc_Multiplication_Leaf_UI* Calc_Mult_UiRef;
    Strct_Chnl_Node_UI* Chnl_UiRef;
    Strct_Compo_Node_UI* StrctCmp_UiRef;
    Strct_ChnlMngr_Node_UI* StrctChnlMngr_UiRef;
    StrctMultiSwNodeUI* StrctMultSw_UiRef;
    Strct_CalcFactory_UI* StrctCalcFac_UiRef;
    Strct_PoolOwner_UI* StrctPoolOwner_UiRef;
    Calc_uCAdc_Leaf_UI* CalcuCAdc_UiRef;
    Src_CstmSw_Leaf_Ui* SrcCstmSw_UiRef;
    Strct_TopMenue_Node_UI* StrctTopMen_UiRef;
    Strct_SaveLoad_Node_UI* StrctSaveLoad_UiRef;
    Src_InternTrim_Leaf_UI* SrcInternTrim_UiRef;
    Strct_Junc_Node_UI* StrctJunc_UiRef;
    TimeCalc_Ramp_Leaf_UI* TimeCalcRamp_UiRef;
    Time_Blinker_Leaf_UI* TimeBlinker_UiRef;
    Calc_ScaleSw_Leaf_Ui* ScaleSwitch_Uiref;
    Calc_Quantizer_Leaf_UI* Quanti_UiRef;
    Calc_DeadArea_Leaf_Ui* DeadSpan_UiRef;
    Calc_MinMaxLimit_Leaf_Ui* MinMaxLimit_UiRef;
};
#endif

#endif // UI_VISITOR_H
