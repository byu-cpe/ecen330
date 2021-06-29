---
layout: page
toc: false
title: "Home Setup: Linux"
indent: 1
number: 2
---





## Compiler Tools and Libraries 

In order to compile programs for the emulator, you need several packages. Run these commands to install them:
```
sudo apt update
sudo apt install build-essential qt5-default clang-format zip python3-pip x11-apps
```

If you want to compile programs to run on the board, you will need the ARM GCC compiler, the Python serial library, and the openocd programmer.  If you are only using the emulator you can skip this step.
```
sudo apt install gcc-arm-none-eabi python3-serial xterm openocd
```




## CMake 

The version of CMake that is available with Ubuntu is too old.  Run this to update to a newer version:

```
sudo pip3 install --upgrade cmake
```

Test your new cmake version, and make sure it is at least 3.14.5:

```
cmake --version
```

## VSCode 

[Install VSCode](https://code.visualstudio.com/).  

If you are using the WSL terminal on Windows, you still install the Windows version of VSCode.  After you install it, run it.  There should be a popup suggesting you install the 'Remote WSL' package.  Install it, then close VS Code.

<img src="{% link media/setup/vscode_wsl.png %}" alt="VS Code Remote - WSL extension popup">

**Verifying installation**: Open your Linux terminal and run `code` to make sure it opens VS Code.

## X-Windows (WSL with emulator only)

In order to display graphical Linux programs from Windows, you need to run an X-Windows server.  
If you only want to run on the board, and never run the emulator, you can skip this step.  Or, if you are running Linux and not WSL on Windows, you can skip this step.

Otherwise, [install an X server]({% link _setup/xserver.md %}).

## Continue

[Continue to Setup Step #2]({% link _setup/step_2.md %})




