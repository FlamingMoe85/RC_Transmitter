#ifndef CALC_MULTIPLICATION_LEAF_UI_H
#define CALC_MULTIPLICATION_LEAF_UI_H

#include <QWidget>
#include "../../share/Graph_App/Calc_Multiplication_Leaf.h"

namespace Ui {
class Calc_Multiplication_Leaf_UI;
}

class Calc_Multiplication_Leaf_UI : public QWidget
{
    Q_OBJECT

public:
    explicit Calc_Multiplication_Leaf_UI(QWidget *parent = 0);
    ~Calc_Multiplication_Leaf_UI();

    void SetRef(Calc_Multiplication_Leaf* ref);

private:
    Ui::Calc_Multiplication_Leaf_UI *ui;
    Calc_Multiplication_Leaf* myRef;

private slots:
    void Slot_Esc();
    void Slot_SpinValChng(double);
};

#endif // CALC_MULTIPLICATION_LEAF_UI_H
