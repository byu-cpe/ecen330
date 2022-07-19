---
layout: page
toc: false
title: "Simon VerifySequence"
---

The *verifySequence* state machine verifies that the user touched the colors in the correct sequence. It provides the *verifySequence_enable()* and *verifySequence_disable()* functions that operate as described for the *buttonHandler* and *flashSequence* state machines. In addition, it provides a function that can be called to determine if the *verifySequence* state machine has completed its task (*verifySequence_complete()*). It also provides two functions that can be called to determine if some error occurred: *verifySequence_isTimeOutError()* and *verifySequence_isUserInputError()*.

The *verifySequence* state machine operates as follows. First you enable the state machine by invoking *verifySequence_enable()*. Once you enable the verifySequence state machine, it will use the buttonHandler state machine to accept the user sequence. Remember that the buttonHandler state machine draws the buttons, draws a larger square over the button when a touch is detected, provides a function that can be called to detect when a release has been detected (really, a touch followed by a release) and the necessary enable() and disable() functions. You use *buttonHandler_getRegionNumber()* to determine what color the user touched. Refer back to the system diagram at the top of the page to see how the buttonHandler state machine works with the verifySequence state machine.

You check *verifySequence_complete()* to see if the state machine has finished its task of verifying the user-tapped color sequence. If this function returns true, the state machine has finished. Verify if an error occurred by calling both *verifySequence_isTimeOutError()* and *verifySequence_isUserInputError()*. If neither of these functions returns true, the user touched the correct sequence of colored squares. Invoke *verifySequence_disable()* to synchronize state-machine operation.

  * You are given the [verifySequence.h]({{iste.github.fileurl}}/lab6/verifySequence.h) file. 
  * You are also given test code in [vsTester.c]({{iste.github.fileurl}}/lab6/vsTester.c). You can see a demonstration of this test code by watching the video below.

## vsTester Video 

<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/yk-YgY5bVoc"> </iframe>

