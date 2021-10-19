//
// TuyaSmartShareDeviceModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

@interface TuyaSmartShareDeviceModel : NSObject

/// The URL of the device icon.
@property (nonatomic, strong) NSString *iconUrl;

/// The device ID.
@property (nonatomic, strong) NSString *devId;

/// The device name or group name.
@property (nonatomic, strong) NSString *name;

/// Specifies whether to share the device.
@property (nonatomic, assign) BOOL share;

/// The room name.
@property (nonatomic, strong) NSString *roomName;


/// The home name.
@property (nonatomic, strong) NSString *homeName;

@end
