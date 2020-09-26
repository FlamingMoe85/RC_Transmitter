#ifndef SCROLLAREAVERT_H
#define SCROLLAREAVERT_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include "Origin.h"

#define VERTICAL    1
#define HORIZONTAL  2

namespace Ui {
class ScrollAreaVert;
}

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class ScrollAreaVert : public QWidget
{
    Q_OBJECT

public:
    explicit ScrollAreaVert(QWidget *parent = 0, int orient = VERTICAL );
    ~ScrollAreaVert();

    void Resize(int width);
    void AddWidget(QWidget* w);
    unsigned int Count();
    QWidget* GetWidget(int sel);
    void DeleteWidget(int delSel);
    int GetWidth();
    int GetHeight();
    int GetScrolBarWidth();
    int GetScrolPos();
    int GetChildCnt();
    void SwapItems(int i, int j);
    void SetStretchFactors(unsigned int xStrt, unsigned int yStrt);

void Resize();

public slots:
    void DeleteElememnt(int delSel);

private:
    Ui::ScrollAreaVert *ui;
    QList<QWidget*> widgetList;
    int currentWidth;
    int currentHeight;
    int orientation;
    unsigned int xStretch;
    unsigned int yStretch;
};

#endif // SCROLLAREAVERT_H
