/*
 * Strct_PoolOwner_Leaf.cpp
 *
 *  Created on: 06.05.2019
 *      Author: Justus
 */

#include "Strct_PoolOwner_Node.h"

Strct_PoolOwner_Node::Strct_PoolOwner_Node() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Compo Pool", 10);

	dummy_1.FillNameArray(dummy_1.GetNameArr(), " - ", 3);
	this->GetChildList()->AddEnd(&dummy_1);

	dummy_2.FillNameArray(dummy_2.GetNameArr(), " - ", 3);
	this->GetChildList()->AddEnd(&dummy_2);

	dummy_3.FillNameArray(dummy_3.GetNameArr(), " - ", 3);
	this->GetChildList()->AddEnd(&dummy_3);
}

Strct_PoolOwner_Node::~Strct_PoolOwner_Node() {
	// TODO Auto-generated destructor stub
}

void Strct_PoolOwner_Node::Run(float* val, uint32_t itteration)
{

}

void Strct_PoolOwner_Node::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
	dummy_1.FillNameArray(dummy_1.GetNameArr(), " - ", 3);
	dummy_2.FillNameArray(dummy_2.GetNameArr(), " - ", 3);
	dummy_3.FillNameArray(dummy_3.GetNameArr(), " - ", 3);
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Strct_PoolOwner_Node::GetVisitor()
{
	return myUiVisitor;
}

void Strct_PoolOwner_Node::SetUiVisitor(UI_Visitor_I* uiVisRef)
{
	myUiVisitor = uiVisRef;
}

void Strct_PoolOwner_Node::Show()
{
	myUiVisitor->DispShowCall(this);
}


void Strct_PoolOwner_Node::Serialize(SerializeDest_I* SerDest)
{

}

void Strct_PoolOwner_Node::Deserialize(SerializeDest_I* SerDest)
{

}

void Strct_PoolOwner_Node::NullSerCntr()
{

}
