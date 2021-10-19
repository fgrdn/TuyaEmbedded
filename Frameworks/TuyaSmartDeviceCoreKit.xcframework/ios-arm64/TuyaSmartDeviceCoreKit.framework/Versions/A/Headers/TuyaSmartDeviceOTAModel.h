//
// TuyaSmartDeviceOTAModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The device update status.
typedef enum : NSUInteger {
    /// Not updating.
    TuyaSmartDeviceOTAModelUpgradeStatusNone = 0,
    /// Updating.
    TuyaSmartDeviceOTAModelUpgradeStatusUpgrading = 2
} TuyaSmartDeviceOTAModelUpgradeStatus;

typedef NS_ENUM(NSInteger, TuyaSmartDeviceCapability){
    TuyaSmartDeviceCapabilityOTAControlDP = 0,
    TuyaSmartDeviceCapabilityUseLEOnline,
    TuyaSmartDeviceCapabilityBeacon,
    TuyaSmartDeviceCapabilityLinkEncrypt,
};

@interface TuyaSmartDeviceOTAModel : NSObject

/// The device ID.
@property (nonatomic, strong) NSString     *devId;

/// The status of device updates.
@property (nonatomic) TuyaSmartDeviceOTAModelUpgradeStatus otaUpgradeStatus;

// Adds a beacon category for the Bluetooth LE beacon device.
@property (nonatomic, strong) NSString     *beaconCategory;

@property (nonatomic, strong) NSString *beaconKey;

@property (nonatomic, strong) NSString *bluetoothCapability;

- (BOOL)deviceCapabilitySupport:(TuyaSmartDeviceCapability)capability;

@end

NS_ASSUME_NONNULL_END
