#include <iostream>
#include "Pi2c/pi2c.h"
#include <linux/types.h>

#define DATA_LENGTH 5
#define IRADDR 0x30
#define REV0 false

// using namespace std;

namespace IRi2c {

    void printData(char buffer[DATA_LENGTH], uint32_t value) {

        printf("0x%02x = 0x", buffer[0]);
        for (u_int8_t i = 1; i < DATA_LENGTH; i++) {
            printf("%02x", buffer[i]);
        }
        printf(" (hex)\n");
        printf("0x%02x = %d (decimal)\n", buffer[0], value);

    }

}

u_int32_t readValue(char addr) {

    Pi2c irBoard(IRADDR, REV0);

    char w[DATA_LENGTH] = { (char)(addr + 0x80), 0x00, 0x00, 0x00, 0x00 };
    irBoard.i2cWrite(w, sizeof(w));

    char buffer[DATA_LENGTH];
    irBoard.i2cRead(buffer, sizeof(buffer));

    u_int32_t r = 0;

    // Convert to decimal
    // r += (u_int32_t)buffer[4] << 24;
    // r += (u_int32_t)buffer[3] << 16;
    // r += (u_int32_t)buffer[2] << 8;
    // r += (u_int32_t)buffer[1];

    for (u_int8_t i = sizeof(buffer); i >= 2; i--) {
        r += (u_int32_t)buffer[i-1] << (((i - 1) * 8) - 8);
    }

    IRi2c::printData(buffer, r);

    return r;

}

int writeValue(char addr, int32_t data) {

    char buffer[DATA_LENGTH];

    buffer[0] = addr;

    // Encode to to char array
    // buffer[1] = (u_int8_t)(((u_int32_t)data)&0x000000FF);
    // buffer[2] = (u_int8_t)((((u_int32_t)data)&0x0000FF00)>>8);
    // buffer[3] = (u_int8_t)((((u_int32_t)data)&0x00FF0000)>>16);
    // buffer[4] = (u_int8_t)((((u_int32_t)data)&0xFF000000)>>24);

    for (u_int8_t i = 1; i < sizeof(buffer); i++) {
        buffer[i] = (u_int8_t)((((u_int32_t)data)&(0x000000ff<<((i * 8) - 8))) >> ((i * 8) - 8));
    }

    IRi2c::printData(buffer, data);

    Pi2c irBoard(IRADDR, REV0);

    return irBoard.i2cWrite(buffer, sizeof(buffer));

}

int main(int argc, char *argv[]) {

    printf("i2c test thing\n");

    writeValue(0x0a, 0); // Max current (mA)
    writeValue(0x0b, 1000); // Max effect (mW)
    writeValue(0x0d, 50); // Max temp (C)
    readValue(0x01);

    return 0;

}
