---
layout: page
toc: false
title: "GPIO and Register-Based Access"
---

As shown in the schematic, these buttons and slide switches are attached to pins on the ZYNQ chip that can be found in the center of the ZYBO board. OK, so far, so good, but how do we access them? The logic values at the pins of the ZYBO chip can be read using a piece of hardware (IP) that I programmed into the bit-stream that you will use in the class. This IP is called General-Purpose Input/Output (GPIO). The GPIO IP is described in the [GPIO documentation]({% link media/lab2/ds744_axi_gpio.pdf %}) that is provided by Xilinx.

I have reproduced the schematic on Page 3 of the GPIO document below. This shows one bit's worth of the GPIO connection. There is a separate GPIO block for the push-buttons and a separate GPIO block for the slide switches (the diagram below shows only one block). Both GPIO blocks are 4-bits wide because there are 4 push-buttons and 4 slide-switches. I have annotated the schematic to show the path that the button or slide-switch logic value will take through the GPIO IP. Also, note that each pin of the GPIO block can function as either an input or output. **You want all of the GPIO pins to function as an input so you can read the switch values.** When a pin is functioning as input, the tri-state driver must be turned off; when functioning as an output, the tri-state driver is turned on. You turn the tri-state driver off or on by writing the correct value to the GPIO_TRI register (see Page 9 of the GPIO documentation). 

Each GPIO block provides 4 inputs/outputs so both the *GPIO_TRI* and *GPIO_DATA* register are each 4 bits wide. When reading the *GPIO_DATA* register, bit 0 corresponds to *BTN_0*, bit 1 corresponds to *BTN_1*, etc. When writing the *GPIO_TRI* register to configure the GPIO so that it provides inputs, bit 0 corresponds to *BTN_0*, bit 1 corresponds to *BTN_1*, etc. You will write the *GPIO_TRI* register in the *_init* functions so that the GPIO block is setup as having only inputs. See Page 9 of the GPIO documentation for programming details for the *GPIO_TRI* register.

For example, if I read the *GPI_DATA* register and receive the hexadecimal value **F** (1111), this means that all push-buttons are depressed. If I read the *GPIO_DATA* and receive the hexadecimal value **A** (1010), this means that push-buttons *BTN_3* and *BTN_1* are depressed.

**Pro Tip:** One way to check to see if hardware is present is to write a write-able register with a value and then read it back to see if the value still exists. If you cannot not successfully write the selected register, the proper hardware may not be present. It would be good to print out an error message in this case to notify the application programmer or user about a catastrophic problem. For example, in the *buttons_init()* function (for example), you could write the value to the *GPIO_TRI* register to setup the GPIO hardware to serve as inputs and then *read* the value back and check to see that it is the correct value.

<img src="{% link media/lab2/gpioschematicannotated.jpg %}" width="600" alt="GPIO Schematic, annotated">

OK, the hardware seems straightforward enough but how do you access the GPIO hardware from software? As you can see in the schematic shown above, three registers are shown (*GPIO_TRI*, *GPIO_DATA*, and *READ_REG_IN*). However, there are only two actual registers that you can access: *GPIO_TRI* and *GPIO_DATA*. *GPIO_DATA* does double duty; when you write it, the value appears at the output (this would be useful for turning on an LED). When you read it, you are reading the value of the switch or button. The Xilinx schematic is a little confusing in this regard. For purposes of this lab, you will only read the *GPIO_DATA* register. A larger picture that shows how the ARM core, the GPIO block, and the switches are organized is shown below.

<img src="{% link media/lab2/zynqgpiobuttonblockdiagram.jpg %}" width="800" alt="GPIO Block Diagram">

<img src="{% link media/lab2/gpioregisteroffsets.jpg %}" width="800" alt="GPIO register offsets">

