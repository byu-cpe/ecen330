---
layout: page
toc: false
title: "System Platform"
number: 10
indent: 0
---



## Zybo Board
  * [GPIO documentation]({% link media/lab2/ds744_axi_gpio.pdf %})
  * [ZYBO Reference Manual]({% link media/lab1/zybo_rm_b_v6.pdf %})
  * [ZYBO Board Schematics]({% link media/lab2/zybo_sch.pdf %})

## Devices


## Address Map



The base addresses 

 You find the base address for the GPIO IP block by looking it up in the *xparameters.h* file.  This file can be found at [zybo/xil_arm_toolchain/bsp/ps7_cortexa9_0/include/xparameters.h]({{iste.github.fileurl}}/platforms/zybo/xil_arm_toolchain/bsp/ps7_cortexa9_0/include/xparameters.h).

## Programming Stack

We often refer to *stacks* when we talk about computing systems. A stack is a conceptual term that refers to multiple layers of software stacked one upon the other. See [Programming Stack] for more information on how this terminology applies to this lab.

Applications on embedded systems are developed in layers like a cake. We commonly refer to this as the program stack. Layers are used to hide detail and to make a project more manageable and maintainable. The **device** layer typically consists of board-level physical components such as switches, LEDs, USB ports, HDMI in and out ports, etc. For FPGA-based systems like ZYNQ, **hardware** that communicates with these devices is often placed in the FPGA fabric (the instructors have already done that for this class). Low-level **driver** software hides low-level details from the top layer, the **application**.

<img src="{% link media/lab2/embeddedprogramstack.png %}" width="800" alt="Embedded programming stack">

