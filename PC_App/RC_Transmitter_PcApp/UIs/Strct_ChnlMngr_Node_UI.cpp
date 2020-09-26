#include "Strct_ChnlMngr_Node_UI.h"

Strct_ChnlMngr_Node_UI::Strct_ChnlMngr_Node_UI()
{
    SetSpecificWidget(&saveLoadUi);
    connect(&saveLoadUi, SIGNAL(Signal_Save(Modell_Manager_Qt*)), this, SLOT(Slot_Save(Modell_Manager_Qt*)));
    connect(&saveLoadUi, SIGNAL(Signal_Load(Modell_Manager_Qt*)), this, SLOT(Slot_Load(Modell_Manager_Qt*)));
}

void Strct_ChnlMngr_Node_UI::SetChnlMngrRef(Strct_ChnlMngr_Node* ref)
{
    myRef = ref;
    SetTypeLabel("Channel Manager");
    SetCurNode(ref);
    RefreshChildArea();
    saveLoadUi.RefreshModelList();
}

void Strct_ChnlMngr_Node_UI::Slot_Save(Modell_Manager_Qt* modMngrRef)
{
    emit Signal_Save(modMngrRef);
}

void Strct_ChnlMngr_Node_UI::Slot_Load(Modell_Manager_Qt* modMngrRef)
{
    emit Signal_Load(modMngrRef);
}

void Strct_ChnlMngr_Node_UI::ClearPoolList()
{
    //myRef->ClearPoolList();
    RefreshPool();
}
