---
layout: lab
toc: true
title: "Old Lab: Simon"
# short_title: "Prev Lab: Simon"
number: 5
---

<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/S8Ndaw5tfdo"> </iframe>

## Overview 

In this lab you will create the ECEN 330 version of the electronic Simon game. Electronic Simon, as you probably recall, is a game where the computer plays a sequence to you and you attempt to re-key in the sequence correctly. Correct attempts allow you to go on to attempt longer sequences. Electronic versions of Simon often combine colored lights with sound. For our lab, we will use the LCD/touch-pad to generate colored squares that the user will attempt to touch in the correct sequence (we won't use sound).

This lab will be implemented using four concurrent, synchronous state machines. As before, I will stipulate the file-names, function-names, and so forth to expose you to at least one good way to implement the game.

## Objectives 
  - Learn how to implement a complex game using concurrent, synchronous state machines.
  - Learn effective ways to communicate between concurrent state machines.
  - Learn how state machines can be controlled by other state machines.
  - Learn how to handle global variables with functions.
  - Learn how to interlock state machines.

## Preliminary 

## Implementation Strategy 

Simon is much more complex than Tic-Tac-Toe, so we need to look at how the game is played in detail so we can come up with good implementation strategies. Our Simon game, as shown in the video above, will use four colored regions on the LCD. The colored sequence will be shown using these colored regions and the user will attempt to follow the computer's sequence by touching the right sequence of colored regions.

Here is the organizational strategy that we will use:

  * Provide a set of display functions to draw the colored regions implemented in: *simonDisplay.h/simonDisplay.c:*
  * Use a *buttonHandler* state machine to handle drawing buttons and for detecting touches and time-outs.
  * Use a *flashSequence* state machine to flash the sequence that the user must attempt to mimic.
  * Use a *verifySequence* state machine to verify that the sequence of user touches matches the computer-generated sequence.
  * Use a *simonControl* state machine to control everything at the top level.

## Milestones 

You will complete this lab in four milestones:
  * Milestone 1: Implement the *buttonHandler* state machine and *simonDisplay* code.
  * Milestone 2: Implement the *flashSequence* state machine and *globals* code.
  * Milestone 3: Implement the *verifySequence* state machine.
  * Milestone 4: Implement the top-level *simonControl* state machine so that you implement a Simon game with the the same behavior as shown in the demo video for the Simon game. 

Once again you are provided a *main.c* with code that can be uncommented to run the chosen milestone.  Aside from uncommenting one of these lines, do not change *main.c*.

```c
////////////////////////////////////////////////////////////////////////////////
// Uncomment one of the following lines to run Milestone 1, 2, 3, or 4    //////
////////////////////////////////////////////////////////////////////////////////
// #define RUN_PROGRAM MILESTONE_1
// #define RUN_PROGRAM MILESTONE_2
// #define RUN_PROGRAM MILESTONE_3
// #define RUN_PROGRAM MILESTONE_4
```

## System Organization 


The figure below shows the "architecture" for the Simon game and shows how the state machines communicate with each other.
Starting at the far left, the *simonControl* state machine coordinates the operation of the other state machines to implement the Simon game. The *simonControl* state machine uses *flashSequence_enable()* and *flashSequence_disable()* to control when the *flashSequence* state machine displays the color sequence to the user. *simonControl* then activates the *verifySequence* state machine to verify that the user correctly taps the color sequence. The related *verifySequence_enable()* and *verifySequence_disable()* functions are used to enable and disable the *verifySequence* state machine. The *verifySequence* state machine controls the *buttonHandler* state machine (again using *buttonHandler_enable()/buttonHandler_disable()* functions) to determine which colors the user has touched. All of the state machines use functions provided by either *simonDisplay.h* or *display.h* to interact with the LCD display/touch pad. Note that some of the function names have been abbreviated in the figure. Also, the figure does not show interactions between the state machines and global variables. This is discussed later in this document.

<img src="{% link media/lab6/simonsoftwarearchitecture.jpg %}" width="1000" alt="Simon software architecture">

### Controlling State Machines with Interlocks 

You will need to use "interlocks" to control when state machines can start up. You need to use an interlock to prevent the state machine from "racing" through to a new state when you may not be ready. Using the *flashSequence* state machine as an example, you use *flashSequence_enable()* to start the machine. You can find out when it has finished "flashing the sequence" by calling *flashSequence_completed()*. If this function returns true, then you know that the state machine has completed its task. Next, you invoke *flashSequence_disable()* to turn off the state machine until you are ready to invoke it again. Invoking this function allows the *flashSequence* state machine to return to its initial state where it waits until you invoke *flashSequence_enable()* to enable the state machine to flash the next element of the sequence. Three of the state machines will require interlocks of this type: *flashSequence*, *buttonHandler*, and *verifySequence*. It is most effective and straightforward if you implement the interlocks in the same general way as shown in the figure below.

The interlock template as shown below will work with any state machine that requires interlocks to synchronize its operation with other state machines. As shown in the figure, assume the existence of some initial state and some final state. These states are not special states but are just the normal states that comprise your state machine. At startup, the state machine does not leave the initial state until a variable named *enable* is set to true (provide a *_enable()* function that sets an enable flag to true). Once the state machine reaches its final state, it stays in that final state until the *enable* variable is set to false (provide a *_disable()* to set the enable variable to false). If you design your state machines using this kind of interlock, you will find that it is straightforward to control them. If you don't use this *enable()/disable()* approach, it is difficult to keep the state machine from immediately commencing operation from the final state.

If you look closely at the provided test programs, you will find that the code carefully exercises the interlock capability. Just look for the related *_enable()* and *_disable()* functions in the source code. If you study the code carefully, you will understand how these interlocks work.

<img src="{% link media/lab6/interlocks.jpg %}" width="600" alt="FSM interlocks">

There are a couple of things to keep in mind with this approach. If you are doing things that must only be done once in either the initial or final state, you may need to add additional states (one after the initial state, one before the final state), or perhaps you can meet the need with a Mealy action.


## Requirements  

This lab will be completed as several interacting modules.  Individual descriptions of simon modules with helps and suggestions:

  - [Writing the simonDisplay Code]({% link _pages/simon_display.md %})
  - [Writing the buttonHandler Code]({% link _pages/simon_button.md %})
  - [Writing the flashSequence Code]({% link _pages/simon_flash.md %})
  - [Writing the verifySequence Code]({% link _pages/simon_verify.md %})
  - [Writing the globals Code]({% link _pages/simon_globals.md %})
  - [Helps and Suggestions]({% link _pages/simon_suggestions.md %})

### simonControl State Machine Code 

*simonControl* provides the top-level control for the Simon Game and it coordinates the behavior of the other state machines to implement the Simon game. You can watch the video at the top of this page to see how things are supposed to work.

We provide you with [simonControl.h]({{iste.github.fileurl}}/lab6/simonControl.h). You must implement at least the *simonControl_init()*, *simonControl_tick()*, and *simonControl_enable()* functions so that the provided *simonMain.c* can compile, link, and operate properly.

### Other Requirements
  - You must follow the coding standard.
  - You must follow the coding standard/strategy for state machines.
  - You are not allowed to use *util_msDelay()* in any of your code. You must implement delays using counters in your state machines.
  - You can select a suitable delay for time-out and a speed for flashing the sequence.
  - If the user selects the incorrect color or you detect a time-out, just display the longest sequence number correctly achieved (allowing enough time for the user to read the message) and go back to the starting screen (see the video that demonstrates the simon game at the top of this page).

## Submission & Pass Off 
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.


### Grade breakdown

  * 10%: Milestone 1
  * 10%: Milestone 2
  * 10%: Milestone 3
  * 40%: Milestone 4
    * -10% overall, if game play is not smooth, correct, responsive. To receive the entire 10% your game must work correctly with no observable bugs. Your game should be responsive and be fun to play.
  * 30%: Code Quality (adhering to the coding standard)
 
