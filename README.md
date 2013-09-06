lsusb command for Mac OS X
==========================

This is an utility to easily list USB devices in Mac OS X, just like the `lsusb` command in Linux. It leverages the data from the `system_profiler SPUSBDataType` built-in command available in Mac.

To install, clone the repository and copy to a location available in your PATH, for example `cp lsusb /usr/sbin`.

Here's an output example:

```
Bus 24 Device 3 ID: 0101:1a40  (TERMINUS TECHNOLOGY INC.) USB 2.0 Hub [MTT] 
Bus 24 Device 5 ID: 6001:0403  (Future Technology Devices International Limited) FT232R USB UART  Serial: A501B6VA
Bus 24 Device 4 ID: 6001:0403  (Future Technology Devices International Limited) FT232R USB UART  Serial: A601EFG9
Bus 24 Device 2 ID: 8507:05ac  (Apple Inc.) Built-in iSight  Serial: 8J97P2KF16V13A00
Bus 26 Device 2 ID: 8403:05ac  (Apple Inc.) Internal Memory Card Reader  Serial: 9833
Bus 04 Device 4 ID: 0236:05ac  (Apple Inc.) Apple Internal Keyboard / Trackpad 
Bus 04 Device 3 ID: 8242:05ac  (Apple Inc.) IR Receiver 
Bus 06 Device 4 ID: f432:0451  (Texas Instruments) Texas Instruments MSP-FET430UIF  Serial: 0CFF41E50F8E3309
Bus 06 Device 2 ID: 4500:0a5c  (Broadcom Corp.) BRCM2046 Hub 
Bus 06 Device 3 ID: 8213:05ac  (Apple Inc.) Bluetooth USB Host Controller  Serial: 002608CCAC6F
```
