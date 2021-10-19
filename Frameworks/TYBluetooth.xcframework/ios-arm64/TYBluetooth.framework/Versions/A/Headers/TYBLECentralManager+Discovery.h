//
//  TYBLECentralManager+Discovery.h
//  Pods-TYBluetooth_Example
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import "TYBLECentralManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYBLECentralManager (Discovery)

/**
 The discovered devices.
 */
@property (nonatomic, strong, readonly) NSArray<TYBLEPeripheral *> *discoveredDevices;

@property (nonatomic, assign) BOOL shouldAutoDiscoveryWhenCenteralPoweredOn;

/**
 Adds a discovery delegate.

 @param delegate The discovery delegate.
 */
- (void)addDiscoveryDelegate:(id<TYBLECentralManagerDiscoveryDelegate>)delegate;

/**
 Removes a discovery delegate.

 @param delegate The discovery delegate.
 */
- (void)removeDiscoveryDelegate:(id<TYBLECentralManagerDiscoveryDelegate>)delegate;

/**
 *  Discovers all Bluetooth devices.
 *
 *  @param timeout The discovery timed out.
 */
- (void)scanForPeripheralsWithServices:(nullable NSArray<CBUUID *> *)serviceUUIDs options:(nullable NSDictionary<NSString *, id> *)options timeout:(NSTimeInterval)timeout;

/**
 *  Discovers all Bluetooth devices.
 *
 *  @param timeout The discovery timed out.
 */
- (void)scanForPeripherals:(NSTimeInterval)timeout;

- (NSArray<CBPeripheral *> *)retrievePeripheralsWithIdentifiers:(NSArray<NSUUID *> *)identifiers;
- (NSArray<CBPeripheral *> *)retrieveConnectedPeripheralsWithServices:(NSArray<CBUUID *> *)serviceUUIDs;

/**
 *  Stops discovery.
 */
- (void)stopScan;

/**
 Clears the discovery cache.
 */
- (void)cleanScanedCache;

@end

NS_ASSUME_NONNULL_END
