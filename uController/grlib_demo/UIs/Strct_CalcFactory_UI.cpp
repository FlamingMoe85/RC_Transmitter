/*
 * Strct_CalcFactory_UI.cpp
 *
 *  Created on: 04.05.2019
 *      Author: Justus
 */

#include "Strct_CalcFactory_UI.h"

Strct_CalcFactory_UI::Strct_CalcFactory_UI() {
	// TODO Auto-generated constructor stub

}

Strct_CalcFactory_UI::~Strct_CalcFactory_UI() {
	// TODO Auto-generated destructor stub
}

void Strct_CalcFactory_UI::SetCalcFactory_Ref(Strct_CalcFactory *ref)
{
	myRef = ref;
	this->SetActUi(this->GetStackPos());
	this->SetChldLst(myRef->GetChildList());
	this->ItemSel(GetItmSel(),1);
	//WidgetPaint((tWidget *)&(myCanvacsesChMnr[0]));
	this->SetName(myRef->GetNameArr());
	Paint();
}

void Strct_CalcFactory_UI::Enter(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	if(myRef->GetChildList()->Count() > 0)
	{
		switch(this->GetItmSel())
		{
			case 0:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Calc_Addition_Leaf());
				break;
			}

			case 1:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Calc_Multiplication_Leaf());
				break;
			}

			case 2:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Calc_uCAdc_Leaf());
				break;
			}

			case 3:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Src_CstmSw_Leaf());
				break;
			}
			case 4:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Src_InternTrim_Leaf());
				break;
			}
			case 5:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new TimeCalc_Ramp_Leaf());
				break;
			}
			case 6:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Time_Blinker_Leaf());
				break;
			}

			case 7:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Calc_ScaleSw_Leaf());
				break;
			}

			case 8:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Calc_Quantizer_Leaf());
				break;
			}

			case 9:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Clac_DeadArea_Leaf());
				break;
			}

			case 10:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Calc_MinMaxLimit_Leaf());
				break;
			}

			case 11:
			{
				myRef->GetEntry()->GetChildList()->AddEnd(new Calc_Expo1_Leaf());
				break;
			}

		}
	}
	(**curNode).Esc(curNode);
	//WidgetRemove((tWidget *)&cmpBtns);
	//WidgetPaint((tWidget *)&cmpBtnsCov);
	(**curNode).Show(UiVis);
}


void Strct_CalcFactory_UI::Esc(Graph_App_I** curNode, UI_Visitor_I* UiVis)
{
	(**curNode).Esc(curNode);
	//WidgetRemove((tWidget *)&cmpBtns);
	//WidgetPaint((tWidget *)&cmpBtnsCov);
	(**curNode).Show(UiVis);
}
