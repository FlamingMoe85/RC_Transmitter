#ifndef SAVE_LOAD_UI_H
#define SAVE_LOAD_UI_H

#include <QWidget>
#include <QString>
#include "UIs/Helper/TrashBin.h"
#include "UIs/Helper/Scroll_Pool.h"
#include "UIs/Helper/Compo_Pool_Item.h"
#include "Modell_Manager_Qt.h"

namespace Ui {
class Save_Load_Ui;
}

class Save_Load_Ui : public QWidget
{
    Q_OBJECT

public:
    explicit Save_Load_Ui(QWidget *parent = nullptr);
    ~Save_Load_Ui();

    void RefreshModelList();

signals:
    void Signal_Save(Modell_Manager_Qt* modMngrRef);
    void Signal_Load(Modell_Manager_Qt* modMngrRef);

private:
    Ui::Save_Load_Ui *ui;
    TrashBin load;
    TrashBin remove;
    Scroll_Pool availbleMods;
    Modell_Manager_Qt modMngr;

    QStringList foundModels;
    void findModels(QStringList *result);

private slots:
    void Slot_Save();
    void Slot_Load(int loadSel);
    void Slot_Delete(int delSel);
};

#endif // SAVE_LOAD_UI_H
