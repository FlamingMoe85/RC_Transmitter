/*
 * Strct_SaveLoad_Node_UI.h
 *
 *  Created on: 29.05.2019
 *      Author: Justus
 */

#ifndef UIS_STRCT_SAVELOAD_NODE_UI_H_
#define UIS_STRCT_SAVELOAD_NODE_UI_H_

#include"../../../share/Graph_App/Strct_SaveLoad_Node.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"
#include "../Storage/ModelManager.h"

	#define OVERWRITE 0
	#define NEW_MOD 1

class Strct_SaveLoad_Node_UI : public Ui_Identifier{
public:
	Strct_SaveLoad_Node_UI();
	virtual ~Strct_SaveLoad_Node_UI();

	void SetSaveLoad_Ref(Strct_SaveLoad_Node* ref);

	void Paint();
	void ItemSel(uint16_t sel, uint16_t cSel); //CHECK -> ItemSelector

	virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	virtual void Up();
	virtual void Down();
	virtual void Right(){ };//No need
	virtual void Left(){ };//No need
	virtual void Grab(){ };//No need


	virtual uint16_t GetCanSel();// CHECK
	virtual uint16_t GetItmSel();// CHECK

	virtual void RemFcnBtns();
	virtual void ConFcnBtns();
	virtual void DelSelItm(){ };

	void SaveMod();
	void ShowFreeSpace();
	uint16_t newOrOvrwrt;

private:
	Strct_SaveLoad_Node* myRef;
	uint16_t curItem;
	uint16_t canSel;
	char name_1[NAME_LENGTH];
	char name_2[NAME_LENGTH];
	char name_3[NAME_LENGTH];




};

#endif /* UIS_STRCT_SAVELOAD_NODE_UI_H_ */
