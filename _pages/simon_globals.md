---
layout: page
toc: false
title: "Simon Globals"
---

There a small amount of information that is shared between state machines. This global information is managed by code in [globals.h](https://github.com/byu-cpe/ecen330_student/blob/main/lab6/globals.h) and *globals.c*. Rather than just directly reading and/or writing global variables directly, it is much better practice to create functional interfaces to these variables. The *globals* code provides functions to set the sequence of colors by copying a supplied array of region numbers. A function to get the sequence length and functions to get and set the sequence iteration length are also provided. The iteration length indicates how far along you are in the current sequence. You can see how these functions are used in the various test functions that we have provided.
You are given [globals.h](https://github.com/byu-cpe/ecen330_student/blob/main/lab6/globals.h), but you will need to write *globals.c*.