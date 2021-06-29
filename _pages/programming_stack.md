---
layout: page
toc: false
title: "Simplified Embedded Programming Stack"
---

Applications on embedded systems are developed in layers like a cake. We commonly refer to this as the program stack. Layers are used to hide detail and to make a project more manageable and maintainable. The **device** layer typically consists of board-level physical components such as switches, LEDs, USB ports, HDMI in and out ports, etc. For FPGA-based systems like ZYNQ, **hardware** that communicates with these devices is often placed in the FPGA fabric (the instructors have already done that for this class). Low-level **driver** software hides low-level details from the top layer, the **application**.

<img src="{% link media/lab2/embeddedprogramstack.png %}" width="800" alt="Embedded programming stack">

