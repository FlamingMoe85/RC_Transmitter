/*
 * ItemSelector.h
 *
 *  Created on: 23.09.2018
 *      Author: Justus
 */

#ifndef UIS_ITEMSELECTOR_H_
#define UIS_ITEMSELECTOR_H_

#include "../../../share/Graph_App/Graph_App_I.h"
#include "../../../share/std/List.hpp"
#include "Ui_Identifier.h"
#include "../utils/UtilClass.h"

class ItemSelector : public Ui_Identifier {
public:
	ItemSelector();
	virtual ~ItemSelector();
	void SetChldLst(List<Graph_App_I*>* lstArg);
	void SetName(char* n);

	void Paint();
	void ItemSel(uint16_t sel, uint16_t cSel);

	void EscItmSel();

	//virtual void Enter();
	//virtual void Esc();
	virtual void Up();
	virtual void Down();
	virtual void Right();
	virtual void Left();
	virtual void Grab();

	virtual uint16_t GetCanSel();
	virtual uint16_t GetItmSel();

	void RmoveNameBtn();
	void ConctNameBtn();

private:
	uint16_t curItem;
	uint16_t canSel;
	List<Graph_App_I*>* myItmLst;
	uint16_t grabMode;
	char counter_1[3], counter_2[3], counter_3[3];



};

#endif /* UIS_ITEMSELECTOR_H_ */
