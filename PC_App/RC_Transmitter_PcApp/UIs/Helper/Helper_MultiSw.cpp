#include "Helper_MultiSw.h"
#include "ui_Helper_MultiSw.h"

Helper_MultiSw::Helper_MultiSw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Helper_MultiSw)
{
    ui->setupUi(this);
    connect(ui->pushButton_NewJunc, SIGNAL(clicked()), this, SLOT(Slot_Clicked()));
}

Helper_MultiSw::~Helper_MultiSw()
{
    delete ui;
}

void Helper_MultiSw::Slot_Clicked()
{
    emit Signal_Clicked();
}
