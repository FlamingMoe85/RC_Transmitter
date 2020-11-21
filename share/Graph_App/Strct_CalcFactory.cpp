/*
 * Strct_CalcFactory.cpp
 *
 *  Created on: 04.05.2019
 *      Author: Justus
 */

#include "Strct_CalcFactory.h"

Strct_CalcFactory::Strct_CalcFactory() {
	// TODO Auto-generated constructor stub
this->FillNameArray(GetNameArr(), "Calc Fac", 8);

addDummy.FillNameArray(addDummy.GetNameArr(), "Add", 3);
this->GetChildList()->AddEnd(&addDummy);

mulDummy.FillNameArray(mulDummy.GetNameArr(), "Mul", 3);
this->GetChildList()->AddEnd(&mulDummy);

adcDummy.FillNameArray(adcDummy.GetNameArr(), "ADC Chnl", 8);
this->GetChildList()->AddEnd(&adcDummy);

cstmSwDummy.FillNameArray(cstmSwDummy.GetNameArr(), "Custom Switch", 13);
this->GetChildList()->AddEnd(&cstmSwDummy);

cstmSwDummy.FillNameArray(intTrimDummy.GetNameArr(), "Trim", 4);
this->GetChildList()->AddEnd(&intTrimDummy);

timeCalcRampDummy.FillNameArray(timeCalcRampDummy.GetNameArr(), "Ramp", 4);
this->GetChildList()->AddEnd(&timeCalcRampDummy);

timeBlinkDummy.FillNameArray(timeBlinkDummy.GetNameArr(), "Blinker", 7);
this->GetChildList()->AddEnd(&timeBlinkDummy);

scaleSwDummy.FillNameArray(scaleSwDummy.GetNameArr(), "Scale Switch", 12);
this->GetChildList()->AddEnd(&scaleSwDummy);

quantizerDummy.FillNameArray(quantizerDummy.GetNameArr(), "Quantizer", 9);
this->GetChildList()->AddEnd(&quantizerDummy);

deadSpanDummy.FillNameArray(deadSpanDummy.GetNameArr(), "Dead Span", 9);
this->GetChildList()->AddEnd(&deadSpanDummy);

limiterDummy.FillNameArray(limiterDummy.GetNameArr(), "Limiter", 7);
this->GetChildList()->AddEnd(&limiterDummy);

expo1Dummy.FillNameArray(expo1Dummy.GetNameArr(), "Expo 1", 6);
this->GetChildList()->AddEnd(&expo1Dummy);

dynSclDummy.FillNameArray(dynSclDummy.GetNameArr(), "Dyn Scale", 9);
this->GetChildList()->AddEnd(&dynSclDummy);
}

Strct_CalcFactory::~Strct_CalcFactory() {
	// TODO Auto-generated destructor stub
}



void Strct_CalcFactory::Run(float* val, uint32_t itteration)
{

}

void Strct_CalcFactory::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Strct_CalcFactory::GetVisitor()
{
	return myUiVisitor;
}

void Strct_CalcFactory::Show()
{
	myUiVisitor->DispShowCall(this);
}


void Strct_CalcFactory::Serialize(SerializeDest_I* SerDest)
{

}

void Strct_CalcFactory::Deserialize(SerializeDest_I* SerDest)
{

}

void Strct_CalcFactory::NullSerCntr()
{

}
