//
// TuyaSmartDeviceShareModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartDeviceShareRequestModel : NSObject

/// The home ID.
@property (nonatomic, assign) long long homeID;

/// The country code.
@property (nonatomic, copy) NSString *countryCode;

/// The account.
@property (nonatomic, copy) NSString *userAccount;

/// A list of device IDs.
@property (nonatomic, copy) NSArray<NSString *> *devIds;

@end

NS_ASSUME_NONNULL_END
