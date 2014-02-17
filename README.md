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
Bus 24 Device 3: ID 1a40:0101 (TERMINUS TECHNOLOGY INC.) USB 2.0 Hub [MTT] 
Bus 24 Device 5: ID 0403:6001 (Future Technology Devices International Limited) FT232R USB UART  Serial: A501B6VA
Bus 24 Device 4: ID 0403:6001 (Future Technology Devices International Limited) FT232R USB UART  Serial: A601EFG9
Bus 24 Device 2: ID 05ac:8507 (Apple Inc.) Built-in iSight  Serial: 8J97P2KF16V13A00
Bus 26 Device 2: ID 05ac:8403 (Apple Inc.) Internal Memory Card Reader  Serial: 9833
Bus 04 Device 4: ID 05ac:0236 (Apple Inc.) Apple Internal Keyboard / Trackpad 
Bus 04 Device 3: ID 05ac:8242 (Apple Inc.) IR Receiver 
Bus 06 Device 2: ID 0a5c:4500 (Broadcom Corp.) BRCM2046 Hub 
Bus 06 Device 3: ID 05ac:8213 (Apple Inc.) Bluetooth USB Host Controller  Serial: 002608CCAC6F
```

## Usage ##

```
 lsusb [ options ] 

 Options:
  -v  
	 Print the original output of `system_profiler SPUSBDataType`

  -d [vendor]:[product]
              Show only devices with the specified vendor and product ID.  Both IDs are given in hexadecimal.
```
