const int redPin = 9;   // Пин для красного светодиода
const int yellowPin = 10; // Пин для желтого светодиода
const int greenPin = 11; // Пин для зеленого светодиода

// Состояния светофора
enum TrafficLightState { RedLight, RedYellowLight, GreenLight, YellowLight, YellowRedLight }; 

unsigned long lastStateChange = 0; // Время последнего изменения состояния
const unsigned long redDuration = 5000; // Длительность красного
const unsigned long yellowDuration = 1000; // Длительность желтого
const unsigned long greenDuration = 2500; // Длительность зеленого

TrafficLightState currentState = RedLight;  // Начальное состояние - красный

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Выключаем все светодиоды
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

void loop() {
  // Проверяем время, прошедшее с последнего изменения состояния
  unsigned long currentTime = millis();
  if (currentTime - lastStateChange >= getDuration(currentState)) {
    // Переходим к следующему состоянию
    currentState = getNextState(currentState);
    lastStateChange = currentTime;
  }

  // Устанавливаем состояние светодиодов в соответствии с текущим состоянием
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

// Возвращает длительность текущего состояния
unsigned long getDuration(TrafficLightState state) {
  switch (state) {
    case RedLight:
      return redDuration;
    case RedYellowLight:
      return yellowDuration;
    case GreenLight:
      return greenDuration;
    case YellowLight:
      return yellowDuration;
    case YellowRedLight:
      return yellowDuration;
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
