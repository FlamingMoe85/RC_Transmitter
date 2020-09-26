#ifndef MODFACTORY_QT_H
#define MODFACTORY_QT_H

#include <QPixmap>
#include "../../share/Graph_App/graph_app_i.h"
#include "../../share/Graph_App/Calc_Multiplication_Leaf.h"
#include "../../share/Graph_App/Calc_uCAdc_Leaf.h"
#include "../../share/Graph_App/Src_CstmSw_Leaf.h"
#include "../../share/Graph_App/Time_Blinker_Leaf.h"
#include "../../share/Graph_App/Calc_ScaleSw_Leaf.h"
#include "../../share/Graph_App/Calc_Quantizer_Leaf.h"

class ModFactory_Qt
{
public:
    ModFactory_Qt();

    static Graph_App_I* GetNewModule(unsigned int type);
    static QString GetTypePicLocation(unsigned int type);

private:
};

#endif // MODFACTORY_QT_H
