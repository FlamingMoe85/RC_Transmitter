#ifndef VERTCUSTOMSLIDER_H
#define VERTCUSTOMSLIDER_H

#include <QWidget>

namespace Ui {
class VertCustomSlider;
}

class VertCustomSlider : public QWidget
{
    Q_OBJECT

public:
    explicit VertCustomSlider(QWidget *parent = 0);
    ~VertCustomSlider();

private:
    Ui::VertCustomSlider *ui;
};

#endif // VERTCUSTOMSLIDER_H
