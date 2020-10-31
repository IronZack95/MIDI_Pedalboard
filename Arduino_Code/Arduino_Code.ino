// constants won't change. They're used here to set pin numbers:
#define ledPin        2
#define Npin          5
#define AnalogPin     A0  // potentiometer wiper (middle terminal) connected to analog pin 3
                          // outside leads to ground and +5V

// Display
#define latchPin      9
#define clockPin      10
#define dataPin       8

#define MINPAGE       0
#define MAXPAGE       3
#define TOLERANCE     20
#define MAXANALOG     1024
#define MINANALOG     0
#define TIMERDELAY    3000
#define DEBOUNCEDELAY 50

long Timer = 0;
long Debounce = 0;
int page = 0;         

byte Numbers[10] = {  B11111100,  // = 0
                      B01100000,  // = 1
                      B11011010,  // = 2
                      B11110010,  // = 3
                      B01100110,  // = 4
                      B10110110,  // = 5
                      B10111110,  // = 6
                      B11100000,  // = 7
                      B11111110,  // = 8
                      B11100110   // = 9
                     };
                     
byte SpecialChar[5] = {  B00000000,  // = nulla
                         B11001110,  // = P
                         B10011100,   // = C
                         B00000001,   // = .
                         B01101110    // = H
                     };

byte Anim[8] = {      B10000000,  
                      B01000000,
                      B00100000,
                      B00010000,
                      B00001000,
                      B00000100,
                      B00000010,
                      B00000001
                     };
 
// variables will change:
const int ButtonPin[] =   {3, 4, 5, 6, 7};
int ButtonState[] =       {0, 0, 0, 0, 0};
int Last_ButtonState[] =  {0, 0, 0, 0, 0};

int val = 0;  // variable to store the value read potenziometer

//USER INTERFACE
int mod = 0;
bool Action = LOW;

/*
  0 - Automatica
  1 - Menu
  2 - Channel Select
  3 - Selezione variabile scelta
  4 - Conferma
*/

int kpc = 144; // the function of the keypad, 144 = Channel 1 Note on
int midC = 60; // MIDI note value for middle C on a standard keyboard
int STATUS_base = 0xB0;
int data1_base =  0x14;
int data2_base =  127;
int MidiChannel = 0;  //equivale al canale 0



// ---------------SETUP---------------
void setup() {
  
  // inizializzo seriale
  Serial.begin(9600); // enable serial communication
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Set latchPin, clockPin, dataPin as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  
  for(int i = 0; i < Npin; i = i + 1){  
    pinMode(ButtonPin[i], INPUT);
  }
  // Inizializzo Display
  sevenSegWrite(page);
  //debug();
}


// ---------------MAIN LOOP---------------

void loop(){
  
  //Leggo Bottoni
  for(int i = 0; i < Npin; i = i + 1){
    ReadButton(i);
  }
  
  //Leggo Potenziometro
  if(mod == 1){
    ReadAnalog(AnalogPin);
  } else{
    
    delay(DEBOUNCEDELAY);  
  }

  if(ButtonState[Npin-2] == 1 && ButtonState[Npin-1] == 1 && Timer>0 && mod == 0){
      sevenSegWrite_char(4);
      if(verificoTimer(Timer,TIMERDELAY) == HIGH){
          mod = 1; 
          Animazione_Menu();
          Action = HIGH;
          Timer = stopTimer(Timer);
        }
    }else{
      Timer = stopTimer(Timer);
      } 
    
  if(Action){
    //debug();
    Eseguire();
    Action = LOW;
  }
}
