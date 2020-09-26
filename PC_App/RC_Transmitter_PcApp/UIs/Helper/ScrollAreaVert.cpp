#include "ScrollAreaVert.h"
#include "ui_ScrollAreaVert.h"
#include <QRect>
#include <QDebug>
#include <QScrollBar>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QPoint>

ScrollAreaVert::ScrollAreaVert(QWidget *parent,int orient) :
    QWidget(parent),
    ui(new Ui::ScrollAreaVert)
{
    ui->setupUi(this);
    currentWidth = 30;
    QWidget *w = new QWidget();
    ui->scrollArea->setWidget(w);
    if(orient == VERTICAL)
    {
        ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }
    else
    {
        ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    }
    orientation = orient;
    xStretch = 1;
    yStretch = 1;
}

ScrollAreaVert::~ScrollAreaVert()
{
    delete ui;
}

void ScrollAreaVert::SetStretchFactors(unsigned int xStrt, unsigned int yStrt)
{
   if(xStrt == 0)xStrt = 1;
   if(yStrt == 0)yStrt = 1;
   xStretch = xStrt;
   yStretch = yStrt;
   Resize();
}

void ScrollAreaVert::DeleteElememnt(int delSel)
{
    Origin *delOrig;
    if(delSel >= widgetList.count()) return;
    widgetList.at(delSel)->setParent(0);
    widgetList.takeAt(delSel)->deleteLater();
 /*
    for(int i=0; i<widgetList.count(); i++)
    {
       qDebug() << "GetType "<<  widgetList.at(i)->GetType();
    }
   */
    Resize();
}

void ScrollAreaVert::Resize(int width)
{
    QRect r;



    if(orientation == VERTICAL)
    {
        for(int i=0; i<widgetList.count(); i++)
        {
            r.setX(0);
            currentHeight = (width*yStretch)/xStretch;
            currentWidth = width;
            r.setY(((width*yStretch)/xStretch)*(i));
            r.setHeight((width*yStretch)/xStretch);
            r.setWidth(width);
            widgetList.at(i)->setGeometry(r);
            widgetList.at(i)->show();
        }
    }
    else if(orientation == HORIZONTAL)
    {
        for(int i=0; i<widgetList.count(); i++)
        {

            currentHeight = width;
            currentWidth = ((width*yStretch)/xStretch);
            r.setX(((width*yStretch)/xStretch)*(i));
            r.setY(0);
            r.setHeight(width);
            r.setWidth((width*yStretch)/xStretch);
            widgetList.at(i)->setGeometry(r);
            widgetList.at(i)->show();
        }
    }
    if(widgetList.count() == 0)
    {
        ui->scrollArea->widget()->resize(1,1);//(width, width);
    }
    else
    {
        if(orientation == VERTICAL)
        {
            ui->scrollArea->widget()->resize(width, (width/xStretch)*widgetList.count());
        }
        else if(orientation == HORIZONTAL)
        {
            ui->scrollArea->widget()->resize((width/xStretch)*widgetList.count(),width);
        }
    }


    ui->scrollArea->update();
}

void ScrollAreaVert::AddWidget(QWidget *w)
{
    widgetList.append(w);
    w->setParent(ui->scrollArea->widget());
}

QWidget *ScrollAreaVert::GetWidget(int sel)
{
    if(sel < widgetList.count()) return widgetList.at(sel);
    return 0;
}

void ScrollAreaVert::DeleteWidget(int delSel)
{
    QWidget* delW;
    if(delSel >= widgetList.count()) return;
    delW = widgetList.takeAt(delSel);
    delW->deleteLater();
}

void ScrollAreaVert::SwapItems(int i, int j)
{
   if(j >= widgetList.count()) j = widgetList.count()-1;
   widgetList.swap(i, j);
}

void ScrollAreaVert::Resize()
{
    Resize(width());
}

int ScrollAreaVert::GetScrolBarWidth()
{
   if(orientation == VERTICAL)
   {
        QScrollBar *sB =  ui->scrollArea->verticalScrollBar();
        return sB->width();
   }
   {
      QScrollBar *sB =  ui->scrollArea->horizontalScrollBar();
      return sB->width();
   }
}

int ScrollAreaVert::GetScrolPos()
{
    if(orientation == VERTICAL)
    {
        return ui->scrollArea->verticalScrollBar()->value();
    }
    else
    {
        return 0;
        if(ui->scrollArea->horizontalScrollBar()->value() > 0)
        {
            return ui->scrollArea->horizontalScrollBar()->value();
        }
        return 0;
    }
}

int ScrollAreaVert::GetChildCnt()
{
    return widgetList.count();
}

int ScrollAreaVert::GetWidth()
{
    return currentWidth;
}

int ScrollAreaVert::GetHeight()
{
    return currentHeight;
}

unsigned int ScrollAreaVert::Count()
{
    return widgetList.count();
}
