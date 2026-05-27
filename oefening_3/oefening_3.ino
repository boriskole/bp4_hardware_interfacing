int pressedCount = 0;

// Om bij te houden of de knop ingedrukt wordt.
int lastButtonState = LOW;
int currentButtonState;

void setup() {
  // Pins instellen.
  pinMode(11, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {

  // Kijken wat voor state de knop heeft.
  currentButtonState = digitalRead(11);
  
  if (isButtonPressedDown()) { // Wanneer er geklikt wordt op de knop.
    pressedCount++;
    toggleButton();
    delay(200); // Zodat de knop logica niet dubbel wordt uitgevoerd.
  }

  // Het status bewaren voor de volgende loop.
  lastButtonState = currentButtonState;

}

void toggleButton() {

  if (pressedCount % 2 == 0) { // De knop moet nu uit gaan.
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
  
}

bool isButtonPressedDown() {
  return currentButtonState == HIGH
  && lastButtonState == LOW; // Dit deel zorgt ervoor dat de knop eerst weer een keer omhoog moet gaan om nog een keer geactiveerd te kunnen worden.
}
