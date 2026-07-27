#include <Servo.h>

Servo myServo;

const int potPin = A0;
int potValue = 0;
int angle = 0;

void setup() {
  myServo.attach(9);
}

void loop() {
  potValue = analogRead(potPin);

  // map potentiometer (0–1023) to servo angle (0–180)
  angle = map(potValue, 0, 1023, 0, 180);

  // smooth movement (optional filtering)
  static float smoothAngle = 90;
  smoothAngle = (smoothAngle * 0.8) + (angle * 0.2);

  myServo.write((int)smoothAngle);

  delay(10);
}
