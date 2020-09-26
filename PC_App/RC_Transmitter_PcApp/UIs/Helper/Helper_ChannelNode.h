#ifndef HELPER_CHANNELNODE_H
#define HELPER_CHANNELNODE_H

#include <QWidget>

namespace Ui {
class Helper_ChannelNode;
}

class Helper_ChannelNode : public QWidget
{
    Q_OBJECT

public:
    explicit Helper_ChannelNode(QWidget *parent = 0);
    ~Helper_ChannelNode();

signals:
    void Signal_Clicked();

private:
    Ui::Helper_ChannelNode *ui;

private slots:
    void Slot_Clicked();
};

#endif // HELPER_CHANNELNODE_H
