//
//  TuyaSmartBLEManager+PlugPlay.h
//  TuyaSmartBLEKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import "TuyaSmartBLEManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBLEManager (PlugPlay)


/// Activates the Bluetooth mode for a dual-mode device.
///
/// @param advModel    The device advertisement model.
/// @param homeId      The ID of the current home.
/// @param token       The token.
/// @param success     Called when the task is finished. DeviceModel is returned.
/// @param failure     Called when the task is interrupted by an error.
- (void)activatorDualDeviceWithBleChannel:(TYBLEAdvModel *)advModel
                                   homeId:(long long)homeId
                                    token:(NSString *)token
                                  success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                                  failure:(TYFailureError)failure;

/// Activates the Wi-Fi channel of a dual-mode device for which the Bluetooth channel is activated.
///
/// @param devId       The device ID.
/// @param ssid        The name of the router.
/// @param password    The password for the device.
/// @param timeout     The timeout value.
/// @param success     Called when the task is finished. DeviceModel is returned.
/// @param failure     Called when the task is interrupted by an error.
- (void)activeDualDeviceWifiChannel:(NSString *)devId
                               ssid:(NSString *)ssid
                           password:(NSString *)password
                            timeout:(NSTimeInterval)timeout
                            success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                            failure:(TYFailureError)failure;



@end

NS_ASSUME_NONNULL_END