You can read and write the GPIO registers via the address that was assigned when I generated the bitstream. You find the base address for the GPIO IP block by looking it up in the *xparameters.h* file.  This file can be found at [zybo/xil_arm_toolchain/bsp/ps7_cortexa9_0/include/xparameters.h](https://github.com/byu-cpe/ecen330_student/blob/master/platforms/zybo/xil_arm_toolchain/bsp/ps7_cortexa9_0/include/xparameters.h).


I have included an excerpt from the *xparameters.h* file that contains the necessary *#define* statements that tell us what the base addresses for the GPIO blocks are.

```
/* Definitions for peripheral GPIO_PUSH_BUTTONS */
#define XPAR_PUSH_BUTTONS_BASEADDR 0x41240000
#define XPAR_PUSH_BUTTONS_HIGHADDR 0x4124FFFF
#define XPAR_PUSH_BUTTONS_DEVICE_ID 3
#define XPAR_PUSH_BUTTONS_INTERRUPT_PRESENT 1
#define XPAR_PUSH_BUTTONS_IS_DUAL 0


/* Definitions for peripheral GPIO_SLIDE_SWITCHES */
#define XPAR_SLIDE_SWITCHES_BASEADDR 0x41280000
#define XPAR_SLIDE_SWITCHES_HIGHADDR 0x4128FFFF
#define XPAR_SLIDE_SWITCHES_DEVICE_ID 4
#define XPAR_SLIDE_SWITCHES_INTERRUPT_PRESENT 1
#define XPAR_SLIDE_SWITCHES_IS_DUAL 0
```

For this lab, you only need to know the base address for the push buttons (*XPAR_PUSH_BUTTONS_BASEADDR*) and the slide switches (*XPAR_SLIDE_SWITCHES_BASEADDR*). You can ignore all of the other lines with #define. 

Review the page about [header files]({% link _documentation/headers.md %}).  **Do not copy the code from xparameters.h into your C files. Follow the instructions about including header files and use the symbolic constant!**

Armed with a knowledge of the base addresses for the two GPIO blocks, how do you access GPIO registers via 'C'? Xilinx makes it very simple. 

```
// Note that I have defined my own BUTTONS_GPIO_DEVICE_BASE_ADDRESS
#define BUTTONS_GPIO_DEVICE_BASE_ADDRESS XPAR_PUSH_BUTTONS_BASEADDR

// Helper function to read GPIO registers.
#include "xil_io.h"
int32_t buttons_readGpioRegister(int32_t offset) {
//   Just use the low-level Xilinx call.
   return Xil_In32(BUTTONS_GPIO_DEVICE_BASE_ADDRESS + offset);
}
```

When you use the above function to read the logic levels of the push buttons, it will return a 32-bit value. The upper 28 bits should be ignored. The lower 4 bits (bit3 - bit0) will represent the logic values of the push buttons. For example, if all 4 push-buttons are pressed when this function is called, the function will return the ''1111'' in those last 4 bits. If btn3 and btn0 are pressed when the function is called, the function will return ''1001'' and so forth.

As previously mentioned, you must access two registers in the GPIO block. These are described in the GPIO reference that was previously discussed. I have included a screen-capture from Page 8 of the GPIO reference that lists the two registers that you must access. You can use the function provided above to access both of these registers. The first (GPIO_DATA) has an offset of 0, so you use an offset of 0 for that one. The second register has an offset of 4, so that is the offset that you provide the readGpioRegister() function when you call it. More details on the registers are described on Pages 8, 9 of the GPIO document so read those pages so you will know what value to write the GPIO_TRI register so that you can configure the pins of the GPIO block so that they function as inputs.

<img src="{% link media/lab2/gpioregisteroffsets.jpg %}" width="800" alt="GPIO register offsets">

Note that you will also have to write a function that writes GPIO registers so that you can write the correct value to the *GPIO_TRI* register. I'll leave that to you :-D

For the switches, try using two low-level Xilinx IO functions for accessing the registers contained in the GPIO IP. These functions are available if you add `#include "xil_io.h"` at the top of your program.   You can find *xil_io.h* at [zybo/xil_arm_toolchain/bsp/ps7_cortexa9_0/include/xil_io.h](https://github.com/byu-cpe/ecen330_student/blob/master/platforms/zybo/xil_arm_toolchain/bsp/ps7_cortexa9_0/include/xil_io.h). 

The functions that allow you to read and write to registers are included here for convenience:

```
uint32_t Xil_In32(uint32_t Addr); // Returns the value at the address.

void Xil_Out32(uint32_t Addr, uint32_t Value);  // Writes value to the address.
```
