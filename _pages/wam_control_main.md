---
layout: page
toc: false
title: "Whack-a-Mole: Control and Main"
---

## wamControl

The controller is relatively simple for this lab. It does four things:
  - calls wamDisplay_updateAllMoleTickCounts() on every tick,
  - waits for the user to touch the screen,
  - waits for the touch analog-to-digital converters (ADC) to settle, and
  - sends the coordinates of the touch to *wamDisplay* by calling the *wamDisplay_whackMole()*, passing the origin of the touch as the argument to the function.

In addition, while waiting for the user to touch or while waiting for the touch ADC to settle, it calls *wamDisplay_updateAllMoleTickCounts()* to update the mole tick counts, as well as activating moles whenever the number of active moles falls below the minimum allowed. That's about it.

As you may have noted, the controller has no notion of how many moles are active, how many moles may be visible, or where the moles are located on the screen. It's primary job is to pass the coordinates of touches to *wamDisplay* routines to be processed. This makes it much easier to develop the display code so it can be very flexible. As the controller knows nothing about the positions of the moles, for example, the controller does not have to be changed when the mole count is changed from 9 to 6, for example. In either case the controller simply sends touch coordinates to the display software. The display software attempts to "whack" the mole with the given coordinates. If the coordinates are over a mole that is awake, the display software erases the mole and increments the hit count in the score screen. Otherwise, the display software increments the miss value in the score screen.

### Handling Initialization 

The function *wamControl_init()* initializes the state machine as if it was starting for the first time. Use this to initialize the controller state machine before starting the game and when restarting the game when the game is interrupted by pressing one of the push-buttons. There are also a number of other functions associated with the controller state machine as can be seen in *wan_control.h* file (see below).


## Main

*main.c* is provided in its entirety to you. Do not modify it, except to uncomment the appropriate line to enable a milestone:

```c
////////////////////////////////////////////////////////////////////////////////
// Uncomment one of the following lines to run Milestone 1 or 2    /////////////
////////////////////////////////////////////////////////////////////////////////
// #define RUN_PROGRAM MILESTONE_1
// #define RUN_PROGRAM MILESTONE_2
```

