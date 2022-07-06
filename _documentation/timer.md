---
layout: page
toc: false
title: "Interval Timer"
number: 12
indent: 1
---

## Commerical Documentation
  * [Xilinx Timer Documentation]({% link media/lab3/axi_timer_ds764.pdf %})


The hardware timers that you will access are Xilinx AXI Timer (axi_timer) (v1.03a). Here's a block diagram of the AXI timer taken from the [Xilinx documentation]({% link media/lab3/axi_timer_ds764.pdf %}). Please refer to the documentation for functional details of the AXI timer.

<img src="{% link media/lab3/axitimerblockdiagram2.jpg %}" width="600" alt="AXI Timer block diagram">


The ECEN 330 FPGA hardware system is configured with **THREE** of these timers, and they are named *timer_0*, *timer_1*, and *timer_2*, as shown below.

<img src="{% link media/lab3/threeintervaltimerdiagram.jpg %}" width="600" alt="Three interval timers on AXI bus">

Here's an excerpt from the *xparameters.h* file with definitions related to these three timers. As you should recall from Lab 2, the base address is your main concern.

**NOTE: Do not copy the code below into your own code. Just include xparameters.h and use the defined values, e.g., XPAR_AXI_TIMER_2_BASEADDR.**

```
/* Definitions for driver TMRCTR */
#define XPAR_XTMRCTR_NUM_INSTANCES 3

/* Definitions for peripheral AXI_TIMER_0 */
#define XPAR_AXI_TIMER_0_DEVICE_ID 0
#define XPAR_AXI_TIMER_0_BASEADDR 0x42800000
#define XPAR_AXI_TIMER_0_HIGHADDR 0x4280FFFF
#define XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ 100000000


/* Definitions for peripheral AXI_TIMER_1 */
#define XPAR_AXI_TIMER_1_DEVICE_ID 1
#define XPAR_AXI_TIMER_1_BASEADDR 0x42840000
#define XPAR_AXI_TIMER_1_HIGHADDR 0x4284FFFF
#define XPAR_AXI_TIMER_1_CLOCK_FREQ_HZ 100000000


/* Definitions for peripheral AXI_TIMER_2 */
#define XPAR_AXI_TIMER_2_DEVICE_ID 2
#define XPAR_AXI_TIMER_2_BASEADDR 0x42880000
#define XPAR_AXI_TIMER_2_HIGHADDR 0x4288FFFF
#define XPAR_AXI_TIMER_2_CLOCK_FREQ_HZ 100000000
```

## Resources 
These timers are fully described in Xilinx's documentation. 

  * [Xilinx Timer Documentation]({% link media/lab3/axi_timer_ds764.pdf %})

If the highlighting does not appear, make sure to read at least the following pages: 1, 2-3 (through Characteristics), 4-5 (Characteristics), 7 (Figure 2), and 11-14 (Register Definitions).

## Overview of Timer Hardware 

The timer hardware is pretty complex and provides lots of functionality. However, we will only use them in their simplest mode as interval timers. As such, you need to carefully study at least the highlighted sections of the Xilinx documentation.

As discussed in the manual, the timer consists of two identical sections each containing a 32-bit counter and associated registers. The two counters can be cascaded to form a single 64-bit counter. This is referred to as cascade mode. In cascade mode, almost all of the control is done via a single control register (*TCSR0*) as the other control registers are mostly ignored in this mode. The counters can be configured to count up or down, you will configure them to count up. This makes the most sense for a simple timer.

You will need to access the following registers in the timer hardware:

### Register Descriptions

Here are some basic descriptions of each hardware register (see the documentation for full details):
  * *TCSR0*: Control/Status Register 0, used to control the cascaded 64-bit counter and to load values into Counter 0.
  * *TCSR1*: Control/Status Register 1, used to load values into Counter 1.
  * *TLR0*: Load Register 0, dictates the value loaded into Counter 0.  If you want to load a 0 into Counter 0 (i.e., reset Counter 0), then this register should have value 0.
  * *TLR1*: Load Register 1, dictates the value loaded into Counter 1.  If you want to load a 0 into Counter 1 (i.e., reset Counter 1), then this register should have value 0.
  * *TCR0*: Counter Register 0, you read this register to find out the current value of Counter 0.
  * *TCR1*: Counter Register 1, you read this register to find out the current value of Counter 0.

### Operations
  - To initialize the counters, you should do the following:
    - write a 0 to the *TCSR0* register.
    - write a 0 to the *TCSR1* register.
    - set the *CASC* bit to **1** and the *UDT0* bit to **0** in the *TCSR0* register (cascade mode and up counting).
  - To store a 0 into Counter 0 (i.e., reset Counter 0), do the following:
    - set *TLR0* register to **0**.
    - set the *LOAD0* bit of *TCSR0* to **1**.
    - set the *LOAD0* bit of *TCSR0* to **0**.
  - To store a 0 into Counter 1 (i.e., reset Counter 1), do the following:
    - set *TLR1* register to **0**.
    - set the *LOAD1* bit of *TCSR1* to **1**.
    - set the *LOAD1* bit of *TCSR1* to **0**.
  - To start the cascaded counter:
    - set the *ENT0* bit of the *TCSR0* register to **1**. When you do this, you must not disturb the other bits in *TCSR0*.
  - To stop the cascaded counter:
    - set the *ENT0* bit of the *TCSR0* register to **0**. When you do this, you must not disturb the other bits in *TCSR0*.

### Additional Notes
  - After loading the counters with 0s to reset them, you must re-initialize them (see Step 1 above). In particular, make sure that you clear the load bit for both counters.
  - The process for reading the two 32-bit counters and reassembling them into a single 64-bit number is described on Page 5 of the documentation.
  - Search the *xparameters.h* file to find out the frequency for the timers. Always use the provided *#define*s as they are provided by *xparameters.h*. Do not use the actual numerical constants.

