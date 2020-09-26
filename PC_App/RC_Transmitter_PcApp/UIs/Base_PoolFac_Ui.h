#ifndef BASE_POOLFAC_UI_H
#define BASE_POOLFAC_UI_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPixmap>
#include "Helper/Scroll_Pool.h"
#include "Helper/Scroll_ModFactory.h"
#include "Helper/Scroll_Items.h"
#include "Helper/TrashBin.h"
#include "Helper/Child_Item.h"

//#include "../modfactory_qt.h"
#include "../../../share/Graph_App/graph_app_i.h"
#include "../../../share/std/List.hpp"
#include "../../../share/Graph_App/PoolOwnerUtils.h"
#include "../Utils_Qt.h"

namespace Ui {
class Base_PoolFac_Ui;
}

class Base_PoolFac_Ui : public QWidget
{
    Q_OBJECT

public:
    explicit Base_PoolFac_Ui(QWidget *parent = 0);
    ~Base_PoolFac_Ui();

    Scroll_Pool* Get_ScrollPool();
    Scroll_Items* Get_ChildItems();
    PoolOwnerUtils* GetPoolUtils();

    void RefreshPool();
    void RefreshChildArea();

    void CharrArrToQtring(char* charArr, QString* name);
    void QStringToCharArr(char* charArr, QString* name);

    void SetTypeLabel(QString type);
    void SetCurNode(Graph_App_I* cN);
    void SetSpecificWidget(QWidget* sW);

private:
    Ui::Base_PoolFac_Ui *ui;
    Scroll_Pool scrollPool;
    Scroll_ModFactory scrollModFac;
    Scroll_Items scrollItems;
    TrashBin* trashBin;
    PoolOwnerUtils poolUtils;

    Graph_App_I* myCurNode;

    Utils_Qt utilsQt;

public slots:
    void Slot_AddCompoNodeFromPool(unsigned int poolPos);
    void Slot_AddModule(unsigned int type, QPixmap pixmap);
    void Slot_Enter(unsigned int pos);
    void Slot_Esc();
    void Slot_NewCompo();
    void Slot_SwapItems(uint srcChldSel, uint swapTar);
    void DeleteElememnt(int delDest);
};

#endif // BASE_POOLFAC_UI_H
