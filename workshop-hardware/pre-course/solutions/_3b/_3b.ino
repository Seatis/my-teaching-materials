int led = 2;
int button = 3;
int ldr = 0;
int ntc = 1;
int fan = 4;

void setup() {
  //TODO: initialize the required pins
  pinMode(fan, OUTPUT);
}

void loop() {
  //TODO: make a thermostat!
  if(analogRead(ntc) > 550){
    digitalWrite(fan, HIGH);
  }
  else if(analogRead(ntc) < 540){
    digitalWrite(fan, LOW);
  }
}

/*
References, hints:
https://courses.ideate.cmu.edu/16-223/f2015/guide/ex/Arduino/input-hysteresis/input-hysteresis.html

Advanced info:
http://pcbheaven.com/wikipages/How_PC_Fans_Work/
*/
