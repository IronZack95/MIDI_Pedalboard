
void ReadButton(int i){
  // read the state of the pushbutton value:
  ButtonState[i] = digitalRead(ButtonPin[i]);
  if(ButtonState[i] != Last_ButtonState[i]){
      Action = HIGH;
      Last_ButtonState[i] = ButtonState[i];
      // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
      if (ButtonState[i] == HIGH) {
        // turn LED on:
        digitalWrite(LED_BUILTIN, HIGH);
        //MIDImessage(kpc, midC, 127);
      } else {
        // turn LED off:
        digitalWrite(LED_BUILTIN, LOW);
        //MIDImessage(kpc - 16, midC, 0);
      }
  }
}


void ReadAnalog(int i){
  int lettura = analogRead(i);
  if( lettura > val + TOLERANCE/2 || lettura < val - TOLERANCE/2 ){
      val = lettura;
      Action = HIGH;
    }
  
  }
