//
// TuyaSmartDiscovery.h
// TuyaSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartDiscovery;

@protocol TuyaSmartDiscoveryDelegate<NSObject>

@required

/// The callback of device discovery.
/// @param discovery The instance of the TuyaSmartDiscovery class.
/// @param deviceModel The device model in Tuya Smart.
/// @param error The NSError object.
- (void)discovery:(TuyaSmartDiscovery *)discovery didDiscoveryDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface TuyaSmartDiscovery : NSObject

@property (nonatomic, weak) id<TuyaSmartDiscoveryDelegate> delegate;

/// Returns the pairing token. This token is valid for 10 minutes.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success
                failure:(TYFailureError)failure;

/// Starts to scan for devices.
/// @param ssid The name of the router.
/// @param password The password of the router.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                      timeout:(NSTimeInterval)timeout
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Starts to scan for devices by using a token.
/// @param ssid The name of the router.
/// @param password The password of the router.
/// @param token The pairing token.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                         token:(NSString *)token
                      timeout:(NSTimeInterval)timeout
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Stops scanning for devices.
- (void)stopDiscovery;

@end

NS_ASSUME_NONNULL_END
