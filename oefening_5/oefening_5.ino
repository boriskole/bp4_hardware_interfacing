#include <Servo.h>

// Vaste variabelen instellen:
const int BUTTON_1_PIN = 13;
const int BUTTON_2_PIN = 9;
const int SERVO_PIN = 3;
const int SERVO_NORMAL_MOVE_DELAY = 8;
const int SERVO_FAST_MOVE_DELAY = 4;

// Variabelen:
Servo servoMotor;
int servoPosition = 0;
bool shouldMoveForward = true;

void setup() {
  Serial.begin(9600);

  // Servo motor 'starten' op pin 3.
  servoMotor.attach(SERVO_PIN);

  // Pin modes instellen op input.
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
}

void loop() {
  // Debug:
  Serial.print("My servo position is: ");
  Serial.println(servoPosition);

  bool isButton1Pressed = digitalRead(BUTTON_1_PIN);
  bool isButton2Pressed = digitalRead(BUTTON_2_PIN);

  if (isButton1Pressed && isButton2Pressed) { // Beide knoppen zijn ingedrukt.
    moveServoMotor(true); 
    delay(SERVO_NORMAL_MOVE_DELAY); // 120 keer 8 is 960. Dus ongv 1 seconde.
  } else if (isButton1Pressed) { // Alleen knop 1 is ingedrukt.
    moveServoMotor(false);
    delay(SERVO_NORMAL_MOVE_DELAY); // 120 keer 8 is 960. Dus ongv 1 seconde.
  } else if (isButton2Pressed) { // Alleen knop 2 is ingedukt.
    moveServoMotor(false);
    delay(SERVO_FAST_MOVE_DELAY); // 120 * 4 = 480. ongv 0.5 seconde.
  }

}

void moveServoMotor(bool pausesInMiddle) {

  if (shouldMoveForward) {

    servoPosition++;

    if (servoPosition >= 120) { // Maximaal is bereikt.
      shouldMoveForward = false; // Status op achteruit zetten.

      // Als de servo motor moet pauzeren na gaan van 0 naar 120.
      if (pausesInMiddle) {
        delay(2000); // 2 seconden wachten.
      }

    }

  } else {

    servoPosition--;

    if (servoPosition <= 0) { // Minimaal is bereikt.
      shouldMoveForward = true; // Status op vooruit zetten.

      // Als de servo motor moet pauzeren na gaan van 120 naar 0.
      if (pausesInMiddle) {
        delay(2000); // 2 seconden wachten.
      }
    }

  }

  servoMotor.write(servoPosition);

}
