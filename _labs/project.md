---
layout: lab
toc: true
title: "Lab 9: Choose Your Own Project"
short_title: "Choose Your Own"
number: 9
order: 9
---

## Overview

For this lab you are encouraged to implement a project of your choice. Do something fun and interesting with your system. Here is how it works.

## Group
Choose whether you will do this project individually, or as a group. You can work in groups up to size 3; however, the larger the group, the more you are expected to accomplish. Take the "quiz" on Learning Suite to indicate whether you will work individually or as a group.  **Everyone needs to complete this quiz otherwise your project won't be graded**.

## Proposal (25%)

Submit a short proposal (1 page max, less is fine, PDF format) via Learning Suite. The proposal will be reviewed to make sure it is not too difficult or too easy. Only one person in your group needs to submit this.

In the proposal, describe your idea and the features of the project. Define the scope of your project, what you intend to implement. Outline any key challenges you foresee and risk mitigation strategies. You won't be graded on spelling, grammar or presentation. It just needs to be clear that you have spent some time thinking through your project idea. The grading rubric for your proposal is as follows:

* **Description 10%**: Clearly describe your idea, the features of the project, and the hardware devices involved.

* **Difficulty 10%**: This grade component is based on whether you have chosen a project of reasonable difficulty. Your project does not need to be overly complex or large to receive full points. Consider the existing multi-week labs (missile command, tic-tac-toe) when choosing the scope of your project.

* **Creativity 5%**: Your idea doesn't need to be completely original or novel. Something that is fun and interacts with hardware would be great. If your idea is very similar to one of the existing labs, you will likely lose some points here.

  Note: If you don't want to choose your own project, you can choose to do the provided [Whack-a-Mole]({% link _other/wam.md %}) or [Simon]({% link _other/simon.md %}) lab.  **However, if you do so, you will not receive points in the creative category**. 


## Implementation (65%)
<!-- Work on the proposed features individually or as a group.   -->

1. Your project must compile and run on the ECEN 330 ZYBO board (Working only on the emulator isn't enough).
1. It should interact with hardware devices, such as GPIO (buttons/switches/LEDs), interval timer, touch screen, or custom hardware devices.
1. **All new code should be placed in the `lab9_project` directory**.  You will need to create a *CMakeLists.txt* file to compile your executable.  <ins>Be sure your executable is named *lab9.elf*</ins>, otherwise the grader will not be able to locate it. You can use the hardware drivers from previous labs that you created in the *drivers* folder; however, they shouldn't be modified.

Grade Breakdown:
* **Implementation 50%**: For full points, your project should implement what you proposed, with the features and hardware discussed in your proposal.  It should be a complete and working program.

* **Quality 15%**: Your program should run smoothly and be bug free. This category evaluates the quality and correctness of your implementation.

  **Note:** You will not be graded against the coding standard for this lab. Try not to be too sad about this. :-)

## Demo Video (10%)
Create a short video (2 minutes max) demonstrating your project and major features, as well as mentioning any major issues or concessions made during your design process. Explain what you actually implemented and any open source software used. 

Upload a link to your video (Youtube link, Google Drive link, Dropbox link, etc.) using the quiz on Learning Suite.  Make sure the link is public and works.


## FAQs

**Q: Can I use a custom piece of hardware, like a video game controller?**

A: Yes, but make sure to show its functionality in your demo video. Explain the optional hardware and the complexity that was involved in supporting it (so you can get credit for your work).  Make sure the software still works somewhat without the hardware so that we can try it out without your custom hardware (example, if there's no game controller connected, use the buttons on the board).

**Q: How should we share code between group members?**

A: I suggest you create a private GitHub repository. You can go to <https://github.com/byu-cpe/ecen330_student> and click *Use This Template* to create a private repository with all of the starter 330 code. Then copy over any of the driver modules (e.g. buttons, switches) you implemented into this repository.

**Q: How do I know if my project is *difficult* enough?**

A: Designing projects from scratch is difficult. I think most people will probably try and implement too much, and find themselves running out of time to get it done on time. Pick a project that has some meaningful complexity (like many objects in missile command, or a smart computer player in the tic-tac-toe lab), but keep it fairly simple overall.

**Q: Can I use publicly available code (open source libraries, ECEN 390 sound driver code, etc.) in my project?**

A: Yes, you can use existing code that you did not write. In your demo video, be sure to mention any parts of code you didn't write yourself.

**Q: Advice?**

A: Make sure your project runs and does something meaningful, even if you don't get your entire project done in time.

That means you should work incrementally, and save progress regularly. Once you have something working, make sure it works well, and then save a copy before moving on to add more functionality. Git works well for this.
