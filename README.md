# ESP32Bluetooth

_Personal project to connect two ESP32 boards via bluetooth_

_This repository is made up of different folders containing the code of different projects related to the bluetooth connection between 2 ESP32 boards_

## Built with 🛠️

_For now all the code has been generated in the Aurduino IDE_

* [Arduino IDE](https://www.arduino.cc/en/software/)

### Requirements 📋

_To work with ESP32 boards in the Arduino IDE it is necessary to follow these steps:_

* Go to **File > Preferences**
* In section **Additional Boards Manager URLs** add this URL:
```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```
* Click **Ok** to save
* Go to **Tools > Board > Boards Manager...**
* Search **ESP32**
* Select **esp32 by Espressif Systems** (use version 2.0.17. In newer versions the bluetooth connection does not work correctly)
* Click **Install**
* Go to **Tools > Board > esp32** and select **ESP32 Dev Module** (or the specific version you are using)
* Go to **Tools > Port** and select the port that corresponds to your ESP32 (normally **COM3** or **COM4**)

