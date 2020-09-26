#ifndef STRCT_JUNC_NODE_UI_H
#define STRCT_JUNC_NODE_UI_H

#include <QObject>
#include "Base_PoolFac_Ui.h"
#include "../../../share/Graph_App/Strct_Junc_Node.h"

class Strct_Junc_Node_UI : public Base_PoolFac_Ui
{
public:
    Strct_Junc_Node_UI();
    void SetJuncRef(Strct_Junc_Node* caller);

private:
    Strct_Junc_Node* myJuncRef;
};

#endif // STRCT_JUNC_NODE_UI_H
