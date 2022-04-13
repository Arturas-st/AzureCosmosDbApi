
It turned out that it is quite dry in my room. Humidity barely exceeds 30%. According to the Swedish Environmental Protection Agency, the best relative humidity indoors is between 30% and 50%, and it should never exceed 60%. Other studies suggest that 40% to 60% is a better range.
To solve the problem, I plan to grow more plants indoors, but then I have to monitor the humidity so that it does not get too wet.
To do this I use two sensors bme280 and dht11 indoors. Dht11 data is stored in "cold" container "Blob Storage" which can then be used to compare data with bme20 sensor data.
It turns out that humidity indoors depends a bit on the humidity outdoors, so I collect weather data from an external source and check when there is any difference.
I use Azure cloud services. Data is saved in Azure Cosmos db and visualized with Power bi


Components:


 
![bmp280-50v-digital-barometric-pressure-altitude-sensor-i2cspi](https://user-images.githubusercontent.com/71280566/163167546-49b3b61d-047d-499d-aa34-c8a3e4ffe507.jpg)Bme280



![41015728-1](https://user-images.githubusercontent.com/71280566/163166280-6def7d31-2126-42b8-89b2-fe7727a09472.jpg) Dht11


![41015979](https://user-images.githubusercontent.com/71280566/163166335-e1d63906-78bf-4e88-ab65-2e7d22585c75.jpg) ESP32 Adafruit Feather 




The Bme280 module has a simple two-wire I2C interface that connects to the ESP32 microcontroller. Sensor measures humidity / temp and barometric pressure. Maximum temperature + 85C, Lowest temperature -40C.
Dht11 contains a chip that makes analog to digital conversion and spits out a digital signal with temperature and humidity that is also connected to ESP32. Maximum temperature + 50C, Lowest temperature 0C.


Chart I have implemented:



![2](https://user-images.githubusercontent.com/71280566/163168649-eed4f32b-6835-4103-ad68-73645e05319e.PNG)


