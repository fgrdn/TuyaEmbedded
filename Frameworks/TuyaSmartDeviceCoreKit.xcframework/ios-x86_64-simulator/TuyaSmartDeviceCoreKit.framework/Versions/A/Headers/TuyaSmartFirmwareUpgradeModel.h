//
// TuyaFirmwareUpgradeInfo.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartFirmwareUpgradeModel
#define TuyaSmart_TuyaSmartFirmwareUpgradeModel

#import <Foundation/Foundation.h>

/// The device firmware update information.
@interface TuyaSmartFirmwareUpgradeModel : NSObject

/// The update copywriting.
@property (nonatomic, strong) NSString  *desc;

/// The device type copywriting.
@property (nonatomic, strong) NSString *typeDesc;

/// Valid values: `0`: no later version. `1`: a later version available. `2`: updating. `5`: waiting for the device to wake up.
@property (nonatomic, assign) NSInteger upgradeStatus;

/// The firmware version that is used in the later version.
@property (nonatomic, strong) NSString  *version;

/// The current firmware version in use.
@property (nonatomic, strong) NSString  *currentVersion;

/// The update timeout. Unit: seconds.
@property (nonatomic, assign) NSInteger timeout;

/// 0: app update notification. 2: app forced update. 3: update detection.
@property (nonatomic, assign) NSInteger upgradeType;

/// The device type.
@property (nonatomic, assign) NSInteger type;

// The device type. 0: normal device. 1: low-power non-keep-alive device.
@property (nonatomic, assign) NSInteger devType;

/// The download URL of the update firmware for Bluetooth devices.
@property (nonatomic, strong) NSString *url;

/// The firmware MD5 message-digest algorithm.
@property (nonatomic, strong) NSString *md5;

/// The size of the firmware package. Unit: bytes.
@property (nonatomic, strong) NSString *fileSize;

/// Firmware sign.
@property (nonatomic, strong) NSString *sign;

/// The last update time of the DP.
@property (nonatomic, assign) long long lastUpgradeTime;

/// The firmware release date.
@property (nonatomic, assign) long long firmwareDeployTime;

/// Indicates whether the update device is controllable. `1` : controllable. `0` : not controllable.
@property (nonatomic, assign) BOOL controlType;

/// The description of waiting for device wake-up. The low-power non-keep-alive device is in the state of "waiting for device wake-up" before an update.
@property (nonatomic, strong) NSString *waitingDesc;

/// The notification text in the firmware update.
@property (nonatomic, strong) NSString *upgradingDesc;

/// if the device has the ability to upgrade.can not upgrade like low power. It will be nil when device has not dp check.
@property (nonatomic, strong) NSNumber *canUpgrade;

/// the remind when device can not upgrade.Value can be nil.
@property (nonatomic, copy) NSString *remind;

/// The notification text in the device download firmware. Currently, only NB-IoT devices are supported.
@property (nonatomic, strong) NSString *downloadingDesc __deprecated_msg("This property is deprecated, Use upgradingDesc instead");

@end

#endif
