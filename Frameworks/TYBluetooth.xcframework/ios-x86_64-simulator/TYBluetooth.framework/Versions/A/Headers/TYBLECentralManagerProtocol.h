//
//  TYBLECentralManagerProtocol.h
//  TYBluetooth
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#ifndef TYBLECentralManagerProtocol_h
#define TYBLECentralManagerProtocol_h

#import <CoreBluetooth/CoreBluetooth.h>

typedef NS_ENUM(NSInteger, TYBLECentralManagerState) {
//    TYBLECentralManagerStateUnknown = 0,
//    TYBLECentralManagerStateResetting,
//    TYBLECentralManagerStateUnsupported,
    TYBLECentralManagerStateUnauthorized = 3, // The Bluetooth permissions are not granted.
    TYBLECentralManagerStatePoweredOff, // The Bluetooth function is disabled.
    TYBLECentralManagerStatePoweredOn, // The Bluetooth function is enabled.
};

@class TYBLECentralManager;
@class TYBLEPeripheral;
@protocol TYBLECentralManagerDiscoveryDelegate <NSObject>

@property (nonatomic, copy, readonly) BOOL(^scanFilter)(NSDictionary *advertisementData, NSNumber *rssi);

- (void)centralManager:(TYBLECentralManager *)central didUpdateState:(BOOL)isPoweredOn;

- (void)centralManager:(TYBLECentralManager *)central didUpdateCentralState:(TYBLECentralManagerState)state;

- (void)centralManager:(TYBLECentralManager *)central didDiscoverPeripheral:(TYBLEPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData RSSI:(NSNumber *)RSSI;

@end

@protocol TYBLECentralManagerSessionDelegate <NSObject>

- (void)centralManager:(TYBLECentralManager *)central didConnectPeripheral:(TYBLEPeripheral *)peripheral;
- (void)centralManager:(TYBLECentralManager *)central didDisconnectPeripheral:(TYBLEPeripheral *)peripheral error:(NSError *)error;
- (void)centralManager:(TYBLECentralManager *)central didFailToConnectPeripheral:(TYBLEPeripheral *)peripheral error:(NSError *)error;

@end

#endif /* TYBLECentralManagerProtocol_h */
