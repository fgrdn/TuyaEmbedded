//
//  TYBLECentralManager+Connection.h
//  Pods-TYBluetooth_Example
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import "TYBLECentralManager.h"
#import "TYBLECentralManagerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class TYBLEPeripheral;
@interface TYBLECentralManager (Connection)

/**
 Adds a connection delegate.

 @param delegate The delegate.
 */
- (void)addConnectionDelegate:(id<TYBLECentralManagerSessionDelegate>)delegate;

/**
 Removes a connection delegate.

 @param delegate The delegate.
 */
- (void)removeConnectionDelegate:(id<TYBLECentralManagerSessionDelegate>)delegate;

/**
 *  Connects to a peripheral.
 *
 *  @param peripheral The peripheral to be connected.
 *  @param timeout The connection timed out.
 */
- (void)connectPeripheral:(TYBLEPeripheral *)peripheral timeout:(NSTimeInterval)timeout;

/**
 Connects to a peripheral.

 @param peripheral The peripheral to be connected.
 @param options The connection parameters.
 @param timeout The connection timed out.
 */
- (void)connectPeripheral:(TYBLEPeripheral *)peripheral options:(nullable NSDictionary<NSString *, id> *)options timeout:(NSTimeInterval)timeout;

/**
 Disconnects from a peripheral.
 
 @param peripheral The connected peripheral.
 @param timeout The disconnection timed out.
 */
- (void)disconnectPeripheral:(TYBLEPeripheral *)peripheral timeout:(NSTimeInterval)timeout;

/**
 *  Disconnects from all peripherals.
 */
- (void)disconnectAllPeripherals;

@end

NS_ASSUME_NONNULL_END
