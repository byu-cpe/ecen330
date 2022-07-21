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

<img src="{% link media/missilecommand/m3.gif %}" width="600">

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