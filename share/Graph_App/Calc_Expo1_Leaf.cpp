/*
 * Calc_Expo1_Leaf.cpp
 *
 *  Created on: 14.11.2020
 *      Author: Justus
 */

#include "Calc_Expo1_Leaf.h"

const float curveLUT[100] =
	    {0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.01,
		0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.02, 0.02, 0.02,
		0.02, 0.02, 0.03, 0.03, 0.03, 0.03, 0.04, 0.04, 0.04, 0.05,
		0.05, 0.05, 0.06, 0.06, 0.06, 0.07, 0.07, 0.08, 0.08, 0.08,
		0.09, 0.09, 0.10, 0.10, 0.11, 0.11, 0.12, 0.12, 0.13, 0.13,
		0.14, 0.15, 0.15, 0.16, 0.16, 0.17, 0.18, 0.19, 0.19, 0.20,
		0.21, 0.22, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29,
		0.30, 0.31, 0.32, 0.33, 0.34, 0.35, 0.36, 0.37, 0.39, 0.40,
		0.41, 0.43, 0.44, 0.46, 0.47, 0.49, 0.51, 0.53, 0.54, 0.56,
		0.59, 0.61, 0.63, 0.66, 0.69, 0.72, 0.76, 0.80, 0.86, 1.00};

Calc_Expo1_Leaf::Calc_Expo1_Leaf() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Expo 1", 6);

		    SetType(EXPO1_TYP);

			trigCompo = 0;
}

Calc_Expo1_Leaf::~Calc_Expo1_Leaf() {
	// TODO Auto-generated destructor stub
}

void Calc_Expo1_Leaf::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Calc_Expo1_Leaf::GetVisitor()
{
	return myUiVisitor;
}

void Calc_Expo1_Leaf::Run(float* val, uint32_t itteration)
{
	int16_t intConv;
	float floatConv;
	float expPerc = 0.0;
	uint32_t trigItt;

	if(trigCompo != 0)trigCompo->Run(&expPerc, trigItt);

	intConv = (int16_t)(*val / 10.0);
	if(intConv < 0) intConv *= (-1);
	if(intConv > 99)intConv = 99;


	expPerc = (expPerc / 1000);
	if(expPerc < 0) expPerc *= (-1);
	if(expPerc > 1)expPerc = 1;

	floatConv = (float)curveLUT[intConv];
	*val = *val * ((floatConv*expPerc) + 1.0 - expPerc);
}


void Calc_Expo1_Leaf::NewTrigCompo()
{
	Graph_App_I* tmpNamingPtr;
	if(trigCompo == 0)
	{
		tmpNamingPtr = new Strct_Compo_Node();
		this->AddToPoolLstEnd((Strct_Compo_Node*)tmpNamingPtr);
		trigCompo = (Strct_Compo_Node*)tmpNamingPtr;
		FillNameArray(tmpNamingPtr->GetNameArr() , "Composition", 11);
	}
}

Strct_Compo_Node* Calc_Expo1_Leaf::GetTrigCompo()
{
	return trigCompo;
}

void Calc_Expo1_Leaf::Serialize(SerializeDest_I* SerDest)
{/**/
	uint16_t slotCnt;
	SerDest->SaveUint16(EXPO1_TYP);

	if(trigCompo != 0)
	{
		SerDest->SaveUint16(1);
		trigCompo->Serialize(SerDest);
	}
	else
	{
		SerDest->SaveUint16(0);
	}

}

void Calc_Expo1_Leaf::Deserialize(SerializeDest_I* SerDest)
{/**/
	uint16_t slotCnt, compoType, poolPos;

	slotCnt = SerDest->GetUint16(); //read if trigger stored
	if(slotCnt == 1)
	{

		compoType = SerDest->GetUint16();
		if(compoType == COMPO_TYP_OPEN)
		{
			trigCompo = new Strct_Compo_Node();
			this->AddToPoolLstEnd(trigCompo);
			trigCompo->Deserialize(SerDest);
		}
		else if(compoType == COMPO_TYP_STORED)
		{
			poolPos = SerDest->GetUint16();
			trigCompo = (this->GetPoolLst()->At(poolPos));
		}
	}
}
