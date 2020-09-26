#include "Src_CstmSw_Leaf_Ui.h"

#include <QDebug>

Src_CstmSw_Leaf_Ui::Src_CstmSw_Leaf_Ui()
{
    SetLabelText(C1PAR, "Position");
    SetLabelText(C2PAR, "Input");
    SetLabelText(C3PAR, "Value");
    SetLabelText(CLM1,"Position");
    SetLabelText(CLM2, "Input");
    SetLabelText(CLM3, "Value");
    scrollAreaRef = GetScrollArea();

    SetSpinBoxProps(0, 0, 1, 0, 0);

    connect(this, SIGNAL(Signal_SpinBx2(double,uint)),
            this, SLOT(Slot_SpinBx2(double,uint)));
    connect(this, SIGNAL(Signal_SpinBx3(double,uint)),
            this, SLOT(Slot_SpinBx3(double,uint)));
    connect(this, SIGNAL(Signal_NewItm()), this, SLOT(Slot_AddPos()));
}


void Src_CstmSw_Leaf_Ui::SetRef(Src_CstmSw_Leaf* ref)
{
    myRef = ref;
    SetCurNode(ref);
    RefreshChildArea();
}


void Src_CstmSw_Leaf_Ui::RefreshChildArea()
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
       ((Helper_Triplet_Item*)scrollAreaRef->GetWidget(i))->Set_C2Par(QString::number(myRef->AddSgndToPairIn(i, 0)));
       ((Helper_Triplet_Item*)scrollAreaRef->GetWidget(i))->Set_C3Par(QString::number(((double)(myRef->AddSgndToPairVal(i, 0)))/10));

    }
}

void Src_CstmSw_Leaf_Ui::Slot_AddPos()
{
    myRef->AddChnlPair();
}

void Src_CstmSw_Leaf_Ui::Slot_SpinBx2(double spnVal, unsigned int sel)
{
    int checkInt = (int)(spnVal);
    double checkDblOld = (double)checkInt, checkDblNew;
    if(spnVal > 0)
    {
        if(checkDblOld < spnVal)
        {
            checkInt++;
            /*
            checkDblNew = (double)checkInt;
            if((spnVal - checkDblOld) < (checkDblNew - spnVal))checkInt--;
            */
        }
    }
    else if(spnVal < 0)
    {

    }
    myRef->SetPairIn(sel, (int16_t)checkInt);
}

void Src_CstmSw_Leaf_Ui::Slot_SpinBx3(double spnVal, unsigned int sel)
{

    myRef->SetPairVal(sel, (int16_t)(spnVal*10));
}
