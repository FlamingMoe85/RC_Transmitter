#ifndef STRCT_CHNL_NODE_UI_H
#define STRCT_CHNL_NODE_UI_H

#include <QObject>
#include "Base_PoolFac_Ui.h"
#include "../../share/Graph_App/Strct_Chnl_Node.h"
#include "UIs/Helper/Helper_ChannelNode.h"
#include "../../share/Graph_App/Strct_MultSw_Node.h"

class Strct_Chnl_Node_UI : public Base_PoolFac_Ui
{
    Q_OBJECT
public:
    Strct_Chnl_Node_UI();

    void SetChnlRef(Strct_Chnl_Node* ref);

private:
    Helper_ChannelNode myCstmWidget;
    Strct_Chnl_Node* myRef;

private slots:
    void Slot_AddSlot();
};

#endif // STRCT_CHNL_NODE_UI_H
