//
// TuyaSmartHomeKitActivator.h
// TuyaSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
NS_ASSUME_NONNULL_BEGIN


@class TuyaSmartHomeKitActivator;
@protocol TuyaSmartHomeKitActivatorDelegate <NSObject>

/// Configures callbacks of network status updates.
/// @param activator The instance.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)homeKitActivator:(TuyaSmartHomeKitActivator *)activator didReceiveHomeKitDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;
@end

@interface TuyaSmartHomeKitActivator : NSObject

///Returns the singleton instance of the class.
+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<TuyaSmartHomeKitActivatorDelegate> delegate;

/// Returns the pairing token for HomeKit devices.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success failure:(TYFailureError)failure;


/// Scans for HomeKit devices.
/// @param timeout The timeout value.
/// @param token The pairing token.
/// @param success Called when the task is finished. TuyaSmartDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout token:(NSString *)token success:(void (^)(TuyaSmartDeviceModel *))success failure:(TYFailureError)failure;


/// Scans for HomeKit devices.
/// @param timeout The timeout value.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout success:(TYSuccessString)success failure:(TYFailureError)failure;


/// Returns device information by product ID.
/// @param productId The product ID.
/// @param success Called when the task is finished. TYSuccessDict is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomekitDeviceInfoWithProductId:(NSString *)productId success:(TYSuccessDict)success failure:(TYFailureError)failure;


/// Returns device information by product ID.
/// @param productId The product ID.
/// @param uuid The device UUID.
/// @param success Called when the task is finished. TYSuccessDict is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomekitDeviceInfoWithProductId:(NSString *)productId uuid:(NSString *)uuid success:(TYSuccessDict)success failure:(TYFailureError)failure;


/// Stops scanning for devices.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
