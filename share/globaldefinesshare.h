#ifndef GLOBALDEFINESSHARE_H
#define GLOBALDEFINESSHARE_H
#include <stdint.h>

#ifndef NULL
#define NULL 0
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define SIGNED true
#define UNSIGNED false

const uint16_t VALUE_STEP_UINT = 5;
const float VALUE_STEP_FLOAT = 5.0;

//1300 + (tmp32 * 0.5) = 500
//2600 + tmp = 1000;
//tmp = 1000 - 2600 = -1600;

const float NEUTRAL = 1500.0;
const float RESET_MULTI_SW = -1600;

#define NAME_LENGTH 20

const uint16_t SLOT_TYP = 15;
const uint16_t COMPO_TYP_OPEN = 1;
const uint16_t COMPO_TYP_STORED = 2;
const uint16_t JUNC_TYP = 3;
const uint16_t CHANNEL_TYP = 4;
const uint16_t CHNMNGR_TYP = 5;
const uint16_t ADD_TYP = 128;
const uint16_t MULT_TYP = 129;
const uint16_t CSTMSW_TYP = 130;
const uint16_t ADCuC_TYP = 131;
const uint16_t INTERN_TRIM_TYP = 132;
const uint16_t RAMP_TYP = 133;
const uint16_t BLINK_TYP = 134;
const uint16_t SCALE_SWITCH_TYP = 135;
const uint16_t QUANTIZER_TYP = 136;

union IntUint16
{
    int16_t int16Val;
    uint16_t uint16Val;
};
#endif // GLOBALDEFINESSHARE_H
