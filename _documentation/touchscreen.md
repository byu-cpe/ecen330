---
layout: page
toc: false
title: "Touchscreen Low-Level Driver"
short_title: "Touchscreen"
number: 14
indent: 1
---

You are provided with a low-level driver for accessing the touchscreen.  The functions are available as part of the display library:

```
#include "display.h"
```

## Programming Guide
There are only three functions in the [display.h]({{iste.github.fileurl}}/include/display.h) file that are related to the touch-screen:

    // Returns whether the touchscreen display is currently being touched.
    bool display_isTouched(void);

    // Returns the touched x-y coordinate point and the pressure (z).
    void display_getTouchedPoint(int16_t *x, int16_t *y, uint8_t *z);
    
    // Throws away all previous touch data.
    void display_clearOldTouchData();

To use the touch-screen do the following: 
  * You detect a touch by checking the `display_isTouched()` function. 
  * Once you have detected a touch, invoke `display_clearOldTouchData()` to clear all of the old data out of the touch-controller.
  * The touched location cannot be read instantaneously after the user touches the screen.  You must wait at least 50 ms for the Analog to Digital Converters (ADC) settle.  
  * After waiting at least 50 ms, invoke `display_getTouchedPoint()` to determine the coordinates of the touched region.

### Return Using Pointers
Since the `display_getTouchedPoint()` needs to provide three values back to the caller, it cannot simply use the function return value.  Instead, the function takes three pointers to variables allocated by the *caller*, and will populate the values into these variables.

This is a common approach used in C to return multiple values.

Your code will look something like this (the `&` operator gets the pointer to/address of a variable):

        int16_t x, y;
        uint8_t z;
        display_getTouchedPoint(&x, &y, &z);

Even though you will ignore the `z` value, you must still provide a valid pointer.

## Coordinates
Touch-screen coordinates are in the same space as the LCD coordinates to make the programming a lot easier. 

