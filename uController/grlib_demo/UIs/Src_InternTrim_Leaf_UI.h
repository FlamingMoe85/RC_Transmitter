/*
 * Src_InternTrim_Leaf_UI.h
 *
 *  Created on: 08.09.2019
 *      Author: Justus
 */

#ifndef UIS_SRC_INTERNTRIM_LEAF_UI_H_
#define UIS_SRC_INTERNTRIM_LEAF_UI_H_

#include"../../../share/Graph_App/Src_InternTrim_Leaf.h"
#include "../utils/UtilClass.h"
#include "Ui_Identifier.h"

class Src_InternTrim_Leaf_UI  : public Ui_Identifier{
public:
	Src_InternTrim_Leaf_UI();
	virtual ~Src_InternTrim_Leaf_UI();

	void SetInternTrim_Ref(Src_InternTrim_Leaf *ref);

		virtual void RemFcnBtns(){ };
		virtual void ConFcnBtns(){ };
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
		virtual void Grab(){ };

		void RepaintVals();

private:
		Src_InternTrim_Leaf* myRef;
		void RepaintTrmSel();

};

#endif /* UIS_SRC_INTERNTRIM_LEAF_UI_H_ */
