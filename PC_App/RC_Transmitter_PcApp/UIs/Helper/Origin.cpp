#include "Origin.h"
#include "ui_Origin.h"

Origin::Origin(QWidget *parent, int type) :
    QWidget(parent),
    ui(new Ui::Origin)
{
    ui->setupUi(this);
    myType = type;
    ui->label->setScaledContents(true);

    switch(type)
    {
    case 'a':
        ui->label->setPixmap(QPixmap(":/images/A.png"));
        break;

    case 'b':
        ui->label->setPixmap(QPixmap(":/images/B.png"));
        break;

    case 'c':
        ui->label->setPixmap(QPixmap(":/images/C.png"));
        break;

    case 'd':
        ui->label->setPixmap(QPixmap(":/images/D.png"));
        break;

    case 'e':
        ui->label->setPixmap(QPixmap(":/images/E.png"));
        break;

    case 'f':
        ui->label->setPixmap(QPixmap(":/images/F.png"));
        break;

    case 'g':
        ui->label->setPixmap(QPixmap(":/images/G.png"));
        break;

    case ('a'+10):
        ui->label->setPixmap(QPixmap(":/images/Ap.png"));
        break;

    case 'b'+10:
        ui->label->setPixmap(QPixmap(":/images/Bp.png"));
        break;

    case 'c'+10:
        ui->label->setPixmap(QPixmap(":/images/Cp.png"));
        break;

    case 'd'+10:
        ui->label->setPixmap(QPixmap(":/images/Dp.png"));
        break;

    case 'e'+10:
        ui->label->setPixmap(QPixmap(":/images/Ep.png"));
        break;

    case 'f'+10:
        ui->label->setPixmap(QPixmap(":/images/Fp.png"));
        break;

    case 'g'+10:
        ui->label->setPixmap(QPixmap(":/images/Gp.png"));
        break;
    }
}

Origin::~Origin()
{
    delete ui;
}

int Origin::GetType()
{
    return myType;
}

const QPixmap *Origin::pixmap()
{
    return ui->label->pixmap();
}
