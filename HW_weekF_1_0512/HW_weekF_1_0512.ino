#include "pitches.h"
#define BUTTON 6

int melody1[] = {
  NOTE_B4, NOTE_B4, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5
};
int melody2[] = {
  NOTE_B3, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 8, 4,
};

void setup() {
  // iterate over the notes of the melody:
   pinMode(6, INPUT_PULLUP);  
   Serial.begin(9600);
}

byte present=1,previous=1,num=0;

void loop() {

  Serial.println(num);
  
  if(num==0){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody1[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
      present = digitalRead(BUTTON);
  if(present==1&&previous==0){
    num++;
    if(num>1)num=0;
    thisNote=8;
  }
  previous=present;
    //present=digitalRead(BUTTON);if(present==0)break;
  }
  }

  else if(num==1){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
       int noteDuration = 1000 / noteDurations[thisNote];
       tone(8, melody2[thisNote], noteDuration);

       int pauseBetweenNotes = noteDuration * 1.30;
       delay(pauseBetweenNotes);
       noTone(8);
         present = digitalRead(BUTTON);
  if(present==1&&previous==0){
    num++;
    if(num>1)num=0;
    thisNote=8;
  }
  previous=present;
      // present=digitalRead(BUTTON);if(present==0)break;
    }
  }

  delay(200);
  
  // no need to repeat the melody.
}
