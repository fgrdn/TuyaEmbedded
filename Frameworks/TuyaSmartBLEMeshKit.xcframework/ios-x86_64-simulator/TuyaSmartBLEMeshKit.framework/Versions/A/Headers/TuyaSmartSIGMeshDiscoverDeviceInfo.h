//
// TuyaSmartSIGMeshDiscoverDeviceInfo.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TYBluetooth/TYBLEAgent.h>

/// The type of Bluetooth mesh node to be scanned.
typedef NS_ENUM(NSUInteger, SIGMeshNodeProvisionType) {
    
    /// An unknown device.
    SIGMeshNodeUnknow,
    
    /// A new device.
    SIGMeshNodeUnprovision,
    
    /// A provisioned device.
    SIGMeshNodeProvisioned,
    
    /// A device that can be connected and controlled through a proxy.
    SIGMeshNodeProxyed,
};

/// The activator type of the Bluetooth mesh node.
typedef enum : NSUInteger {
    /// Standard pairing.
    TYSIGMeshNodeActivatorTypeStandard = 0,
    
    /// Wi-Fi Easy Connect.
    TYSIGMeshNodeActivatorTypeQuick = 1 << 0,
} TYSIGMeshNodeActivatorType;

NS_ASSUME_NONNULL_BEGIN

#define kQuickVersion @"kQuickVersion"

/// @brief The Bluetooth LE mesh device model that is used to scan a Bluetooth peripheral.
@interface TuyaSmartSIGMeshDiscoverDeviceInfo : NSObject

/// The Bluetooth peripheral to be scanned.
@property (nonatomic, strong) TYBLEPeripheral *peripheral;

/// The type of node.
@property (nonatomic, assign) SIGMeshNodeProvisionType provisionType;

/// The type of activator.
@property (nonatomic, assign) TYSIGMeshNodeActivatorType activatorType;

/// The MAC address of the `Powered by Tuya` device node.
@property (nonatomic, copy) NSString *mac;

/// The product category code (PCC) value of the `Powered by Tuya` device node.
@property (nonatomic, copy) NSString *type;

/// The product ID for `Powered by Tuya` device node.
@property (nonatomic, copy) NSString *productId;

/// Applies to over-the-air (OTA) updates.
@property (nonatomic, copy) NSString *nodeId;

/// Indicates whether the pairing operation in Wi-Fi Easy Connect mode is successful. Valid values: `YES` and `NO`. This value is used as the extension information.
@property (nonatomic, strong) NSDictionary *extendInfo;

@end

NS_ASSUME_NONNULL_END
