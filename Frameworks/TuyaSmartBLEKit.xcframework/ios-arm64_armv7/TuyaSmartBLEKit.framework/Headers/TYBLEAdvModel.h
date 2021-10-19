//
// TYBLEAdvModel.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

/// The different types of Bluetooth LE devices.
typedef enum : NSUInteger {
    /// The unknown type of Bluetooth LE device.
    TYSmartBLETypeUnknow = 1,
    /// The type of Bluetooth LE device that supports an earlier protocol. The device does not support a security protocol.
    TYSmartBLETypeBLE,
    /// The type of Bluetooth LE device that supports an earlier protocol of a lower security level.
    TYSmartBLETypeBLEPlus,
    /// The type of Bluetooth LE device that supports an earlier protocol. The device does not support a security protocol.
    TYSmartBLETypeBLEWifi,
    /// The type of Bluetooth LE device that supports a later protocol of a higher security level.
    TYSmartBLETypeBLESecurity,
    /// The type of Bluetooth LE dual-mode device that supports a later protocol of a higher security level.
    TYSmartBLETypeBLEWifiSecurity,
    /// The type of Bluetooth LE dual-mode device that supports a later protocol of a higher security level and that supports the plug and play (PnP) function.
    TYSmartBLETypeBLEWifiPlugPlay,
    /// The type of Bluetooth LE and Zigbee dual-mode device that supports a later protocol of a higher security level.
    TYSmartBLETypeBLEZigbee,
    /// The type of Bluetooth LE and LTE Category 1 dual-mode device that supports a later protocol of a higher security level.
    TYSmartBLETypeBLELTESecurity,
    /// The beacon security.
    TYSmartBLETypeBLEBeacon,
} TYSmartBLEType;

/// @brief TYBLEAdvModel provides a model to get the Bluetooth LE device broadcast information.
///
/// All the device information is obtained from the Bluetooth device broadcast packet data.

/// The different types of Bluetooth LE devices. See the following parameter descriptions.
@interface TYBLEAdvModel : NSObject

/// The UUID of the Bluetooth LE device.
@property (nonatomic, strong) NSString           *uuid;
/// The product ID of the Bluetooth LE device.
@property (nonatomic, strong) NSString           *productId;
/// The MAC address of the Bluetooth LE device.
@property (nonatomic, strong) NSString           *mac;
/// The activation state of the Bluetooth LE device.
@property (nonatomic, assign) BOOL               isActive;
/// The type of Bluetooth LE device.
@property (nonatomic, assign) TYSmartBLEType     bleType;
/// Indicates whether the Bluetooth LE device supports connections through the router on a 5 GHz band.
/// @note `TYSmartBLETypeBLEWifi` or `TYSmartBLETypeBLEWifiSecurity` is only available for `bleType`.
@property (nonatomic, assign) BOOL               isSupport5G;
/// Indicates whether the Bluetooth LE device supports the product key.
@property (nonatomic, assign) BOOL               isProuductKey;
/// The protocol version of the Bluetooth LE device.
@property (nonatomic, assign) int                bleProtocolV;


@end
