int pressedCount = 0;

void setup() {
  // Pins instellen.
  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  
  if (digitalRead(11) == HIGH) { // Wanneer er geklikt wordt op de knop.
    pressedCount++;
    toggleButton();
    delay(300); // Zodat de knop logica niet dubbel wordt uitgevoerd.
  }

}

void toggleButton() {

  if (pressedCount % 2 == 0) { // De knop moet nu uit gaan.
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
  
}
