#define RED_PIN 9  // Красный пин
#define GREEN_PIN 10 // Зеленый пин
#define BLUE_PIN 11 // Синий пин

String message;
int redValue, greenValue, blueValue;

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    message = ""; // Очищаем сообщение
    while (Serial.available() > 0) {
      char incomingChar = Serial.read();
      message += incomingChar;
    }

    // Парсим полученное сообщение
    if (parseMessage(message)) {
      // Устанавливаем яркость светодиодов
      analogWrite(RED_PIN, redValue);
      analogWrite(GREEN_PIN, greenValue);
      analogWrite(BLUE_PIN, blueValue);

      Serial.println("Код введен правильно."); // Добавляем сообщение об успехе
    } else {
      Serial.println("Ошибка: Неправильный формат ввода. Введите три числа, разделенные запятыми.");
    }
  }
}

bool parseMessage(String msg) {
  int commaIndex1 = msg.indexOf(',');
  int commaIndex2 = msg.lastIndexOf(',');

  if (commaIndex1 != -1 && commaIndex2 != -1 && commaIndex1 != commaIndex2) {
    // Извлекаем значения
    redValue = msg.substring(0, commaIndex1).toInt();
    greenValue = msg.substring(commaIndex1 + 1, commaIndex2).toInt();
    blueValue = msg.substring(commaIndex2 + 1).toInt();

    // Дополнительная проверка значений на диапазон 0-255
    if (redValue >= 0 && redValue <= 255 &&
        greenValue >= 0 && greenValue <= 255 &&
        blueValue >= 0 && blueValue <= 255) {
      return true; // Значения корректны
    }
  }
  return false; // Формат неверен или значения вне диапазона
}
// 255, 0, 0: Красный цвет 
// 0, 255, 0: Зеленый цвет 
// 0, 0, 255: Синий цвет 
// 255, 255, 0: Желтый цвет 
// 255, 0, 255: Фиолетовый цвет 
// 0, 255, 255: Голубой цвет 
// 255, 255, 255: Белый цвет 
// 0, 0, 0: Выключен