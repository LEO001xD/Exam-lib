#include <Arduino.h>
//#define ldr_work2 34
//int led_work2[3] = {19, 18, 17};
void 001xd_work2_setup() {
  pinMode(ldr_work2,INPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(led_work2[i], OUTPUT);
  }
  Serial.begin(115200);
}

void 001xd_work3_loop() {
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
