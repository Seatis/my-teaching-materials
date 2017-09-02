int led = 2;
int button = 3;
int ldr = 0;
int ntc = 1;

// The fan's external switch (a MOSFET) is connected to pin D4.
// give this pin a name:
int fan = 4;

// The setup routine runs once when you press reset or after power-up:
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  //TODO: initialize fan pin
  pinMode(fan, OUTPUT);
}

// The loop routine runs over and over again forever:
void loop() {
  //TODO: turn on the fan if the button is pressed
  if(digitalRead(button) == HIGH){
    digitalWrite(fan, HIGH);
  }
  else{
    digitalWrite(fan, LOW);
  }
}

/*
References, hints:
https://www.arduino.cc/en/reference/else
https://www.arduino.cc/en/Reference/pinMode
https://www.arduino.cc/en/Reference/digitalRead
https://www.arduino.cc/en/Reference/digitalWrite

Advanced info:
https://oscarliang.com/how-to-use-mosfet-beginner-tutorial/
http://www.infineon.com/dgdl/irl520npbf.pdf?fileId=5546d462533600a40153565f9b62255b
*/
