//pressing nothing to display value of analog revolving potentiometer
//pressing key1 to show 0-3 on LED Segment Displays
//pressing key2 and buzzer ringing
//pressing key3 and flowing light on

//defining three pins of 74HC595
int latchPin = 4;//ST_CP
int clockPin = 5;//SH_CP
int dataPin = 2; //DS

//defining three key input
int key1 = A1;
int key2 = A2;
int key3 = A3;

//buzzer pin
int buzzer = 3;

//pin definition of flowing light
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;


int dat_wei[4] = {0x01, 0x02, 0x04, 0x08}; //LED Segment Displays
//showing 1--4
int dat_duan[11] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0xF7}; //LED Segment Displays showing 0--9
const byte numeros[16] = {
  0b11111100,
  0b01100000,
  0b11011010,
  0b11110010,
  0b01100110,
  0b10110110,
  0b10111110,
  0b11100000,
  0b11111110,
  0b11100110,
  0b11101110,
  0b00111110,
  0b10011100,
  0b01111010,
  0b10011110,
  0b10001110
};

const byte my_bin10b[10] = {
  0b0000,
  0b0001,
  0b0010,
  0b0011,
  0b0100,
  0b0101,
  0b0110,
  0b0111,
  0b1000,
  0b1001
};

char i = 0;

void setup ()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(key1, INPUT);
  pinMode(key2, INPUT);
  pinMode(key3, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  for (char i = 8; i < 14; i++)
    digitalWrite(i, HIGH);

  digitalWrite(buzzer, HIGH); //to avoid low noice at the startup
}

void loop()
{
  if (digitalRead(key1) == LOW )
    //SMG();                    //testing LED Segment Displays
    analog();                //testing analog input
  if (digitalRead(key2) == LOW )
    buzzer_();                //testing buzzer
  if (digitalRead(key3) == LOW)
    led_display();            //testing LED
  if (digitalRead(key1) == HIGH & digitalRead(key2) == HIGH & digitalRead(key3) == HIGH)
    //analog();                //testing analog input
    SMG();                    //testing LED Segment Displays
}

void SMG(void)
{
  digitalWrite(latchPin, LOW);                        //clear LED Segment Displays
  shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
  shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
  digitalWrite(latchPin, HIGH);

  for (i=0; i*100<=10000; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]);
    digitalWrite(latchPin, HIGH);
    delay(i);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[2]);
    digitalWrite(latchPin, HIGH);
    delay(i);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[1]);
    digitalWrite(latchPin, HIGH);
    delay(i);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[0]);
    digitalWrite(latchPin, HIGH);
    delay(i);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[1]);
    digitalWrite(latchPin, HIGH);
    delay(i);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[2]);
    digitalWrite(latchPin, HIGH);
    delay(i);
  }

//  while (1)
//  {
    //                                      hgfedcba
//    // arranca loop
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b11111110);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]); 
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b11111101);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]); 
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b11111011);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]); 
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b11110111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]); 
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b11101111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]); 
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b11011111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]);
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//    // fin loop

//    // arranca nightrider
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]);
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[2]);
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[1]);
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[0]);
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[1]);
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//    shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[2]);
//    digitalWrite(latchPin, HIGH);
//    delay(100);
//    // fin nightrider

//    for (i=50; i*2<=1000; i++) {
//      digitalWrite(latchPin, LOW);
//      shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]);
//      digitalWrite(latchPin, HIGH);
//      delay(i);
//      digitalWrite(latchPin, LOW);
//      shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[2]);
//      digitalWrite(latchPin, HIGH);
//      delay(i);
//      digitalWrite(latchPin, LOW);
//      shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[1]);
//      digitalWrite(latchPin, HIGH);
//      delay(i);
//      digitalWrite(latchPin, LOW);
//      shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[0]);
//      digitalWrite(latchPin, HIGH);
//      delay(i);
//      digitalWrite(latchPin, LOW);
//      shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[1]);
//      digitalWrite(latchPin, HIGH);
//      delay(i);
//      digitalWrite(latchPin, LOW);
//      shiftOut(dataPin, clockPin, MSBFIRST, 0b10111111);
//      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[2]);
//      digitalWrite(latchPin, HIGH);
//      delay(i);
//    }


