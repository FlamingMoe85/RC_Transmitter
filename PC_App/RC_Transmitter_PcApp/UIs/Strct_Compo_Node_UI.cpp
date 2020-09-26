#include "Strct_Compo_Node_UI.h"

Strct_Compo_Node_UI::Strct_Compo_Node_UI()
{
     /*Strct_Compo_Node* compNodePtr;


    myNodeRef = new Strct_Compo_Node();
    SetCurNode(myNodeRef);

    compNodePtr = new Strct_Compo_Node();
    compNodePtr->FillNameArray(compNodePtr->GetNameArr(), "Compo 1", 7);
    GetPoolUtils()->AddToPoolLstEnd(compNodePtr);

    compNodePtr = new Strct_Compo_Node();
    compNodePtr->FillNameArray(compNodePtr->GetNameArr(), "Compo 2", 7);
    GetPoolUtils()->AddToPoolLstEnd(compNodePtr);

    compNodePtr = new Strct_Compo_Node();
    compNodePtr->FillNameArray(compNodePtr->GetNameArr(), "Compo 3", 7);
    GetPoolUtils()->AddToPoolLstEnd(compNodePtr);

    compNodePtr = new Strct_Compo_Node();
    compNodePtr->FillNameArray(compNodePtr->GetNameArr(), "Compo 4", 7);
    GetPoolUtils()->AddToPoolLstEnd(compNodePtr);
*/


}

void Strct_Compo_Node_UI::SetStrctCmp_Ref(Strct_Compo_Node* caller)
{
    myNodeRef = caller;
    SetTypeLabel("Composition");
    SetCurNode(caller);
    RefreshChildArea();
    //emit ShowMe(this);
}



