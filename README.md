# nRF24L01_Receiver-I2C
このコードはESP32でnRF24L01のデータを受信し、I2C経由で送信するコードです。[このリポジトリ](https://github.com/TatsuyaM2667/ESP32_I2C_SpreadSheet)に対応してます。

nRF24L01との配線は以下の通りです。
| ESP32      | nRF24L01　  |
|:-----------|------------:|
|   3.3V     |  VCC        | 
|   GND      |  GND        | 
|   CE       |  GPIO17     | 
|   CSN      |  GPIO5      | 
|   SCK      |  GPIO18     | 
|   MOSI     |  GPIO23     | 
|   MISO     |  GPIO19     |


[このリポジトリ](https://github.com/TatsuyaM2667/ESP32_I2C_SpreadSheet)を使う場合、ESP32とはGPIO21(SDA)、GPIO22(SCL)と設定しています。
## 👨‍💻 作者
- [TatsuyaM2667](https://github.com/TatsuyaM2667)
