#include "Strct_Chnl_Node_UI.h"

Strct_Chnl_Node_UI::Strct_Chnl_Node_UI()
{
    SetSpecificWidget(&myCstmWidget);
    connect(&myCstmWidget, SIGNAL(Signal_Clicked()), this, SLOT(Slot_AddSlot()));
}

void Strct_Chnl_Node_UI::SetChnlRef(Strct_Chnl_Node* ref)
{
    myRef = ref;
    SetSpecificWidget(&myCstmWidget);
    SetTypeLabel("Channel");
    SetCurNode(ref);
    RefreshChildArea();
}

void Strct_Chnl_Node_UI::Slot_AddSlot()
{
    myRef->GetChildList()->AddEnd(new Strct_MultSw_Node());
    myRef->GetChildList()->At(myRef->GetChildList()->Count()-1)->FillNameArray(myRef->GetChildList()->At(myRef->GetChildList()->Count()-1)->GetNameArr(), "Slot", 4);
    RefreshChildArea();
}
