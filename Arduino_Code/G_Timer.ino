
long startTimer(long Time){
  Time = millis();
  //Serial.println("start");
  return Time;
  }

bool verificoTimer(long Time, long Delay){
  //Serial.println("ver"); Serial.println(millis() - Time);
    if(millis() - Time >= Delay){
      return HIGH;
      }
  return LOW;
  }

long stopTimer(long Time){
  Time = 0;
  //Serial.println("stop");
  return Time;
  }
