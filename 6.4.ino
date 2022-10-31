int switch_pin = 8;
int led_pin = 11;

boolean last = LOW;
boolean current = LOW;
int lvl = 0;

void setup() {
	pinMode(switch_pin, INPUT);
	pinMode(led_pin, OUTPUT);
}

boolean debounse(boolean last) {
	boolean current = digitalRead(switch_pin);
	if(last != current) {
		delay(5);
		current = digitalRead(switch_pin);
	}
	return current;
}

void loop() {
	current = debounse(last);
	if(last == LOW && current == HIGH) {
		lvl = lvl + 51;
	}
	last = current;

	if(lvl > 255) lvl = 0;
	analogWrite(led_pin, lvl);
}