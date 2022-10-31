const int  buttonPin = 2;
const int ledPin = 8;

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
    } else {
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;

  digitalWrite(ledPin, buttonPushCounter % 2);
}