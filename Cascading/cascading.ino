#include <SoftwareSerial.h>
#define u_down 2
#define u_left 3
#define u_up 4
#define u_right 12
#define d_left 6
#define d_down 7
#define d_right 8
#define d_point 9
SoftwareSerial mySerial(11, 10);

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  mySerial.begin(9600);
  while (!mySerial) {}

  pinMode(u_left, OUTPUT);
  pinMode(u_right, OUTPUT);
  pinMode(u_up, OUTPUT);
  pinMode(u_down, OUTPUT);
  pinMode(d_right, OUTPUT);
  pinMode(d_left, OUTPUT);
  pinMode(d_down, OUTPUT);
  pinMode(d_point, OUTPUT);
}

void turn_off_all(){
  digitalWrite(u_up, LOW);
  digitalWrite(u_left, LOW);
  digitalWrite(u_right, LOW);
  digitalWrite(u_down, LOW);
  digitalWrite(d_down, LOW);
  digitalWrite(d_left, LOW);
  digitalWrite(d_right, LOW);
  digitalWrite(d_point, LOW);
}

void turn_on_all(){
  digitalWrite(u_up, HIGH);
  digitalWrite(u_left, HIGH);
  digitalWrite(u_right, HIGH);
  digitalWrite(u_down, HIGH);
  digitalWrite(d_down, HIGH);
  digitalWrite(d_left, HIGH);
  digitalWrite(d_right, HIGH);
  digitalWrite(d_point, HIGH);
}

void turn_by_string(String inp){
  if (inp.charAt(0) == '1'){
    digitalWrite(u_up, HIGH);
  }
  if (inp.charAt(1) == '1'){
    digitalWrite(u_left, HIGH);
  }
  if (inp.charAt(2) == '1'){
    digitalWrite(u_right, HIGH);
  }
  if (inp.charAt(3) == '1'){
    digitalWrite(u_down, HIGH);
  }
  if (inp.charAt(4) == '1'){
    digitalWrite(d_left, HIGH);
  }
  if (inp.charAt(5) == '1'){
    digitalWrite(d_right, HIGH);
  }
  if (inp.charAt(6) == '1'){
    digitalWrite(d_down, HIGH);
  }
  if (inp.charAt(7) == '1'){
    digitalWrite(d_point, HIGH);
  }
}

void turn_0(){
  turn_off_all();
  turn_by_string("11101110");
}

void turn_1(){
  turn_off_all();
  turn_by_string("00100100");
}

void turn_2(){
  turn_off_all();
  turn_by_string("10111010");
}

void turn_3(){
  turn_off_all();
  turn_by_string("10110110");
}

void turn_4(){
  turn_off_all();
  turn_by_string("01110100");
}

void turn_5(){
  turn_off_all();
  turn_by_string("11010110");
}

void turn_6(){
  turn_off_all();
  turn_by_string("11011110");
}

void turn_7(){
  turn_off_all();
  turn_by_string("10100100");
}

void turn_8(){
  turn_off_all();
  turn_by_string("11111110");
}

void turn_9(){
  turn_off_all();
  turn_by_string("11110110");
}

void turns(String inp){
  if (inp == "on\n") {
    turn_on_all();
  } else if (inp == "off\n") {
    turn_off_all();
  } else if (inp == "0\n") {
    turn_0();
  } else if (inp == "1\n") {
    turn_1();
  } else if (inp == "2\n") {
    turn_2();
  } else if (inp == "3\n") {
    turn_3();
  } else if (inp == "4\n") {
    turn_4();
  } else if (inp == "5\n") {
    turn_5();
  } else if (inp == "6\n") {
    turn_6();
  } else if (inp == "7\n") {
    turn_7();
  } else if (inp == "8\n") {
    turn_8();
  } else if (inp == "9\n") {
    turn_9();
  }
}

void loop() {
  if (mySerial.available()) {
    String keke = Serial.readString() + "\n";
    turns(keke);
  }
}
