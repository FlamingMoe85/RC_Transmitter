#ifndef ORIGIN_H
#define ORIGIN_H

#include <QWidget>

namespace Ui {
class Origin;
}

class Origin : public QWidget
{
    Q_OBJECT

public:
    explicit Origin(QWidget *parent = 0, int type = 'a');
    ~Origin();

    int GetType();
    const QPixmap* pixmap();

private:
    Ui::Origin *ui;
    int myType;
};

#endif // ORIGIN_H
