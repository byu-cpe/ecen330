---
layout: page
toc: false
title: "Interrupt Controller"
number: 13
indent: 1
---

The following shows the hardware components and wiring of the interrupt system that you will use for the labs in this class.  Each of the three AXI Interval Timers has an interrupt output (irq) that is fed to one of the inputs of the AXI Interrupt controller as shown below.  The AXI Interrupt Controller aggregates these inputs into a single interrupt output (irq) that is send to the ARM Processor.

<img src="{% link media/interrupts/interrupts.png %}" width="800">

## Documentation

Here is the full documentation of the AXI Interrupt Controller hardware. Like the other hardware manuals, you should pay closest attention to the *Register Space* section.
  * [Xilinx AXI Interrupt Controller v4.1 Documentation]({% link media/interrupts/pg099-axi-intc.pdf %})

## Behavior

Many students often get confused about how interrupts work in this system, and make the assumption that the *Interrupt Controller* is basically an OR-gate that indicates if any interrupt input is active.  In reality, the interrupts system is more complicated, as each connection can be enabled/disabled at the sender or receiver end, and interrupts remain "active" until explicitly acknowledged.

Here are some details that may help make this more clear:

### AXI Interval Timer
* Assuming it is configured in count-down mode with reload, the Interval Timer will raise its *irq* output every time the timer reaches 0 and reloads.
* The **interrupt output option must be enabled** for the timer to generate interrupts (`intervalTimer_enableInterrupt()`).
* The *irq* output will <ins>remain high/active until acknowledged</ins> by writing to the appropriate bit in the Control/Status register (`intervalTimer_ackInterrupt()`).

### AXI Interrupt Controller
* The **interrupt output option must be enabled** for the Interrupt Controller to generate interrupt outputs.  You should do this within the initialization of the Interrupt Controller (within `interrupts_init()`).
* Each **interrupt input must be individually enabled**, otherwise interrupts on this input will be ignored (`interrupts_irq_enable()`).  
* Assuming these are both enabled, then anytime an interrupt is detected on an input, the output *irq* will be activated.  The *irq* output <ins>will remain active until the received interrupt is acknowledged</ins> (`interrupts_ack()`), even if the incoming interrupt is no longer active.

### ARM Processor
* The **interrupt input on the ARM processor must be enabled** before the processor will respond to any interrupts.  This is done through the following: 

        armInterrupts_init();
        armInterrupts_setupIntc(myIsr);
        armInterrupts_enable();

    where *myIsr* is an Interrupt Service Routing (ISR) function that you want to be called whenever the ARM processor detects an interrupt.

### Summary

Based on the above, there are **four different things that need to be enabled** during setup before interrupts will begin working.  

| Needs Enabling | Code Location |
|----------------|---------------|
| Interval Timer *irq* output  | `intervalTimer_enableInterrupt()`. Called by your application code on each timer you want to use for interrupts. |
| Interrupt Controller input line | `interrupts_irq_enable()`. Called by your application code for each timer you want to use for interrupts. |
| Interrupt Controller *irq* output | Set both enable bits on the *Master Enable* register during `interrupts_init()` |
| ARM Processor Input | Need to call the three `armInterrupts_*` functions listed above to initialize and enable the interrupt input, as well as register your ISR. This can be done within `interrupts_init()`. |

Also, every time a timer interrupt occurs, there are <ins>two places where the interrupt needs to be acknowledged</ins>, otherwise it will continue indefinitely!

| Needs Acknowledging | Code Location |
|---------------------|---------------|
| Interval Timer        | Call `intervalTimer_ackInterrupt()`. |
| Interrupt Controller  | Call `interrupts_ack()`. |


