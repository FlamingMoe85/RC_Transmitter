/*
 * Z_SystemConfig_Leaf_UI.h
 *
 *  Created on: 11.11.2020
 *      Author: Justus
 */

#ifndef UIS_Z_SYSTEMCONFIG_LEAF_UI_H_
#define UIS_Z_SYSTEMCONFIG_LEAF_UI_H_

#include"../../../share/Graph_App/Z_SystemConfig_Leaf.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Z_SystemConfig_Leaf_UI  : public Ui_Identifier{
public:
	Z_SystemConfig_Leaf_UI();
	virtual ~Z_SystemConfig_Leaf_UI();

	void SetSysConfig_Ref(Z_SystemConfig_Leaf* ref);


		virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
		virtual void Up(){ };
		virtual void Down(){ };
		virtual void Right(){ };//No need
		virtual void Left(){ };//No need
		virtual void Grab(){ };//No need


		virtual uint16_t GetCanSel(){ };// CHECK
		virtual uint16_t GetItmSel(){ };// CHECK

		virtual void RemFcnBtns(){ };
		virtual void ConFcnBtns(){ };
		virtual void DelSelItm(){ };

private:
		Z_SystemConfig_Leaf* myRef;
};

#endif /* UIS_Z_SYSTEMCONFIG_LEAF_UI_H_ */
