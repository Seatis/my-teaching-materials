int led = 2;
int button = 3;
int ldr = 0;

// Don't be confused! In this simulator there isn't any NTC component, hence another LDR was placed in the circuit.
// On your breadboard put a NTC sensor in place of the second LDR (which is connected to Arduino with the purple wire)!

// The NTC sensor is connected to pin A1.
// give this pin a name:
int ntc = 1;

// The setup routine runs once when you press reset or after power-up:
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  //TODO: initialize the serial port
}

// The loop routine runs over and over again forever:
void loop() {
  if(analogRead(ldr) > 512){
    //TODO: turn on the LED blinking when the LDR detects light and the NTC detects higher temperature than room temperature (~20°C)
    //TODO: if you want to check the actual analog value feel free to print it out to the serial port!
    
    digitalWrite(led, HIGH);   // turn the LED on
    delay(100);                // wait 100ms
    digitalWrite(led, LOW);    // turn the LED off
    delay(100);                // wait 100ms
    
  }
}

/*
References, hints:
https://www.arduino.cc/en/Reference/analogRead
https://learn.adafruit.com/thermistor

https://www.arduino.cc/en/Serial/Begin
https://www.arduino.cc/en/Serial/Println
https://www.arduino.cc/en/guide/environment#toc12

Advanced info:
http://hu.farnell.com/vishay/ntcle100e3103jb0/thermistor-10k-5-ntc-rad/dp/1187031
http://www.ohmslawcalculator.com/voltage-divider-calculator
*/
