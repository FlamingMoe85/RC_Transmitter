/*
 * Src_CstmSw_Leaf_Ui.h
 *
 *  Created on: 18.05.2019
 *      Author: Justus
 */

#ifndef UIS_SRC_CSTMSW_LEAF_UI_H_
#define UIS_SRC_CSTMSW_LEAF_UI_H_

#include"../../../share/Graph_App/Src_CstmSw_Leaf.h"
#include "../utils/UtilClass.h"
#include "Ui_Identifier.h"
#include "../../../share/QuadEncConsumerBase.h"

class Src_CstmSw_Leaf_Ui : public Ui_Identifier, public QuadEncConsumerBase{
public:
	Src_CstmSw_Leaf_Ui();
	virtual ~Src_CstmSw_Leaf_Ui();

	void SetCstmSw_Ref(Src_CstmSw_Leaf *ref);

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

		virtual void QuadEncNotify(int16_t val);

private:
		Src_CstmSw_Leaf* myRef;
		uint16_t inSel;
		uint16_t column;
};

#endif /* UIS_SRC_CSTMSW_LEAF_UI_H_ */
