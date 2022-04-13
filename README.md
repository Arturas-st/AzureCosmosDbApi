
It turned out that it is quite dry in my room. Humidity barely exceeds 30%. According to the Swedish Environmental Protection Agency, the best relative humidity indoors is between 30% and 50%, and it should never exceed 60%. Other studies suggest that 40% to 60% is a better range.
To solve the problem, I plan to grow more plants indoors, but then I have to monitor the humidity so that it does not get too wet.
To do this I use two sensors bme280 and dht11 indoors. Dht11 data is stored in "cold" container "Blob Storage" which can then be used to compare data with bme20 sensor data.
It turns out that humidity indoors depends a bit on the humidity outdoors, so I collect weather data from an external source and check when there is any difference.
I use Azure cloud services. Data is saved in Azure Cosmos db and visualized with Power bi


Components:


![images (1)](https://user-images.githubusercontent.com/71280566/163165892-fb6d1ac5-9e0c-4480-a081-ca1d5c0bc943.jpg)  Bme280
