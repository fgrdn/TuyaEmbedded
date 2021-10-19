//
// TuyaSmartDeviceModelUtils.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartDeviceModelUtils_h
#define TuyaSmartDeviceModelUtils_h

/// The device update status.
typedef enum : NSUInteger {
    TuyaSmartDeviceUpgradeStatusDefault = 0,    // Default: No update is required.
    TuyaSmartDeviceUpgradeStatusReady,          // Ready: The hardware is ready.
    TuyaSmartDeviceUpgradeStatusUpgrading,      // Upgrading: The update is in progress.
    TuyaSmartDeviceUpgradeStatusSuccess,        // Success: The update is completed.
    TuyaSmartDeviceUpgradeStatusFailure,        // Failure: The update has an exception.
    TuyaSmartDeviceUpgradeStatusWaitingExectue, // NB-IoT devices wait to execute NB-IoT tasks. Device tasks have been sent but not yet executed.
    TuyaSmartDeviceUpgradeStatusDownloaded,     // NB-IoT devices have downloaded NB-IoT firmware.
    TuyaSmartDeviceUpgradeStatusTimeout         // Timeout: The update timed out.
} TuyaSmartDeviceUpgradeStatus;

#endif /* TuyaSmartDeviceModelUtils_h */
