//
//  TuyaSmartBLEWifiActivator+PlugPlay.h
//  TuyaSmartBLEKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <TuyaSmartBLEKit/TuyaSmartBLEKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBLEWifiActivator (PlugPlay)

/// Activates the Zigbee sub-device through the Bluetooth LE channel.
/// The result is returned by TuyaSmartBLEWifiActivatorDelegate.
///
/// @param advModel     The device advertisement model.
/// @param homeId       The ID of the current home.
/// @param device       The gateway device.
/// @param timeout      The timeout value.
- (void)activatorZigbeeSubDeviceWithBleChannel:(TYBLEAdvModel *)advModel
                                        homeId:(long long)homeId
                                 gatewayDevice:(TuyaSmartDevice *)device
                                       timeout:(NSTimeInterval)timeout;

/// Enables the Zigbee sub-device to switch to Zigbee pairing.
///
/// @param advModel     Device advertisement model.
/// @param homeId       The ID of the current home.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)switchZigbeeSubDeviceToZigbeeActivator:(TYBLEAdvModel *)advModel
                                        homeId:(long long)homeId
                                       success:(TYSuccessHandler)success
                                       failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
