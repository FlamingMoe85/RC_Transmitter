/*
 * Z_Wizard_Node.cpp
 *
 *  Created on: 25.01.2021
 *      Author: Justus
 */

#include "Z_Wizard_Node.h"

Z_Wizard_Node::Z_Wizard_Node() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Wizards" , (uint16_t)8);
	SetType(WIZARD_MEN_TYP);

	this->GetChildList()->AddEnd(&internTrimWiz);
}

Z_Wizard_Node::~Z_Wizard_Node() {
	// TODO Auto-generated destructor stub
}

void Z_Wizard_Node::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Z_Wizard_Node::GetVisitor()
{
	return myUiVisitor;
}
