#ifndef STRCT_MULTI_SW_NODE_UI_H
#define STRCT_MULTI_SW_NODE_UI_H

#include <QObject>
#include "Base_PoolFac_Ui.h"
#include "Helper/Helper_MultiSw.h"
#include "../../share/Graph_App/Strct_MultSw_Node.h"
#include "../../share/Graph_App/Strct_Junc_Node.h"

class Strct_Multi_Sw_Node_UI : public Base_PoolFac_Ui
{
    Q_OBJECT
public:
    Strct_Multi_Sw_Node_UI();
    void SetMultiSwref(Strct_MultSw_Node* ref);

private:
    Helper_MultiSw myCstmWidget;
    Strct_MultSw_Node* myRef;

private slots:
    void Slot_AddJunction();
};

#endif // STRCT_MULTI_SW_NODE_UI_H
