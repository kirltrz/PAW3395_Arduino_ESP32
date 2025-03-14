#include "stdint.h"
#include "usr_delay.h"
// 寄存器地址
#define PAW3395_SPIREGISTER_MOTION 0x02
#define PAW3395_SPIREGISTER_MotionBurst 0x16
#define PAW3395_SPIREGISTER_POWERUPRESET 0x3A
/*******************CPI配置寄存器********************/
#define SET_RESOLUTION 0x47
#define RESOLUTION_X_LOW 0x48
#define RESOLUTION_X_HIGH 0x49
#define RESOLUTION_Y_LOW 0x4A
#define RESOLUTION_Y_HIGH 0x4B
#define RIPPLE_CONTROL 0x5A
#define MOTION_CTRL 0x5C
// 寄存器值
#define PAW3395_POWERUPRESET_POWERON 0x5A
// 寄存器位
#define PAW3395_OP_MODE0 0
#define PAW3395_OP_MODE1 1
#define PAW3395_PG_FIRST 6
#define PAW3395_PG_VALID 7
// 操作延时
/// SPI读地址延迟
#define PAW3395_TIMINGS_SRAD 2 // 2μs
/// 读取和后续命令之间的SPI延时
#define PAW3395_TIMINGS_SRWSRR 2 // 2μs
/// 写入命令之间的SPI延时
#define PAW3395_TIMINGS_SWW 5 // 5μs
/// 写入和读取命令之间的SPI延时
#define PAW3395_TIMINGS_SWR 5 // 5μs
/// SPI，NCS到SCLK活动/非活动
#define PAW3395_TIMINGS_NCS_SCLK 1 // 120ns
/// 为设置NCS为高电平而退出运动突发模式的延时
#define PAW3395_TIMINGS_BEXIT 4 // 500ns
#define PAW3395_SPI_WRITE 0x80

void paw3395Init(void);                      // 初始化传感器
void Motion_Burst(int16_t *dx, int16_t *dy); // 读取dx和dy

void Power_up_sequence(void);           // 上电
void Pixel_Burst_Read(uint8_t *pFrame); // 输出原始数据
void DPI_Config(uint16_t CPI_Num);      // 设置DPI