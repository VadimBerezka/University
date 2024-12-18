#include <math.h>
#include <SD.h> 

#define TERMIST_B 4300 
#define VIN 5.0 
#define CHIP_SELECT_PIN 10 

File dataFile; // Объект для работы с файлом

void setup() {
  Serial.begin(9600); 

  // Инициализация SD-карты
  if (!SD.begin(CHIP_SELECT_PIN)) {
    Serial.println("Ошибка инициализации SD-карты");
    while (1); 
  }
  Serial.println("SD-карта инициализирована");

  // Создаем файл для записи
  dataFile = SD.open("data.txt", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Ошибка создания файла");
    while (1); 
  }
  Serial.println("Файл создан");

  // Выводим заголовки столбцов
  dataFile.println("Second,Temperature"); 
}

void loop() {
  float voltage = analogRead(A0) * VIN / 1024.0; 
  float r1 = voltage / (VIN - voltage); 
  float temperature = 1./( 1./(TERMIST_B)*log(r1)+1./(25. + 273.) ) - 273; 
  
  // Записываем данные в файл
  dataFile.print(millis() / 60000); 
  dataFile.print(","); 
  dataFile.println(temperature); 

  delay(500); 
}
