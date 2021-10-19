//
//  TYSmartBLEAPMEnum.h
//  Pods
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#ifndef TYSmartBLEAPMEnum_h
#define TYSmartBLEAPMEnum_h

typedef enum : NSUInteger {
    TYSmartBLEAPMType_Activate = 1,// Activates the Bluetooth device.
    TYSmartBLEAPMType_Online = 2,// Connects the device to the LAN.
    TYSmartBLEAPMType_Offline = 3,// Disconnects the device from the LAN.
    TYSmartBLEAPMType_Delete = 4,// Removes the device.
    TYSmartBLEAPMType_Publish = 5,// Sends commands to the device.
    TYSmartBLEAPMType_Report = 6,// Reports data from the device.
} TYSmartBLEAPMType;

#endif /* TYSmartBLEAPMEnum_h */
