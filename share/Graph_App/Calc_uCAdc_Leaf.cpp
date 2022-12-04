/*
 * Calc_uCAdc_Leaf.cpp
 *
 *  Created on: 15.05.2019
 *      Author: Justus
 */

#include "Calc_uCAdc_Leaf.h"

extern float fourAdcs[12];

Calc_uCAdc_Leaf::Calc_uCAdc_Leaf() {
	// TODO Auto-generated constructor stub
	myChnl = 0;
	this->FillNameArray(GetNameArr(), "ADC Chnl", 8);
    SetType(ADCuC_TYP);
}


void Calc_uCAdc_Leaf::Run(float* val, uint32_t itteration)
{
    (void)itteration;
	*val += fourAdcs[myChnl];
	value = *val;
}

void Calc_uCAdc_Leaf::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Calc_uCAdc_Leaf::GetVisitor()
{
	return myUiVisitor;
}

Calc_uCAdc_Leaf::~Calc_uCAdc_Leaf() {
	// TODO Auto-generated destructor stub
}

void Calc_uCAdc_Leaf::IncChnlVal()
{
	if(myChnl < 11)myChnl++;
}
void Calc_uCAdc_Leaf::DecChnlVal()
{
	if(myChnl > 0)myChnl--;
}

uint16_t Calc_uCAdc_Leaf::GetChnlVal()
{
	return myChnl;
}

float Calc_uCAdc_Leaf::GetAdc()
{
	return value;
}

void Calc_uCAdc_Leaf::SetChnlSel(uint16_t sel)
{
    if(sel >= 11) sel = 11;
    myChnl = sel;
}

void Calc_uCAdc_Leaf::Serialize(SerializeDest_I* SerDest)
{
	SerDest->SaveUint16(ADCuC_TYP);
	SerDest->SaveUint16(myChnl);
}

void Calc_uCAdc_Leaf::Deserialize(SerializeDest_I* SerDest)
{
	myChnl = SerDest->GetUint16();
}
