#define LED 13
#define PhotoResistor 0
#define UsersValue 1

int cnt = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  if (analogRead(PhotoResistor) > analogRead(UsersValue)) cnt = 0;
  if (analogRead(PhotoResistor) < analogRead(UsersValue)) cnt += 1;

  if (cnt > 100) {
    
    digitalWrite(LED, HIGH);
    do {
      delay(50);
    } while(analogRead(PhotoResistor) < analogRead(UsersValue));
    cnt = 0;
    digitalWrite(LED, LOW);
  }

  delay(10);



  // digitalWrite(LED, analogRead(PhotoResistor));
  // digitalWrite(LED, analogRead(PhotoResistor) < trashold ? HIGH : LOW);
  // Serial.println(analogRead(PhotoResistor));
}