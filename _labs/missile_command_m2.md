---
layout: lab
toc: true
title: "Missile Command, Milestone 2: Game Control"
short_title: "M2: Game Control"
order: 8.2
indent: 1
---

In this milestone you will implement the game control logic.  This part of the program will allocate and manage all of the missile objects, detect collisions and trigger explosions, and detect when the user launches missiles.

The provided test program is very simple, it will just repeatedly tick your game control module.  In turn, your game control logic will tick all of the missile state machines, and in the next milestone, the plane.

A video of the test program is shown below:

<img src="{% link media/missilecommand/m2.gif %}" width="600" alt="Video of Milestone 2 test program">

## Preliminary

1. **Header file:** Review the provided [gameControl.h]({{site.github.fileurl}}/lab8_missilecommand/gameControl.h).
  * This module contains an *init* and *tick* function; however, the game control itself isn't actually a state machine.  Rather, during the *tick* function the module ticks all of the other state machines.

1. **Collisions:** As part of your tick function you will need to detect whenever enemy missiles enter an explosion region.  You can use the following pseudocode:
    ```c
    // Check if missile i should explode, caused by an exploding missile j
    for (i in enemy missiles)
      for (j in all missiles)
        
        if (missile[i] is not flying)
          continue
        if (missile[j] is not exploding)
          continue
        
        if (missile[i] within missile[j] radius)
          missile_trigger_explosion(&missile[i])
        
    ```

1.  **Missing Interrupts:**  The test code will report whether you missed interrupts.  You may not be able to tick all missiles in the short time between interrupts, so you may need to only tick a portion of the missiles in each tick of the game control.  This is discussed in the [class notes]({% link media/missilecommand/missilecommand.pdf %}).

## Implementation

### Requirements
- Implement the game control logic in *gameControl.c*.
- The test program should behave like the video above.

