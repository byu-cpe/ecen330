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

1. Submit a short proposal (1 page is plenty) via Learning Suite. The proposal will be reviewed to make sure it is not too difficult or too easy. If you are working as a group, include the names of those in your group.
1. Work on the proposed features individually or as a group.
1. Submit a link to a short video (1-2 minutes) via Learning Suite demonstrating your project and all of its features. Make sure your video link is publicly viewable. Again, if you are working as a group, include the names of those in your group.

## Requirements

1. Your project should run on the ECEN 330 ZYBO board.
1. It should interact with hardware devices, such as GPIO (buttons/switches/LEDs), interval timer, touch screen, or custom hardware devices.

You can optionally work in groups (up to size 3); however, the larger the group, the more you are expected to accomplish.

## Proposal Guidance and Grading

In the a short proposal (1 page max), describe your idea and the features of the project. Define the scope of your project, what you intend to implement. Outline any key challenges you foresee and risk mitigation strategies. You won't be graded on spelling, grammar or presentation. It just needs to be clear that you have spent some time thinking through your project idea. The grading rubric for your proposal is as follows:

* **Description 20%**: Clearly describe your idea, the features of the project, and the hardware devices involved.

* **Difficulty 15%**: This grade component is based on whether you have chosen a project of reasonable difficulty. Your project does not need to be overly complex or large to receive full points. Consider the existing labs (clock, tic-tac-toe, simon and whack-a-mole) when choosing the scope of your project.

* **Creativity 5%**: Your idea doesn't need to be completely original or novel. Something that is fun and interacts with hardware would be great. If your idea is very similar to one of the existing labs, you will likely lose some points here.

  Note: If you don't want to choose your own project, you can choose to do the provided [Whack-a-Mole]({% link _other/wam.md %}) lab. **However, if you do so, you will not receive points in the creative category**. This is not to suggest that your project should be twice as complex as whack-a-mole! (In fact, whack-a-mole is of sufficient complexity and difficulty). We want to encourage you to design and make your own project, as you will likely learn more from this process.

## Demo Video Guidance and Grading

Create a short video (2 minutes max) demonstrating your project and major features, as well as mentioning any major issues or concessions made during your design process. Explain what you actually implemented and any open source software used. The video grading rubric follows:

* **Implementation 50%**: For full points, your project should implement what you proposed, run correctly, and be responsive. The focus here is on demonstrated function.

* **Quality 10%**: Ideally, the features demonstrated should be bug free. This category evaluates the quality and correctness of your implementation.

**Note:** You will not be graded against the coding standard for this lab. Try not to be too sad about this. :-)

## FAQs

**Q: What directory should I use to implement my project?**

A: If you are designing your own project, make a new "lab" subdirectory in your cloned repository (e.g. lab7p) and place **_all_** your code files there. If you are going to implement whack-a-mole, use the existing lab7 directory.

**Q: Can I use a custom piece of hardware, like a video game controller?**

A: Yes, but make sure to show its functionality in your demo video. Explain the optional hardware and the complexity that was involved in supporting it (so you can get credit for your work).

**Q: How should we share code between group members?**

A: I suggest you create a private GitHub repository. You can go to <https://github.com/byu-cpe/ecen330_student> and click *Use This Template* to create a private repository with all of the starter 330 code. Then copy over any of the driver modules (e.g. buttons, switches) you implemented into this repository.

**Q: How do I know if my project is *difficult* enough?**

A: Designing projects from scratch is difficult. I think most people will probably try and implement too much, and find themselves running out of time to get it done on time. Pick a project that has some meaningful complexity (like timely user input in the Simon lab, or a smart computer player in the tic-tac-toe lab), but keep it fairly simple overall.

**Q: Can I use publicly available code (open source libraries, ECEN 390 sound driver code, etc.) in my project?**

A: Yes, you can use existing code that you did not write. In your demo video, be sure to mention any parts of code you didn't write yourself.

**Q: Advice?**

A: Make sure your project runs and does something meaningful, even if you don't get your entire project done in time.

That means you should work incrementally, and save progress regularly. Once you have something working, make sure it works well, and then save a copy before moving on to add more functionality. Git works well for this.
