#include <iostream>
#include "Pi2c/pi2c.h"
#include <linux/types.h>

// using namespace std;

int main(int argc, char *argv[]) {

    printf("i2c test thing\n");

    Pi2c irBoard(0x30, false);

    char a[] = {0x0C, 0x00, 0x00, 0x00, 0x00};
    irBoard.i2cWrite(a, 5);

    char buffer[5];
    irBoard.i2cRead(buffer, 5);

    printf("data: %s\n", buffer);

    return 0;

}
