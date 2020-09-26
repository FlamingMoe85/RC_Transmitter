#include "Strct_Junc_Node_UI.h"

Strct_Junc_Node_UI::Strct_Junc_Node_UI()
{

}

void Strct_Junc_Node_UI::SetJuncRef(Strct_Junc_Node* caller)
{
    myJuncRef = caller;
    SetTypeLabel("Junction");
    SetCurNode(caller);
    RefreshChildArea();
}
