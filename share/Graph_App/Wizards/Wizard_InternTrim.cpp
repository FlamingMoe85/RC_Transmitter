/*
 * Wizard_InternTrim.cpp
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#include "Wizard_InternTrim.h"
#include "../Strct_CalcFactory.h"
#include "../Strct_Compo_Node.h"

extern Strct_CalcFactory GlobalModFactory;

Wizard_InternTrim::Wizard_InternTrim() {
	// TODO Auto-generated constructor stub
    this->FillNameArray(GetNameArr(), "Intern Trim" , (uint16_t)12);
    SetType(INTERN_TRIM_WIZ_TYP);
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
	tmpCompoNode = new Strct_Compo_Node();
	tmpCompoNode->GetChildList()->AddEnd(GlobalModFactory.GetModuleByType(CSTMSW_TYP));
	tmpCompoNode->GetChildList()->AddEnd(GlobalModFactory.GetModuleByType(INTEGRATOR_TYP));
	tmpCompoNode->GetChildList()->AddEnd(GlobalModFactory.GetModuleByType(RAMP_TYP));
	GetPoolLst()->AddEnd(tmpCompoNode);
}
