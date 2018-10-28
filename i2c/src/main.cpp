#include <iostream>
#include "Pi2c/pi2c.h"
#include <linux/types.h>
// #include <unistd.h>

#define DATA_LENGTH 5

// using namespace std;

u_int32_t readValue(Pi2c con, char addr) {

    char w[DATA_LENGTH] = { (char)(addr + 0x80), 0x00, 0x00, 0x00, 0x00 };
    // char w[] = { 0x0c + 0x80, 0x00, 0x00, 0x00, 0x00 };
    con.i2cWrite(w, sizeof(w));

    char buffer[DATA_LENGTH];
    con.i2cRead(buffer, sizeof(buffer));

    u_int32_t r = 0;

    // Convert to decimal
    // r += (u_int32_t)buffer[4] << 24;
    // r += (u_int32_t)buffer[3] << 16;
    // r += (u_int32_t)buffer[2] << 8;
    // r += (u_int32_t)buffer[1];

    for (u_int8_t i = sizeof(buffer); i >= 2; i--) {
        r += (u_int32_t)buffer[i-1] << (((i - 1) * 8) - 8);
    }

    // Print the data
    printf("0x%02x = 0x", buffer[0]);
    for (u_int8_t i = 1; i < sizeof(buffer); i++) {
        printf("%02x", buffer[i]);
    }
    printf(" (hex)\n");
    printf("0x%02x = %d (decimal)\n", buffer[0], r);

    return r;

}

int writeValue(Pi2c con, char addr, int32_t data) {

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

    printf("0x%02x = 0x", buffer[0]);
    for (u_int8_t i = 1; i < sizeof(buffer); i++) {
        printf("%02x", buffer[i]);
    }
    printf(" (hex)\n");
    printf("0x%02x = %d (decimal)\n", buffer[0], data);

    return con.i2cWrite(buffer, sizeof(buffer));

}

int main(int argc, char *argv[]) {

    printf("i2c test thing\n");

    Pi2c irBoard(0x30, false);

    // writeValue(irBoard, 0x0b, 3000);
    readValue(irBoard, 0x0c);
    readValue(irBoard, 0x0c);
    readValue(irBoard, 0x0c);

    // usleep(1000);

    // char a[] = {0x0C+0x80, 0x00, 0x00, 0x00, 0x00};
    // irBoard.i2cWrite(a, 5);

    // char buffer[5];
    // irBoard.i2cRead(buffer, 5);
    // printf("data: %02x%02x%02x%02x%02x\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
    // irBoard.i2cRead(buffer, 5);
    // printf("data: %02x%02x%02x%02x%02x\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

    return 0;

}
