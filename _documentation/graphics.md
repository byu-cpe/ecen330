---
layout: page
toc: false
title: "LCD Graphics"
number: 11
indent: 1
---

## Documentation
  - [Graphics Library Documentation]({% link media/lab1/adafruit-gfx-graphics-library.pdf %})
    * This is a description of the graphics software that is available for use with the 330 board. This software was ported over from Adafruit (they sell the LCD panel that is mounted on the 330 board).
    * If you add the prefix "display_" to the function names described in this document, most (not quite all) of the functions are available for use with the ZYBO board, e.g., `drawLine()` becomes `display_drawLine()`.
    * Take a look at [include/display.h](https://github.com/byu-cpe/ecen330_student/blob/main/include/display.h). 

## Drawing Shapes
 * Filling screen: `display_fillScreen`
 * Pixels: `display_drawPixel`
 * Lines: `display_drawLine`, `display_drawFastVLine`, `display_drawFastHLine`
 * Rectangles: `display_drawRect`, `display_fillRect`
 * Circles: `display_drawCircle`, `display_fillCircle`
 * Triangles: `display_drawTriangle`, `display_fillTriangle`
 * and many more

## Drawing Text
 * `display_drawChar`
 * `display_setCursor`
 * `display_setTextColor`, `display_setTextColorBg`
 * `display_setTextSize`
 * `display_print`, `display_println`
 * and many more...


## Helpful Defines
  * `DISPLAY_WIDTH`: width of LCD in pixels
  * `DISPLAY_HEIGHT`: height of LCD in pixels
  * `DISPLAY_CHAR_WIDTH`: pixel width of one character (multiplied by size of font)
  * `DISPLAY_CHAR_HEIGHT`: pixel height of one character (multiplied by size of font)


### Colors

* `DISPLAY_BLACK`
* `DISPLAY_BLUE`
* `DISPLAY_DARK_BLUE`
* `DISPLAY_RED`
* `DISPLAY_DARK_RED`
* `DISPLAY_GREEN`
* `DISPLAY_DARK_GREEN`
* `DISPLAY_CYAN`
* `DISPLAY_DARK_CYAN`
* `DISPLAY_MAGENTA`
* `DISPLAY_DARK_MAGENTA`
* `DISPLAY_YELLOW`
* `DISPLAY_DARK_YELLOW`
* `DISPLAY_WHITE`
* `DISPLAY_GRAY`
* `DISPLAY_DARK_GRAY`
* `DISPLAY_LIGHT_GRAY`
