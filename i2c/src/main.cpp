#include <iostream>
#include <linux/types.h>
#include "IRi2c/IRi2c.h"

// using namespace std;

int main(int argc, char *argv[]) {

    printf("i2c test thing\n");

    // IRi2c::writeData(0x0a, 0); // Max current (mA)
    // IRi2c::writeData(0x0b, 1000); // Max effect (mW)
    // IRi2c::writeData(0x0d, 50); // Max temp (C)
    IRi2c::writeData(IRi2c::IR_ISET_LED1, 100);
    IRi2c::writeData(IRi2c::IR_PSET_LED1, 1000);
    IRi2c::writeData(IRi2c::IR_TSET_LED1, 50);
    IRi2c::readData(IRi2c::IR_VDD);

    return 0;

}
