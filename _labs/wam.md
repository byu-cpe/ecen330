---
layout: lab
toc: true
title: "Lab 7: Whack-a-Mole"
short_title: Whack-a-Mole
number: 7-old
---

# <span style="color:red"> Warning: Under Construction</span>

<span style="color:red"> This lab is changing for Fall 2021.  Please stay tuned.</span>


<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/hEq2CnNf5V4"> </iframe>

## Overview

In this lab you will create a touch-screen version of the Whack A Mole game. In the arcade game, moles pop out of holes and your job is to "whack" them by hitting them before they go back into their hole. In our version of the game, the moles are drawn on a screen. When they appear, you touch them with your finger to "whack" them. Perhaps we should rename the game "Pet the Mole". 

You will need to support three different configurations of the game: 9 moles, 6 moles, and 4 moles. The user chooses the configuration by sliding the switches appropriately. Watch the videos in the Videos Section to view the three different board configurations.

As was done with prior labs, the Whack a Mole game is conceptually organized and developed in two parts: display (wamDisplay) and control (wamControl). wam is an abbreviation for Whack A Mole and it helps shorten file-names, function-names, variable-names, etc. 

## Objectives 
  - Learn how to use *malloc()* and *free()* to implement dynamically-sized arrays.
  - Learn to make your code more flexible and responsive to user input by changing the mole layout according to user input via the slide switches. Your game will support at least three layouts: 9 moles, 6 moles, and 4 moles.
  - More practice using the *rand()* and *srand()* functions.
  - More practice with structs.
  - More exposure to different implementation approaches (the implementation style for this game moves complexity to the display software and simplifies overall control).
  - Practice using object-oriented implementation strategy.
  - Whack Moles :-)

## Preliminary 

### Program Organization
The organization of the game is similar to past labs where the display code is separated from the control code. However, in this lab, the display code will be significantly smarter than in past labs. Responsibilities for the display code include:
  - drawing the mole display,
  - supporting three different configurations of the mole board: 9 moles, 6 moles, and 4 moles,
  - activating random moles,
  - keeping track of the number of active moles,
  - drawing and erasing moles as they wake up and go dormant, or get whacked.
  - determining if a mole has been whacked by the user,
  - keeping and displaying a tally of hits, misses, and the current level of difficulty.

The controller is quite simple (my controller only has three states). The responsibilities of the controller include:
  - waiting for the user to touch the display,
  - waiting for the touch analog-to-digital converters to settle,
  - sending the touch coordinates to the display code.

### Source Code 

Three files are provided: 
  * [wamControl.h](https://github.com/byu-cpe/ecen330_student/blob/master/lab7/wamControl.h)
  * [wamDisplay.h](https://github.com/byu-cpe/ecen330_student/blob/master/lab7/wamDisplay.h)
  * [main.c](https://github.com/byu-cpe/ecen330_student/blob/master/lab7/main.c). 

**Note: Much of the functionality of the various functions is described in the commented code in the provided files. Carefully read these comments as it will save you a lot of time.**

## Implementation 

This following sections discuss how the wamDisplay and wamControl code are organized. Links to source code are also provided.

  - [Representing Moles with a Data Structure]({% link _pages/wam_data_structures.md %})
  - [Using rand() to Create Random Behavior]({% link _pages/wam_rand.md %})
  - [Drawing and Erasing Moles]({% link _pages/wam_drawing.md %})
  - [wamControl and main]({% link _pages/wam_control_main.md %})

### Milestones 
The game will be completed in two milestones.
  * **Milestone 1**: Implement enough of the game so that you can:
    * display the mole screen with the score display for 9, 6, and 4 moles, using the slide switches as described in *main.c*.
    * Fully implement the game-start and game-over screens.
    * test can be implemented as a separate *run_test()* function in *wamDisplay.c*. There is a *wamDisplay_runMilestone1_test()* function declaration provided for this purpose.
    * See the demonstration video for details.
  * **Milestone 2**:
    * Finish the game so that it meets all of the requirements.


## Requirements 
  - You must create a Whack a Mole game that supports 9, 6, and 4 moles with behavior that closely resembles the game shown in the videos. The number of moles is selected before starting the game by pushing the slide switches as discussed in *main.c*. Pushing the slide switches should not interrupt game play.
  - The game can be forced to quit by pressing any push-button. Upon quitting, the game should go to the game-over screen.
  - The game layout must be very close to the one shown in the video. It must also have a dedicated score screen at the bottom of the screen that is very similar to the one shown in the video. The score screen must display hit counts, miss counts, and the current difficulty level.
  - Game play should become progressively more difficult during game play. Levels should automatically advance during game play as the hit-count increases. You make the game more difficult in at least two ways: increasing the number of active moles and decreasing the time they are present (*ticksUntilDormant*). 
  - You must have a start-screen and a game-over screen as shown in the video.
  - You must use *malloc()* and *free()* to allocate and deallocate memory for the mole-info records when resizing the game.
  <!-- - You must use the *wamControl_setMsPerTick()* function to inform the controller how many ms transpire between each tick. In turn, the wamDisplay software must use *wamControl_getRandomMoleAsleepInterval()* and *wamControl_getRandomMoleAwakeInterval()* to set the tick counts for *ticksUntilAwake* and *ticksUntilDormant* variables in the mole-info record. -->

## Submission & Pass Off 
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.

### Grade Breakdown 

  * 35%: Milestone 1
  * 35%: Milestone 2 
  * 30%: Code quality (adherence to coding standard)


## Videos 

### Milestone 1 
<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/E4fJg1MWaHI"> </iframe>

### Complete Game 
<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/akiCjLoxr3Q"> </iframe>

## Resources 
The web has quite a bit of information on how to use *rand()* and pointers, including *malloc()* and *free()*. Here are a few curated links.
  * <http://www.cplusplus.com/reference/cstdlib/rand/>
  * <http://www.cplusplus.com/reference/cstdlib/malloc/> (Also check out the "See also" links at the bottom of the page.)
  * <http://www.cplusplus.com/reference/cstdlib/free/>
  * <http://en.cppreference.com/w/cpp/language/sizeof>
