
// display a number on the digital segment display

void sevenSegWrite(byte digit) {
  // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);
     
  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, Numbers[digit]);  
 
  // set the latchPin to high potential, after sending data
  digitalWrite(latchPin, HIGH);
}

void sevenSegWrite_char(byte digit) {
  // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);
     
  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, SpecialChar[digit]);  
 
  // set the latchPin to high potential, after sending data
  digitalWrite(latchPin, HIGH);
}

void sevenSegWrite_Anim(byte digit) {
  // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);
     
  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, Anim[digit]);  
 
  // set the latchPin to high potential, after sending data
  digitalWrite(latchPin, HIGH);
}

void Animazione_Menu(){
  //-------piccola animazione--------
      for(int i = 0 ; i < 8 ; i++){
        sevenSegWrite_Anim(i); delay(40);
        }
      sevenSegWrite_char(1);  delay(500);
      sevenSegWrite_char(2);  delay(500);
  //----- fine piccola animazione----
  }

void Animazione_Save(){
//-------piccola animazione--------
    for(int i = 0 ; i < 8 ; i++){
      sevenSegWrite_Anim(i); delay(20);
      }
    sevenSegWrite_char(2);  delay(200);
    sevenSegWrite_char(3);  delay(200);
    sevenSegWrite_char(2);  delay(200);
    sevenSegWrite_char(3);  delay(200);
    sevenSegWrite(MidiChannel + 1); delay(600);
//----- fine piccola animazione----
}
