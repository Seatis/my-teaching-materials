// Welcome!

// If you push the Upload & Run button this software will be loaded to the virtual hardware which will run the code.
// Try to run this code! You can see that the LED is lit.

// Above you can see the hardware needed by this software. The white board with lots of holes is called "breadboard".
// Before you start to build the circuit read about the breadboard: https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard

// After you finished with the circuit ask a mentor to verify it before you connect the arduino to a USB port! If you mess something the USB port could be destroyed!

// To load the code on the Arduino you will need the Arduino IDE running on your laptop. A mentor will help you in the installation process.

// If you open the Arduino IDE it will create a new project. Delete the deafault code then copy this file content into the new project.
// Then click on the right arrow button on the top-left corner of the IDE window. If your arduino is connected to the laptop and everything is fine,
// the code will be loaded to the microcontroller and the red LED will be lit.

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// During this workshop every project has a task for you marked with "TODO:". If you don't know where to start look at the "References" provided at the end of the files.
// If you are interested in advenced stuff check out the "Advanced info:" links!

//Let's start your first project!
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// The red LED is connected to D2 pin. "D" means that this pin is a digital pin, it can have a LOW or HIGH state. 
// give this pin a name:
int led = 2;

// The setup routine runs once when you press reset or after power-up:
void setup() {
  // A digital pin can be used as an output.
  // In output mode you can set a pin to LOW or HIGH state.
  pinMode(led, OUTPUT);    // this is equivalent to pinMode(2, OUTPUT)
}

// The loop routine runs over and over again forever:
void loop() {
  // If you set an output pin to HIGH state the MCU will connect the pin to the MCU's supply pin (in this case to 5V).
  digitalWrite(led, HIGH);   // turn the LED on
  delay(1000);               // wait for a second
  
  // If you set an output pin to LOW state the MCU will connect the pin to the MCU's ground pin (GND).
  //TODO: turn the LED off by making the voltage LOW
  digitalWrite(led, LOW);
  //TODO: wait for a second
  delay(1000);
}

/*
References, hints:
https://www.arduino.cc/en/Reference/Setup
https://www.arduino.cc/en/reference/loop
https://www.arduino.cc/en/Reference/pinMode
https://www.arduino.cc/en/Reference/digitalWrite
https://www.arduino.cc/en/Reference/Delay

Andvanced info:
https://learn.adafruit.com/adafruit-arduino-lesson-2-leds/leds?view=all
*/
