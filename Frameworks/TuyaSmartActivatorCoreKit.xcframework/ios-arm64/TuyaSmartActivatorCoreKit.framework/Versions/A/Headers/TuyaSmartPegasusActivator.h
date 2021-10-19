//
// TuyaSmartPegasusActivator.h
// TuyaSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartPegasusActivator;
@protocol TuyaSmartPegasusActivatorDelegate <NSObject>

/// Returns the devices that are found by Pegasus.
/// @param activator The activator instance.
/// @param serverDeviceModel The device is found, but no device ID is available.
/// @param deviceModel The device is found, but no device ID is available.
/// @param error An error occurs while processing the request.
- (void)pegasusActivator:(TuyaSmartPegasusActivator *)activator serverDevice:(TuyaSmartDeviceModel *)serverDeviceModel didFoundDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError * __nullable)error;

/// Returns the devices that are found by Pegasus.
/// @param activator The activator instance.
/// @param deviceModel The device that is found by Pegasus.
/// @param error An error occurs while processing the request.
- (void)pegasusActivator:(TuyaSmartPegasusActivator *)activator didReceiveDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError * __nullable)error;

@end

@interface TuyaSmartPegasusActivator : NSObject

@property (nonatomic, weak) id<TuyaSmartPegasusActivatorDelegate> delegate;


/// Starts to scan for and pair devices by using Pegasus.
/// @param devIDs A list of device IDs.
/// @param serverTimeout The timeout value for paired devices to scan for devices to be paired.
/// @param clientTimeout The timeout value for devices to be paired. These devices are not added to the home.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIDs:(NSArray<NSString *> *)devIDs
                  serverTimeout:(NSTimeInterval)serverTimeout
                  clientTimeout:(NSTimeInterval)clientTimeout
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;


/// Stops pairing devices by Pegasus after devices are paired.
/// @param devIDs A list of devices that support Pegasus.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)stopDiscoverWithDevIDs:(NSArray<NSString *> *)devIDs
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;


/// Pairs specified devices by using Pegasus.
/// @param devIDs A list of devices that support Pegasus.
/// @param UUIDs A list of UUIDs of devices to be configured.
/// @param token The pairing token.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startActivatorWithDevIDs:(NSArray<NSString *> *)devIDs
                           UUIDs:(NSArray<NSString *> *)UUIDs
                           token:(NSString *)token
                         timeout:(NSTimeInterval)timeout
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;


/// Cancels the Pegasus-based pairing of devices.
/// @param devIDs A list of devices that support Pegasus.
/// @param UUIDs A list of UUIDs of devices to be paired.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelActivatorWithDevIDs:(NSArray<NSString *> *)devIDs
                            UUIDs:(NSArray<NSString *> *)UUIDs
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;
@end

NS_ASSUME_NONNULL_END
