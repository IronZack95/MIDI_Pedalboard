
void Eseguire(){
  
  switch(mod){
    case 0:   //modalità automatica
      Auto();
      sevenSegWrite(page);
    break;
    case 1:   //modalità Menu
      Menu();
    break;
    default: break;
    }
  
  }

void Auto(){
  
  // gestione pulsanti

  for(int i = 0; i < Npin-2; i++){
    if(ButtonState[i] == 1){
        //MIDImessage(STATUS_base + MidiChannel, data1_base + (Npin-2)*page + i, data2_base);
        SERIALmessage(data1_base + (Npin-2)*page + i, analogRead(AnalogPin));
      }
    }

  // gestione selettori
  if(ButtonState[Npin-2] == 1 && ButtonState[Npin-1] == 0){
        if(page==MINPAGE){
          page = MAXPAGE;
        }else{
          page = page - 1;
        }
    }
  if(ButtonState[Npin-2] == 0 && ButtonState[Npin-1] == 1){
        if(page==MAXPAGE){
          page = MINPAGE;
        }else{
          page = page + 1;
        }
    }
  if(ButtonState[Npin-2] == 1 && ButtonState[Npin-1] == 1){
        Timer = startTimer(Timer);
    } 
  
  }


void Menu(){
  
  int out = (val+1)/128;  // posso scegliere 8 canali midi
  sevenSegWrite(out);

  if(ButtonState[Npin-2] == 1 && ButtonState[Npin-1] == 0){   // SAVE
        MidiChannel = out - 1;
        mod = 0; page = 0;
        Animazione_Save();
        
    }
  if(ButtonState[Npin-2] == 0 && ButtonState[Npin-1] == 1){   //  EXIT
        mod = 0;  page = 0;
    }
  }
