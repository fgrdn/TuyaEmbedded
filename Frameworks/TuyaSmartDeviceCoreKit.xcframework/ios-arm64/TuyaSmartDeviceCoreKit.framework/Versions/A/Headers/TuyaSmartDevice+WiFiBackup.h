//
// TuyaSmartDevice+WiFiBackup.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#if TARGET_OS_IOS

#import "TuyaSmartDevice.h"

/// @brief The Smart Device Wi-Fi Alternative Switching function allows you to get an alternative Wi-Fi network.
///
/// When the current Wi-Fi network is not available, the device automatically switches to the alternative Wi-Fi network to ensure that the device can work as expected.
///
API_AVAILABLE(ios(10.0))
@interface TuyaSmartDevice (WiFiBackup)

/// Returns the current Wi-Fi information.
/// @param success Called when the task is finished. TYSuccessDict is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getCurrentWifiInfoWithSuccess:(TYSuccessDict)success failure:(TYFailureError)failure;


/// Returns a list of alternative Wi-Fi networks.
/// @param success Called when the task is finished. TYSuccessDict is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getBackupWifiListWithSuccess:(TYSuccessDict)success failure:(TYFailureError)failure;


/// Sets up a list of alternative networks.
/// @param list A list of alternative Wi-Fi networks.
/// @param success Called when the task is finished. A list of TuyaSmartBackupWifiModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)setBackupWifiList:(NSArray<TuyaSmartBackupWifiModel *> *)list success:(TYSuccessDict)success failure:(TYFailureError)failure;


/// Switches to a saved alternative Wi-Fi network.
/// @param hash The hash for the service set identifier (SSID) and password. The value is returned from the device.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)switchToBackupWifiWithHash:(NSString *)hash success:(TYSuccessDict)success failure:(TYFailureError)failure;


/// Switches to a new alternative Wi-Fi network.
/// @param ssid The SSID.
/// @param password The SSID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)switchToBackupWifiWithSSID:(NSString *)ssid password:(NSString *)password success:(TYSuccessDict)success failure:(TYFailureError)failure;


@end

#endif
