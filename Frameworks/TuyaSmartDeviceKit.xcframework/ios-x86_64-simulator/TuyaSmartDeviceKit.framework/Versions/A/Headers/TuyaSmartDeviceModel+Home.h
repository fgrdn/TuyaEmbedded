//
//  TuyaSmartDeviceModel+Home.h
//  TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartDeviceModel (Home)

@property (nonatomic, assign) long long homeId;
@property (nonatomic, assign) long long roomId;

@property (nonatomic, assign) NSInteger displayOrder;
@property (nonatomic, assign) NSInteger homeDisplayOrder;

@end

NS_ASSUME_NONNULL_END
