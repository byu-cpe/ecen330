---
layout: page
toc: false
title: "Interrupt Controller"
number: 13
indent: 1
---

## Class Notes

 {% pdf "{{ site.baseurl }}/media/interrupts/interrupt_controller.pdf %}


## Commercial Documentation

Here is the full documentation of the AXI Interrupt Controller hardware. Like the other hardware manuals, you should pay closest attention to the *Register Space* section.
  * [Xilinx AXI Interrupt Controller v4.1 Documentation]({% link media/interrupts/pg099-axi-intc.pdf %})

## Base Address

The AXI Interrupt Controller is located at the base address provided by `XPAR_AXI_INTC_0_BASEADDR` (make sure to `#include <xparamters.h>` like in the previous lab).

## Summary

Based on the above, there are **four different things that need to be enabled** during setup before interrupts will begin working.  

| Needs Enabling | Code Location |
|----------------|---------------|
| Interval Timer *irq* output  | `intervalTimer_enableInterrupt()`. Called by your application code on each timer you want to use for interrupts. |
| Interrupt Controller input line | `interrupts_irq_enable()`. Called by your application code for each timer you want to use for interrupts. |
| Interrupt Controller *irq* output | Set both enable bits on the *Master Enable* register during `interrupts_init()`. |
| ARM Processor Input | Need to call the three functions (`armInterrupts_init()`, `armInterrupts_setupIntc(myIsr)`, and `armInterrupts_enable()`) to initialize and enable the interrupt input, as well as register your ISR. This should be done within `interrupts_init()`. |

Also, every time a timer interrupt occurs, there are <ins>two places where the interrupt needs to be acknowledged</ins>, otherwise it will continue indefinitely!

| Needs Acknowledging | Code Location |
|---------------------|---------------|
| Interval Timer        | Call `intervalTimer_ackInterrupt()`. |
| Interrupt Controller  | Call `interrupts_ack()`. |


