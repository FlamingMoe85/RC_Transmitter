#include "Time_Blinker_Leaf_UI.h"

Time_Blinker_Leaf_UI::Time_Blinker_Leaf_UI()
{
    SetLabelText(C1PAR, "Step");
    SetLabelText(C2PAR, "Duration");
    SetLabelText(C3PAR, "Value");
    SetLabelText(CLM1,"Step");
    SetLabelText(CLM2, "Duration");
    SetLabelText(CLM3, "Value");
    scrollAreaRef = GetScrollArea();

    SetSpinBoxProps(0, 0, 1, 0, 0);

    connect(this, SIGNAL(Signal_SpinBx2(double,uint)),
            this, SLOT(Slot_SpinBx2(double,uint)));
    connect(this, SIGNAL(Signal_SpinBx3(double,uint)),
            this, SLOT(Slot_SpinBx3(double,uint)));
    connect(this, SIGNAL(Signal_NewItm()), this, SLOT(Slot_AddStep()));
}

void Time_Blinker_Leaf_UI::SetRef(Time_Blinker_Leaf* ref)
{
    myRef = ref;
    SetCurNode(ref);
    RefreshChildArea();
}


void Time_Blinker_Leaf_UI::RefreshChildArea()
{
    int childCnt = myRef->GetAmtOfSlots();
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
       ((Helper_Triplet_Item*)scrollAreaRef->GetWidget(i))->Set_C2Par(QString::number(myRef->AddSgndToSlotDur(i, 0)));
       ((Helper_Triplet_Item*)scrollAreaRef->GetWidget(i))->Set_C3Par(QString::number(((double)(myRef->AddSgndToSlotVal(i, 0)))/10));

    }
}

void Time_Blinker_Leaf_UI::Slot_SpinBx2(double spnVal, unsigned int sel)
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
    myRef->SetBlnkDur(sel, (int16_t)checkInt);
}

void Time_Blinker_Leaf_UI::Slot_SpinBx3(double spnVal, unsigned int sel)
{
    myRef->SetBlnkVal(sel, (int16_t)(spnVal*10));
}

void Time_Blinker_Leaf_UI::Slot_AddStep()
{
    myRef->AddSlot();
}
