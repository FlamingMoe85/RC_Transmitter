#include "Base_Quadlet_Ui.h"
#include "ui_Base_Quadlet_Ui.h"

Base_Quadlet_Ui::Base_Quadlet_Ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Base_Quadlet_Ui)
{
    ui->setupUi(this);
}

Base_Quadlet_Ui::~Base_Quadlet_Ui()
{
    delete ui;
}
