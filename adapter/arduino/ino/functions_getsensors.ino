//------------------------------------- Function getsensors ------------------------------------//
//Функция запроса значений различных сенсоров/датчиков подключенных к Arduino и присвоение
//значяений соответствующим глобальным переменным.
void getSensors () {
  //Обработка данных датчика bmp085 на шине I2C (пины A4, A5)
  //Глобальная переменная Pout типа float - атмосферное давление в мм. рт. ст.
  Pout = bmp085.readPressure()/133.3;
  //Обработка данных датчика DHT22. Подключение к порту цифровому P9 Arduino
  //Глобальные переменные Hout и Tout типа флоат - влажность (%) и температура (град. С)
  if (DHT.read22(DHT22_PIN)==DHTLIB_OK) {
    Hout = DHT.humidity;
    Tout = DHT.temperature;
  }
  //Обработка данных цифрового датчика освещенности типа BH1750 на шине I2C (пины A4, A5)
  //Глобальная переменная Lux типа unsigned int (беззнаковое целое от 0 до 65535) - освещенность в люксах
  Lux = lightMeter.readLightLevel();
  //Обработка данных цифровых датчиков температуры типа DS18B20.
  //Шина 1-Wire на цифровой пин P8 Arduino.
  //Подключено 3 датчика температуры, адреса задаются в секции глобальных констант "Sensors"
  //Три значение температуры T1, T2, T3 типа float (град. С).
  DS_sensors.requestTemperatures();
  T1 = DS_sensors.getTempC(addr_T1);
  T2 = DS_sensors.getTempC(addr_T2);
  T3 = DS_sensors.getTempC(addr_T3);

}