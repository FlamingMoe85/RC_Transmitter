/*
 * Source.cpp
 *
 *  Created on: 22.11.2020
 *      Author: Justus
 */

#include "Source.h"
#include "../Strct_Compo_Node.h"

Source::Source() {
	// TODO Auto-generated constructor stub

	myCompoNode = 0;
}

Source::~Source() {
	// TODO Auto-generated destructor stub
}

void Source::NewTrigCompo()
{
	Graph_App_I* tmpNamingPtr;
	if(myCompoNode == 0)
	{
		tmpNamingPtr = new Strct_Compo_Node();
		this->AddToPoolLstEnd((Strct_Compo_Node*)tmpNamingPtr);
		myCompoNode = (Strct_Compo_Node*)tmpNamingPtr;
		Graph_App_I::FillNameArray(tmpNamingPtr->GetNameArr() , "Composition", 11);
		//FillNameArray(tmpNamingPtr->GetNameArr() , "Composition", 11);
	}
}

void Source::SetTrigCompo(Strct_Compo_Node* tc)
{
	myCompoNode = tc;
}

/**/
void Source::SetMyType(uint16_t type)
{
	myType = type;
}

uint16_t Source::GetType()
{
	return myType;
}


Strct_Compo_Node* Source::GetTrigCompo()
{
	return myCompoNode;
}


void Source::SetVisitor(UI_Visitor_I* v)
{
	myUiVisitor = v;
}

UI_Visitor_I* Source::GetVisitor()
{
	return myUiVisitor;
}

void Source::Serialize(SerializeDest_I* SerDest)
{/**/
	SerDest->SaveUint16(GetType());

	if(GetTrigCompo() != 0)
	{
		SerDest->SaveUint16(1);
		GetTrigCompo()->Serialize(SerDest);
	}
	else
	{
		SerDest->SaveUint16(0);
	}

}

void Source::Deserialize(SerializeDest_I* SerDest)
{/**/
	uint16_t slotCnt, compoType, poolPos;

	slotCnt = SerDest->GetUint16(); //read if Source stored
	if(slotCnt == 1)
	{

		compoType = SerDest->GetUint16();
		if(compoType == COMPO_TYP_OPEN)
		{
			SetTrigCompo(new Strct_Compo_Node());
			this->AddToPoolLstEnd(GetTrigCompo());
			GetTrigCompo()->Deserialize(SerDest);
		}
		else if(compoType == COMPO_TYP_STORED)
		{
			poolPos = SerDest->GetUint16();
			SetTrigCompo(this->GetPoolLst()->At(poolPos));
		}
	}
}
