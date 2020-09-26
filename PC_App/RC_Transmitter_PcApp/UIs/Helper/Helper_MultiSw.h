#ifndef HELPER_MULTISW_H
#define HELPER_MULTISW_H

#include <QWidget>

namespace Ui {
class Helper_MultiSw;
}

class Helper_MultiSw : public QWidget
{
    Q_OBJECT

public:
    explicit Helper_MultiSw(QWidget *parent = 0);
    ~Helper_MultiSw();

signals:
    void Signal_Clicked();

private slots:
    void Slot_Clicked();

private:
    Ui::Helper_MultiSw *ui;
};

#endif // HELPER_MULTISW_H
