---
layout: page
toc: false
title: "Clock Control"
---


Here is [clockControl.h](https://github.com/byu-cpe/ecen330_student/blob/main/lab4/clockControl.h). 


The requirements of the clockControl state machine are:
1. To detect when a user taps on the LCD screen, wait the appropriate amount of time for the ADC to settle, and then call *clockDisplay_performIncDec()* so that the display code can read the touch location and process the touch.

1. Alternatively, if the user continues to touch a region for at least 0.5 seconds, then the seconds, minutes, or hours field should begin auto-incrementing or auto-decrementing 10 times a second (again by calling *clockDisplay_performIncDec()*) until the user stops touching the screen.  

1. Keep time, incrementing the seconds value each time one second of time has elapsed.  However, you should not start keeping time until the clock display has been touched at least once.


The following state machine shows the implementation for the first two requirements above.  


<img src="{% link media/clock/clockstatemachine.jpg %}" width="800" alt="Clock control state machine diagram">


Once you have it tested and working, you can modify it to add the functionality in requirement #3 above .Add this functionality to the original state-diagram and then implement it using the conversion process outlined in the text.

Be sure to follow the guidelines in [Coding and Debugging State Machines]({% link _other/coding_state_machines.md %}).
