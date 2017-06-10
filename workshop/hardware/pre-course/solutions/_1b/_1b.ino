int led = 2;

// The switch is connected to D3 pin. "D" means that this pin is a digital pin, it can has a LOW or HIGH state.
// give this pin a name:
int button = 3;

// The setup routine runs once when you press reset or after power-up:
void setup() {
  pinMode(led, OUTPUT);
  
  // A digital pin can be used as an input.
  // In input mode you can read the state of the pin. 
  //TODO: set the button pin to input mode
  pinMode(button, INPUT);
}

// The loop routine runs over and over again forever:
void loop() {
  //TODO: turn on the LED blinking when the button is pressed
  if(digitalRead(button) == HIGH){
    digitalWrite(led, HIGH);   // turn the LED on
    delay(100);                // wait 100ms
    digitalWrite(led, LOW);    // turn the LED off
    delay(100);                // wait 100ms
  }
}

/*
References, hints:
https://www.arduino.cc/en/Reference/pinMode
https://www.arduino.cc/en/reference/if
https://www.arduino.cc/en/Reference/digitalRead

Advanced info:
http://www.varesano.net/blog/fabio/pushbuttons%20and%20tilt%20sensorsswitches%20how%20they%20work%20and%20some%20arduino%20usage%20examples
*/
