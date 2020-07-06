const int buttonStartRecordPin = 2;
const int buttonStopRecordPin = 3;
const int buttonLightSignalPin = 4;
const int ledStartRecordPin =  5;
const int ledStopRecordPin =  6;
const int ledLightSignalPin =  7;
const int ledPin =  13;

int startRecord = 0;
int stopRecord = 0;
int lightSignal = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonStartRecordPin, INPUT);
  pinMode(buttonStopRecordPin, INPUT);
  pinMode(buttonLightSignalPin, INPUT);
}

void blink(int count = 2, int demora = 50) {
  for (int i = 0; i < count; i++) {
    digitalWrite(ledPin, HIGH);
    delay(demora);
    digitalWrite(ledPin, LOW);
    delay(demora);
  }
}

void loop() {
  int recordLeng = 100;
  int lightRecord[recordLeng] = {};
  startRecord = digitalRead(buttonStartRecordPin);
  if (startRecord == HIGH) {
    digitalWrite(ledStartRecordPin, HIGH);
    delay(1000);
    digitalWrite(ledStartRecordPin, LOW);
    for (int i = 0; i < recordLeng && stopRecord != HIGH; i++) {
      stopRecord = digitalRead(buttonStopRecordPin);
      if (stopRecord == HIGH) {
        digitalWrite(ledStopRecordPin, HIGH);
        delay(1000);
        digitalWrite(ledStopRecordPin, LOW);
        recordLeng = i;
      }
      lightRecord[i] = digitalRead(buttonLightSignalPin);
      if (lightRecord[i] == HIGH) {
        digitalWrite(ledLightSignalPin, HIGH);
      } else {
        digitalWrite(ledLightSignalPin, LOW);
      }
      delay(100);
    }
    for (int i = 0; i < 3; i++) {
      blink();
      for (int i = 0; i < recordLeng; i++) {
        if (lightRecord[i] == HIGH) {
          digitalWrite(ledLightSignalPin, HIGH);
        } else {
          digitalWrite(ledLightSignalPin, LOW);
        }
        delay(100);
      }
    }
    blink(10, 60);
  }
}
