#include "Calc_Quantizer_Leaf_UI.h"

Calc_Quantizer_Leaf_UI::Calc_Quantizer_Leaf_UI()
{
    SetLabelText(C1PAR, "Position");
    SetLabelText(C2PAR, "Level");
    SetLabelText(C3PAR, "Value");
    SetLabelText(CLM1_TRI,"Postion");
    SetLabelText(CLM2_TRI, "Level");
    SetLabelText(CLM3_TRI, "Value");
    scrollAreaRef = GetScrollArea();

    //SetSpinBoxProps(0, 0, 1, 0, 0);

    connect(this, SIGNAL(Signal_SpinBx2(double,uint)),
            this, SLOT(Slot_SpinBx2(double,uint)));
    connect(this, SIGNAL(Signal_SpinBx3(double,uint)),
            this, SLOT(Slot_SpinBx3(double,uint)));
    connect(this, SIGNAL(Signal_NewItm()), this, SLOT(Slot_AddStep()));
}


void Calc_Quantizer_Leaf_UI::SetRef(Calc_Quantizer_Leaf* ref)
{
    myRef = ref;
    SetCurNode(ref);
    RefreshChildArea();
}


void Calc_Quantizer_Leaf_UI::RefreshChildArea()
{
    int childCnt = myRef->GetAmtOfPairs();
    int childItmCnt = scrollAreaRef->Count();
    int countDiff = childCnt - childItmCnt;
    char* nameArr;
    QString name;

    for(countDiff; countDiff > 0; countDiff--)
    {
        scrollAreaRef->AddWidget((QWidget*)new Helper_Triplet_Item());
    }

    for(countDiff; countDiff < 0; countDiff++)
    {
        scrollAreaRef->DeleteWidget(scrollAreaRef->Count()-1);
    }
    scrollAreaRef->Resize();

    for(int i=0; i<scrollAreaRef->Count(); i++)
    {
       ((Helper_Triplet_Item*)scrollAreaRef->GetWidget(i))->Set_Pos(QString::number(i));
       ((Helper_Triplet_Item*)scrollAreaRef->GetWidget(i))->Set_C2Par(QString::number(((double)(myRef->AddSgndToLevel(i, 0))/10)));
       ((Helper_Triplet_Item*)scrollAreaRef->GetWidget(i))->Set_C3Par(QString::number(((double)(myRef->AddSgndToLevelVal(i, 0)))/10));

    }
}

void Calc_Quantizer_Leaf_UI::Slot_SpinBx2(double spnVal, unsigned int sel)
{
    myRef->SetLevelAt(sel, (int16_t)(spnVal*10));
}

void Calc_Quantizer_Leaf_UI::Slot_SpinBx3(double spnVal, unsigned int sel)
{
    myRef->SetValAt(sel, (int16_t)(spnVal*10));
}

void Calc_Quantizer_Leaf_UI::Slot_AddStep()
{
    myRef->AddMark();
}
