/*
 * Z_MusicControl_Leaf_Ui.h
 *
 *  Created on: 09.02.2022
 *      Author: Justus
 */

#ifndef UIS_Z_MUSICCONTROL_LEAF_UI_H_
#define UIS_Z_MUSICCONTROL_LEAF_UI_H_

#include"../../../share/Graph_App/Z_MusicControl.h"
#include "ItemSelector.h"
#include "Ui_Identifier.h"

class Z_MusicControl_Leaf_Ui  : public Ui_Identifier{
public:
	Z_MusicControl_Leaf_Ui();
	virtual ~Z_MusicControl_Leaf_Ui();

	void SetMusicControl_Ref(Z_MusicControl* ref);


		virtual void Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis);
		virtual void Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis){ };
		virtual void Up();
		virtual void Down();
		virtual void Right();
		virtual void Left();
		virtual void Grab(){ };
		virtual void RefreshButtons() { };


		virtual uint16_t GetCanSel(){ };
		virtual uint16_t GetItmSel(){ };

		virtual void RemFcnBtns(){ };
		virtual void ConFcnBtns(){ };
		virtual void DelSelItm(){ };


private:

		void PaintSelected();

		Z_MusicControl* myRef;
		uint16_t curPos;
		uint16_t amtControls;
};

#endif /* UIS_Z_MUSICCONTROL_LEAF_UI_H_ */
