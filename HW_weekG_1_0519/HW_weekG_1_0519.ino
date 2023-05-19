#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9 
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0   

#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262

const int row[] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8
};
const int col[] = {
  COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8
};
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};      //

byte A[8][8] = {
  {1,1,1,0,0,1,1,1},
  {1,0,0,1,1,0,0,1},
  {1,0,1,1,1,1,0,1},
  {1,0,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,0,1},
  {1,0,1,1,1,1,0,1},
  {1,0,1,1,1,1,0,1}
};      //
  
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int thisNote = -1, noteDuration = 0;
long previousTime = 0, presentTime = 0, pauseBetweenNotes = 0;
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

void checkToPlay(){
  presentTime = millis();
  if(presentTime - previousTime >= pauseBetweenNotes){
    thisNote += 1;
    if(thisNote >= 8){
      thisNote = -1;
      pauseBetweenNotes = 100;
      previousTime = millis();
    }
    else{
      noteDuration = 500 / noteDurations[thisNote];
      tone(9, melody[thisNote], noteDuration);
      pauseBetweenNotes = noteDuration * 1.2;
      previousTime = millis();
    }
  }
}

void setup(){
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop(){

  for(int i = 0; i < 8; i++){
    digitalWrite(latchPin,LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
    digitalWrite(latchPin,HIGH);
    checkToPlay();
    delay(1);
  }
  
}