//    for (i = 0; i < 10; i++) {
//      delay(500);
//      digitalWrite(latchPin, LOW);
//      shiftOut(dataPin, clockPin, MSBFIRST, dat_duan[i]);
//      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[0]);   //way of MSBFIRST,data about first piece
//      digitalWrite(latchPin, HIGH);
//    }
//    delay(1000);

//    for (i = 0; i < 10; i++) {
//      delay(1000);
//      digitalWrite(latchPin, LOW);
//      shiftOut(dataPin, clockPin, LSBFIRST, my_bin10b[i]);
//      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]);   //way of MSBFIRST,data about first piece
//      digitalWrite(latchPin, HIGH);
//    }
//    delay(1000);

    //    for (i = 0; i < 16; i++) {
    //      delay(1000);
    //      digitalWrite(latchPin, LOW);
    //      shiftOut(dataPin, clockPin, LSBFIRST, numeros[i]);
    //      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[2]);   //way of MSBFIRST,data about first piece
    //      digitalWrite(latchPin, HIGH);
    //    }
    //    delay(1000);

    //    //count up routine
    //    for (int j = 0; j < 256; j++) {
    //      // pone a masa latchPin y lo mantiene a nivel bajo durante la transmisión
    //      digitalWrite(latchPin, LOW);
    //      shiftOut(dataPin, clockPin, LSBFIRST, j);
    //      shiftOut(dataPin, clockPin, MSBFIRST , dat_wei[3]);   //way of MSBFIRST,data about first piece
    //      // devuelve el latch pin a nivel alto indicando al chipque
    //      // ya no necesita escuchar la información
    //      digitalWrite(latchPin, HIGH);
    //      delay(1000);
    //    }

//    if (digitalRead(key1) == HIGH)
//    {
//      digitalWrite(latchPin, LOW);                        //clear LED Segment Displays
//      shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
//      shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
//      digitalWrite(latchPin, HIGH);
//      break;
//    }
//  }
}

void buzzer_(void)
{
  char i;

  digitalWrite(latchPin, LOW);                        //clear LED Segment Displays
  shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
  shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
  digitalWrite(latchPin, HIGH);

  while (1)
  {
    for (i = 0; i < 80; i++) // output a frequency sound
    {
      digitalWrite(buzzer, LOW); // sound
      delay(1);//delay1ms
      digitalWrite(buzzer, HIGH); //not sound
      delay(1);//ms delay
    }
    for (i = 0; i < 100; i++) // output a frequency sound
    {
      digitalWrite(buzzer, LOW); // sound
      digitalWrite(buzzer, HIGH); //not sound
      delay(4);//2ms delay
    }
    if (digitalRead(key2) == HIGH)
    {
      digitalWrite(latchPin, LOW);                        //clear LED Segment Displays
      shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
      shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
      digitalWrite(latchPin, HIGH);
      break;
    }
  }
}

void led_display()
{
  digitalWrite(latchPin, LOW);                        //clear LED Segment Displays
  shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
  shiftOut(dataPin, clockPin, MSBFIRST , 0x00);
  digitalWrite(latchPin, HIGH);

  while (1)
  {
    digitalWrite(led1, LOW);
    delay(100);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(100);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    delay(100);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    delay(100);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, LOW);
    delay(100);
    digitalWrite(led6, HIGH);
    if (digitalRead(key3) == HIGH)
    {
      break;
    }
  }
}


void analog()
{
  int val, qian, bai, shi, ge;
  val = analogRead(A0);
  qian = val / 1000;
  bai = val % 1000;
  bai = bai / 100;
  shi = val % 100;
  shi = shi / 10;
  ge = val % 10;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST , dat_duan[qian]);
  shiftOut(dataPin, clockPin, MSBFIRST , 0x01);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST , dat_duan[bai]);
  shiftOut(dataPin, clockPin, MSBFIRST , 0x02);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST , dat_duan[shi]);
  shiftOut(dataPin, clockPin, MSBFIRST , 0x04);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST , dat_duan[ge]);
  shiftOut(dataPin, clockPin, MSBFIRST , 0x08);
  digitalWrite(latchPin, HIGH);
}
