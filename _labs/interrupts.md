---
layout: lab
toc: true
title: "Lab 4: Interrupt Controller Driver"
short_title: Interrupt Driver
number: 4
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
    * Make note of the section on initializing the ARM interrupt input.  You should call this code inside your `interrupts_init()` function.  

1. **Driver Interface**. Read through the interface for your driver, provided in [interrupts.h](https://github.com/byu-cpe/ecen330_student/blob/main/drivers/interrupts.h).



1. **Interrupt Service Routine (ISR)**: The call to `armInterrupts_setupIntc` requires a function pointer to an ISR function that can be run when the ARM processor detects an interrupt.  This function should be a helper function inside your `interrupts.c` driver.  In this helper function you will determine which interrupt input(s) to the Interrupt Controller were responsible for the interrupt, and call the device-specific ISR callback function that was registered previously (if there is one registered).  Here is an example prototype:

            static void interrupts_isr() {
                // Loop through each interrupt input
                for (each interrupt input, i) {
                    
                    // Check if it has an interrupt pending
                    if (input has pending interrupt) {

                        // Check if there is a registered ISR and call it.
                        if (isrFcnPtrs[i])
                            isrFcnPtrs[i]();
            }}}


1. **Building the code:** 
    * **Driver:** 
        * This driver will be written in *drivers/interrupts.c*, which you must create yourself.  Uncomment the two lines in the *drivers* [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/main/drivers/CMakeLists.txt) file so that the *interrupts* library is built.  

    * **Application Code:**
        * Your test application should be written in *lab4_interrupts/interrupt_test.c*.  For this lab, you will need to write your own CMakeLists.txt file, which you can base off of previous labs.
        * As usual, update the top-level [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/main/CMakeLists.txt) and add a `add_subdirectory(lab4_interrupts)` statement.

## Implementation

### Requirements

1. Write a driver for the Interrupt Controller, implementing the functions defined in [interrupts.h](https://github.com/byu-cpe/ecen330_student/blob/main/drivers/interrupts.h).  See comments in this file for details on the behavior of each function.

1. Implement the *interrupt_test_run()* function, such that:
    * Each of the three interval timers are running in count-down mode, and generating an interrupt at 10Hz, 1Hz and 0.1Hz.
    * Create an interrupt handler function for each timer that toggles an LED.
    * Your test code should match the behavior of the video above.



### Files
  - **Submitted files:** *drivers/interrupts.c*, *lab4_interrupts/interrupt_test.c*.
  - Do not change or create any other files.

### Other Notes

* **Interrupt handler functions:**  In your test application, you will have a separate interrupt service routine (ISR) for each of your three timers.  Within each of these ISR functions, you should:
    1. *(Optionally)* Print a message so you know the function is being called.
    1. Acknowledge both:
        * The interrupt output of the Interval Timer
        * The interrupt input of the Interrupt Controller
        
        (Think about which one you should do first -- the order matters!)
    3. Flip the value of the appropriate LED.
* Like the previous two drivers, it would be good to write helper functions for accessing device registers.  For example:\

      readRegister(uint32_t offset);
      writeRegister(uint32_t offset, uint32_t value);

* Take your time and be careful when creating `#defines` for register offsets and bit masks.  Spending a few extra minutes to get these 100% correct will save you lots of debugging time.

* Make sure you understand the behavior of the various Interrupt Controller registers.  These registers have more complex behaviors than previous labs; however, you should find these behaviors quite helpful in completing your driver.  *Hint:* Most of your driver functions can be implemented by making a single register read/write.


## Submission
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.

### Grade Breakdown 
  * 70%: Driver and test application functionality.
  * 30%: Coding standard