---
layout: page
toc: false
title: "Simon Button Handler"
---


The *buttonHandler* state machine and associated code abstract the "buttons" from the user. The *buttonHandler* state machine draws the buttons, draws a larger square over the button when a touch is detected, provides a function that can be called to detect when a release has been detected (really, a touch followed by a release) and the necessary *enable()* and *disable()* functions. During normal usage, you would call *buttonHandler_enable()* to start the state machine. Next you would continuously check to see if a button was touched and then released by calling *buttonHandler_releaseDetected()*. If this function returns true, you would invoke *buttonHandler_getRegionNumber()* to find out what region/color was touched. You would call *buttonHandler_disable()* to stop the state machine and allow it to return to its initial state. This process would begin again by calling *buttonHandler_enable()*.

**Note: because time-out (when the user takes too long to touch a colored button on the screen) is detected by verifySequence, it is possible to leave the buttonHandler hanging in a state (waiting for a touch, for example) if verifySequence detects a time-out. So, you need to design your state machine so that, no matter what state it is in, it will jump back to the proper beginning state anytime the enable/disable flag becomes false. For example, if verifySequence detects time-out while the buttonHandler state-machine is waiting for the user to touch the display, verifySequence would invoke button_handler_disable(). When this happens, the button_handler state-machine must return to the state that it would normally return to if it had completely detected a touch-noTouch sequence.**

  * You are given the [buttonHandler.h](https://github.com/byu-cpe/ecen330_student/blob/master/lab6/buttonHandler.h) file.
  * You are also given the test code for the *buttonHander*.  This is located in [bhTester.c](https://github.com/byu-cpe/ecen330_student/blob/master/lab6/bhTester.c).  You can see how the test operates by watching the video below.

**Note: the buttonHandler test code (and ultimately the simonControl code) draws the buttons the first time as the game is started. This simplifies the buttonHander state-machine. So, your buttonHandler does not need to draw the buttons when the game first starts up. You will do that in the simonControl code. Once the buttons are drawn for the first time, the buttonHandler will keep the display properly updated, as shown in the buttonHandler test code.**

## bhTester Video 

<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/PVAOhThg8Bk"> </iframe>


