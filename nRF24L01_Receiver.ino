#include <Wire.h>
#include <SPI.h>
#include <RF24.h>

#define I2C_SLAVE_ADDR 0x42  

RF24 radio(17, 5);
const byte address[6] = "00001";

struct SensorData {
  float temperature;
  float humidity;
  float pressure;
  float latitude;
  float longitude;
};

void setup() {
  Serial.begin(115200);
  Wire.begin(); // マスターとして
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    SensorData data;
    radio.read(&data, sizeof(data));

    // シリアルモニタに表示
    Serial.printf("T:%.2f H:%.2f P:%.2f Lat:%.6f Lon:%.6f\n",
      data.temperature, data.humidity, data.pressure,
      data.latitude, data.longitude);

    // I2Cでバイト形式でデータ送信
    Wire.beginTransmission(I2C_SLAVE_ADDR);
    Wire.write((const uint8_t*)&data, sizeof(SensorData));
    Wire.endTransmission();

    delay(1000);
  }
}
