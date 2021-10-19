//
//  TuyaSmartDevice+Home.h
//  TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartDevice (Home)

/// Synchronizes device information.
/// @param devId The device ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)syncDeviceInfoWithDevId:(NSString *)devId
                         homeId:(long long)homeId
                        success:(nullable TYSuccessHandler)success
                        failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
