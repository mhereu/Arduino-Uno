void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    switch (Serial.read()) {
      case '0':
        digitalWrite(LED_BUILTIN, LOW);
        break;
      case '1':
        digitalWrite(LED_BUILTIN, HIGH);
        break;
    }
  }
}
