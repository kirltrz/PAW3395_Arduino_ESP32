#include "usr_delay.h"

void delay_ms(uint16_t nms)
{
    delay(nms);
}
void delay_us(uint32_t nus)
{
    delayMicroseconds(nus);
}
void delay_125_ns(uint8_t nns)
{
    uint32_t cycles = (125 * nns) / (1000000000 / 240000000); // 计算需要的 CPU 周期数
    uint32_t start = xthal_get_ccount();
    while (xthal_get_ccount() - start < cycles);
}