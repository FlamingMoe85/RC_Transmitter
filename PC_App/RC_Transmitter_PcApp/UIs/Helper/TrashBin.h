#ifndef TRASHBIN_H
#define TRASHBIN_H

#include <QWidget>

namespace Ui {
class TrashBin;
}

#define TRASH   0
#define ROCKET  1

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class TrashBin : public QWidget
{
    Q_OBJECT

public:
    explicit TrashBin(QWidget *parent = 0);
    ~TrashBin();

    void DefinePixMap(int pixSel);

private:
    Ui::TrashBin *ui;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

signals:

    void DelElement(int);
};

#endif // TRASHBIN_H
