#include "VertCustomSlider.h"
#include "ui_VertCustomSlider.h"

VertCustomSlider::VertCustomSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VertCustomSlider)
{
    ui->setupUi(this);
}

VertCustomSlider::~VertCustomSlider()
{
    delete ui;
}
