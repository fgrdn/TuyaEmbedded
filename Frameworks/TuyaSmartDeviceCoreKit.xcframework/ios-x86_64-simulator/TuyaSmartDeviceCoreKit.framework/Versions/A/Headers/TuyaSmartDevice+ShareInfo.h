//
//  TuyaSmartDevice+ShareInfo.h
//  TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartDevice.h"

@class TuyaSmartReceivedShareUserModel;

/// Tuya smart device share function
@interface TuyaSmartDevice (ShareInfo)

/// Get users for device sharing.
/// @param success Called when the task finishes successfully. TuyaSmartReceivedShareUserModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareInfoWithSuccess:(void(^)(TuyaSmartReceivedShareUserModel *model))success
                       failure:(TYFailureError)failure;

/// Remove Received Shared.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeReceiveDeviceShareWithSuccess:(TYSuccessHandler)success
                                    failure:(TYFailureError)failure;


@end
