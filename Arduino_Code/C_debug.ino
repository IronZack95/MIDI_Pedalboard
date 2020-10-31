
void debug(){
  
  for(int i = 0; i < Npin; i = i + 1){
    Serial.print(ButtonPin[i]);
  }
  Serial.println();
  
  for(int i = 0; i < Npin; i = i + 1){
    Serial.print(ButtonState[i]);
  }
  Serial.println();

  for(int i = 0; i < Npin; i = i + 1){
    Serial.print(Last_ButtonState[i]);
  }
  Serial.println();

  Serial.print("mod:      ");  Serial.println(mod);
  Serial.print("Action:   ");  Serial.println(Action);
  Serial.print("MIDI ch:  ");  Serial.println(MidiChannel);
  Serial.print("val:      ");  Serial.println(val);
  Serial.print("Timer:    ");  Serial.println(Timer);
  
  }
