/*
 * Strct_MultSw_Node.cpp
 *
 *  Created on: 22.04.2019
 *      Author: Justus
 */

#include "Strct_MultSw_Node.h"
#include "Strct_Compo_Node.h"
#include "Strct_Junc_Node.h"


Strct_MultSw_Node::Strct_MultSw_Node() {
	// TODO Auto-generated constructor stub
    SetType(SLOT_TYP);

}

Strct_MultSw_Node::~Strct_MultSw_Node() {
	// TODO Auto-generated destructor stub
}

void Strct_MultSw_Node::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Strct_MultSw_Node::GetVisitor()
{
	return myUiVisitor;
}

void Strct_MultSw_Node::Show()
{
	myUiVisitor->DispShowCall(this);
}

void Strct_MultSw_Node::Run(float* val, uint32_t itteration)
{

    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->Run(val,itteration);
    }
    if(*val < -1200.0) *val = -1200;
    else if(*val > 1200.0) *val = 1200;
}

void Strct_MultSw_Node::AddCompAtEnd()
{
	Graph_App_I* tmpNamingPtr;
	tmpNamingPtr = new Strct_Compo_Node();
	this->AddToPoolLstEnd((Strct_Compo_Node*)tmpNamingPtr);
	GetChildList()->AddEnd(tmpNamingPtr);
	FillNameArray(tmpNamingPtr->GetNameArr() , "Composition", 11);
	Show();
}

void Strct_MultSw_Node::NullSerCntr()
{
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
        GetChildList()->At(i)->NullSerCntr();
    }
}

void Strct_MultSw_Node::Serialize(SerializeDest_I* SerDest)
{
	SerDest->SaveUint16(SLOT_TYP);
	SerDest->SaveName(this->GetNameArr());
    SerDest->SaveUint16(GetChildList()->Count());
    for(uint16_t i=0; i<GetChildList()->Count(); i++)
    {
    	GetChildList()->At(i)->Serialize(SerDest);
    }
}

void Strct_MultSw_Node::Deserialize(SerializeDest_I* SerDest)
{
	uint16_t savedSlots, compoType, poolPos;
	savedSlots = SerDest->GetUint16(); //dummy read Typ
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
		else if(compoType == JUNC_TYP)
		{
			GetChildList()->AddEnd(new Strct_Junc_Node());
			GetChildList()->At(GetChildList()->Count()-1)->Deserialize(SerDest);
		}

	}
}
