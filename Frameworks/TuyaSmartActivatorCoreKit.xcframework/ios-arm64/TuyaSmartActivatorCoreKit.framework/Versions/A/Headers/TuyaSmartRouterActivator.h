//
// TuyaSmartRouterActivator.h
// TuyaSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartRouterActivator;

@protocol TuyaSmartRouterActivatorDelegate <NSObject>

/// The callback of pairing status updates.
/// @param activator The activator instance.
/// @param deviceModel The value of TuyaSmartDeviceModel.
/// @param error An error occurs while processing the request.
- (void)routerActivator:(TuyaSmartRouterActivator *)activator didReceiveAutoConfigDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface TuyaSmartRouterActivator : NSObject

/// Returns the delegate of TuyaSmartRouterActivator.
@property (nonatomic, weak) id<TuyaSmartRouterActivatorDelegate> delegate;


/// Returns the pairing token. This token is valid for 10 minutes.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success
                failure:(TYFailureError)failure;


/// Starts to scan for devices.
/// @param devIds A list of device IDs.
/// @param type Specifies whether to start scanning. Set the value to `0` to start scanning.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Starts to scan for devices.
/// @param devIds A list of device IDs.
/// @param token The pairing token.
/// @param type Specifies whether to start scanning. Set the value to `0` to start scanning.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                token:(NSString *)token
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Stops scanning for devices.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
