#include <Arduino.h>
#include <HCSR04.h>
//#define ldr_work2 34
//int led_work2[3] = {19, 18, 17};
void 001xd_work2_setup() {
  pinMode(ldr_work2,INPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(led_work2[i], OUTPUT);
  }
  Serial.begin(115200);
}

void 001xd_work2_loop() {
  int sun = analogRead(ldr_work2);
  Serial.print("sun >>");
  Serial.println(sun);
  delay(100);
  if (sun <= 1000) {
    for (int i = 0; i < 3; i++) {
    digitalWrite(led_work2[i], 1);
    }
  }
  else {
    for (int i = 0; i < 3; i++) {
      digitalWrite(led_work2[i], 0);
    }
  }
}
void 001xd_work3_setup() {
  HCSR04 hc(16, 17); //initialisation class HCSR04 (trig pin , echo pin)void setup() {
  pinMode(led1_work3, OUTPUT);
  pinMode(led2_work3, OUTPUT);
  pinMode(led3_work3, OUTPUT);
  Serial.begin(115200);
}
void 001xd_work3_loop() {
  int distance = hc.dist();
  Serial.println(distance); //return current distance (cm) in serial
  delay(100);
  if (distance >= 0 && distance <= 5) {
    digitalWrite(led1_work3, HIGH);
    digitalWrite(led2_work3, LOW);
    digitalWrite(led3_work3, LOW);
  } else if (distance > 5 && distance < 11) {
    digitalWrite(led2_work3, HIGH);
    digitalWrite(led1_work3, LOW);
    digitalWrite(led3_work3, LOW);
  } else if (distance >= 11) {
    digitalWrite(led3_work3, HIGH);
    digitalWrite(led1_work3, LOW);
    digitalWrite(led2_work3, LOW);
  }
}

