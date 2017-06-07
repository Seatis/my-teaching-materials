# Closed loop control
*Create a program on the MCU which can control the fan speed*

## Objectives
 - Create a bigger project
 - Get familiar with control loops

## Materials & Resources

- [Proportional control](https://en.wikipedia.org/wiki/Proportional_control)
- [RS232 library](https://www.youtube.com/watch?v=4jgBy1aOltU&t=11s) video

### Advanced Control loops
- [The PID controller](https://en.wikipedia.org/wiki/PID_controller)
- [Calculate average in given period](#calculate-average-in-given-period)
https://www.youtube.com/watch?v=WsUau1GTNF0

## Workshop
This project is based on the [PWM](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/PWM), [AC-peripheral](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/AC-peripheral) and a litle bit on [ADC workshop](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/SPI-communication-ADC).

This program will be control the fan speed, first with open loop control, at the end of the project with closed loop control. The speed need to be measured as we did in the AC workshop, the required speed need to be adjusted with a potentiometer and measured with the ADC.


<img src="img/GF-ATmega168PB-TempLogger.png" width="50%"></img>

### Basic tasks
- [Make it work](#Make it work)
- [Open loop control](#Open loop control)
- [Closed loop control, P](#Closed loop control, P)
- [Closed loop control, PI](#Closed loop control, PI)

### Advanced tasks
- [Set read filename](#set-read-filename)
- [Calculate average in given period](#calculate-average-in-given-period)

### Make it work
Just make it work:
 - The serial port
 - Read and print out the ADC value
 - Set up and validate the PWM peripheral
 - Set up and validate the AC peripheral, measure the fan speed, print it out

<img src="img/connect-all-the-things.jpg" width="25%"></img>

All the hardware (fan, potentiometer, AC, resistors, capacitors, the FET, the wiring) and all the codes, librarys need to be tested and together in one big project.

### Open loop control
Let's use multiple peripherals with each other. It will be an open loop "controller"
  - Read the ADC value and set a PWM signal according to it. So, if in the ADC is 5V set 100% PWM duty, if the ADC 0V set 0% PWM duty.
  - Print out the PWM duty cycle and the measured PRM of the ventilator.

  Why is it bad? Our open loop "controller" doesn't care about what RPM is the ventilator turning, if it's turning, so it' not really CONTROL the hole progress, it just set the PWM and something will be happen. No feedback from the ventilator is used.

### Closed loop control, P

Let's use the feedback from the ventilator. It will be a proportional controller, it will regulate the PWM according to the measured RPM.

So:
- Read the ADC value, it will be the setpoint (SP)
- The process variable (PV) will be the measured RPM
- Calculate the error (SP-PV)
- Calculate the output value with the proportional gain (P)
- Advanced: Make the Kp adjustable via UART

### Connect all the thing


## Solution
[Solution](#)
