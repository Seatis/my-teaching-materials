int led = 2;
int button = 3;

// The LDR sensor is connected to pin A0. "A" means that this pin is an analog pin, 
// the MCU can read it's voltage value (not only the LOW or HIGH state, that is why it is different from a digital pin). 
// give this pin a name:
int ldr = 0;

// The setup routine runs once when you press reset or after power-up:
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  
  // On arduino an analog pin does not require any initialization (unlike digital pins).
}

// The loop routine runs over and over again forever:
void loop() {
  //TODO: turn on the LED blinking when the LDR detects light
  if(analogRead(ldr) > 512){
    digitalWrite(led, HIGH);   // turn the LED on
    delay(100);                // wait 100ms
    digitalWrite(led, LOW);    // turn the LED off
    delay(100);                // wait 100ms
  }
}

/*
References, hints:
https://www.arduino.cc/en/Reference/analogRead
https://learn.adafruit.com/photocells/

Advanced info:
http://www.tme.eu/hu/details/gm3516/fotoellenallasok/wodeyijia/
http://www.ohmslawcalculator.com/voltage-divider-calculator
*/
