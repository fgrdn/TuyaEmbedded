//
// TuyaSmartShareMemberDetailModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

@class TuyaSmartShareDeviceModel;

@interface TuyaSmartShareMemberDetailModel : NSObject

/// The device model list.
@property (nonatomic, strong) NSArray <TuyaSmartShareDeviceModel *> *devices;

/// The phone number.
@property (nonatomic, strong) NSString *mobile;

/// The name.
@property (nonatomic, strong) NSString *name;

/// The nickname.
@property (nonatomic, strong) NSString *remarkName;

/// Specifies whether to enable automatic sharing.
@property (nonatomic, assign) BOOL autoSharing;


@end
