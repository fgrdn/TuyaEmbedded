//
// TuyaSmartActivator+Home.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartActivator (Home)

/// Returns the pairing token by home ID. This token is valid for 10 minutes.
/// @param homeId The home ID.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeId:(long long)homeId
                   success:(TYSuccessString)success
                   failure:(TYFailureError)failure;


/// Returns the pairing token by product ID. This token is valid for 10 minutes.
/// @param productKey The product ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithProductKey:(NSString *)productKey
                        homeId:(long long)homeId
                       success:(TYSuccessString)success
                       failure:(TYFailureError)failure;

/// Returns the pairing token by UUID. This token is valid for 10 minutes.
/// @param uuid The device UUID.
/// @param homeId The home ID.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithUUID:(NSString *)uuid
                  homeId:(long long)homeId
                 success:(TYSuccessString)success
                 failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
