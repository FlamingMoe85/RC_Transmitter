#ifndef SRC_CSTMSW_LEAF_UI_H
#define SRC_CSTMSW_LEAF_UI_H

#include <QWidget>

#include "Base_Triplet_Ui.h"
#include "../../share/Graph_App/Src_CstmSw_Leaf.h"

class Src_CstmSw_Leaf_Ui : public Base_Triplet_Ui
{
     Q_OBJECT
public:
    Src_CstmSw_Leaf_Ui();
     void SetRef(Src_CstmSw_Leaf* ref);
     void RefreshChildArea();

private:
    Src_CstmSw_Leaf* myRef;
    Scroll_Triplet* scrollAreaRef;

private slots:
    void Slot_SpinBx2(double spnVal, unsigned int sel);
    void Slot_SpinBx3(double spnVal, unsigned int sel);
    void Slot_AddPos();

};

#endif // SRC_CSTMSW_LEAF_UI_H
