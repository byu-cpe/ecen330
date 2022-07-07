---
layout: lab
toc: true
title: "Lab 7: Choose Your Own Adventure"
short_title: "Choose Your Own"
number: 7
---

## Overview

For this lab you are free to implement a project of your choice.

## Requirements

1. Your project should run on the ECEN 330 board.  
1. It should interact with hardware devices, such as GPIO (buttons/switches/LEDs), interval timer, touch screen, or custom hardware devices.

You can optionally work in teams (up to size 3); however, the larger the team, the more you are expected to accomplish.


## Grading Scheme

| Category  | Percentage |
|-----------|------------|
| Proposal  | 20%   
| Project Difficulty & Creativity   | 30%
| Project Implementation            | 40%
| Youtube Video                     | 10%

  * **Proposal**: In LearningSuite, complete the *Proposal Quiz*. In this quiz you will need to describe your idea, identify three milestones, describe key challenges, and risk mitigation strategies.

    This proposal is for your own benefit.  You won't be graded on spelling, grammar or presentation.  It just needs to be clear that you have spent some time thinking through your project idea.
 
 * **Project Difficulty & Creativity**: This grade component is based on whether you have chosen an interesting project of reasonable difficulty.  Your project does not need to be overly complex or large to receive full points.  Consider the existing labs (clock, tic-tac-toe, simon and whack-a-mole) when choosing the scope of your project.

   **Note:** If you don't want to choose your own project, you can choose to do the provided [Whack-a-Mole]({% link _other/wam.md %}) lab.  **However, if you do so, you will receive 20/30 in this category**.  This is not to suggest that your project should be twice as complex as Whack-a-mole! (In fact, Whack-a-mole is of sufficient complexity and difficulty).  However, we want to encourage you to design and make your own project, as you will likely learn more from this process.

* **Project Implementation:** This will evaluate the quality and correctness of your implementation.  For full points, your project should implement what you proposed, compile without errors or warnings, run correctly, and be responsive and be bug-free.

* **Youtube Video:** You should create a short video (2 minutes max) demonstrating your project and major features, as well as mentioning any major issues or concessions made during your design process. 

**Note:** You will not be graded against the coding standard for this lab.

## Code Structure

Create a *lab_project* directory in your repository and place **_all_** your code files there.

## FAQs

**Q: Can I use a custom piece of hardware, like a video game controller?**

A: Yes, but obviously this makes grading more difficult.  In this case your project should have an option to use the I/O on the board (buttons, switches, touchscreen) instead.  This option should be the default when you submit your code so I can try out your project without the piece of hardware.  

Then, in your Youtube video you should explain the optional hardware and the complexity that was involved in supporting it (so that you can get credit for that work).

**Q: How should we share code between team members?**

A: I suggest you create a private Github repository.  You can go to <https://github.com/byu-cpe/ecen330_student> and click *Use This Template* to create a private repository with all of the starter 330 code.  You would then want to put any necessary code (ie. buttons and switches drivers) into this repository.

**Q: How do I know if my project is *difficult* enough?**

A: Designing projects from scratch is difficult.  I think most people will probably try and implement too much, and find themselves running out of time to get it done on time. Pick a project that has some meaningful complexity (like timely user input in the Simon lab, or a smart computer player in the tic-tac-toe lab), but keep it fairly simple overall.

**Q: Can I use publicly available code (open source libraries, ECEN 390 sound driver code, etc) in my project?

A: Yes, you can use existing code that you did not write.  In your youtube video be sure to mention any parts of code you didn't write yourself.

**Q: Advice?**

A: Make sure you submit something that compiles, runs, and does something meaningful.  Even if you don't get your entire project done in time.

That means you should work incrementally, and save progress regularly.  Once you have something working, make it sure it works well, and then save a copy before moving on to add more functionality.  Git works well for this.

## Submission

**Be careful to follow these instructions carefully.  If your code doesn't compile and run properly, you will lose points.**

Submit a zip file on LearningSuite with the entire contents of your *lab_project* directory.

This can be done by the following command:
```
cd lab_project
zip my_project.zip ./*
```

Notes:
  * The files should be *directly* in your zip file (ie, your zip file should **NOT** contain a directory of your files).
  * You will need to modify your top-level CMakeLists.txt file to have a line *add_subdirectory(lab_project)*, but you shouldn't submit the top-level CMakeLists.txt file.
  * Like previous labs, you can use the existing drivers (buttons_switches, intervalTimer) and don't need to submit them with your files.  
