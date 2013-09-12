//
//  main.c
//  lsusb-iokit
//
//  Created by JLH on 9/11/13.
//  Copyright (c) 2013 JLH. All rights reserved.
//

#include <stdio.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/usb/IOUSBLib.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/usb/USBSpec.h>
#include <CoreFoundation/CoreFoundation.h>

void process_usb_device(io_service_t device);
static bool getVidAndPid(io_service_t device, int *vid, int *pid);

// Based on http://stackoverflow.com/questions/7567872/how-to-create-a-program-to-list-all-the-usb-devices-in-a-mac
// and http://lists.apple.com/archives/usb/2007/Nov/msg00038.html
int main(int argc, const char *argv[])
{
    printf("Starting\n");
    CFMutableDictionaryRef matchingDict;
    io_iterator_t iter;
    kern_return_t kr;
    io_service_t device;
    
    /* set up a matching dictionary for the class */
    matchingDict = IOServiceMatching(kIOUSBDeviceClassName);
    if (matchingDict == NULL) {
        return -1; // fail
    }
    
    /* Now we have a dictionary, get an iterator.*/
    kr = IOServiceGetMatchingServices(kIOMasterPortDefault, matchingDict, &iter);
    if (kr != KERN_SUCCESS) {
        return -1;
    }
    
    /* iterate */
    while ((device = IOIteratorNext(iter))) {
        /* do something with device, eg. check properties */
        process_usb_device(device);
        /* And free the reference taken before continuing to the next item */
        IOObjectRelease(device);
    }

    
    /* Done, release the iterator */
    IOObjectRelease(iter);
    printf("Done\n");
    return 0;
}

typedef struct USBDevice_t {
    char deviceName[200];
    int vid, pid;
} USBDevice;

void process_usb_device(io_service_t device) {
    USBDevice d;
    IORegistryEntryGetName(device, d.deviceName);
    getVidAndPid(device, &(d.vid), &(d.pid));
    printf("%s %04x:%04x\n", d.deviceName, d.vid, d.pid);
}

static bool getVidAndPid(io_service_t device, int *vid, int *pid) {
	bool success = false;
	CFNumberRef	cfVendorId = (CFNumberRef)IORegistryEntryCreateCFProperty(device, CFSTR("idVendor"), kCFAllocatorDefault, 0);
	if (cfVendorId && (CFGetTypeID(cfVendorId) == CFNumberGetTypeID()))	{
		Boolean result;
		result = CFNumberGetValue(cfVendorId, kCFNumberSInt32Type, vid);
		CFRelease(cfVendorId);
		if (result) {
			CFNumberRef	cfProductId = (CFNumberRef)IORegistryEntryCreateCFProperty(device,                                      CFSTR("idProduct"), kCFAllocatorDefault, 0);
			if (cfProductId && (CFGetTypeID(cfProductId) == CFNumberGetTypeID())) {
				Boolean result;
				result = CFNumberGetValue(cfProductId,
                                          kCFNumberSInt32Type, pid);
				CFRelease(cfProductId);
				if (result) {
					success = true;
				}
			}
		}
	}
	return (success);
}
