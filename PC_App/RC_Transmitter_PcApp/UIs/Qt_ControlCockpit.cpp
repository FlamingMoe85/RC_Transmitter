#include "Qt_ControlCockpit.h"
#include "ui_Qt_ControlCockpit.h"

#include <QDebug>

Qt_ControlCockpit::Qt_ControlCockpit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qt_ControlCockpit)
{
    ui->setupUi(this);
    ui->widget_2->layout()->addWidget(&knopRight);
    connect(ui->pushButton_Neutral, SIGNAL(clicked()), this, SLOT(Slot_Neutral()));
    connect(&knopRight, SIGNAL(Signal_Posistion(float,float)), this, SLOT(Slot_KnopMove(float,float)));

    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(Slot_Sw7()));
    connect(ui->pushButton_7_8, SIGNAL(clicked()), this, SLOT(Slot_Sw7_8()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(Slot_Sw8()));
}

Qt_ControlCockpit::~Qt_ControlCockpit()
{
    delete ui;
}

void Qt_ControlCockpit::Slot_Neutral()
{
    knopRight.Neutral();
    knopRight.SetAreaDims(this->width(), this->height());
}

void Qt_ControlCockpit::Slot_KnopMove(float xPos, float yPos)
{
    //qDebug() << "xPos " << xPos << "   yPos " << yPos;
    rightX = xPos;
    rightY = yPos;
}

float Qt_ControlCockpit::GetRight_X()
{
    return rightX;
}
float Qt_ControlCockpit::GetRight_Y()
{
    return rightY;
}

unsigned int Qt_ControlCockpit::GetDigitals()
{
    return switches;
}

void Qt_ControlCockpit::Slot_Sw7()
{
    switches = 64;
}
void Qt_ControlCockpit::Slot_Sw7_8()
{
    switches = 0;
}
void Qt_ControlCockpit::Slot_Sw8()
{
    switches = 128;
}
