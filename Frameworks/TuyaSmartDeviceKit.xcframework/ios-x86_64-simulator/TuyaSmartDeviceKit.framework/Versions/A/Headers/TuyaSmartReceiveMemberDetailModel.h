//
// TuyaSmartReceiveMemberDetailModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

@class TuyaSmartShareDeviceModel;

@interface TuyaSmartReceiveMemberDetailModel : NSObject

@property (nonatomic, strong) NSArray <TuyaSmartShareDeviceModel *> *devices;

/// The account information, email, or phone number.
@property (nonatomic, strong) NSString *mobile;

/// The user nickname.
@property (nonatomic, strong) NSString *name;

/// The remarks.
@property (nonatomic, strong) NSString *remarkName;

@end
