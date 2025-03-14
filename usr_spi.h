#include "stdint.h"
#include <Arduino.h>
#include <SPI.h>
/*使用的SPI控制器，对于esp32s3 SPI2->FSPI，SPI3->HSPI*/
#define MYSPIBUS HSPI

/*针脚定义*/
#define NCS 42
#define MISO 41
#define MOSI 40
#define SCLK 39

#define CS_High digitalWrite(NCS, HIGH)
#define CS_Low digitalWrite(NCS, LOW)

#define SPI_I2S_FLAG_RXNE ((uint16_t)0x0001)
#define SPI_I2S_FLAG_TXE ((uint16_t)0x0002)
/**********************************************************************************************************/
void SPI_Init(void);
uint8_t SPI_SendReceive(uint8_t data);
uint8_t read_register(uint8_t adress);
void write_register(uint8_t adress, uint8_t vlue);