#include <LiquidCrystal_I2C.h>

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-ultrasonic-sensor-lcd
 */

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // I2C address 0x3F, 16 column and 2 rows

int trigPin = 7;    // TRIG pin
int echoPin = 6;    // ECHO pin

long duration_us, distance_cm;

void setup() {
  Serial.begin(9600);
  lcd.init();               // initialize the lcd
  lcd.backlight();          // open the backlight 
  pinMode(trigPin, OUTPUT); // config trigger pin to output mode
  pinMode(echoPin, INPUT);  // config echo pin to input mode 
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = duration_us * 0.034/2;
  Serial.println(distance_cm);
     
  lcd.setCursor(0, 0); // start to print at the first row
  lcd.print("Distance: ");,
  lcd.print(distance_cm);

  delay(1000);
}
