#ifndef BASE_QUADLET_UI_H
#define BASE_QUADLET_UI_H

#include <QWidget>

#include"Helper/Scroll_Quadlet.h"
#include"Helper/Helper_Quadlet_Item.h"
#include "../../../share/Graph_App/graph_app_i.h"
#include "../modfactory_qt.h"
#include "../Utils_Qt.h"

namespace Ui {
class Base_Quadlet_Ui;
}

class Base_Quadlet_Ui : public QWidget
{
    Q_OBJECT

public:
    explicit Base_Quadlet_Ui(QWidget *parent = nullptr);
    ~Base_Quadlet_Ui();

    void SetCurNode(Graph_App_I* cN);

    void SetLabelText(unsigned int labelSel, QString txt);
    void SetSpinBoxProps(unsigned int spnBxSel, unsigned int digits, double stepSize, double min, double val);
    Scroll_Quadlet* GetScrollArea();

signals:
    void Signal_NewItm();
    void Signal_SpinBx2(double spnVal, unsigned int sel);
    void Signal_SpinBx3(double spnVal, unsigned int sel);
    void Signal_SpinBx4(double spnVal, unsigned int sel);


private:
    Ui::Base_Quadlet_Ui *ui;

    Graph_App_I* myCurNode;

    Scroll_Quadlet quadletScrollArea;
    Helper_Quadlet_Item* curItem;

    unsigned int myCurSelItem;



#define C1PAR 0
#define C2PAR 1
#define C3PAR 2
#define C4PAR 3
#define  CLM1_QUAD 4
#define  CLM2_QUAD 5
#define  CLM3_QUAD 6
#define  CLM4_QUAD 7

private slots:
    void Slot_Esc();
    void Slot_NewItm();
    void Slot_SpinBx2(double spnVal);
    void Slot_SpinBx3(double spnVal);
    void Slot_SpinBx4(double spnVal);
    void Slot_ItemSel(unsigned int itmSel);
};

#endif // BASE_QUADLET_UI_H
