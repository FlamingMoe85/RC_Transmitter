#include "Helper_ChannelNode.h"
#include "ui_Helper_ChannelNode.h"

Helper_ChannelNode::Helper_ChannelNode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Helper_ChannelNode)
{
    ui->setupUi(this);
    connect(ui->pushButton_AddSlot, SIGNAL(clicked()), this, SLOT(Slot_Clicked()));
}

Helper_ChannelNode::~Helper_ChannelNode()
{
    delete ui;
}

void Helper_ChannelNode::Slot_Clicked()
{
    Signal_Clicked();
}
