# HW-364A OLED Display Wifi example

Made this project just for fun. But at this moment I see a lot of possibilities to expand.
Now it may connect to wifi, unfortunatelly only 2G, print ip, mac-address connected AP and ping stats.
So let me say that is version 001 :)

Environment: Visual Studio Code with PlatormIO

Board: HW-364A v2.1.0 with USB-C
* NodeMCU ESP8266 Development Board
* 0.96 Inch OLED Display 128x64 pixels
* CH340 Driver Module

The display was connected as:
* I2C on D5/D6 pins (GPIO14/GPIO12) as SDA/SCL
* Address: 0x3C
