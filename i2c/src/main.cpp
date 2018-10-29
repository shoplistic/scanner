#include <iostream>
#include <linux/types.h>
#include "IRi2c/IRi2c.h"
// #include <unistd.h>

// using namespace std;

int main(int argc, char *argv[]) {

    printf("i2c test thing\n");

    IRi2c::writeData(IRi2c::IR_ISET_LED3, 20);
    IRi2c::writeData(IRi2c::IR_PSET_LED3, 1000);
    IRi2c::writeData(IRi2c::IR_TSET_LED3, 50);

    // while (true) {
    //     IRi2c::readData(IRi2c::IR_VDD);
    //     IRi2c::readData(IRi2c::IR_LIGHTSENSOR);
    //     sleep(1);
    // }

    return 0;

}
