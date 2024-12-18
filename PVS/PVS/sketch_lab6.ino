int buttonState = 0;
const int buttonPin = 2;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

}

void loop() {
   buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH)
  {
    Serial.println("on");
    
  }

  delay(200);

}