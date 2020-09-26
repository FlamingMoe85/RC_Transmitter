#include "Calc_Addition_Leaf.h"

Calc_Addition_Leaf::Calc_Addition_Leaf()
{
    myAddVal = 0;
    myAddVal_F =0;
    //nameArr = "Offset";
    this->FillNameArray(GetNameArr(), "Offset", 6);
}

void Calc_Addition_Leaf::Run(float* val, uint32_t itteration)
{
    *val += myAddVal_F;
}

void Calc_Addition_Leaf::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Calc_Addition_Leaf::GetVisitor()
{
	return myUiVisitor;
}

void Calc_Addition_Leaf::Show()
{
	myUiVisitor->DispShowCall(this);
}

void Calc_Addition_Leaf::SetSgndAddVal(int16_t addVal)
{
    myAddVal = addVal;
    myAddVal_F = myAddVal;
}

int16_t Calc_Addition_Leaf::GetSgndAddVal()
{
    return myAddVal;
}

void Calc_Addition_Leaf::AddSgndVal(int16_t addVal)
{
	myAddVal += addVal;
    myAddVal_F = myAddVal;
}

void Calc_Addition_Leaf::Serialize(SerializeDest_I* SerDest)
{
   	SerDest->SaveUint16(ADD_TYP);
    SerDest->SaveInt16(myAddVal);
}

void Calc_Addition_Leaf::Deserialize(SerializeDest_I* SerDest)
{
    myAddVal = SerDest->GetInt16();
    myAddVal_F = myAddVal;
}

void Calc_Addition_Leaf::NullSerCntr()
{

}
