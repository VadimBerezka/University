#define FIRST_LED_PIN 2
#define LAST_LED_PIN 12

unsigned long previousMillis = 0;  // Запоминаем время предыдущего переключения
const long interval = 1000;       // Интервал между переключениями (в миллисекундах)

int currentLED = FIRST_LED_PIN; // Начальный LED

void setup() {
  for (int pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; ++pin) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Проверяем, прошло ли достаточно времени для переключения
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Обновляем время последнего переключения

    // Переключаем LED
    digitalWrite(currentLED, LOW); // Гасим предыдущий LED

    // Переходим к следующему LED
    currentLED++;
    if (currentLED > LAST_LED_PIN) {
      currentLED = FIRST_LED_PIN;  // Возвращаемся к первому LED
    }

    digitalWrite(currentLED, HIGH); // Включаем новый LED
  }
}