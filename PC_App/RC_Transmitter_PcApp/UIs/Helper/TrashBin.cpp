#include "TrashBin.h"
#include "ui_TrashBin.h"
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QDropEvent>

TrashBin::TrashBin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrashBin)
{
    ui->setupUi(this);
}

TrashBin::~TrashBin()
{
    delete ui;
}

void TrashBin::DefinePixMap(int pixSel)
{
    switch(pixSel)
    {
        case ROCKET:
            ui->label->setPixmap(QPixmap(":/images/rakete.png"));
            break;
    }
}

void TrashBin::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdataDrop")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdataDrop");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        qint32 typeQ, type;
        dataStream >> pixmap >> offset >> typeQ;
        emit DelElement((int)typeQ);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    }
    if (event->mimeData()->hasFormat("Composition")) {
        QByteArray itemData = event->mimeData()->data("Composition");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        qint32 typeQ, type;
        dataStream >> typeQ >> offset;
        emit DelElement((int)typeQ);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    }
    else {
        event->ignore();
    }
}

void TrashBin::dragEnterEvent(QDragEnterEvent *event)
{
    if ((event->mimeData()->hasFormat("application/x-dnditemdataDrop")) ||
            (event->mimeData()->hasFormat("Composition"))){
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void TrashBin::dragMoveEvent(QDragMoveEvent *event)
{
    if ((event->mimeData()->hasFormat("application/x-dnditemdataDrop")) ||
        (event->mimeData()->hasFormat("Composition"))){
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}
