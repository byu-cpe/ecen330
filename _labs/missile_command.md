---
layout: lab
toc: false
title: "Lab 8: Missile Command"
short_title: Missile Command
number: 8
order: 8
---

## Overview

In this lab you will create a game similar to the popular Atari arcade game [Missile Command](https://en.wikipedia.org/wiki/Missile_Command). The game will be a bit simpler than the original: you will have unlimited missiles, enemy missiles won't split up, you don't have to worry about defending cities, and we won't track points or high scores.  Aside from these features, the main gameplay will be very similar to the original game.  You can click the touchscreen to launch missiles from your bases to intercept incoming enemy missiles and cause them to explode.  With clever timing you can cause chain reactions and eliminate several enemy missiles with a single shot.


<img src="{% link media/missilecommand/m3.gif %}" width="600">

Designing such a game with many objects moving and interacting concurrently can be challenging.  To manage this complexity we will leverage the state machine design pattern.  In fact, every object (all missiles and the plane) will be managed by their own independent state machine, with *init* and *tick* functions.  

### Objectives
* Learn how to create a complex game using state machines to track several different objects.
* Use optimization techniques to ensure you don't miss any interrupts.
* Make a fun and challenging game!

## Preliminary

1. **Program Organization:**. The program is divided into three main parts, and you will complete one per milestone:
    - *Milestone 1:* In this milestone you will create missiles (in *missile.c*) that can fly and explode, but do not interact.  The test program will create and manage the missiles with no user input.
    - *Milestone 2:* In this milestone you will create the game control logic (*gameControl.c*) which will allocate and manage the missiles, accept touchscreen input and detect collisions between missiles.
    - *Milestone 3:* You will complete the game by creating the plane state machine (*plane.c*), and update the game logic to tick the plane state machine, and print statistics to the screen.

1. **Class Notes:**  We will discuss the provided code structures in class using [these slides]({% link media/missilecommand/missilecommand.pdf %}).


1. **Compiling:** You will need to write your own *CMakeLists.txt* file to compile the programs:
  * [main_m1.c]({{site.github.fileurl}}/lab8_missilecommand/main_m1.c) can be compiled to create the Milestone 1 test executable.
  * [main_m2.c]({{site.github.fileurl}}/lab8_missilecommand/main_m2.c) can be compiled to create the Milestone 2 test executable.
  * [main_m3.c]({{site.github.fileurl}}/lab8_missilecommand/main_m2.c) can be compiled to create the Milestone 3 test executable.

## Implementation

See Milestone pages:
* [Milestone 1: Missiles]({% link _labs/missile_command_m1.md %})
* [Milestone 2: Game Control]({% link _labs/missile_command_m1.md %})
* [Milestone 3: Plane and Stats]({% link _labs/missile_command_m1.md %})

### Files
  - **Submitted files:** 
    * *lab8_missilecommand/missile.c*
    * *lab8_missilecommand/gameControl.c*
    * *lab8_missilecommand/plane.c*

## Submission & Pass Off
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.


## Submission

### Grade Breakdown 
  * Milestone 1: 25%
    * -10% overall, if you don't create and print the output of the 10 extra test boards.
  * Milestone 2: 25%
    * -10% overall, if you miss more than 1 interrupt
  * Milestone 3: 30%
    * -10% overall, if you miss more than 1 interrupt
  * Code Quality (adhering to the coding standard): 20%