---
layout: lab
toc: true
title: "Missile Command, Milestone 1: Missiles"
short_title: "M1: Missiles"
order: 8.1
indent: 1
---

In this milestone you will implement the missile state machine in *missile.c*.  This state machine will be used for every missile object in the game.  Player missiles are shown in green and explode when reaching their destination.  Enemy missiles are red and explode when hitting an explosion (but this won't happen until next milestone).  A video of the test program is shown below:

<img src="{% link media/missilecommand/m1.gif %}" width="600">

## Preliminary

1. Review the provided [missile.h]({{site.github.fileurl}}/lab8_missilecommand/missile.h).
  * Make sure you understand the purpose of each member of the *missile_t* struct.  Review the [class notes]({% link media/missilecommand/missilecommand.pdf %}) if needed.

## Implementation

### Requirements
- Implement the functions in *missile.h*
    * *missile_init_plane()* won't be used in this milestone, so you can implement it later if you like.
    * *missile_is_dead()*, *missile_is_exploding()*, and *missile_is_flying()* are very simple functions that can just return a boolean based on the the current state of the missile.  The Milestone 1 test program only uses *missile_is_dead()*, but you will likely find the other functions helpful in later milestones.
- The test function should behave like the video above.  You can choose your own colors, but the player missiles and enemy missiles should be different colors.

