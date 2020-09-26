#ifndef STRCT_CHNLMNGR_NODE_UI_H
#define STRCT_CHNLMNGR_NODE_UI_H

#include <QObject>
#include "Base_PoolFac_Ui.h"
#include "../../share/Graph_App/Strct_ChnlMngr_Node.h"
#include "../../share/Graph_App/Strct_Chnl_Node.h"
#include "../Save_Load_Ui.h"

class Strct_ChnlMngr_Node_UI : public Base_PoolFac_Ui
{
    Q_OBJECT
public:
    Strct_ChnlMngr_Node_UI();
    void SetChnlMngrRef(Strct_ChnlMngr_Node* ref);
    void ClearPoolList();

private:
    Strct_ChnlMngr_Node* myRef;
    Save_Load_Ui saveLoadUi;

signals:
    void Signal_Save(Modell_Manager_Qt* modMngrRef);
    void Signal_Load(Modell_Manager_Qt* modMngrRef);

private slots:
    void Slot_Save(Modell_Manager_Qt* modMngrRef);
    void Slot_Load(Modell_Manager_Qt* modMngrRef);
};

#endif // STRCT_CHNLMNGR_NODE_UI_H
