#include "Calc_ScaleSw_Leaf_Ui.h"

Calc_ScaleSw_Leaf_Ui::Calc_ScaleSw_Leaf_Ui()
{
    SetLabelText(C1PAR, "Position");
    SetLabelText(C2PAR, "Input");
    SetLabelText(C3PAR, "Scale");
    SetLabelText(CLM1,"Postion");
    SetLabelText(CLM2, "Input");
    SetLabelText(CLM3, "Scale");
    scrollAreaRef = GetScrollArea();

    SetSpinBoxProps(0, 0, 1, 0, 0);

    connect(this, SIGNAL(Signal_SpinBx2(double,uint)),
            this, SLOT(Slot_SpinBx2(double,uint)));
    connect(this, SIGNAL(Signal_SpinBx3(double,uint)),
            this, SLOT(Slot_SpinBx3(double,uint)));
    connect(this, SIGNAL(Signal_NewItm()), this, SLOT(Slot_AddStep()));
}
void Calc_ScaleSw_Leaf_Ui::SetRef(Calc_ScaleSw_Leaf* ref)
{
    myRef = ref;
    SetCurNode(ref);
    RefreshChildArea();
}


void Calc_ScaleSw_Leaf_Ui::RefreshChildArea()
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
       ((Helper_Triplet_Item*)scrollAreaRef->GetWidget(i))->Set_C3Par(QString::number(((double)(myRef->AddSgndToPairValPos(i, 0)))/10));

    }
}

void Calc_ScaleSw_Leaf_Ui::Slot_SpinBx2(double spnVal, unsigned int sel)
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
    myRef->SetIn(sel, (int16_t)checkInt);
}

void Calc_ScaleSw_Leaf_Ui::Slot_SpinBx3(double spnVal, unsigned int sel)
{
    myRef->SetValPos(sel, (int16_t)(spnVal*10));
}

void Calc_ScaleSw_Leaf_Ui::Slot_AddStep()
{
    myRef->AddChnlPair();
}
