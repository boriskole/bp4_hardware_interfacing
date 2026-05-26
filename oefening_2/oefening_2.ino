const int usedPins[] = {13, 12, 11, 10, 9, 8, 7, 6};

void setup() {
  // Alle pins in de array op output zetten.
  for (int i = 0; i < 8; i++) {
    pinMode(usedPins[i], OUTPUT);
  }
}

void loop() {
  // Links naar rechts.
  for (int i = 0; i < 8; i++) {
    flickerLight(usedPins[i]);
  }

  // Rechts naar linsks.
  for (int i = 7; i >= 0; i--) { // Hier 7 ipv 8, omdat licht 8 al staat door de loop hiervoor.
    flickerLight(usedPins[i]);
  }
}

// Methode om licht aan te zetten even wachten en dan weer uit te zetten.
void flickerLight(int pinPosition) {
  digitalWrite(pinPosition, HIGH);
  delay(80);
  digitalWrite(pinPosition, LOW);
}