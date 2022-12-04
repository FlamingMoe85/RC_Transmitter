#include "Calc_Multiplication_Leaf.h"


Calc_Multiplication_Leaf::Calc_Multiplication_Leaf()
{
    //nameArr = "Scale";
    this->FillNameArray(GetNameArr(), "Scale", 5);
    myMulVal = 1000;
    myMulVal_F = myMulVal;
    SetType(MULT_TYP);
}

void Calc_Multiplication_Leaf::Show(UI_Visitor_I *UiVisitor)
{
	myUiVisitor = UiVisitor;
    UiVisitor->DispShowCall(this);
}

UI_Visitor_I* Calc_Multiplication_Leaf::GetVisitor()
{
	return myUiVisitor;
}

void Calc_Multiplication_Leaf::Run(float* val, uint32_t itteration)
{
    (void)itteration;
     *val = ((*val) * myMulVal_F) / 1000.0;
}

void Calc_Multiplication_Leaf::SetMulVal(int16_t mulVal)
{
    myMulVal = mulVal;
    myMulVal_F = myMulVal;
}

int16_t Calc_Multiplication_Leaf::GetMulVal()
{
    return myMulVal;
}

void Calc_Multiplication_Leaf::Serialize(SerializeDest_I* SerDest)
{
	SerDest->SaveUint16(MULT_TYP);
    SerDest->SaveInt16(myMulVal);
}

void Calc_Multiplication_Leaf::Deserialize(SerializeDest_I* SerDest)
{
    myMulVal = SerDest->GetInt16();
    myMulVal_F = myMulVal;
}

void Calc_Multiplication_Leaf::NullSerCntr()
{

}
