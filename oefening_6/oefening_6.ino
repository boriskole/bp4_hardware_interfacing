#include <Servo.h>

const int JOYSTICK_HORIZONTAL_PIN = A0;
const int JOYSTICK_BUTTON_PIN = 0;
const int SERVO_MOTOR_PIN = 11;

Servo servoMotor;
int servoPosition = 0;
bool shouldMoveForward = true;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_MOTOR_PIN);
}

void loop() {
  // Data ophalen uit de joystick.
  int joystickHorizontal = analogRead(JOYSTICK_HORIZONTAL_PIN);
  int joystickButton = digitalRead(JOYSTICK_BUTTON_PIN);

  // De 0 tot 1023 omzetten naar links-midden-rechts.
  int joystickDirection = map(joystickHorizontal, 0, 1023, 0, 3);

  if (joystickButton == LOW) { // De joystick wordt ingedrukt
    rotateServo();
  }

  if (joystickDirection == 0) { // De joystick wordt naar links geduwd.
    moveServoLeft();
  }

  if (joystickDirection == 2) { // De joystick wordt naar rechts geduwd.
    moveServoRight();
  }

}

void rotateServo() {
  // Code gekopieerd uit opdracht 5.
  if (shouldMoveForward) {

    servoPosition++;

    if (servoPosition >= 180) { // Maximaal is bereikt.
      shouldMoveForward = false; // Status op achteruit zetten.
    }

  } else {

    servoPosition--;

    if (servoPosition <= 0) { // Minimaal is bereikt.
      shouldMoveForward = true; // Status op vooruit zetten.
    }

  }

  delay(20);
  servoMotor.write(servoPosition);

}

void moveServoDirection() {
  servoPosition = constrain(servoPosition, 0, 180); // Zorgen dat de positie niet te ver buiten te max en min kan gaan.
  servoMotor.write(servoPosition -= 1);
  delay(20);
}

void moveServoRight() {
  servoPosition = constrain(servoPosition, 0, 180); // Zorgen dat de positie niet te ver buiten te max en min kan gaan.
  servoMotor.write(servoPosition += 1);
  delay(20);
}
