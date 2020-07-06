//common
int ledCount = 6;
int leds[] = {3,5,6,9,10,11};
int pushButton = 2;
int state = HIGH;
int last_state = HIGH;
int currentEffect = 0;
int amountEffects = 5;
unsigned long currentMillis;

//knightRider
int currentLed = 0;
int currentLedBrightness = 0;
int prevLed = -1;
int prevLedBrightness = 0;
int moveDirection = 1;  // 1 left to right, -1 right to left

//snake, splitIn, splitOut
unsigned long previousMillis = 0;
const long interval = 200;
int i, k, l = 0;
int brightness, brightness2, brightness3 = 0;

//random
int random_num = 0;
int previous = 0;

void setup() {
  randomSeed(analogRead(0));
  pinMode(pushButton, INPUT_PULLUP);
  for (int i=0;i<ledCount;i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void knightRider() {
  if (currentLedBrightness < 255) {
    currentLedBrightness = currentLedBrightness + 2;
    analogWrite(leds[currentLed], currentLedBrightness);
    if (prevLed >= 0) {
      if (currentLedBrightness < 255) {
        prevLedBrightness = 255 - currentLedBrightness;
      } else {
        prevLedBrightness = 0;
      }
      analogWrite(leds[prevLed], prevLedBrightness);
    }
  } else {
    prevLed = currentLed;
    if (currentLed == ledCount-1) {
      moveDirection = -1;
    } else if (currentLed == 0) {
      moveDirection = 1;
    }
    currentLed = currentLed + (1*moveDirection);
    currentLedBrightness = 0;
  }
  delay(1);  
}

void snake() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    for (int j=0;j<=i;j++){
      analogWrite(leds[j], brightness);
    }
    i++;
    if (i == ledCount) {
      brightness = (brightness == 0) ? 255 : 0;
      i = 0;
    }
  }
}

void splitIn() {
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (k > 0) {
      analogWrite(leds[k-1], 0);
      analogWrite(leds[ledCount-k], 0);
    }
    analogWrite(leds[k], brightness2);
    analogWrite(leds[ledCount-1-k], brightness2);
    if (k < ledCount/2) {
      k++;
    } else {
      brightness2 = (brightness2 == 0) ? 255 : 0;
      k=0;
    }
  }
}

void splitOut() {
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (l > 0) {
      analogWrite(leds[ledCount/2 + l-1], 0);
      analogWrite(leds[ledCount/2 -1-l+1], 0);
    }
    analogWrite(leds[ledCount/2 + l], brightness3);
    analogWrite(leds[ledCount/2 -1-l], brightness3);
    if (l < ledCount/2) {
      l++;
    } else {
      brightness3 = (brightness3 == 0) ? 255 : 0;
      l=0;
    }
  }
}

void randomLed() {
  analogWrite(leds[previous], 0);
  analogWrite(leds[random_num], 255);
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    previous = random_num;
    random_num = random(0, ledCount);
  }  
}

int nextEffect() {
  if (currentEffect >= amountEffects-1) {
    currentEffect = 0;
  } else {
    currentEffect++;
  }
  delay(100);
}

void loop() {
  currentMillis = millis();
  state = digitalRead(pushButton);
  if (state != last_state) {
    if (state == LOW) {
      nextEffect();
    }
  }
  last_state = state;
  switch (currentEffect) {
    case 0:
      knightRider();
      break;
    case 1:
      randomLed();
      break;
    case 2:
      snake();
      break;
    case 3:
      splitIn();
      break;
    case 4:
      splitOut();
      break;
  }
}
