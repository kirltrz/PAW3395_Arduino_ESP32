#include <Arduino.h>
#include "PAW3395.h"

int16_t dx, dy;
float x, y;

void setup()
{
  Serial.begin(115200);

  paw3395Init();

  Serial.println("initial finished");
}

void loop()
{
  Motion_Burst(&dx, &dy); // 读取PAW3395传回来的dx和dy
  x = dx * 0.0009769;     // 26000DPI下的转换系数
  y = dy * 0.0009769;

  Serial.print("x:");
  Serial.print(x);
  Serial.print("  y:");
  Serial.print(y);
  Serial.print("  dx:");
  Serial.print(dx);
  Serial.print("  dy:");
  Serial.println(dy);

  // delay(5);
}
