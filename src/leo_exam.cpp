#include <Arduino.h>
#include <HCSR04.h>
#include <ESP32Servo.h>//work4
#include <LiquidCrystal.h>//work5

namespace work1{
void dx100_setup(const uint8_t led_work1[], const uint8_t arrayLength) {
  for (int i = 0; i < arrayLength; i++) {
    pinMode(led_work1[i], OUTPUT);
  }
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void dx100_loop(const uint8_t led_work1[], const uint8_t arrayLength) {
  for (int i = 0; i < arrayLength; i++) {
    digitalWrite(led_work1[i], HIGH);
    delay(100);
  }
  for (int i = arrayLength; i >= 0; i--) {
    digitalWrite(led_work1[i], LOW); // Subtract 1 because array indices start from 0
    delay(100);
  }
  delay(10); // this speeds up the simulation
}
}//namespace work1

namespace work2{
void dx100_setup(const uint8_t ldr_work2, const uint8_t led_work2[], const uint8_t arrayLength) {
  pinMode(ldr_work2,INPUT);
  for (int i = 0; i < arrayLength; i++) {
    pinMode(led_work2[i], OUTPUT);
  }
  Serial.begin(115200);
}

void dx100_loop(const uint8_t ldr_work2, const uint8_t led_work2[], const uint8_t arrayLength) {
  int sun = analogRead(ldr_work2);
  Serial.print("sun >>");
  Serial.println(sun);
  delay(100);
  if (sun <= 1000) {
    for (int i = 0; i < arrayLength; i++) {
    digitalWrite(led_work2[i], 1);
    }
  }
  else {
    for (int i = 0; i < arrayLength; i++) {
      digitalWrite(led_work2[i], 0);
    }
  }
}
}//namespace work2
namespace work3{
HCSR04 hc(16, 17);
void dx100_setup(const uint8_t led1_work3, const uint8_t led2_work3, const uint8_t led3_work3) {
  pinMode(led1_work3, OUTPUT);
  pinMode(led2_work3, OUTPUT);
  pinMode(led3_work3, OUTPUT);
  Serial.begin(115200);
}
void dx100_loop(const uint8_t led1_work3, const uint8_t led2_work3, const uint8_t led3_work3) {
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
}//namespace work3
namespace work4{
HCSR04 hc(16, 17);
Servo servo; 
void dx100_setup(const uint8_t servo_work4) { 
  servo.attach(servo_work4, 500, 2400);
  Serial.begin(115200);
}
void dx100_loop() {
  int distance = hc.dist();
  Serial.println(distance); 
  delay(100);
  if (distance >= 0 && distance <= 5) {
    servo.write(45);
    delay(100);
  } else if (distance > 5 && distance < 11) {
    servo.write(90);
    delay(100);
  } else if (distance >= 11 && distance <= 20) {
    servo.write(180);
    delay(100);
  }
}
}//namespace work4
namespace work5{
int potenVal;
HCSR04 hc(16, 17);

void dx100_setup(const uint8_t potentio_work5, LiquidCrystal lcd) {
  pinMode(potentio_work5, INPUT);
  lcd.begin(16, 2);
  Serial.begin(115200);
}
void dx100_loop(const uint8_t potentio_work5, LiquidCrystal lcd) {
  int distance = hc.dist();
  lcd.setCursor(0, 0);
  lcd.print("distance : "); 
  lcd.print(distance);
  lcd.print("        "); 
  delay(1);
  potenVal =  analogRead(potentio_work5);
  lcd.setCursor(0, 1);
  lcd.print("Potentio : ");
  lcd.print(potenVal);
  lcd.print("      "); 
  delay(1);
  Serial.print("distance:");
  Serial.println(distance);
  Serial.print("potentio:");
  Serial.println(potenVal);
}
}//namespace work5
