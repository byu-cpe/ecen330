---
layout: lab
toc: true
title: "Missile Command, Milestone 3: Plane & Stats"
short_title: "M3: Plane & Stats"
order: 8.3
indent: 1
---

In this milestone you will complete the Missile Command game.  You will add a state machine for the plane which fires a single missile when moving across the screen.  You will also track some statistics and display them on the screen: the number of missiles the player fired, and the number of enemy/plane missiles that impact the ground.

A video of the complete game is shown below:

<img src="{% link media/missilecommand/m3.gif %}" width="600" alt="Video of Milestone 3 test program">

## Preliminary

1. Review the provided [plane.h]({{site.github.fileurl}}/lab8_missilecommand/plane.h).
    * The plane should be implemented as a state machine.

1. **Plane Behavior:** 
    * The plane is destroyed when entering an explosion radius, but does not produce its own explosion.
    * A plane fires a single missile while traveling across the screen.  You can choose when the plane fires the missile.
    * After the plane is destroyed, or travels off screen, you should wait some time (no more than 10 seconds) before sending the plane again.

1. **Game Control Modifications**: You will need to modify your *gameControl.c* code to:
    * Tick the plane state machine.
    * Track and draw the required statistics.

## Implementation

### Requirements
- Implement the functions in *plane.h*
- The final test program should behave like the video above.

### Other Notes
* You may notice that once you add calls to your *plane.c* functions in your *gameControl*, your Milestone 2 will no longer compile as you probably didn't configure *plane.c* to be compiled for your Milestone 2 executable.  You have a couple options:
    1. You could change Milestone 2 to also compile plane.c.  This works fine if you've already zipped up and submitted Milestone 2.  However, if you haven't yet zipped up your Milestone 2 submission this will be an issue.  Your *plane.c* file won't be submitted as part of Milestone 2, so you need to make sure your *Milestone 2* code compiles without it. 
    2. Alternatively, if you want your Milestone 2 code to continue to work without plane.c compiled into it, you can add macros to only call the plane functions when Milestone 3 is compiled.  In your gameControl.c you would call plane functions like this:
        ```c
        #ifdef LAB8_M3
            plane_init(plane_missile);
        #endif
        ```

        And then to define `LAB8_M3` when Milestone 3 is compiled, you could add this to your *CMakeLists.txt*:
        ```
        target_compile_definitions(lab8_m3.elf PUBLIC LAB8_M3)
        ```