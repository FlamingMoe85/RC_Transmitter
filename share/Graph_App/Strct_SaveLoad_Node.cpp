/*
 * Strct_SaveLoad_Node.cpp
 *
 *  Created on: 29.05.2019
 *      Author: Justus
 */

#include "Strct_SaveLoad_Node.h"
#include "../../uController/grlib_demo/utils/UtilClass.h"

Strct_SaveLoad_Node::Strct_SaveLoad_Node() {
	// TODO Auto-generated constructor stub
	this->FillNameArray(GetNameArr(), "Save / Load" , (uint16_t)11);
}

Strct_SaveLoad_Node::~Strct_SaveLoad_Node() {
	// TODO Auto-generated destructor stub
}

void Strct_SaveLoad_Node::SetModMngr(SerializeDest_I* mM)
{
	myModMngr = mM;
}

void Strct_SaveLoad_Node::PrepForOverwrite(uint32_t modNmbr)
{
	myModMngr->PrepForOverwrite(modNmbr);
}

void Strct_SaveLoad_Node::SaveMod(char* namAr)
{
	//UtilClass::SgndIntToStrng(&(namArr[0]), saveCntr++);
	myModMngr->NewModel();
    myModMngr->SaveName(namAr);
    //myModMngr->FinalSaveStrobe();
}

uint16_t Strct_SaveLoad_Node::GetAmtOfModels()
{
	return myModMngr->GetAmtOfModels();
}


uint16_t Strct_SaveLoad_Node::GetCurModNmbr()
{
	return myModMngr->GetCurModNmbr();
}

void Strct_SaveLoad_Node::GetNameOfModel(char* namArr, uint16_t modNmbr)
{
	myModMngr->GetNameOfModel(namArr, modNmbr);
}

uint16_t Strct_SaveLoad_Node::GetFreeSpacePerc()
{
	return ((myModMngr->GetAmtUsablelocks() - myModMngr->GetAmtUsedBlock())*1000)/myModMngr->GetAmtUsablelocks();
}

void Strct_SaveLoad_Node::Show(UI_Visitor_I* UiVisitor)
{
	myUiVisitor = UiVisitor;
	Show();
}

void Strct_SaveLoad_Node::Show()
{
	myUiVisitor->DispShowCall(this);
}

UI_Visitor_I* Strct_SaveLoad_Node::GetVisitor()
{
	return myUiVisitor;
}
