#ifndef UI_VISITORQT_H
#define UI_VISITORQT_H

#ifdef QT_CREATOR
#include "Ui_Visitor_I.hpp"

#include <QWidget>
#include <QLayout>
#include <QStackedWidget>

#include "../../PC_App/RC_Transmitter_PcApp/UIs/Strct_Compo_Node_UI.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Calc_Multiplication_Leaf_UI.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Strct_Junc_Node_UI.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Strct_Multi_Sw_Node_UI.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Strct_Chnl_Node_UI.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Strct_ChnlMngr_Node_UI.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Calc_uCAdc_Leaf_UI.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Src_CstmSw_Leaf_Ui.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Time_Blinker_Leaf_UI.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Calc_ScaleSw_Leaf_Ui.h"
#include "../../PC_App/RC_Transmitter_PcApp/UIs/Calc_Quantizer_Leaf_UI.h"

class Ui_VisitorQt : public UI_Visitor_I
{
public:
    Ui_VisitorQt();

    void SetUiArea(QStackedWidget* uiA);

    void SetCompNodeUiRef(Strct_Compo_Node_UI* nju);
    void DispShowCall(Strct_Compo_Node* caller);

    void SetCalcMult_UiRef(Calc_Multiplication_Leaf_UI* uiRef);
    void DispShowCall(Calc_Multiplication_Leaf* caller);


    void SetJunc_UiRef(Strct_Junc_Node_UI* uiRef);
    void DispShowCall(Strct_Junc_Node* caller);

    void SetMultSw_UiRef(Strct_Multi_Sw_Node_UI* uiRef);
    void DispShowCall(Strct_MultSw_Node *caller);

    void SetChnl_UiRef(Strct_Chnl_Node_UI* uiRef);
    void DispShowCall(Strct_Chnl_Node *caller);


   void SetChnlMngr_UiRef(Strct_ChnlMngr_Node_UI* uiRef);
    void DispShowCall(Strct_ChnlMngr_Node *caller);

    void SetuCAdc_UiRef(Calc_uCAdc_Leaf_UI* uiRef);
      void DispShowCall(Calc_uCAdc_Leaf *caller);

    void SetCstmSw_UiRef(Src_CstmSw_Leaf_Ui* uiRef);
    void DispShowCall(Src_CstmSw_Leaf *caller);

      void SetBlinker_UiRef(Time_Blinker_Leaf_UI* uiRef);
      void DispShowCall(Time_Blinker_Leaf* caller);

    void SetScaleSwitch_UiRef(Calc_ScaleSw_Leaf_Ui* uiRef);
    void DispShowCall(Calc_ScaleSw_Leaf* caller);

    void SetQuanti_UiRef(Calc_Quantizer_Leaf_UI* uiRef);
    virtual void DispShowCall(Calc_Quantizer_Leaf* caller);



  // void SetCalcAdd_UiRef(Calc_Addition_Leaf_UI* uiRef){ }
   void DispShowCall(Calc_Addition_Leaf* caller){(void)caller; }




//   void SetCalcFac_UiRef(Strct_CalcFactory_UI* uiRef){ }
   void DispShowCall(Strct_CalcFactory *caller){(void)caller; }

//   void SetPoolOwn_UiRef(Strct_PoolOwner_UI* uiRef){ }
   void DispShowCall(Strct_PoolOwner_Node *caller){(void)caller; }








 //  void SetTopMen_UiRef(Strct_TopMenue_Node_UI* uiRef){ }
   void DispShowCall(Strct_TopMenue_Node *caller){(void)caller; }

 //  void SetSaveLoad_UiRef(Strct_SaveLoad_Node_UI* uiRef){ }
   void DispShowCall(Strct_SaveLoad_Node *caller){(void)caller; }

//   void SetInternTrim_UiRef(Src_InternTrim_Leaf_UI* uiRef){ }
   void DispShowCall(Src_InternTrim_Leaf* caller){(void)caller; }

