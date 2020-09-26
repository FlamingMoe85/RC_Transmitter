#ifndef CALC_MULTIPLICATION_LEAF_H
#define CALC_MULTIPLICATION_LEAF_H

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Calc_Multiplication_Leaf : public Graph_Leaf<Graph_App_I>
{
public:
    Calc_Multiplication_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr();

    void SetMulVal(int16_t mulVal);
    int16_t GetMulVal();

private:

    int16_t myMulVal;
    float myMulVal_F;
    UI_Visitor_I *myUiVisitor;
};

#endif // CALC_MULTIPLICATION_LEAF_H
