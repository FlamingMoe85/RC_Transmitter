#ifndef TIME_BLINKER_LEAF_UI_H
#define TIME_BLINKER_LEAF_UI_H

#include <QObject>

#include "Base_Triplet_Ui.h"
#include "../../share/Graph_App/Time_Blinker_Leaf.h"

class Time_Blinker_Leaf_UI : public Base_Triplet_Ui
{
    Q_OBJECT
public:
    Time_Blinker_Leaf_UI();

    void SetRef(Time_Blinker_Leaf* ref);
    void RefreshChildArea();


private:
    Time_Blinker_Leaf* myRef;
    Scroll_Triplet* scrollAreaRef;

private slots:
    void Slot_SpinBx2(double spnVal, unsigned int sel);
    void Slot_SpinBx3(double spnVal, unsigned int sel);
    void Slot_AddStep();
};

#endif // TIME_BLINKER_LEAF_UI_H
