---
layout: page
toc: false
title: Coding State Machines
indent: 0
number: 2
---



## Coding Standard

### 1. General 

  * **1.1** You must write C-code. No class definitions are allowed. If you need a data-structure, it must be something supported by "C", such as a ''struct''.

  * **1.2** When compiled, your code must not cause the compiler to issue any warnings or errors. 

  * **1.3** Your code, when submitted, must be in a finished form. You are allowed a total of 5 lines of "commented-out" code per file.

  * **1.4** Avoid using repetitive sections of copied and pasted code in your programs.

  * **1.5** Busy loops (delays based on for-loops) are not allowed, except for test code.

  * **1.6** All code will be graded against the coding standard.


### 2. Files
  * **2.1** All ".h" files must contain declarations for all constant values, function prototypes, etc., that you want to "advertise" for use. All ".h" files must not contain executable code, only function declarations, #define, etc. This includes any definitions of any variables.

  * **2.2** All ".h" files must have a corresponding ".c" with the same base name.


### 3. Naming
  * **3.1** All function names and constant values contained in ".h" files must be prefixed by the base-name of the file + underscore (e.g., ''buttons_read()'', ''#define BUTTONS_BTN0_MASK 0x1''). Function names and constant values that are used only within .c files do not need to be prefixed by the base-name of the file.

  * **3.2** All ''#define'' names must be all uppercase letters.

  * **3.3** All names (including `#define`) must be *meaningful*. For example, `#define TEN 10` is unacceptable.


### 4. Data Types 
  * **4.1** For integer variables, you must use the types contained in [stdint.h](http://en.wikibooks.org/wiki/C_Programming/C_Reference/stdint.h). There are two exceptions:
    - You may use *int* as the return type of *main()*.
    - You may use the standard integer types when interacting with C or OS library calls (ie: *char* when working with *strcpy()*, *int* when calling *open()*, etc.).


### 5. Comments 
  * **5.1** Comments must be *meaningful*. Make sure that your code completely describes your intent. If your code is unclear or does not completely describe what is going on, comment accordingly.

  * **5.2** Each function definition (not declaration), including *main()*, must have a comment header which includes:
    - A description of the function (what it does, what has to happen first, etc.).
    - A list of all of the arguments, their names, and meanings.
    - A description of the return value and its meaning.

  * **5.3** Each time you create a new scope (when using `{}` braces), there must be a comment associated with it to describe what the code is doing. Loops and conditionals, for example, define a new scope. 
    - For *if* statements, a comment preceding the *if* is sufficient; you aren't required to add additional comments for *else*/*else if* statements. 
    - Scopes containing a single statement (ie, *if (x) y++;*) do not require a comment.


### 6. Formatting 
  * **6.1** You must use the `clang-format` code formatter on your code. The formatter will ensure that all indention is consistent throughout your code.


### 7. Magic Numbers and Strings 
  * **7.1** All scalar constants must be `#define`, with one exception: 
    * The constants **0** or **1** may be used anywhere in your code, except as standalone function arguments.  For example, `foo(0)` is not permitted, while `foo(x+1, y+1)` is allowed.

  * **7.2** All strings used on your touchscreen must be `#define`. Debugging statements that are printed to the console do not need to be `#defined`.


### 8. Miscellaneous 
  * **8.1** Use the `const` key word only if you are defining an array of constant values (e.g., `const uint8_t foo[LEN] = {1, 2};`)


### 9. State Machines =====
  * **9.1** The state machine must use `switch` statements as taught by the textbook.

  * **9.2** State update must be before state action.

  * **9.3** The state names used in the *enum* must be the same as those used in your state diagrams.

  * **9.4** Each state machine must be placed in its own file. One state machine must be contained entirely in a single file.

  * **9.5** All variables in your state machine defined outside of a function must be defined using the *static* keyword.

  * **9.6** You must provide an *init* function (*base-name_init*) that is called before any of your provided functions can be called. This function must initialize the *currentState* and any other state variables.


### 10. Warnings 
  * **10.1** Your code must compile without warnings.


## Grading Source Code
The TAs will apply the following method  when evaluating your source code. The goal is to get you in the habit of writing, readable, reusable, high-quality code. As such the TAs will be quite strict when grading your code.
  * In general, the coding standard counts toward 30% of your lab grade (some exceptions noted below).
  * Each lab has a set number of maximum points that represents how many infractions can be made before you earn 0% on the coding standard portion.
  * You will lose a point for each infraction, not just each type of infraction.  For example, if your code has 5 magic numbers, you will lose 5 points.
  * For example, in Lab 4, if you have 10 infractions, you will receive a coding standard score of 10/20, and thus 15%/30% on the coding standard portion of the lab.
 

| Lab |  Points | Notes on Lab |
|-----|---------|--------------|
| Lab1 |  10 | Feedback given, but worth 0% of lab grade |
| Lab2 |  10 | 30% of lab grade, first 10 infractions won't reduce your score |
| Lab3 |  10 | 30% of lab grade |
| Lab4 |  20 | 30% of lab grade |
| Lab5 |  20 | 30% of lab grade |
| Lab6 |  30 | 30% of lab grade |
| Lab7 |  20 | 30% of lab grade | 