/*
 * Strct_SaveLoad_Node.h
 *
 *  Created on: 29.05.2019
 *      Author: Justus
 */

#ifndef SHARE_GRAPH_APP_STRCT_SAVELOAD_NODE_H_
#define SHARE_GRAPH_APP_STRCT_SAVELOAD_NODE_H_

#include "Graph_App_I.h"
#include "../std/Graph_Node.h"
#include "../globaldefinesshare.h"
#include "GraphAppCommons.h"
#include "../UIs/Ui_Visitor_I.hpp"
#include "../std/SerializeDest_I.hpp"

class Strct_SaveLoad_Node : public Graph_Node<Graph_App_I> {
public:
	Strct_SaveLoad_Node();
	virtual ~Strct_SaveLoad_Node();

    virtual void Run(float* val, uint32_t itteration){ };
    virtual void Show(UI_Visitor_I* UiVisitor);
    virtual UI_Visitor_I* GetVisitor();
    virtual void Show();
    virtual void Serialize(SerializeDest_I* SerDest){ };
    virtual void Deserialize(SerializeDest_I* SerDest){ };
    virtual void NullSerCntr(){ };

    void SetModMngr(SerializeDest_I* mM);
    void SaveMod(char* namAr);
    uint16_t GetAmtOfModels();
    void GetNameOfModel(char* namArr, uint16_t modNmbr);
    uint16_t GetFreeSpacePerc();
    uint16_t GetCurModNmbr();
    void PrepForOverwrite(uint32_t modNmbr);


private:
    UI_Visitor_I *myUiVisitor;
    SerializeDest_I* myModMngr;
    uint16_t saveCntr;
	char namArr[20];
};

#endif /* SHARE_GRAPH_APP_STRCT_SAVELOAD_NODE_H_ */
