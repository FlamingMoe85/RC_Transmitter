#ifndef QT_CONTROLCOCKPIT_H
#define QT_CONTROLCOCKPIT_H

#include <QWidget>
#include "Qt_ControlKnop.h"

namespace Ui {
class Qt_ControlCockpit;
}

class Qt_ControlCockpit : public QWidget
{
    Q_OBJECT

public:
    explicit Qt_ControlCockpit(QWidget *parent = 0);
    ~Qt_ControlCockpit();

    float GetRight_X();
    float GetRight_Y();
    unsigned int GetDigitals();

private:
    Ui::Qt_ControlCockpit *ui;

    Qt_ControlKnop knopRight;
    float rightX, rightY;
    unsigned int switches;

private slots:
    void Slot_Neutral();
    void Slot_KnopMove(float, float);

    void Slot_Sw7();
    void Slot_Sw7_8();
    void Slot_Sw8();
};

#endif // QT_CONTROLCOCKPIT_H
