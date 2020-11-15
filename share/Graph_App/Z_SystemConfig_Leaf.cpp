/*
 * Z_SystemConfig_Leaf.cpp
 *
 *  Created on: 11.11.2020
 *      Author: Justus
 */

#include "Z_SystemConfig_Leaf.h"

Z_SystemConfig_Leaf::Z_SystemConfig_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Sys Configs" , (uint16_t)11);
}

Z_SystemConfig_Leaf::~Z_SystemConfig_Leaf() {
	// TODO Auto-generated destructor stub
}

void Z_SystemConfig_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	myUiVisitor->DispShowCall(this);
}

UI_Visitor_I* Z_SystemConfig_Leaf::GetVisitor()
{
	return myUiVisitor;
}
