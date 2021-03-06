#ifndef CALC_SCALESW_LEAF_UI_H
#define CALC_SCALESW_LEAF_UI_H

#include <QObject>
#include "Base_Quadlet_Ui.h"
#include "../../share/Graph_App/Calc_ScaleSw_Leaf.h"

class Calc_ScaleSw_Leaf_Ui : public Base_Quadlet_Ui
{
    Q_OBJECT
public:
    Calc_ScaleSw_Leaf_Ui();

    void SetRef(Calc_ScaleSw_Leaf* ref);
    void RefreshChildArea();


private:
    Calc_ScaleSw_Leaf* myRef;
    Scroll_Quadlet* scrollAreaRef;

private slots:
    void Slot_SpinBx2(double spnVal, unsigned int sel);
    void Slot_SpinBx3(double spnVal, unsigned int sel);
    void Slot_SpinBx4(double spnVal, unsigned int sel);
    void Slot_AddStep();
};

#endif // CALC_SCALESW_LEAF_UI_H
