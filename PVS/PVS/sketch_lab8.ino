const int redPin = 9;   // Пин для красного светодиода
const int yellowPin = 10; // Пин для желтого светодиода
const int greenPin = 11; // Пин для зеленого светодиода

// Состояния светофора
enum TrafficLightState { RedLight, RedYellowLight, GreenLight, YellowLight, YellowRedLight }; 

// Состояния работы
enum TrafficLightMode { Normal, Sleep, RedMode, GreenMode };
TrafficLightMode currentMode = Normal; 

unsigned long lastStateChange = 0; // Время последнего изменения состояния
const unsigned long redDuration = 5000; // Длительность красного
const unsigned long yellowDuration = 1000; // Длительность желтого
const unsigned long greenDuration = 2500; // Длительность зеленого
const unsigned long blinkDuration = 500; // Длительность мигания 
const unsigned long greenBlinkDuration = 2500; // Длительность мигания зеленого
const unsigned long greenBlinkInterval = 250; // Интервал мигания зеленого

TrafficLightState currentState = RedLight; // Переменная должна быть глобальной
bool isModeSet = false; // Флаг, указывающий, установлен ли режим

void setup() {
  Serial.begin(9600);  // Инициализация последовательного порта
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Выключаем все светодиоды
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'N':
        currentMode = Normal;
        Serial.println("Включён режим normal");
        isModeSet = true; // Устанавливаем флаг
        break;
      case 'S':
        currentMode = Sleep;
        Serial.println("Включён режим sleep");
        isModeSet = true; // Устанавливаем флаг
        break;
      case 'R':
        currentMode = RedMode;
        Serial.println("Включён режим red");
        isModeSet = true; // Устанавливаем флаг
        break;
      case 'G':
        currentMode = GreenMode;
        Serial.println("Включён режим green");
        isModeSet = true; // Устанавливаем флаг
        break;
    }
  }

  // Управление светофором только если режим установлен
  if (isModeSet) {
    switch (currentMode) {
      case Normal:
        // Нормальный режим (циклический)
        normalMode();
        break;
      case Sleep:
        // Спящий режим (мигающий желтый)
        sleepMode();
        break;
      case RedMode:
        // Только красный
        digitalWrite(redPin, HIGH);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
        break;
      case GreenMode:
        // Только зеленый
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, HIGH);
        break;
    }
  }
}

// Нормальный режим
void normalMode() {
  unsigned long currentTime = millis();
  if (currentTime - lastStateChange >= getDuration(currentState)) {
    currentState = getNextState(currentState);
    lastStateChange = currentTime;
  }

  // Устанавливаем состояние светодиодов
  switch (currentState) {
    case RedLight: 
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
      break;
    case RedYellowLight:
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
      break;
    case GreenLight:
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
      break;
    case YellowLight: 
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
      break;
    case YellowRedLight:
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
      break;
  }
}

// Спящий режим
void sleepMode() {
  unsigned long currentTime = millis();
  if (currentTime - lastStateChange >= blinkDuration) {
    digitalWrite(yellowPin, !digitalRead(yellowPin)); // Мигание желтого
    lastStateChange = currentTime;
  }
  // Выключаем красный
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
}

// Возвращает длительность текущего состояния
unsigned long getDuration(TrafficLightState state) {
  switch (state) {
    case RedLight:
      return redDuration;
    case RedYellowLight:
      return yellowDuration; // Длительность желтого в режиме RedYellowLight
    case GreenLight:
      return greenDuration;
    case YellowLight:
      return yellowDuration;
    case YellowRedLight:
      return yellowDuration; // Длительность желтого в режиме YellowRedLight
    default:
      return 0;
  }
}

// Возвращает следующее состояние
TrafficLightState getNextState(TrafficLightState state) {
  switch (state) {
    case RedLight:
      return RedYellowLight; 
    case RedYellowLight:
      return GreenLight; 
    case GreenLight:
      return YellowLight; 
    case YellowLight:
      return YellowRedLight; 
    case YellowRedLight:
      return RedLight; 
    default:
      return RedLight;
  }
}