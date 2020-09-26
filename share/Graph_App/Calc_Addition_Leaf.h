#ifndef CALC_ADDITION_LEAF_H
#define CALC_ADDITION_LEAF_H

#include "Graph_App_I.h"
#include "../std/Graph_Leaf.hpp"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Calc_Addition_Leaf : public Graph_Leaf<Graph_App_I>
{
public:
    Calc_Addition_Leaf();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr();

    void SetSgndAddVal(int16_t addVal);
    void AddSgndVal(int16_t addVal);
    int16_t GetSgndAddVal();

    void Show();
    UI_Visitor_I *myUiVisitor;

private:

    int16_t myAddVal;
    float myAddVal_F;
};

#endif // CALC_ADDITION_LEAF_H
