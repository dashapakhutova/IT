#define led_pin 3
#define sensor_pin A2

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if (Serial.available()  > 0) {
    char message = Serial.read();
    if (message == 'u') {
      digitalWrite(led_pin, HIGH);
    } else if (message == 'd'){
      digitalWrite(led_pin, LOW);
    } else {
      Serial.println("Unknown message");
    }
  }
  int val = analogRead(sensor_pin);
  Serial.println(val);
}