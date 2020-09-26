#ifndef CALC_UCADC_LEAF_UI_H
#define CALC_UCADC_LEAF_UI_H

#include <QWidget>
#include "../../share/Graph_App/Calc_uCAdc_Leaf.h"

namespace Ui {
class Calc_uCAdc_Leaf_UI;
}

class Calc_uCAdc_Leaf_UI : public QWidget
{
    Q_OBJECT

public:
    explicit Calc_uCAdc_Leaf_UI(QWidget *parent = 0);
    ~Calc_uCAdc_Leaf_UI();

    void SetRef(Calc_uCAdc_Leaf* ref);

private:
    Ui::Calc_uCAdc_Leaf_UI *ui;
    Calc_uCAdc_Leaf* myRef;

private slots:
    void Slot_Esc();
    void Slot_SpinValChng(int);
};

#endif // CALC_UCADC_LEAF_UI_H
