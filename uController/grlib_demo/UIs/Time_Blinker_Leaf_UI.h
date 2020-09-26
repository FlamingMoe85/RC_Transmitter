/*
 * Time_Blinker_Leaf_UI.h
 *
 *  Created on: 27.12.2019
 *      Author: Justus
 */

#ifndef UIS_TIME_BLINKER_LEAF_UI_H_
#define UIS_TIME_BLINKER_LEAF_UI_H_

#include "../../../share/Graph_App/Time_Blinker_Leaf.h"
#include "Ui_Identifier.h"
#include "../utils/UtilClass.h"
#include "../../../share/QuadEncConsumerBase.h"

#include "./grlib/grlib.h"
#include "./grlib/widget.h"

class Time_Blinker_Leaf_UI : public Ui_Identifier, public QuadEncConsumerBase{
public:
	Time_Blinker_Leaf_UI();
	virtual ~Time_Blinker_Leaf_UI();

	void SetTime_Blinker_Ref(Time_Blinker_Leaf *ref);

		virtual void RemFcnBtns();
		virtual void ConFcnBtns();
		virtual void DelSelItm(){ };

		void Paint();
		virtual uint16_t GetItmSel();
		virtual uint16_t GetCanSel();

		virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
	    virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
		virtual void Up();
		virtual void Down();
		virtual void Right();
		virtual void Left();
		virtual void Grab();
		void Up(int16_t val);
		void Down(int16_t val);

		void AddIn();
		void DelIn();

		void RepaintVal();

		void SetCompPool(Strct_PoolOwner_Node* poolOwnRef);
		void EnterCompoPool();//(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		void EnterTrigCompo();

		virtual void QuadEncNotify(int16_t val);

private:
		Time_Blinker_Leaf* myRef;
		uint16_t inSel;
		uint16_t column;
		Strct_PoolOwner_Node* myPoolOwnerRef;

};

#endif /* UIS_TIME_BLINKER_LEAF_UI_H_ */
