---
layout: page
toc: false
title: "LCD Graphics"
number: 11
indent: 1
---

  - [Graphics Library Documentation]({% link media/lab1/adafruit-gfx-graphics-library.pdf %})
    * This is a description of the graphics software that is available for use with the 330 board. I ported over this software from Adafruit (they sell the LCD panel that is mounted on the 330 board).
    * If you add the prefix "display_" to the function names described in this document, most (not quite all) of the functions are available for use with the ZYBO board, e.g., `drawLine()` becomes `display_drawLine()`.
    * Take a look at [include/display.h](https://github.com/byu-cpe/ecen330_student/blob/main/include/display.h). Also, note that *DISPLAY_WIDTH* and *DISPLAY_HEIGHT* are defined in display.h to be the correct values for height and width of the display. *display.h* is also listed in the source-code section for your convenience.

## Drawing Shapes

## Colors

## Helpful Defines