 //  void SetRamp_UiRef(TimeCalc_Ramp_Leaf_UI* uiRef){ }
   void DispShowCall(TimeCalc_Ramp_Leaf* caller){(void)caller; }


   void DispShowCall(Clac_DeadArea_Leaf* caller){(void)caller; }
   void DispShowCall(Calc_MinMaxLimit_Leaf* caller){(void)caller; }
   void DispShowCall(Calc_Expo1_Leaf* caller){(void)caller; }
   void DispShowCall(Calc_DynamicScale_Leaf* caller){(void)caller; }
   void DispShowCall(Time_Integrator_Leaf* caller){(void)caller; }
   void DispShowCall(Wizard_TwoChnlModl_Leaf* caller){(void)caller; }
   void DispShowCall(Wizard_InternTrim* caller){(void)caller; }
   void DispShowCall(Z_MusicControl* caller){(void)caller; }
   void DispShowCall(Z_Wizard_Node* caller){(void)caller; }
   void DispShowCall(Z_SystemConfig_Leaf* caller){(void)caller; }


   /*
   virtual void DispShowCall(Calc_Addition_Leaf* caller)=0;
   virtual void DispShowCall(Calc_Multiplication_Leaf* caller)=0;
   virtual void DispShowCall(Strct_Compo_Node* caller)=0;
   virtual void DispShowCall(Strct_Chnl_Node* caller)=0;
   virtual void DispShowCall(Strct_ChnlMngr_Node* caller)=0;
   virtual void DispShowCall(Strct_MultSw_Node* caller)=0;
   virtual void DispShowCall(Strct_CalcFactory* caller)=0;
   virtual void DispShowCall(Strct_PoolOwner_Node* caller)=0;
   virtual void DispShowCall(Calc_uCAdc_Leaf* caller)=0;
   virtual void DispShowCall(Src_CstmSw_Leaf* caller)=0;
   virtual void DispShowCall(Strct_TopMenue_Node* caller)=0;
   virtual void DispShowCall(Strct_SaveLoad_Node* caller)=0;
   virtual void DispShowCall(Src_InternTrim_Leaf* caller)=0;
   virtual void DispShowCall(Strct_Junc_Node* caller)=0;
   virtual void DispShowCall(TimeCalc_Ramp_Leaf* caller)=0;
   virtual void DispShowCall(Time_Blinker_Leaf* caller)=0;
   virtual void DispShowCall(Calc_ScaleSw_Leaf* caller)=0;
   virtual void DispShowCall(Calc_Quantizer_Leaf* caller)=0;
   virtual void DispShowCall(Clac_DeadArea_Leaf* caller)=0;
   virtual void DispShowCall(Calc_MinMaxLimit_Leaf* caller)=0;
   virtual void DispShowCall(Z_SystemConfig_Leaf* caller)=0;
   virtual void DispShowCall(Calc_Expo1_Leaf* caller)=0;
   virtual void DispShowCall(Calc_DynamicScale_Leaf* caller)=0;
   virtual void DispShowCall(Time_Integrator_Leaf* caller)=0;
   virtual void DispShowCall(Z_Wizard_Node* caller)=0;

   */


private:
    QStackedWidget* uiArea;

    Strct_Compo_Node_UI* StrctCmp_UiRef;
    Calc_Multiplication_Leaf_UI* calcMultUi;
    Strct_Junc_Node_UI* juncUiRef;
    Strct_Multi_Sw_Node_UI* multiSwUiRef;
    Strct_Chnl_Node_UI* channelUiRef;
    Strct_ChnlMngr_Node_UI* chnlMngrUiRef;
    Calc_uCAdc_Leaf_UI* adcSelUiRef;
    Src_CstmSw_Leaf_Ui* cstmSwUiRef;
    Time_Blinker_Leaf_UI* blinkUiRef;
    Calc_ScaleSw_Leaf_Ui* scaleSwUiRef;
    Calc_Quantizer_Leaf_UI* quantUiRef;
};
#endif
#endif // UI_VISITORQT_H
