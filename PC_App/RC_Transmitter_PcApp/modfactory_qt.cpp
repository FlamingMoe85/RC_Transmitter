#include "modfactory_qt.h"


//static QPixmap* pixmapMult;
//static QPixmap* pixmapMatruschka;

ModFactory_Qt::ModFactory_Qt()
{
    //pixmapMult = new QPixmap(":/images/mult.png");
   // pixmapMatruschka = new QPixmap(":/images/Matruschka.png");
}


Graph_App_I* ModFactory_Qt::GetNewModule(unsigned int type)
{
    switch(type)
    {
        case MULT_TYP:
            return new Calc_Multiplication_Leaf();
            break;

        case ADCuC_TYP:
            return new Calc_uCAdc_Leaf();
            break;

        case CSTMSW_TYP:
            return new Src_CstmSw_Leaf();
            break;

        case BLINK_TYP:
            return new Time_Blinker_Leaf();
            break;

    case SCALE_SWITCH_TYP:
        return new Calc_ScaleSw_Leaf();
        break;

    case QUANTIZER_TYP:
        return new Calc_Quantizer_Leaf();
        break;
    }
}

QString ModFactory_Qt::GetTypePicLocation(unsigned int type)
{
    switch(type)
    {
        case MULT_TYP:
            return ":/images/mult.png";

        case COMPO_TYP_OPEN:
            return ":/images/Matruschka.png";

        case JUNC_TYP:
            return ":/images/junction.png";

        case SLOT_TYP:
            return ":/images/multiSw.png";

        case CHANNEL_TYP:
            return ":/images/channel.png";

        case ADCuC_TYP:
             return ":/images/channelSel.png";

        case CSTMSW_TYP:
             return ":/images/switch.png";

        case BLINK_TYP:
            return ":/images/blinker.png";

        case SCALE_SWITCH_TYP:
            return ":/images/scaleSwitch.png";

    case QUANTIZER_TYP:
        return ":/images/quantizer.png";

    }
    return ":/images/default.png";
}
