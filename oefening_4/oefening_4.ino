const int usedDigitalPins[] = {13, 12, 11, 10, 9, 8, 7};
const int digitalPinCount = 7;

void setup() {
    // De pin mode op output zetten voor elke digitale pin.
    for (int i = 0; i < digitalPinCount; i++) {
        pinMode(usedDigitalPins[i], OUTPUT);
    }

    Serial.begin(9600);
}

void loop() {

    // Aantal LED's die aangezet moeten worden ophalen.
    int activeLedCount = getActiveLedCount();

    // Zet LEDs aan tot aan activeLedCount.
    for (int i = 0; i < digitalPinCount; i++) {
        digitalWrite(
            usedDigitalPins[i],
            i < activeLedCount ? HIGH : LOW
        );
    }

}

// Helper function die berekent hoe veel LED's aan moeten staan.
int getActiveLedCount() {
    // Waarde ophalen uit de potmeter.
    int rawPotmeterValue = analogRead(A0);

    Serial.println(rawPotmeterValue);

    // De waarde van de potmeter omzetten naar een lichtniveau 0 t/m 7.
    return map(rawPotmeterValue, 0, 1023, 0, 8);
}