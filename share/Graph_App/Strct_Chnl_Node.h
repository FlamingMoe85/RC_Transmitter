#ifndef STRCT_CHNL_NODE_H
#define STRCT_CHNL_NODE_H

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
//#include "Strct_PoolOwners.h"

class Strct_Chnl_Node : public Graph_Node<Graph_App_I>//, public Strct_PoolOwners
{
public:
    Strct_Chnl_Node();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Show();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr();

    void AddSltAtEnd();

private:

    uint16_t multSwCnt;
    UI_Visitor_I *myUiVisitor;
};

#endif // STRCT_CHNL_NODE_H
