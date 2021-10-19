//
// TuyaSmartCommunicationMode.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The communication type.
typedef NS_ENUM(NSUInteger, TYCommunicationType) {
    TYCommunicationTypeLAN      = 0, // LAN
    TYCommunicationTypeMQTT     = 1, // MQTT
    TYCommunicationTypeHTTP     = 2, // Http
    TYCommunicationTypeBLE      = 3, // Single Point Bluetooth
    TYCommunicationTypeSIGMesh  = 4, // Sig Mesh
    TYCommunicationTypeBLEMesh  = 5, // Tuya Private Mesh
    TYCommunicationTypeBLEBeacon  = 6, // Beacon
};

/// The communication mode.
@interface TuyaSmartCommunicationMode : NSObject

/// The communication protocol version.
@property (nonatomic, assign) double pv;

/// The communication protocol type.
@property (nonatomic, assign) TYCommunicationType type;

@end

/// The device communication.
@interface TuyaSmartCommunication : NSObject

/// The communication sequence.
@property (nonatomic, strong) NSArray<TuyaSmartCommunicationMode *> *communicationModes;

/// The communication nodes.
@property (nonatomic, strong) NSString *communicationNode;

@end

NS_ASSUME_NONNULL_END
