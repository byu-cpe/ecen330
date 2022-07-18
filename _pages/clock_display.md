---
layout: page
toc: false
title: "Clock Display"
---

1. You must implement the following functions in *clockDisplay.c*. The [clockDisplay.h](https://github.com/byu-cpe/ecen330_student/blob/main/lab6_clock/clockDisplay.h) file is provided in the repo.
These are the only functions that you should "advertise" in the *clockDisplay.h* file. In your *clockDisplay.c* file you will implement these functions and other supporting functions.

1. You must implement the clockDisplay code such that it only updates the characters that have changed on the screen. Doing so will eliminate annoying flashing artifacts and make things run more smoothly. You cannot get full credit if the screen flashes or if the TAs determine (by code inspection) that you are updating characters continuously even if they have not changed.

1. You must be able to resize the screen by changing the `#define CLOCKDISPLAY_TEXT_SIZE 6` statement in *clockDisplay.h*.  This define controls the *text-size* of the characters used to display the clock (see the *setTextSize()* function in the graphics library documentation. When you change the character size, you must reposition the display so that it is centered and such that the triangles serving as arrows are resized as well.  For example, if you change the text size to 4 and recompile the code, everything must be centered and properly rendered, as shown below. You will need to actually compute the positions for things based upon the chosen text-size. You do not need to resize the touch areas.
You must be able to handle text sizes from 3 to 6.

    <img src="{% link media/clock/smallerclockphoto.jpg %}" width="300" alt="Small sized clock">

1. For *Milestone 1*, you must implement a *clockDisplay_runTest()* function that tests the clockDisplay code by running through the following operations (with a suitable delay):
  * increment hours
  * decrement hours
  * increment minutes
  * decrement minutes
  * increment seconds
  * decrement seconds
  * show the clock keeping time at a rate that is 10x the usual rate to quickly view the display while it changes. *clockDisplay_runTest()* should terminate after it has been keeping time at the 10x clock rate for 10 actual seconds. You will need a delay function for this purpose and you can find one in *utils.h*: `void utils_msDelay(long ms);`. This function implements a delay that is approximately 1 millisecond long if you pass in a value of 1. Just include the *utils.h* file in your *main.c* file and you can call the function with an appropriate argument. Note that you can only use this wait function when implementing the *clockDisplay_runTest()*. *clockControl.c* must use a state machine to implement delays. See the video below for a demonstration of clockDisplay_runTest().

<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/Yb-4OF4ULz4"> </iframe>

## Interfacing with Control

The clockControl will handle detecting when a user presses the screen (either a single short press, or a long press to do rapid incrementing), and will then call *clockDisplay_performIncDec()*, which instructs the display code to determine which of the 6 triangle regions is touched, and adjust the time appropriately.

Since the *clockDisplay_performIncDec()* function reads the touched location, it's not used in your Milestone 1 *runTest()* function, where there is no user interaction.  Instead, the function is needed in *Milestone 2*.  However, if you make good use of helper functions, you should be able to implement this function easily, making use of helper functions you created in *Milestone 1*.

## Clock Display Helps 

You can use the 'C' function [sprintf()](https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm) to greatly reduce the amount of work for generating the display. *sprintf()* is just like *printf()* except that, instead of printing to a terminal window, it "prints" the characters to a *char* array. Here is what I suggest:
  * Use three different integer variables to maintain the time as hours, minutes and seconds.
  * Use *sprintf()* to format these three variables into a time string (array of *char*). Study the formatting directives for *sprintf()*. For example, `%2hd` prints a decimal value (*h* indicates a short int) with a width of 2 with a leading space if the leading digit would be a 0. `%02hd` prints a decimal value but includes the leading 0. Think about how you might use these formatting strings together to format a time string. Combining these formatting strings with a couple of other things will completely format the clock string with no additional programming.
  * Keep two *char* arrays. One array is used to store the string containing the current time displayed on the LCD. The other string keeps track of the clock string that was written previously. Each time a change is made to the time either by keeping time, or by setting the time, compare the characters in the two *char* arrays. When you find a difference between the two arrays, erase the character(s) on the LCD display at that position and then redraw the new character(s). Redrawing is just drawing the previous character as background (*DISPLAY_BLACK* in this case). You then simply draw the new character in its place.
  * *DISPLAY_WIDTH* and *DISPLAY_HEIGHT* are defined in display.h to be the correct values for the TFT display.


## Touch Regions

The regions that you will use for the Clock lab are shown in the figure below. Thus the touch region is not limited to the triangle but is the entire rectangular region as shown below.

<img src="{% link media/clock/clocktouchscreenlayout.jpg %}" width="500" alt="Touch screen button layout for clock lab">

