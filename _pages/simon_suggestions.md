---
layout: page
toc: false
title: "Simon Suggestions"
---

## Generating Random Sequences 
If you include *stdlib.h* you have access to two functions that help to generate random sequences. The first function *srand(seed)* allows you to provide a *seed* value for the random number generator. Each time you call *rand()*, it will return an integer that is part of a pseudorandom sequence. However, each time you start your program from scratch, *rand()* will return the same sequence of integers. If, each time you run the program, you start out by invoking *srand(seed)* with a different seed value, the sequence will be different each time you run the program. So, how do you generate random seed values? In my Simon game I am incrementing a counter while waiting for the user to touch the screen. Once the user touches the screen, I take the counter value and use that as the seed value for *srand()*.

Review this [link](http://www.cplusplus.com/reference/cstdlib/srand/) for a more detailed explanation of and another example of how to use *srand()* and *rand()*.


## Using Function Pointers to Time the Duration of Individual Ticks 
I wrote a function called *tickTimer()* that made it relatively easy to measure how long various tick functions were taking. You may find it useful to debug timing issues. I'll provide the code here and you can modify it to suit you. Note that it uses a function-pointer so that you can pass in the pointer to a tick function so it can be invoked and timed. As currently written, it keeps track of which *tick()* function consumed the most time. I found it quite helpful while debugging my Simon game because I could see what state-machine was taking the most time at any point during the game.

```c
typedef void (functionPointer_t)();
#define MAX_DURATION_TIMER_INDEX 2
static double maxDuration_g;                    // The max duration across all ticks.
static const char* maxDurationFunctionName_g;   // Name of the function with longest duration is here.
#define SIMON_CONTROL_TICK "simonControl_tick()"
#define VERIFY_SEQUENCE_TICK "verifySequence_tick()"
#define FLASH_SEQUENCE_TICK "flashSequency_tick()"
#define BUTTON_HANDLER_TICK "buttonHandler_tick()"

// This assumes that the interval timer was initialized.
static void tickTimer(functionPointer_t* fp,
                      const char* functionName) {
    intervalTimer_reset(MAX_DURATION_TIMER_INDEX);  // Reset the timer.
    intervalTimer_start(MAX_DURATION_TIMER_INDEX);  // Start the timer.
    fp();                                           // Invoke the tick function passed in by argument.
    intervalTimer_stop(MAX_DURATION_TIMER_INDEX);   // Stop the timer.
    double duration;                                // Keep track of tick duration.
    duration = intervalTimer_getTotalDurationInSeconds(MAX_DURATION_TIMER_INDEX);  // Get the duration.
    if (maxDuration_g < duration) {                 // Keep the max duration.
        maxDuration_g = duration;
        maxDurationFunctionName_g = functionName;   // Keep track of which function had the max. duration.
    }
}
```

To use the code, just wrap *tickTimer()* around your normal tick function as shown below.

```c
  tickTimer(flashSequence_tick, FLASH_SEQUENCE_TICK);    // Tick a state machine.
  tickTimer(verifySequence_tick, VERIFY_SEQUENCE_TICK);  // Tick a state machine.
  tickTimer(buttonHandler_tick, BUTTON_HANDLER_TICK);    // Tick a state machine.
  tickTimer(simonControl_tick, SIMON_CONTROL_TICK);      // Tick a state machine.
  ...
```