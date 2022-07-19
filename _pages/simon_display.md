---
layout: page
toc: false
title: "Simon Display"
---


SimonDisplay provides a function that draws a "button", e.g., a small square in the region that indicates to the user the color that is assigned to the region (*simonDisplay_drawButton()*). It also provides a function to draw a square that fills in the entire region (*simonDisplay_drawSquare()*). This function serves two purposes: 1) it can be used when flashing the computer's sequence to the user, and 2) it can be used to provide touch feedback to the user. That is, when the user touches the smaller "button", the game can then draw the bigger square in the touched area so that the user knows that the game acknowledges his or her touch. This will be discussed in more detail when we talk about the *buttonHandler* state machine. Both of these functions accept a region-number argument to determine where to draw the "button" or square.

Finally, simonDisplay also computes the region number based upon the map shown in the [simonDisplay.h]({{iste.github.fileurl}}/lab6/simonDisplay.h) file (*simonDisplay_computeRegionNumber()*). It also provides a convenience function that draws all of the buttons (*simonDisplay_drawAllButtons()*).

I have provided the entire [simonDisplay.h]({{iste.github.fileurl}}/lab6/simonDisplay.h) file. You must implement all of the functions as shown. Read the comments to understand what operations each function must perform. 

There is no provided test code for simonDisplay.  You may want to write your own test code to verify it is working correctly.
