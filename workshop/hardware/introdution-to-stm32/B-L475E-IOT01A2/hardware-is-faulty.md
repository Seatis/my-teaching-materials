# We have found a factory defect
*or the tale of a broken board that finds it way back to the world of programming*

## Recognition
We tried to build, run and debug a project on the brand new STM32 board. The building went great, but when it came to
debugging we got the following error message: *Wrong device detected*. It was clearly impossible because we were using the original library package directly from the manufacturer. After trying to fix this (without any success) from the software side, we started to observe the hardware. In the [document](http://www.st.com/content/ccc/resource/technical/document/user_manual/group0/b1/b8/7a/f2/f7/8d/4b/6b/DM00347848/files/DM00347848.pdf/jcr:content/translations/en.DM00347848.pdf) (from page 43.) we found the circuit diagram of the board. It turned out that the programmer's SWD reset OUT is not connected to the MUS's reset. Because of this the MCU couldn't reset the board when it was needed.

### Solution
A little soldering is enough to deal with this problem. On the back of the board you can find a register named: SB8. All you have to do is: connect this to the GPIO PIN called NRST on the upper side of the board, and this will fix your board for a lifetime.

TODO: image!
