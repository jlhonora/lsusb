lsusb command for Mac OS X
==========================

This is an utility to easily list USB devices in Mac OS X, just like the `lsusb` command in Linux. It leverages the data from the `system_profiler SPUSBDataType` built-in command available in Mac. You can type `lsusb -v` to get the unmodified output of `system_profiler SPUSBDataType`.

To install, clone the repository and copy to a location available in your PATH, for example `sudo cp lsusb /usr/sbin`. You can also install it with [Homebrew](http://brew.sh):

```
brew update             && \
brew tap jlhonora/lsusb && \
brew install lsusb
```

Here's an output example:

```
Bus 036 Device 002: ID 05ac:8507 Apple Inc. Built-in iSight  Serial: 8J97P2KF16V13A00
Bus 038 Device 002: ID 05ac:8403 Apple Inc. Internal Memory Card Reader  Serial: 000000009833
Bus 004 Device 003: ID 05ac:8242 Apple Inc. IR Receiver 
Bus 004 Device 002: ID 05ac:0236 Apple Inc. Apple Internal Keyboard / Trackpad 
Bus 006 Device 002: ID 0a5c:4500 Broadcom Corp. BRCM2046 Hub 
Bus 006 Device 003: ID 05ac:8213 Apple Inc. Bluetooth USB Host Controller  Serial: 002608CCAC6F
Bus 036 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub 
Bus 038 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub 
Bus 004 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub 
Bus 006 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
```

## Usage ##

```
List USB devices
  -v  Increase verbosity (show output of "system_profiler SPUSBDataType")
  -s  [[bus]:][devnum]
       Show only devices with specified device and/or
       bus numbers (in decimal)
  -d  [vendor]:[product]
       Show only devices with the specified vendor and
       product ID numbers (in hexadecimal)
  -p  Display manufacturer names in parentheses
  -t  Dump the physical USB device hierarchy as a tree
  -V  Show version of program
  -h  Show usage and help
```

For a more accurate usage description type `man lsusb` or `man man/lsusb.8` if inside the script's directory.
