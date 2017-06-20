# USB HID
*Create a touch pad*

## Objectives
 - Create a touch pad
 - Get familiar with the SWSTM32 environment

## Materials & Resources
### Tools
- [SWSTM32 IDE](http://www.openstm32.org/)
- [STM32CubeF7](http://www.st.com/en/embedded-software/stm32cubef7.html) software package

### Materials
| Material | Duration |
|:---------|-----:|
|[SparkFun Engineering Roundtable 11-12-12: HID and USB Devices with Chris Taylor](https://www.youtube.com/watch?v=1unTKKGd8qs)|17:44|

### Optional materials
*If you are more interested and don't afraid from a tiny bit of theory.*

| Material | Duration |
|:---------|-----:|
|[Fun and Easy USB - How the USB Protocol Works](https://www.youtube.com/watch?v=F7NlCaaL3yU)|15:01|
| [Tutorial about USB HID Report Descriptors](http://eleccelerator.com/tutorial-about-usb-hid-report-descriptors/) |-|
| [Device Class Definition for Human Interface Devices (HID)](http://www.usb.org/developers/hidpage/HID1_11.pdf) | - |

## Workshop
### Touch pad
The STM32F746G-DISCOVERY board has a capacitive touch screen which can be used to
detect the user's finger position. The board also has two USB connectors, which can
be used to connect the board to a PC.

The board should work like an external touch pad if the user connects the board
to the PC (with the `USB_FS` connector).

## Solution
[Solution](https://github.com/greenfox-academy/teaching-materials/tree/master/project/hardware/solutions/usb-hid)
