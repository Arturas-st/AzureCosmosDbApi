#include <WiFi.h>
#include "time.h"
#include "Esp32MQTTClient.h"
#include "AzureIotHub.h"
#include <ArduinoJson.h>


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // I2C
unsigned long delayTime;

#define INTERVAL 1000 *5
#define DEVICE_NAME "esp32"



char * ssid = "";
char *pass = "";
char *connectionString = "";
bool messagePending = false;
unsigned long prevMillis = 0;
unsigned long epochTime;
float prevTemp = 0;

void setup() {
  bool status;
  status = bme.begin(0x76); 
  initSerial();
  initWifi();
  initDevice();
  delay(2000);

  configTime(3600,3600,"pool.ntp.org");
}
void loop() {
  unsigned long currentMillis = millis();
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  float presure = bme.readPressure() / 100.0F;
  //printValues();

  if(!messagePending){
    if((currentMillis - prevMillis) > INTERVAL){
      prevMillis = currentMillis;
      epochTime = time(NULL);

      if(!(std::isnan(temperature)) && !(std::isnan(humidity))){

        if(temperature > (prevTemp +1) || temperature < (prevTemp - 1)){
           prevTemp = temperature;
           char payload[256];
           char epochTimeBuf[12];
               
          DynamicJsonDocument doc(1024);
          doc["temp"] = temperature;
          doc["hum"] = humidity; 
          doc["ts"] = epochTime;         
         
          serializeJson(doc, payload);
          SendMessage(payload, itoa(epochTime, epochTimeBuf, 10));         
        }
      }     
    }
  }
  Esp32MQTTClient_Check();
  delay(10);

}
