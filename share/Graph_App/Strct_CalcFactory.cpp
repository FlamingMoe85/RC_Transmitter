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


machineList.AddEnd(&adcMachine);
machineList.AddEnd(&cstmSwMachine);
machineList.AddEnd(&sclSwMachine);
machineList.AddEnd(&blinkMach);
machineList.AddEnd(&deadAreaMach);
machineList.AddEnd(&dynScaleMach);
machineList.AddEnd(&expo1Mach);
machineList.AddEnd(&integrMach);
machineList.AddEnd(&internTrimMach);
machineList.AddEnd(&quantMach);
machineList.AddEnd(&limiterMach);
machineList.AddEnd(&rampMach);
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

char* Strct_CalcFactory::GetNameOfMachIndex(uint16_t index)
{
	return machineList.At(index)->GetNameArr();
}

uint16_t Strct_CalcFactory::GetAmtOfMachines()
{
	return machineList.Count();
}

uint16_t Strct_CalcFactory::GetMachTypeByIndex(uint16_t index)
{
	return machineList.At(index)->GetType();
}

void Strct_CalcFactory::AddModuleToEntryByType(uint16_t t)
{
	for(uint16_t typeToIndex = 0; typeToIndex < machineList.Count(); typeToIndex++)
	{
		if(machineList.At(typeToIndex)->GetType() == t)
		{
			this->GetEntry()->GetChildList()->AddEnd(machineList.At(typeToIndex)->GetInstance());
			break;
		}
	}

}

Graph_App_I* Strct_CalcFactory::GetModuleByType(uint16_t t)
{
	for(uint16_t typeToIndex = 0; typeToIndex < machineList.Count(); typeToIndex++)
	{
		if(machineList.At(typeToIndex)->GetType() == t)
		{
			return machineList.At(typeToIndex)->GetInstance();
		}
	}
}
