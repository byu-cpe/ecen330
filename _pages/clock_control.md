---
layout: page
toc: false
title: "Clock Control"
---


Here is [clockControl.h](https://github.com/byu-cpe/ecen330_student/blob/master/lab4/clockControl.h). 


You will implement clock control in two phases based upon the state diagram that I provide below. You will convert this state diagram I provide using the procedures shown in the text. Implemented correctly, the state diagram will give you a working clock-display except that it won't keep time. You will add that functionality in the second phase.

<img src="{% link media/lab4/clockstatemachine.jpg %}" width="800" alt="Clock control state machine diagram">

The conversion of the state diagram in to 'C' code is very straightforward and relies on the procedures discussed in the book up through the chapter on synchronous state machines.

Once you have successfully converted this state diagram into 'C' code, you can test it using the provided *main.c* (making sure to set the *#define* to Milestone 2). 

Once you have debugged your state machine, you need to add the following functionality to the state-diagram to complete your clock:
  - start time keeping by making the clock keep time, and
  - don't start keeping time until the clock display has been touched at least once.

Add this functionality to the original state-diagram and then implement it using the conversion process outlined in the text.  Be sure to follow the guidelines in [Coding and Debugging State Machines]({% link _other/coding_state_machines.md %}).
