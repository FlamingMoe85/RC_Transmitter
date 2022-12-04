#ifndef BASE_TRIPLET_UI_H
#define BASE_TRIPLET_UI_H

#include <QWidget>
#include <QString>

#include"Helper/Scroll_Triplet.h"
#include"Helper/Helper_Triplet_Item.h"
#include "../../../share/Graph_App/graph_app_i.h"
#include "../modfactory_qt.h"
#include "../Utils_Qt.h"

namespace Ui {
class Base_Triplet_Ui;
}

class Base_Triplet_Ui : public QWidget, public Utils_Qt
{
    Q_OBJECT

public:
    explicit Base_Triplet_Ui(QWidget *parent = 0);
    ~Base_Triplet_Ui();

    void SetCurNode(Graph_App_I* cN);
    void SetLabelText(unsigned int labelSel, QString txt);
    void SetSpinBoxProps(unsigned int spnBxSel, unsigned int digits, double stepSize, double min, double val);
    Scroll_Triplet* GetScrollArea();

signals:
    void Signal_NewItm();
    void Signal_SpinBx2(double spnVal, unsigned int sel);
    void Signal_SpinBx3(double spnVal, unsigned int sel);


private:
    Ui::Base_Triplet_Ui *ui;

    Graph_App_I* myCurNode;

    Scroll_Triplet tripletScrollArea;
    Helper_Triplet_Item* curItem;

    unsigned int myCurSelItem;



#define C1PAR 0
#define C2PAR 1
#define C3PAR 2
#define CLM1_TRI 3
#define CLM2_TRI 4
#define CLM3_TRI 5

private slots:
    void Slot_Esc();
    void Slot_NewItm();
    void Slot_SpinBx2(double spnVal);
    void Slot_SpinBx3(double spnVal);
    void Slot_ItemSel(unsigned int itmSel);
};

#endif // BASE_TRIPLET_UI_H
