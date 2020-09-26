#ifndef CALC_QUANTIZER_LEAF_UI_H
#define CALC_QUANTIZER_LEAF_UI_H

#include <QObject>
#include "Base_Triplet_Ui.h"
#include "../../share/Graph_App/Calc_Quantizer_Leaf.h"

class Calc_Quantizer_Leaf_UI : public Base_Triplet_Ui
{
    Q_OBJECT
public:
    Calc_Quantizer_Leaf_UI();
    void SetRef(Calc_Quantizer_Leaf* ref);
    void RefreshChildArea();


private:
    Calc_Quantizer_Leaf* myRef;
    Scroll_Triplet* scrollAreaRef;

private slots:
    void Slot_SpinBx2(double spnVal, unsigned int sel);
    void Slot_SpinBx3(double spnVal, unsigned int sel);
    void Slot_AddStep();
};

#endif // CALC_QUANTIZER_LEAF_UI_H
