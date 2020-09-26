#ifndef STRCT_COMPO_NODE_UI_H
#define STRCT_COMPO_NODE_UI_H

#include "Base_PoolFac_Ui.h"
#include "Helper/Compo_Pool_Item.h"
#include "../../../share/Graph_App/Strct_Compo_Node.h"

class Strct_Compo_Node_UI : public Base_PoolFac_Ui
{
    Q_OBJECT
public:
    Strct_Compo_Node_UI();
    void SetStrctCmp_Ref(Strct_Compo_Node* caller);

private:

    Strct_Compo_Node* myNodeRef;

signals:
    void ShowMe(Strct_Compo_Node_UI*);

public slots:
};

#endif // STRCT_COMPO_NODE_UI_H
