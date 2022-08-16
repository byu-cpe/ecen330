---
layout: page
toc: false
title: "Submitting Your Source Code to Learning Suite for Pass-Off"
short_title: "Submitting Code"
number: 5
indent: 1
---

You will turn in your source code to learning suite by submitting a single zip file for each lab.  **DO NOT** create the zip file on your own.  You must follow the steps below to use the provided program to create the zip file.  This ensures the correct files are submitted, and in a format that will work with the TA's grading system.

From the top-level directory, run:

    ./check_and_zip.py lab1

For other labs, change `lab1` to the appropriate value: `lab2`, `lab3`, `lab4`, `lab5`, `lab6`, `lab7m1`, `lab7m2`, `lab8m1`, `lab8m2`, `lab8m3`.

This program will:
  * Check out a fresh copy of the provided starter code repository.
  * Copy your files for this lab into that repository.
  * Build and run the new repository using the emulator. (Close the emulator once you are satisfied that your program is working)
  * Create a zip file, \<username\>_lab#.zip
  * Delete the temporary repository.

**Submit the created zip file using learning suite.**

If this script fails, you need to figure out why.  Do not ignore the errors and manually create a zip file.  If your code doesn't work with this test program, it won't work when the TAs try and grade it.

If the code fails to build, the most likely cases are 1) You changed files you were not supposed to change (such as the header files), 2) You created new files, or incorrectly named files, not specified in the lab description.


## Copying Zip File to Your Computer 
If you are using WSL or a VM, you may be wondering how to copy the produced Zip file to your computer, so that you can submit it via Learning Suite.  


### Virtual Machine 

The [VM Setup]({% link _setup/vm.md %}) page describes how to set up shared folders that allow you to copy files between your VM and your host computer.  You could also just open Chrome or Firefox within the VM and navigate to Learning Suite to submit the file.

### WSL 
If you are using WSL, your Windows C:\ is accessible at */mnt/c/*.  So, to copy a file to your Downloads folder, you could do the following:

    cp ~/ecen330/username_lab1.zip /mnt/c/Users/<WindowsUsername>/Downloads/

Alternatively, you can access your WSL files from within Windows File Explorer using the path `\\wsl$`.  Once you open this location, select your Linux distribution, then go to */home/\<linux_username\>*.

<!-- 
If you are working remotely, you can do this combined with the ''scp'' command described above, like this:
<code>
scp caedm_username@caedm-machine:/home/caedm_username/ecen330/username_lab1.zip /mnt/c/Users/<WindowsUsername>/Downloads/
</code> -->
