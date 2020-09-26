/*
 * Strct_TopMenue_Node.cpp
 *
 *  Created on: 29.05.2019
 *      Author: Justus
 */

#include "Strct_TopMenue_Node.h"

Strct_TopMenue_Node::Strct_TopMenue_Node() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Top Menu" , (uint16_t)8);
}

Strct_TopMenue_Node::~Strct_TopMenue_Node() {
	// TODO Auto-generated destructor stub
}

void Strct_TopMenue_Node::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Strct_TopMenue_Node::GetVisitor()
{
	return myUiVisitor;
}

void Strct_TopMenue_Node::Show()
{
	myUiVisitor->DispShowCall(this);
}
