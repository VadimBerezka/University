#define LED_PIN 9
String message;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char incomingChar = Serial.read();
    
    // Если пришел символ, добавляем его к сообщению
    if (incomingChar != '\n') {
      message += incomingChar;
    } else {
      // Приводим строку к нижнему регистру для унифицированной проверки
      message.toLowerCase();
      
      // Проверка на команды "on" и "off"
      if (message == "on") {
        digitalWrite(LED_PIN, HIGH);  // Включаем светодиод
        Serial.println("LED включён");
      } else if (message == "off") {
        digitalWrite(LED_PIN, LOW);   // Выключаем светодиод
        Serial.println("LED выключен");
      } else {
        // Если не "on" и не "off", проверяем, является ли это числом
        int value = message.toInt();
        
        if (value >= 0 && value <= 255) {
          analogWrite(LED_PIN, value); // Устанавливаем яркость светодиода
        } else {
          Serial.println("Ошибка: введите числов диапазоне (0-255)");
        }
      }
      
      // Очищаем сообщение после обработки
      message = "";
    }
  }
}