/*
 * Strct_TopMenue_Node_UI.h
 *
 *  Created on: 29.05.2019
 *      Author: Justus
 */

#ifndef UIS_STRCT_TOPMENUE_NODE_UI_H_
#define UIS_STRCT_TOPMENUE_NODE_UI_H_

#include"../../../share/Graph_App/Strct_TopMenue_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Strct_TopMenue_Node_UI : public ItemSelector{
public:
	Strct_TopMenue_Node_UI();
	virtual ~Strct_TopMenue_Node_UI();

	void SetTopMenue_Ref(Strct_TopMenue_Node* ref);
	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);

	virtual void RemFcnBtns(){ };
	virtual void ConFcnBtns(){ };
	virtual void DelSelItm(){ };


	virtual void Up(){ItemUp();};
	virtual void Down(){ItemDown();};
	virtual void Right(){ItemRight();};
	virtual void Left(){ItemLeft();};
	virtual void Grab(){ItemGrab();};
	virtual void RefreshButtons() { };

private:
	Strct_TopMenue_Node* myRef;
};

#endif /* UIS_STRCT_TOPMENUE_NODE_UI_H_ */
