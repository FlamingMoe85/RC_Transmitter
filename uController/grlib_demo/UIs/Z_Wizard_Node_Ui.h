/*
 * Z_Wizard_Node_Ui.h
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#ifndef UIS_Z_WIZARD_NODE_UI_H_
#define UIS_Z_WIZARD_NODE_UI_H_

#include"../../../share/Graph_App/Z_Wizard_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Z_Wizard_Node_Ui : public ItemSelector {
public:
	Z_Wizard_Node_Ui();
	virtual ~Z_Wizard_Node_Ui();

	void SetWizard_Ref(Z_Wizard_Node* ref);
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
	Z_Wizard_Node* myRef;
};

#endif /* UIS_Z_WIZARD_NODE_UI_H_ */
