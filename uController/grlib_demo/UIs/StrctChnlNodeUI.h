/*
 * StrctChnlNodeUI.h
 *
 *  Created on: 22.09.2018
 *      Author: Justus
 */

#ifndef UIS_STRCTCHNLNODEUI_H_
#define UIS_STRCTCHNLNODEUI_H_

#include"../../../share/Graph_App/Strct_Chnl_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Strct_Chnl_Node_UI : public ItemSelector  {
public:
	Strct_Chnl_Node_UI();
	virtual ~Strct_Chnl_Node_UI();

	void SetStrctChnl_Ref(Strct_Chnl_Node* ref);
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	virtual void RemFcnBtns();
	virtual void ConFcnBtns();
	virtual void DelSelItm(){ };

	virtual void Up(){ItemUp();};
	virtual void Down(){ItemDown();};
	virtual void Right();
	virtual void Left();
	virtual void Grab();
	virtual void RefreshButtons();

private:
	Strct_Chnl_Node* myRef;

	unsigned int secMenStat,btnSel;
};

#endif /* UIS_STRCTCHNLNODEUI_H_ */
