#include "usr_spi.h"
#include "usr_delay.h"

SPISettings paw3395Settings(
    10000000, // 10MHz时钟 (APB时钟80MHz / 8)
    MSBFIRST, // MSB优先
    SPI_MODE3 // CPOL=1, CPHA=1
);

SPIClass mySPI(MYSPIBUS);
void SPI_Init(void)
{
  mySPI.begin(SCLK, MISO, MOSI);         // 初始化SPI
  mySPI.setDataMode(SPI_MODE3);          // SPI模式3
  mySPI.setClockDivider(SPI_CLOCK_DIV8); // 设置SPI时钟分频
}
// SPI发送和接收数据
uint8_t SPI_SendReceive(uint8_t data)
{
  return mySPI.transfer(data);
}

// 读取寄存器
uint8_t read_register(uint8_t address)
{
  uint8_t temp;
  mySPI.beginTransaction(paw3395Settings);
  CS_Low;

  // 根据数据手册要求的最小延时（125ns）
  delay_125_ns(1);

  mySPI.transfer(address); // 发送读地址（bit7=0）
  delayMicroseconds(5);    // 保持延时满足t_SRAD

  temp = mySPI.transfer(0xFF); // 获取数据
  CS_High;
  mySPI.endTransaction();

  return temp;
}

// 写入寄存器
void write_register(uint8_t address, uint8_t value)
{
  mySPI.beginTransaction(paw3395Settings);
  CS_Low;

  // 根据数据手册要求的最小延时（125ns）
  delay_125_ns(1); // 近似替代125ns延时

  mySPI.transfer(address | 0x80); // 写地址（bit7=1）
  mySPI.transfer(value);

  CS_High;
  mySPI.endTransaction();

  delayMicroseconds(5); // 满足t_SWW时序要求
}

void SPI_SendData(uint8_t data)
{
  mySPI.transfer(data);
}
uint8_t SPI_ReceiveData()
{
  return mySPI.transfer(0xFF); // 发送0xFF以接收数据
}