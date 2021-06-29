---
layout: page
toc: false
title: "VS Code Tips"
number: 6
---

## Building from Within VS Code 

From within VSCode you can build your code as follows:
  * To run `cmake` you can press F1 and select *Tasks: Run Task*, *cmake*.  
  * To run `make` you can press F1 and select *Tasks: Run Task*, *make*, or *Tasks: Run Build Task*, or *Ctrl+Shift+B* (on Windows).

The tasks have been set up in the [tasks.json](https://github.com/byu-cpe/ecen330_student/blob/master/.vscode/tasks.json) file.  Consider adding a new task to this file that allows you to program *lab1.elf* to the board.


## Debugging from VS Code