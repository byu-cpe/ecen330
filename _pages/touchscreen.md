---
layout: page
toc: false
title: "Using the Touch Screen"
---

Touch-screen coordinates are in the same space as the LCD coordinates to make the programming a lot easier. **Note that the rotation is automatically set for you in display_init(). Don't change it or the touch-display coordinates won't match the lcd screen coordinates.**

There are only three functions in the [display.h](https://github.com/byu-cpe/ecen330_student/blob/master/include/display.h) file that are related to the touch-screen:

    bool display_isTouched(void);

    // Returns the x-y coordinate point and the pressure (z).
    void display_getTouchedPoint(int16_t *x, int16_t *y, uint8_t *z);
    
    // Throws away all previous touch data.
    void display_clearOldTouchData();

To use the touch-screen do the following: 
  * You detect a touch on the the array calling the *display_isTouched()* function. 
  * Once you have detected a touch, invoke *display_clearOldTouchData()* to clear all of the old data out of the touch-controller.
  * Next, you wait about 40-50 ms for the Analog to Digital Converters (ADC) settle.
  * After waiting 40-50 ms, invoke *display_getTouchedPoint()* to determine the coordinates of the touched region.
  * Make sure to pass the **address** of the arguments to *display_getTouchedPoint()*. Otherwise the arguments cannot be updated by the function. Your code will look something like:

        int16_t x, y;
        uint8_t z;
        display_getTouchedPoint(&x, &y, &z);
        ...


The regions that you will use for the Clock lab are shown in the figure below. Thus the touch region is not limited to the triangle but is the entire rectangular region as shown below.

<img src="{% link media/lab4/clocktouchscreenlayout.jpg %}" width="500" alt="Touch screen button layout for clock lab">

