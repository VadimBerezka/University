#include <math.h> 

#define TERMIST_B 4300 
#define VIN 5.0 

void setup() { 
  Serial.begin(9600); 
  Serial.println("Minute,Temperature");  
} 

void loop() { 
  float voltage = analogRead(A0) * VIN / 1024.0; 
  float r1 = voltage / (VIN - voltage); 
  float temperature = 1./( 1./(TERMIST_B)*log(r1)+1./(25. + 273.) ) - 273; 
  
  Serial.print(millis() / 60000); 
  Serial.print(","); 
  Serial.println(temperature); 
  
  delay(500); 
}

// Импорт данных в Excel:
// Откройте Монитор порта: В Arduino IDE нажмите на значок с лупой (Монитор порта).
// Скопируйте данные: Выделите данные из Монитора порта и скопируйте их в буфер обмена.
// Вставьте в Excel: Вставьте данные в Excel, используя “Вставить специальные” -> “Текст, разграниченный запятыми”.
// Постройте график: Выделите столбцы с данными и выберите тип графика “Точечная диаграмма” или “График”.