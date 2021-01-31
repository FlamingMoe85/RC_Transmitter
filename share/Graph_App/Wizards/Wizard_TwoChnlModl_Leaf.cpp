/*
 * Wizard_TwoChnlModl_Leaf.cpp
 *
 *  Created on: 28.01.2021
 *      Author: Justus
 */

#include "Wizard_TwoChnlModl_Leaf.h"

#include "../Strct_Compo_Node.h"


//extern Strct_CalcFactory GlobalModFactory;
static uint16_t data[] = {3, 	ADCuC_TYP,0,
								SCALE_SWITCH_TYP, 1, 0, 1000, 1000,
								CSTMSW_TYP, 1, 1, 0, 0,//13
								3, 	ADCuC_TYP,0,
								SCALE_SWITCH_TYP, 1, 0, 1000, 1000,
								CSTMSW_TYP, 1, 1, 0, 0};//26
static char gas[] = "Gas";
static char steer[] = "Steer";

Wizard_TwoChnlModl_Leaf::Wizard_TwoChnlModl_Leaf() {
	// TODO Auto-generated constructor stub
    this->FillNameArray(GetNameArr(), "2 Chnl Model" , (uint16_t)12);
    SetType(TWO_CHNL_MODL_WIZ_TYP);

}

Wizard_TwoChnlModl_Leaf::~Wizard_TwoChnlModl_Leaf() {
	// TODO Auto-generated destructor stub
}

void Wizard_TwoChnlModl_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	selADC[GAS] = 0;
	selADC[GAS_SCL] = 1000;
	selADC[STEER] = 0;
	selADC[STEER_SCL] = 1000;
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Wizard_TwoChnlModl_Leaf::GetVisitor()
{
	return myUiVisitor;
}

void Wizard_TwoChnlModl_Leaf::Generate()
{
	Strct_Compo_Node* tmpCompoNode;

	dataCntr = 0;
	dataArrRef = &(data[0]);
	nameRef = &(gas[0]);
	tmpCompoNode = new Strct_Compo_Node();
	tmpCompoNode->Deserialize(this);
	GetPoolLst()->AddEnd(tmpCompoNode);


	dataArrRef = &(data[0]);
	nameRef = &(steer[0]);
	tmpCompoNode = new Strct_Compo_Node();
	tmpCompoNode->Deserialize(this);
	GetPoolLst()->AddEnd(tmpCompoNode);
}


int16_t Wizard_TwoChnlModl_Leaf::AddValtoSel(uint16_t sel, int16_t val)
{
	if((sel == GAS) || (sel == STEER))
	{
		if(val >= 0)
		{
			AddValToSel(sel, (uint16_t)val);
		}
		else
		{
			SubValFromSel(sel, (uint16_t)(val * (-1)));
		}
	}
	else
	{
		AddValToSel(sel, val);
	}
}

uint16_t Wizard_TwoChnlModl_Leaf::GetSel(uint16_t sel)
{
	if(sel > STEER_SCL) return 0;
	return selADC[sel];
}

int16_t Wizard_TwoChnlModl_Leaf::AddValToSel(uint16_t sel, int16_t val)
{
	if(sel > STEER_SCL) return 0;
	selADC[sel] += val;
	return selADC[sel];
}

int16_t Wizard_TwoChnlModl_Leaf::SubValFromSel(uint16_t sel, uint16_t val)
{
	if(sel > STEER_SCL) return 0;
	if(selADC[sel] < val)val = 0;
	else selADC[sel] -= val;
	return selADC[sel];
}



/**/
void Wizard_TwoChnlModl_Leaf::GetName(char* nameArr)
{
	uint16_t i = 0;
	char curChar = nameRef[i];
	while(curChar != 0)
	{
		nameArr[i] = curChar;
		i++;
		curChar = nameRef[i];

	}
	nameArr[i] = curChar;
}

uint16_t Wizard_TwoChnlModl_Leaf::GetUint16()
{
	if(dataCntr == 2)
	{
		dataCntr++;
		return selADC[GAS];
	}
	if(dataCntr == 15)
	{
		dataCntr++;
		return selADC[STEER];
	}
	return dataArrRef[dataCntr++];
}

int16_t Wizard_TwoChnlModl_Leaf::GetInt16()
{
	IntUint16 conv;


	if((dataCntr == 6) || (dataCntr == 7))
	{
		dataCntr++;
		conv.uint16Val =  selADC[GAS_SCL];
	}
	else if((dataCntr == 19) || (dataCntr == 20))
	{
		dataCntr++;
		conv.uint16Val =  selADC[STEER_SCL];
	}
	else
	{
		conv.uint16Val = dataArrRef[dataCntr++];
	}
	return conv.int16Val;
}
