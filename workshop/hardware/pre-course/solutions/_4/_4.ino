int led = 2;
int button = 3;
int ldr = 0;
int ntc = 1;
int fan = 4;

void setup() {
  //TODO: initialize the required pins
  //TODO: initialize serial interface 
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //TODO: turn on the LED if the LDR senses light
  //TODO: if you want to see the actual sensor value print out it to the serial port!
  if(analogRead(ldr) > 910){
    digitalWrite(led, HIGH);
  }
  else if(analogRead(ntc) < 890){
    digitalWrite(led, LOW);
  }
  Serial.println(analogRead(ldr));
}

/*
References, hints:

https://www.arduino.cc/en/Serial/Begin
https://www.arduino.cc/en/Serial/Println
https://www.arduino.cc/en/guide/environment#toc12

Advanced info:
*/
