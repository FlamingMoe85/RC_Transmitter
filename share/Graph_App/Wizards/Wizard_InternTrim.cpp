/*
 * Wizard_InternTrim.cpp
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#include "Wizard_InternTrim.h"
//#include "../Strct_CalcFactory.h"
#include "../Strct_Compo_Node.h"


//extern Strct_CalcFactory GlobalModFactory;
static uint16_t data[] = {2, CSTMSW_TYP,0, 3, 0, 0, 0,0, 0,0,
							INTEGRATOR_TYP, 1000, 64536, 0, 0, 1};


Wizard_InternTrim::Wizard_InternTrim() {
	// TODO Auto-generated constructor stub
    this->FillNameArray(GetNameArr(), "Intern Trim" , (uint16_t)12);
    SetType(INTERN_TRIM_WIZ_TYP);
/*
    dataArr[0] = CSTMSW_TYP;
    dataArr[1] = 0;
    dataArr[2] = 3;
    dataArr[3] = 0;
    dataArr[4] = 0;
    dataArr[5] = 1;
    dataArr[6] = 0;
    dataArr[7] = 2;
    dataArr[8] = 0;
    */
}

Wizard_InternTrim::~Wizard_InternTrim() {
	// TODO Auto-generated destructor stub
}

void Wizard_InternTrim::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Wizard_InternTrim::GetVisitor()
{
	return myUiVisitor;
}

void Wizard_InternTrim::Generate()
{
	Strct_Compo_Node* tmpCompoNode;
	dataCntr = 0;
	tmpCompoNode = new Strct_Compo_Node();
	tmpCompoNode->Deserialize(this);
	/*globalWizSorFaker.SetDataArr(dataArr);
	tmpCompoNode->Deserialize(&globalWizSorFaker);
	*/
	//tmpCompoNode->GetChildList()->AddEnd(GlobalModFactory.GetDeserializedModule(&(data[0])));
	//tmpCompoNode->GetChildList()->AddEnd(GlobalModFactory.GetModuleByType(INTEGRATOR_TYP));
	//tmpCompoNode->GetChildList()->AddEnd(GlobalModFactory.GetModuleByType(RAMP_TYP));

	GetPoolLst()->AddEnd(tmpCompoNode);
}

/**/
void Wizard_InternTrim::GetName(char* nameArr)
{
	nameArr = GetNameArr();
}

uint16_t Wizard_InternTrim::GetUint16()
{
	return data[dataCntr++];
}

int16_t Wizard_InternTrim::GetInt16()
{
	IntUint16 conv;
	conv.uint16Val = data[dataCntr++];
	return conv.int16Val;
}

