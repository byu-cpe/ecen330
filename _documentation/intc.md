---
layout: page
toc: false
title: "Interrupt Controller"
number: 13
indent: 1
---

The following shows the hardware components and wiring of the interrupt system that you will use for the labs in this class.  Each of the three AXI Interval Timers has an interrupt output (irq) that is fed to one of the inputs of the AXI Interrupt controller as shown below.  The AXI Interrupt Controller aggregates these inputs into a single interrupt output (irq) that is sent to the ARM Processor.

<img src="{% link media/interrupts/interrupts.png %}" width="800" alt="Interrupt connection diagram">

When the interrupt controller detects an interrupt at one of it's inputs (input signal goes from 0 to 1), it then triggers an interrupt on its output that then notifies the processor that an interrupt has occurred.  The processor then **immediately** pauses its execution and runs the **interrupt service routing (ISR)** function (also known as an *interrupt handler* function).  In order for this to happen, some setup is required: on the interrupt controller you must enable each appropriate input pin, as well as enable the global output.  The interrupt input of the processor must also be enabled. 

When a processor interrupt does occur, and the ISR function is run, <ins>care must be taken to properly **handle** the interrupt</ins>.  Doing this correctly is essential, but is often confusing to new embedded systems programmers. If you first understand one key concept, then what needs to happen makes a lot more sense: **The hardware modules (timers, interrupt controller, etc.) can request an interrupt by raising their interrupt output, but they don't automatically know when the processor has responded to the interrupt.**  So, hardware modules (including the interrupt control and timers you will use) are typically designed to continue to send an interrupt output until the software notifies it that the interrupt has been handled.  So:
  * In your ISR, you need to communicate with the interrupt controller hardware (via register writes) to acknowledge/clear the interrupt.  If you don't do this, then when you return from your ISR function, the processor will see that the interrupt controller is still sending an interrupt, and it will call your ISR function again!  Then you will have ended up in an endless loop and it will seem like your program has frozen.
  * You also need to communicate with the timer hardware (using `intervalTimer_ackInterrupt`) to acknowledge/clear the interrupt it is generating.  Otherwise the Interrupt Controller hardware will 

 The interrupt controller does not stop sending its interrupt output to the processor just because an interrupt was triggered.  The software must explicitly 

When the processor detects an interrupt and runs your interrupt handler, you will need to 

## Commerical Documentation

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


