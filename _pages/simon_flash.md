---
layout: page
toc: false
title: "Simon FlashSequence"
---

The *flashSequence* state machine flashes the computer's color sequence to the user so that the user can attempt to copy it. *flashSequence_enable()* allows the state machine to leave its initial state. *flashSequence_completed()* can be called to see if the machine has completed the task of flashing the color sequence to the user. *flashSequence_disable()* allows the state machine to return to its initial state (make sure that it has completed its task). 

  * The [flashSequence.h]({{site.github.fileurl}}/lab6/flashSequence.h) file is provided to you.
  * Test code is provided to you in [fsTester.c]({{site.github.fileurl}}/lab6/fsTester.c), so you can test your state machine implementation to see if it is working correctly. You can watch the video below to see an example of the test code in action.


## fsTester Video 

<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/vuxKXupeuQg"> </iframe>