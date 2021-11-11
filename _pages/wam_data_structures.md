---
layout: page
toc: false
title: "Whack-a-Mole: Data Structures"
---

## wamDisplay_moleInfo_t Struct

Moles are represented using a struct that is shown below. Carefully read the comments associated with the struct to understand how the struct is used. The ticksUntilAwake/ticksUntilDormant will be decremented at a regular rate by the controlling state machine.

```c
typedef struct {
        wamDisplay_point_t origin;  // This is the origin of the hole for this mole.

        // A mole is active if either of the tick counts are non-zero. The mole is dormant otherwise.
        // During operation, non-zero tick counts are decremented at a regular rate by the control state machine.
        // The mole remains in his hole until ticksUntilAwake decrements to zero and then he pops out.
        // The mole remains popped out of his hole until ticksUntilDormant decrements to zero.
        // Once ticksUntilDormant goes to zero, the mole hides in his hole and remains dormant until activated again.
        wamDisplay_moleTickCount_t ticksUntilAwake;  // Moles wake up (pop out of hole) when this goes from 1 -> 0.
        wamDisplay_moleTickCount_t ticksUntilDormant; // Moles go dormant (back in hole) this goes 1 -> 0.
} wamDisplay_moleInfo_t;
```

Each mole is represented by a single mole-info record that provides the mole's screen coordinates and awake/dormant status (*ticksUntilAwake*, *ticksUntilDormant*). You will use a one-dimensional array of pointers to keep track of, and to access your mole-info records. You will need to resize this array whenever the user selects a different number of moles for game play. You will allocate/deallocate memory using *malloc()/free()* whenever you resize the array.


## Coding Example for malloc() and free() 

The mole-info records will be accessed via a one-dimensional array of pointers, where each pointer will point to a single mole-info record. The order that these mole-info records occur within the array is unimportant. It is only important that you can access each of the mole-info records.  The following code is a good starting point for *wamDisplay.c*:

```c
// This will contain pointers to all of the mole info records.
// This will ultimately be treated as an array of pointers.
static wamDisplay_moleInfo_t** wamDisplay_moleInfo;

// Allocates the memory for wamDisplay_moleInfo_t records.
// Computes the origin for each mole assuming a simple row-column layout:
// 9 moles: 3 rows, 3 columns, 6 moles: 2 rows, 3 columns, 4 moles: 2 rows, 2 columns
// Also inits the tick counts for awake and dormant.
void wamDisplay_computeMoleInfo() {
    // Setup all of the moles, creates and inits mole info records.
    // Create the container array. It contains pointers to each of the mole-hole info records.
    //    wamDisplay_moleInfo =  // Need to uncomment this line and initialize this variable via malloc().
}
```

The array of pointers will be stored at *wamDisplay_moleInfo* (see above). To illustrate how this is done, here is a simple example that performs tasks similar to those that you will need to perform. You can compile this program if you like. Also, though the steps that assign and print-out the values of the structs is not described here it is provided so you can see how to access the variables in the struct.

```c
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {uint16_t x; uint16_t y;} myStruct;  // Simple struct as an example.

// Step 1: Define the variable that will contain the array of pointers.
static myStruct** arrayOfPointers = NULL;  // This is just a pointer, it doesn't point to anything yet.

#define NUMBER_OF_POINTERS 4

int main() {
 
    // Step 2: allocate enough memory to hold NUMBER_OF_POINTERS. I need enough storage for 4
    // pointers. sizeof(myStruct*) returns the number of bytes for a single pointer to a myStruct. 
    // Multiply that value by 4 to get enough memory for 4 pointers. 
    // malloc() returns a (void *) so you must cast it to match the type of arrayOfPointers.
    // Rule of thumb: the number of stars (*) must match on both sides of the equation.
    // arrayOfPointers is pointer-to-pointer (myStruct**) so you need two stars (*) for the cast.
    arrayOfPointers = (myStruct**) malloc(NUMBER_OF_POINTERS * sizeof(myStruct*));

    // Step 3: Allocate memory for each myStruct.
    // sizeof(myStruct) returns the number of bytes required by a single myStruct.
    // The for-loop iterates 4 times, during each iteration, it grabs enough memory
    // for a single myStruct and stores it address (the pointer value) in a location in arrayOfPointers.
    for (uint16_t i=0; i<NUMBER_OF_POINTERS; i++) {
        // Second, allocate an instance of myStruct and point to it.
        arrayOfPointers[i] = (myStruct*) malloc(sizeof(myStruct));
    }
    // Step 4: assign values to these structs.
    for (uint16_t j=0; j<NUMBER_OF_POINTERS; j++) {
        arrayOfPointers[j]->x = j;  // Just need a number.
        arrayOfPointers[j]->y = NUMBER_OF_POINTERS - j;  // Just need a number.
    }
    // Verify that the assignments worked.
    for (uint16_t k=0; k<NUMBER_OF_POINTERS; k++) {
        printf("Struct contents x:%d, y:%d\n", arrayOfPointers[k]->x, arrayOfPointers[k]->y);
    }
    // When you are done, you must return the memory to the system or you will create a memory leak.
    // First deallocate all of the structs.
    for (uint16_t l=0; l<NUMBER_OF_POINTERS; l++) {
        free(arrayOfPointers[l]);   // This deallocates the memory. 
        arrayOfPointers[l] = NULL;  // This step is not necessary but will keep you from reusing deallocated memory.
    }
    // Next, deallocate the array that contains the pointers to the structs.
    free(arrayOfPointers);   // Deallocates the container of arrays.
    arrayOfPointers = NULL;  // Also keeps you from reusing the deallocated memory.
}
```

Let's work through the three labeled steps of the above example. See the figure below for additional explanation.

Step 1: Define the pointer to the array of pointers. This pointer doesn't yet point to anything.

Step 2: Allocate sufficient memory to contain 4 pointers, where each pointer will eventually point to a struct. *arrayOfPointers* now points to something; however, the memory it contains does not point to anything.

Step 3: Allocate 4 instances of *myStruct* and point to them using the *arrayOfPointers*.

<img src="{% link media/lab7/pointerexample.jpg %}" width="700" alt="Diagram of pointer to pointers">

The code example also demonstrates how to deallocate memory when you are done. This is an important step to make sure that the memory footprint of your program doesn't grow indiscriminately over time.

