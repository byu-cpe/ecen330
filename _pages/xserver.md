---
layout: page
toc: false
title: "XServer"
indent: 2
number: 3
---

Anytime you want to run Linux graphical programs (such as the emulator) from Windows or Mac, you need an *X Window Server* running on your local machine. 

## Windows Install 

  - Install an X Windows server.  There are many, but I suggest you download and install [VcXsrv Windows X Server](https://sourceforge.net/projects/vcxsrv/).

  - [Check your WSL version](https://learn.microsoft.com/en-us/windows/wsl/install#check-which-version-of-wsl-you-are-running) to see if you have version 1 or 2 installed.
  - Edit your `.bashrc` file and add the follwing line (depending on your WSL version)
    - *WSL Version 1*
  
        `export DISPLAY=localhost:0.0`

    - *WSL Version 2*

        `export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0`

  - Restart your terminal.
  - To run the X server, find *XLaunch* in your start menu and run it. (Press Windows key and type *XLaunch*).
    - Click *Next* on the options windows, leaving the default options alone.
  - You can test that your X server is working by running `xeyes`.  If the X server is running correctly, this will create a pop-up window with a set of animated eyes that follow your mouse cursor.  (You may need to install *xeyes* using the command `sudo apt install x11-apps`).
  - When running, the XServer will display in your Windows system tray.  If you restart your computer, or close the XServer, you will need to run *XLaunch* again.

### Firewall
If the above instructions still aren't working, it's possible that Windows Firewall is blocking the X-server.  To fix this, run the Windows *Incoming Connections* troubleshooter. 
  - Open Windows Settings (Win + I)
  - Click *Update & Security*
  - Click *Troubleshoot* in the left-hand pane.
  - Click the *Additional Troubleshooters* link.
  - Click the *Incoming Connections* troubleshooter (If you have trouble finding this there are some pictures to help here [[https://www.howto-connect.com/troubleshoot-incoming-connection-windows-10/]]).
  - When the troubleshooter runs, it will hopefully provide you with an option titled *Allow other computers to connect to VcXsrv windows xserver".  Select that and click Next.  You will then need to click *Try these repairs as an administrator'', and then *Apply this fix*.  Then *Close*.  

## macOS Install 

1. Go to [XQuartz](https://www.xquartz.org) and download XQuartz. XQuartx is the X-server for Macs. Do the standard stuff for installation.

2. Logout and then log back in. This step is important because your environment will not be setup properly otherwise.

