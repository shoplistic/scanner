#include "IRi2c.h"

namespace IRi2c
{

void printData(char buffer[DATA_LENGTH], uint32_t value)
{

    printf("0x%02x = 0x", buffer[0]);
    for (uint8_t i = 1; i < DATA_LENGTH; i++)
    {
        printf("%02x", buffer[i]);
    }
    printf(" (hex)\n");
    printf("0x%02x = %d (decimal)\n", buffer[0], value);
}

uint32_t readData(ParamName addr)
{

    Pi2c irBoard(IRADDR, REV0);

    char w[DATA_LENGTH] = {(char)(addr + 0x80), 0x00, 0x00, 0x00, 0x00};
    irBoard.i2cWrite(w, sizeof(w));

    char buffer[DATA_LENGTH];
    irBoard.i2cRead(buffer, sizeof(buffer));

    uint32_t r = 0;

    // Convert to decimal
    // r += (uint32_t)buffer[4] << 24;
    // r += (uint32_t)buffer[3] << 16;
    // r += (uint32_t)buffer[2] << 8;
    // r += (uint32_t)buffer[1];

    for (uint8_t i = sizeof(buffer); i >= 2; i--)
    {
        r += (uint32_t)buffer[i - 1] << (((i - 1) * 8) - 8);
    }

    IRi2c::printData(buffer, r);

    return r;
}

uint32_t writeData(ParamName addr, uint32_t data)
{

    char buffer[DATA_LENGTH];

    buffer[0] = addr;

    // Encode to to char array
    // buffer[1] = (uint8_t)(((uint32_t)data)&0x000000FF);
    // buffer[2] = (uint8_t)((((uint32_t)data)&0x0000FF00)>>8);
    // buffer[3] = (uint8_t)((((uint32_t)data)&0x00FF0000)>>16);
    // buffer[4] = (uint8_t)((((uint32_t)data)&0xFF000000)>>24);

    for (uint8_t i = 1; i < sizeof(buffer); i++)
    {
        buffer[i] = (uint8_t)((((uint32_t)data) & (0x000000ff << ((i * 8) - 8))) >> ((i * 8) - 8));
    }

    IRi2c::printData(buffer, data);

    Pi2c irBoard(IRADDR, REV0);

    return irBoard.i2cWrite(buffer, sizeof(buffer));
}

} // namespace IRi2c
