---
layout: page
toc: false
title: "Whack-a-Mole: Drawing/Erasing Moles"
---

There are no functions for drawing and erasing moles in *wamDisplay.h* as this functionality is only necessary within *wamDisplay.c*. The following two functions, implemented in *wamDisplay.c* draw and erase moles as necessary:
  * *wamDisplay_updateAllMoleTickCounts()*
    * Once the mole tick-counts have been updated, this function will either draw the mole (the mole has awakened) or erase the mole (the mole has become inactive).
  * _wamDisplay_whackMole(wamDisplay_point_t* whackOrigin)_
    * This function will erase an active mole if the coordinates of the "whack" match the coordinates of an active mole.


The following starter code can be used in wamDisplay.c to store and set up the data structures for the mole info records.

```c
// This will contain pointers to all of the mole info records.
// This will ultimately be treated as an array of pointers.
static wamDisplay_moleInfo_t **wamDisplay_moleInfo;

// Allocates the memory for wamDisplay_moleInfo_t records.
// Computes the origin for each mole assuming a simple row-column layout:
// 9 moles: 3 rows, 3 columns, 6 moles: 2 rows, 3 columns, 4 moles: 2 rows, 2
// columns Also inits the tick counts for awake and dormant.
void wamDisplay_computeMoleInfo() {
  // Setup all of the moles, creates and inits mole info records.
  // Create the container array. It contains pointers to each of the mole-hole
  // info records.
  //    wamDisplay_moleInfo =  // Need to uncomment this line and initialize
  //    this variable via malloc().
}
```