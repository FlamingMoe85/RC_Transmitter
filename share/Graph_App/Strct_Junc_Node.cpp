/*
 * Strct_Junc_Node.cpp
 *
 *  Created on: 18.09.2019
 *      Author: Justus
 */

#include "Strct_Junc_Node.h"
#include "Strct_Compo_Node.h"

Strct_Junc_Node::Strct_Junc_Node() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Junction" , (uint16_t)8);
    SetType(JUNC_TYP);
}

Strct_Junc_Node::~Strct_Junc_Node() {
	// TODO Auto-generated destructor stub
}

void Strct_Junc_Node::Run(float* val, uint32_t itteration)
{
	float sum = 0, dummy = 0;
	for(uint16_t i=0; i<GetChildList()->Count(); i++)
	{
		dummy = 0;
		GetChildList()->At(i)->Run(&dummy,itteration);
		sum += dummy;
	}
	*val += sum;
}

void Strct_Junc_Node::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Strct_Junc_Node::GetVisitor()
{
	return myUiVisitor;
}

void Strct_Junc_Node::Show()
{
	myUiVisitor->DispShowCall(this);
}

void Strct_Junc_Node::AddCompAtEnd()
{
	Graph_App_I* tmpNamingPtr;
	tmpNamingPtr = new Strct_Compo_Node();
	this->AddToPoolLstEnd((Strct_Compo_Node*)tmpNamingPtr);
	GetChildList()->AddEnd(tmpNamingPtr);
	FillNameArray(tmpNamingPtr->GetNameArr() , "Composition", 11);
	Show();
}

void Strct_Junc_Node::Serialize(SerializeDest_I* SerDest)
{
	SerDest->SaveUint16(JUNC_TYP);
	SerDest->SaveName(this->GetNameArr());
	SerDest->SaveUint16(GetChildList()->Count());
	for(uint16_t i=0; i<GetChildList()->Count(); i++)
	{
		GetChildList()->At(i)->Serialize(SerDest);
	}
}

void Strct_Junc_Node::Deserialize(SerializeDest_I* SerDest)
{
	uint16_t savedSlots, compoType, poolPos;
	//savedSlots = SerDest->GetUint16(); //dummy read Typ
	SerDest->GetName(this->GetNameArr());
	savedSlots = SerDest->GetUint16();// amt Chlds
	for(uint16_t i=0; i<savedSlots; i++)
	{
		compoType = SerDest->GetUint16();
		if(compoType == COMPO_TYP_OPEN)
		{
			GetChildList()->AddEnd(new Strct_Compo_Node());
			this->AddToPoolLstEnd((Strct_Compo_Node*)GetChildList()->At(GetChildList()->Count()-1));
			GetChildList()->At(GetChildList()->Count()-1)->Deserialize(SerDest);
		}
		else if(compoType == COMPO_TYP_STORED)
		{
			poolPos = SerDest->GetUint16();
			GetChildList()->AddEnd(this->GetPoolLst()->At(poolPos));
		}

	}
}
