---
layout: page
toc: false
title: "Whack-a-Mole: Random Behavior"
---


## wamDisplay: Using *rand()* and *srand() to Create Random Behavior 
Whack a Mole exhibits random behavior in at least three different ways:
  - moles are randomly activated,
  - moles randomly wake up, and
  - moles randomly go back to sleep (become dormant).

In your game, a mole is randomly selected and activated when the *wamControl* state machine invokes *wamDisplay_activateRandomMole()*. This function randomly selects a random mole that is not currently active and sets its *ticksUntilAwake* and *ticksUntilDormant* variables to random values (more on that later). First of all, how do you randomly select a mole?

## Selecting a Mole with A Randomly-Generated Array Index 
As discussed above, all moles are represented by mole-info records and these are accessed by a one-dimensional array. Randomly selecting a currently dormant mole and activating it can be performed using the following steps:
  * Step 1: generate a random index that is in the proper range, e.g, if you have a total of 9 moles, the index must be between 0 and 8.
  * Step 2: access the mole-info record from the array. If the mole is currently dormant, activate it, if not, go back to Step 1. 

It is a good idea to limit this to some number of attempts in case you have a bug of some sort. Otherwise, you may get stuck in an infinite loop though this should only happen in the presence of a bug.

Generating a random index that is in range is straightforward if you know how to use the *%* (modulo) operator. As you should recall, the modulo operator performs integer division and returns the remainder. Thus the following code will give you a random number between 0 and 4:

    rand() % 5


## Generating Random Time Intervals 
In addition to activating random moles, you need to also set mole's *ticksUntilWake* and *ticksUntilDormant* to reasonable random values. By reasonable, I mean that the time intervals have to be such that they provide good game play. It wouldn't make much sense to set the *ticksUntilAwake* variable so that it takes an hour for the mole to wake up and pop up out of its hole. You probably don't want the value to be 0 either. Something between 0.5 and 1.0 seconds might be a good place to start, for example. In any case, you can simply use *rand()* again for this purpose. The code below will generate a tick-count that will consume between 0.5 and 1.5 seconds, assuming that ticks occur every 50 ms (the controller updates mole tick-counts via *wamDisplay_updateAllMoleTickCounts()*).

    (rand() % 21) + 10


If the result of *rand() % 21* is 0, 0 + 10 = 10, 10 ticks at 50ms/tick = 0.5 seconds. That represents the lower bound. If the result of *rand() % 21* is 20, 20+10 = 30, 30 ticks at 50ms/tick = 1.5 seconds. This is the upper bound.

## Setting Mole Asleep/Awake Intervals in Seconds
You use *wamControl_setMsPerTick()* to tell the controller how many ms will transpire between each tick. The *wamDisplay* code then uses *wamControl_getRandomMoleAsleepInterval()* and *wamControl_getRandomMoleAwakeInterval()* to compute a tick count for each of the *ticksUntilAwake* and *ticksUntilDormant* variables for each mole when it is activated. Doing things this way makes the time intervals independent of the tick rate and makes it much easier to determine good values for the amount of time the mole spends asleep before awaking (*ticksUntilAwake*) and the time the mole spends awake before going dormant (*ticksUntilDormant*).
