//
// TYGroupDevList.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartGroupDevListModel
#define TuyaSmart_TuyaSmartGroupDevListModel

#import <Foundation/Foundation.h>

/// Information about the group device list.
@interface TuyaSmartGroupDevListModel : NSObject


/// The device ID.
@property(nonatomic,strong) NSString    *devId;

/// The gateway ID.
@property(nonatomic,strong) NSString    *gwId;

/// Indicates whether the device is online.
@property(nonatomic,assign) BOOL        online;

/// The URL of the device icon.
@property(nonatomic,strong) NSString    *iconUrl;

/// The product ID.
@property(nonatomic,strong) NSString    *productId;

/// Indicates whether the device is selected.
@property(nonatomic,assign) BOOL        checked;

/// The device name.
@property(nonatomic,strong) NSString    *name;

/// The device address.
@property(nonatomic,strong) NSString    *nodeId;


@end

#endif

