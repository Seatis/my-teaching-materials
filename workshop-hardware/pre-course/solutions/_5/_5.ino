int led = 2;
int button = 3;
int ldr = 0;
int ntc = 1;
int fan = 4;

//The RGB LED has common anode!
int r = 7;  //Cathode of red LED
int g = 5;  //Cathode of green LED
int b = 6;  //Cathode of blue LED

void setup() {
  //TODO: initialize the required pins
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  //TODO: turn on the RGB LED in different colors! 
  //TODO: use PWM to create custom colors!
  analogWrite(r, 255);
  analogWrite(g, 255);
  analogWrite(b, 0);
}

/*
References, hints:
https://www.arduino.cc/en/Reference/AnalogWrite
http://www.tme.eu/hu/Document/f1d636d206371381ca4983632554510b/ll-509RGBM2E-004.pdf

Advanced info:
https://learn.sparkfun.com/tutorials/pulse-width-modulation
*/
