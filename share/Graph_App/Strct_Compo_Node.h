#ifndef STRCT_COMPO_NODE_H
#define STRCT_COMPO_NODE_H

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "Calc_Addition_Leaf.h"
#include "Calc_Multiplication_Leaf.h"
#include "Calc_uCAdc_Leaf.h"
#include "Src_CstmSw_Leaf.h"
#include "Src_InternTrim_Leaf.h"
#include "TimeCalc_Ramp_Leaf.h"
#include "Time_Blinker_Leaf.h"
#include "Calc_ScaleSw_Leaf.h"
#include "Calc_Quantizer_Leaf.h"
#include "Clac_DeadArea_Leaf.hpp"
#include "Calc_MinMaxLimit_Leaf.h"
#include "PoolOwnerUtils.h"

class Strct_Compo_Node : public Graph_Node<Graph_App_I>, public PoolOwnerUtils
{
public:
    Strct_Compo_Node();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Show();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr();

    void ClearSerFlag();
    void AddCompAtEnd();

private:
    uint16_t serFlag, serPos;
    UI_Visitor_I *myUiVisitor;
};

#endif // STRCT_COMPO_NODE_H
