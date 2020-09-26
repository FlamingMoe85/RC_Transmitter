#include "Strct_Multi_Sw_Node_UI.h"

Strct_Multi_Sw_Node_UI::Strct_Multi_Sw_Node_UI()
{
    SetSpecificWidget(&myCstmWidget);
    connect(&myCstmWidget, SIGNAL(Signal_Clicked()), this, SLOT(Slot_AddJunction()));
}

void Strct_Multi_Sw_Node_UI::SetMultiSwref(Strct_MultSw_Node* ref)
{
    myRef = ref;
    SetSpecificWidget(&myCstmWidget);
    SetTypeLabel("Multiswitch");
    SetCurNode(ref);
    RefreshChildArea();
}

void Strct_Multi_Sw_Node_UI::Slot_AddJunction()
{
    myRef->GetChildList()->AddEnd(new Strct_Junc_Node());
    RefreshChildArea();
}
