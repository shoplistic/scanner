#include <linux/types.h>
#include "IRi2c/IRi2c.h"
#include <stdint.h>

int main(int argc, char *argv[]) {

    printf("i2c IR Controller\n");

    uint8_t brightness = 0;

    if (argc == 2) {

        brightness = (uint8_t)atoi(argv[1]);

    } else {

        printf("Invalid arguments, expected a number (0-255)\n");
        exit(-1);

    }

    IRi2c::writeData(IRi2c::IR_ISET_LED3, brightness);
    IRi2c::writeData(IRi2c::IR_PSET_LED3, 1000);
    IRi2c::writeData(IRi2c::IR_TSET_LED3, 50);

    // while (true) {
    //     IRi2c::readData(IRi2c::IR_VDD);
    //     IRi2c::readData(IRi2c::IR_LIGHTSENSOR);
    //     sleep(1);
    // }

    return 0;

}
