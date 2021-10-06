---
layout: page
toc: false
title: Coding State Machines
indent: 0
number: 2
---

## How to Write Good Code for State Machines 

The Zybook text does a reasonable job explaining how to implement control as software-based state machines. However, it provides little guidance regarding a good implementation strategy. I tried several different strategies over the summer and have found one that works well. We will adopt it as part of the coding standard for state machines for this course. 

### In the Tick Function: State Update then State Action

In the text, the authors implement the `tick()` function with two switch statements. We will still follow this approach.  The first switch statement will perform the state-update, and the second switch statement will perform the state-action.

### State Machine Initialization Function 

All state machines should have an initialization function that will initialize the current state as well as initialize any state machine variables.  This initialization function should be called by `main` before entering the loop that is responsible for calling the `tick` function.

Why do this? 
  * It ensures all variables in the state machine are properly initialized (including the starting state).
  * It provides a single function that can be called to reset the state machine.
  * You cannot perform initialization in the first state of your state machine because the tick function first performs the state transition, and then the state action, so assuming you immediately transition out of your first state, **any actions you place in your initial state will be skipped and never executed**.



### File Organization 
Your state-machine will be completely contained in a single file. The name of this file will be given in the description for each of the labs. This single file will contain everything that the state-machine needs to implement control. Other non-control functions such as updating the display and so forth will be located in a different file. You will also have a single ".h" file to advertise the init and tick functions. The name that you must use with this ".h" will be given to you in the lab description.

#### All Variables Used By the tick() Function Have File or function Scope 
Any variable defined outside of a function needs to be defined using the `static` keyword. This ensures that the variable is local to a single file and avoids multiple-definition errors from the compiler/linker. If the variables are defined inside the tick function, they have local scope but you probably still need to use the `static` keyword because you will often want the value preserved between "tick" invocations, (e.g., a variable that you increment to implement a timer).


## Example 
I will provide a snippet from my implementation of the clock lab so that you can see what I mean.

```c
// States for the controller state machine.
enum clockControl_st_t {
	init_st,                 // Start here, transition out of this state on the first tick.
	never_touched_st,        // Wait here until the first touch - clock is disabled until set.
	waiting_for_touch_st,    // waiting for touch, clock is enabled and running.
	ad_timer_running_st,     // waiting for the touch-controller ADC to settle.
	auto_timer_running_st,   // waiting for the auto-update delay to expire 
                                 // (user is holding down button for auto-inc/dec)
	rate_timer_running_st,   // waiting for the rate-timer to expire to know when to perform the auto inc/dec.
	rate_timer_expired_st,   // when the rate-timer expires, perform the inc/dec function.
	add_second_to_clock_st   // add a second to the clock time and reset the ms counter.
};
static enum clockControl_st_t currentState;

void clockControl_init() {
  currentState = init_st;
}

void clockControl_tick() {  
  // Perform state update first.
  switch(currentState) {
    case init_st:
      break;
    case never_touched_st:
      break;
    case waiting_for_touch_st:
      break;
    case ad_timer_running_st:
      break;
    case auto_timer_running_st:
      break;
    case rate_timer_running_st:
      break;
    case rate_timer_expired_st:
      break;
    case add_second_to_clock_st:
      break;
    default:
      // print an error message here.
      break;
  }
  
  // Perform state action next.
  switch(currentState) {
    case init_st:
      break;
    case never_touched_st:
      break;
    case waiting_for_touch_st:
      break;
    case ad_timer_running_st:
      break;
    case auto_timer_running_st:
      break;
    case rate_timer_running_st:
      break;
    case rate_timer_expired_st:
      break;
     default:
      // print an error message here.
      break;
  }  
}
```

## Requirements 
Please follow the template shown above.
  - State-update before state-action.
  - You must declare a *currentState* variable as part of the enum state declaration. Use *currentState* as shown above.
  - Have an init function that initializes *currentState* and any other state variables.
  - The state names used in the *enum* must be the same names as those used in your state diagrams.
  - Each state machine will be placed in its own file.
  - Follow the *enum* approach shown above. 

## Debugging Software State Machines 
Debugging software-based state machines, especially those that are time based (referred to as synchronous in the text) can be difficult using a conventional debugger because stopping the program interferes with execution and can make it difficult to find the bug. Often it is helpful to have your state machines print out messages as they change state so you can watch state transitions occur in real-time.

The snippet of code shown below would be placed in the same file as the clock state-machine shown above. Call this function at the top of the tick function. The function shown below will print out state changes as they occur. What makes this code particularly helpful is that it only prints out a message when currentState changes value. This eliminates a lot of extraneous printing that often hides what you are trying to see. It keeps track of the previous value of currentState by using a static variable. Try using this function, I suspect that you will find it to be quite useful.

Place this function before the tick() function in the file to keep the compiler happy. Also make sure to `#include <stdio.h>`.

```c
// All printed messages for states are provided here.
#define INIT_ST_MSG "init state\n"
#define NEVER_TOUCHED_ST_MSG "never_touched_st\n"
#define WAITING_FOR_TOUCH_ST_MSG "waiting for touch_st\n"
#define AD_TIMER_RUNNING_ST_MSG "ad_timer_running_st\n"
#define AUTO_TIMER_RUNNING_ST_MSG "auto_timer_running_st\n"
#define RATE_TIMER_RUNNING_ST_MSG "rate_timer_running_st\n"
#define RATE_TIMER_EXPIRED_ST_MSG "rate_timer_expired_st\n"
// This is a debug state print routine. It will print the names of the states each
// time tick() is called. It only prints states if they are different than the
// previous state.
void debugStatePrint() {
  static enum clockControl_st_t previousState;
  static bool firstPass = true;
  // Only print the message if:
  // 1. This the first pass and the value for previousState is unknown.
  // 2. previousState != currentState - this prevents reprinting the same state name over and over.
  if (previousState != currentState || firstPass) {
    firstPass = false;                // previousState will be defined, firstPass is false.
    previousState = currentState;     // keep track of the last state that you were in.
    switch(currentState) {            // This prints messages based upon the state that you were in.
      case init_st:
        printf(INIT_ST_MSG);
        break;
      case never_touched_st:
        printf(NEVER_TOUCHED_ST_MSG);
        break;
      case waiting_for_touch_st:
        printf(WAITING_FOR_TOUCH_ST_MSG);
        break;
      case ad_timer_running_st:
        printf(AD_TIMER_RUNNING_ST);
        break;
      case auto_timer_running_st:
        printf(AUTO_TIMER_RUNNING_ST);
        break;
      case rate_timer_running_st:
        printf(RATE_TIMER_RUNNING_ST_MSG);
        break;
      case rate_timer_expired_st:
        printf(RATE_TIMER_EXPIRED_ST_MSG);
        break;
     }
  }
}
```