#ifndef BASE_QUADLET_UI_H
#define BASE_QUADLET_UI_H

#include <QWidget>

namespace Ui {
class Base_Quadlet_Ui;
}

class Base_Quadlet_Ui : public QWidget
{
    Q_OBJECT

public:
    explicit Base_Quadlet_Ui(QWidget *parent = nullptr);
    ~Base_Quadlet_Ui();

private:
    Ui::Base_Quadlet_Ui *ui;
};

#endif // BASE_QUADLET_UI_H
