---
layout: lab
toc: true
title: "Lab 4: Interrupt Controller Driver"
short_title: Interrupt Driver
number: 4
order: 4
---

## Overview


Managing device interrupts is a critical part of designing embedded systems.  Interrupts allow you to respond to the needs of different hardware devices quickly and efficiently, without needing to perform constant device polling.
In computer systems there are often many different devices generating interrupts.  An [Interrupt Controller](https://en.wikipedia.org/wiki/Programmable_interrupt_controller), "is an integrated circuit that helps a microprocessor (or CPU) handle interrupt requests (IRQ) coming from multiple different sources (like external I/O devices) which may occur simultaneously."  

In this lab you will create a driver for an interrupt controller than receives interrupt requests from the three Interval Timers you used last lab, and forwards a single interrupt request on to the ARM processor.

After your driver is complete, you will write a simple test application to verify your driver is working correctly.  This test application will initialize each timer to generate interrupts at different rates, and use each interrupt to blink an LED.

<img src="{% link media/interrupts/interrupt_test.gif %}" width="500" alt="Interrupt test application">

### Objectives

* Gain experience using interrupts, and an interrupt controller.
* Gain experience writing a driver for a more complex hardware module.
* Learn about function pointers and callback functions.

## Preliminary

1. **Hardware**. Read about the [Interrupt Controller Hardware]({% link _documentation/intc.md %}).

1. **Driver Interface**. Read through the interface for your driver, provided in [interrupts.h]({{site.github.fileurl}}/drivers/interrupts.h).
    * Although not specified in the *.h* file, your driver should have an ISR helper function that will run user-provided callback functions that were registered through `interrupts_register()`.

1. **Building the code:** 
    * **Driver:** 
        * This driver will be written in *drivers/interrupts.c*, which you must create yourself.  Uncomment the two lines in the *drivers* [CMakeLists.txt]({{site.github.fileurl}}/drivers/CMakeLists.txt) file so that the *interrupts* library is built.  

    * **Application Code:**
        * Your test application should be written in *lab4_interrupts/interrupt_test.c*.  For this lab, you will need to write your own CMakeLists.txt file, which you can base off of previous labs.
        * As usual, update the top-level [CMakeLists.txt]({{site.github.fileurl}}/CMakeLists.txt) and add a `add_subdirectory(lab4_interrupts)` statement.

## Implementation

### Requirements

1. Write a driver for the Interrupt Controller, implementing the functions defined in [interrupts.h]({{site.github.fileurl}}/drivers/interrupts.h).  Consult the comments in this file for details on the behavior of each function, as well as the in-class discussion.

1. Implement the *interrupt_test_run()* function, such that:
    * Each of the three interval timers are running in count-down mode, and generating an interrupt at 10Hz, 1Hz and 0.1Hz.
    * Create an interrupt handler function for each timer that toggles an LED.
    * Your test code should match the behavior of the video above.



### Files
  - **Submitted files:** *drivers/interrupts.c*, *lab4_interrupts/interrupt_test.c*.
  - Do not change or create any other files.

### Other Notes
* **Test Application Setup:** Your test application will need to set up multiple devices:
    * Remember to call `interrupts_init()`, `leds_init()`, and each Interval Timer initialization function.
    * Enable device interrupt lines (IRQ output from Timer and IRQ input to Interrupt Controller)
    * Register callback functions for each timer with the interrupt handler (see next item).

* **Interrupt handler functions:**  In your test application, you will have functions to handle the interrupt for each of your three timers.  Within each of these callback functions, you should:
    1. *(Optionally)* Print a message so you know the function is being called.
    1. Acknowledge both:
        * The interrupt output of the Interval Timer
        * The interrupt input of the Interrupt Controller        
        (Think about which one you should do first -- the order matters!)
    3. Flip the value of the appropriate LED.

* Like the previous two drivers, it would be good to write helper functions for accessing device registers.  For example:
```c
    static uint32_t readRegister(uint32_t offset);
    static void writeRegister(uint32_t offset, uint32_t value);
```

* Take your time and be careful when creating `#defines` for register offsets and bit masks.  Spending a few extra minutes to get these 100% correct will save you lots of debugging time.

* Make sure you understand the behavior of the various Interrupt Controller registers.  These registers have more complex behaviors than previous labs; however, you should find these behaviors quite helpful in completing your driver.  *Hint:* Most of your driver functions can be implemented by making a single register read/write.


## Submission
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.

### Grade Breakdown 
  * 80%: Driver and test application functionality.
  * 20%: Coding standard