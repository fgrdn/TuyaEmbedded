//
// TuyaSmartBLEManager+Channel.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartBLEManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^TPBleResultBlock)(NSString *result);

/// @brief TuyaSmartBLEManager+Channel provides methods to enable Bluetooth LE devices to report large amounts of data through Bluetooth channels.
@interface TuyaSmartBLEManager (Channel)
 
/// Indicates whether the device is connected.
///
/// @param uuid     The UUID for the device.
///
/// @return The local connection status of the Bluetooth LE device.
- (BOOL)isBLEChannelDeviceConnect:(NSString *)uuid;

/// Sets the callback when the transfer is completed.
///
/// @param block    Called when the task is finished.
/// @param uuid     The UUID of the device.
- (void)setCompletionBlock:(TPBleResultBlock)block uuid:(NSString *)uuid;

/// The app requests to start a big data transfer.
///
/// @param uuid     The UUID of the device.
- (void)appApplyLaunch:(NSString *)uuid;

/// The app forcibly terminates data transmission.
///
/// @param uuid     The UUID of the device.
- (BOOL)appMandatoryTrans:(NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
