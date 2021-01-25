#ifndef UI_VISITOR_I_HPP
#define UI_VISITOR_I_HPP

class Calc_Addition_Leaf;
class Calc_Multiplication_Leaf;
class Strct_Compo_Node;
class Strct_Chnl_Node;
class Strct_ChnlMngr_Node;
class Strct_MultSw_Node;
class Strct_CalcFactory;
class Strct_PoolOwner_Node;
class Calc_uCAdc_Leaf;
class Src_CstmSw_Leaf;
class Strct_TopMenue_Node;
class Strct_SaveLoad_Node;
class Src_InternTrim_Leaf;
class Strct_Junc_Node;
class TimeCalc_Ramp_Leaf;
class Time_Blinker_Leaf;
class Calc_ScaleSw_Leaf;
class Calc_Quantizer_Leaf;
class Clac_DeadArea_Leaf;
class Calc_MinMaxLimit_Leaf;
class Z_SystemConfig_Leaf;
class Calc_Expo1_Leaf;
class Calc_DynamicScale_Leaf;
class Time_Integrator_Leaf;
class Wizard_InternTrim;

class Z_Wizard_Node;

class UI_Visitor_I
{
public:

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
    virtual void DispShowCall(Wizard_InternTrim* caller)=0;


};

#endif // UI_VISITOR_I_HPP
