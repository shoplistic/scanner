#include <linux/types.h>
#include <stdio.h>
#include "../Pi2c/pi2c.h"

#define DATA_LENGTH 5
#define IRADDR 0x30
#define REV0 false

namespace IRi2c
{

enum ParamName
{
    // Parameters for IR Led MCU
    IR_SW_VER,
    IR_VDD,
    IR_REF_CORR,
    IR_VREF,
    IR_MCU_TEMP,
    // Parameters for IR control Led 1
    IR_PWM_LED1,
    IR_VF_LED1,
    IR_I_LED1,
    IR_P_LED1,
    IR_P_Total_LED1,
    IR_ISET_LED1,
    IR_PSET_LED1,
    IR_TEMP_LED1,
    IR_TSET_LED1,
    // Parameters for IR control Led 2
    IR_PWM_LED2,
    IR_VF_LED2,
    IR_I_LED2,
    IR_P_LED2,
    IR_P_Total_LED2,
    IR_ISET_LED2,
    IR_PSET_LED2,
    IR_TEMP_LED2,
    IR_TSET_LED2,
    // Parameters for IR control Led 3
    IR_PWM_LED3,
    IR_VF_LED3,
    IR_I_LED3,
    IR_P_LED3,
    IR_P_Total_LED3,
    IR_ISET_LED3,
    IR_PSET_LED3,
    IR_TEMP_LED3,
    IR_TSET_LED3,
    // Parameters for IR control Led 4
    IR_PWM_LED4,
    IR_VF_LED4,
    IR_I_LED4,
    IR_P_LED4,
    IR_P_Total_LED4,
    IR_ISET_LED4,
    IR_PSET_LED4,
    IR_TEMP_LED4,
    IR_TSET_LED4,
    // Wiper parameters
    IR_WIPER_N_PULSES,
    IR_WIPER_N_STROKE,
    IR_WIPER_PRESENT,
    // Other parameters
    IR_CONTROL_REG,
    IR_STATUS_REG,
    IR_LIGHTSENSOR
};

void printData(char buffer[DATA_LENGTH], u_int32_t value);
u_int32_t readData(ParamName addr);
u_int32_t writeData(ParamName addr, u_int32_t value);

}
