#ifndef STRCT_CHNLMNGR_NODE_H
#define STRCT_CHNLMNGR_NODE_H

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"

class Strct_ChnlMngr_Node: public Graph_Node<Graph_App_I>
{
public:
    Strct_ChnlMngr_Node();

    virtual void Run(float* val, uint32_t itteration);
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Serialize(SerializeDest_I* SerDest);
    virtual void Deserialize(SerializeDest_I* SerDest);
    virtual void NullSerCntr();

    void Run();
    int32_t GetChnlVal(uint16_t chnl);

private:

    uint32_t itteration;
    float resultArr[7];
    UI_Visitor_I *myUiVisitor;
};

#endif // STRCT_CHNLMNGR_NODE_H
