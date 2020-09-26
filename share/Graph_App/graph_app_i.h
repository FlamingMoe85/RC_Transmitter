#ifndef GRAPH_APP_I_H
#define GRAPH_APP_I_H

#include "../std/Graph_Basic_I.h"
//#include "../share/std/Graph_Basic_I.h"
#include "../std/SerializeDest_I.hpp"
#include "../UIs/Ui_Visitor_I.hpp"
#include "../globaldefinesshare.h"

class Graph_App_I //: public Graph_Basic_I
{
public:

    virtual int16_t Enter(Graph_App_I** ittsCurNode, uint16_t destLoc) = 0;
    virtual int16_t Esc(Graph_App_I **ittsCurNode) = 0;
    virtual void SetEntry(Graph_App_I* ent) = 0;
    virtual Graph_App_I* GetEntry() = 0;
    virtual uint16_t AmtOfChilds() = 0;
    virtual List<Graph_App_I*>* GetChildList() = 0;
    virtual int16_t FindLoop(Graph_App_I* candi) = 0;
    virtual void SetCurrentNodePtrLoc(Graph_App_I** n) = 0;
    virtual Graph_App_I** GetCurNodePtrLoc() = 0;

    virtual void Run(float* val, uint32_t itteration) = 0;
    virtual void Show(UI_Visitor_I* UiVisitor) = 0;
    virtual UI_Visitor_I* GetVisitor() = 0;
    virtual void Serialize(SerializeDest_I* SerDest) = 0;
    virtual void Deserialize(SerializeDest_I* SerDest) = 0;
    virtual void NullSerCntr() = 0;

    char* GetNameArr()
    {
        return nameArr;
    }

    static void FillNameArray(char arrAdr[], const char* name, uint16_t length)
    {
        for(uint16_t i=0; i<length; i++)
        {
            arrAdr[i] = name[i];
        }
        arrAdr[length] = '\0';
    }

    void SetType(uint16_t t)
    {
        type = t;
    }
    uint16_t GetType()
    {
        return type;
    }


private:

    char nameArr[NAME_LENGTH];
    uint16_t type;
};

#endif // GRAPH_APP_I_H
