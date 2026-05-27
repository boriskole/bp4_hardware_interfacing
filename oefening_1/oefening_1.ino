void setup() {
  // Correcte pinmodes instellen.
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // Alleen licht 1 aan en licht 2 uit.
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  delay(1000);

  // Alleen licht 2 aan en licht 1 uit.
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(1000);
}
