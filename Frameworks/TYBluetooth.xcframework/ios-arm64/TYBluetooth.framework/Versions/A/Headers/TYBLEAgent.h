//
//  TYBLEAgent.h
//  TuyaSmartPublic
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class TYBLECentralManager;
@class TYBLEPeripheral;

typedef void(^TYBLEAgentCentralNotifyCallback)(NSData *data, NSError *error);
typedef void(^TYBLEAgentCentralReadCallback)(NSData *data, NSError *error);
typedef void(^TYBLEAgentCentralWriteCallback)(NSError *error);
typedef void(^TYBLEAgentCentralDiscoverCallback)(TYBLEPeripheral *peripheral, NSError *error);
typedef void(^TYBLEAgentCentralConnectionCallback)(TYBLEPeripheral *peripheral, NSError *error) ;

typedef NS_ENUM(int, TYBLEAgentRole)
{
    kTYBLEAgentDiscovery    = 0x01, // Discovers devices.
    kTYBLEAgentSession      = 0x10, // Communicates with devices.
    kTYBLEAgentBoth         = 0x11, // Discovers and communicates with devices.
};


@protocol TYBLEAgent <NSObject>

@optional

- (void)onCentralDidDisconnecteFromPeripheral:(TYBLEPeripheral *)peripheral;
- (void)onCentralDidDisconnectFromPeripheral:(TYBLEPeripheral *)peripheral error:(NSError *)error;
- (void)onCentralDidUpdateState:(BOOL)isPoweredOn;
- (void)onBLECentralDidUpdateState:(TYBLECentralManagerState)state;

@end


@interface TYBLEAgent : NSObject

@property (nonatomic, assign, readonly) TYBLEAgentRole role;

@property (nonatomic, copy, readonly) BOOL(^scanFilter)(NSDictionary *advertisementData, NSNumber *rssi);

/**
 *  Specifies whether to enable Bluetooth.
 */
@property (nonatomic, assign, readonly) BOOL isPoweredOn;

/**
 Adds a delegate.
 
 @param delegate The delegate.
 */
- (void)addDelegate:(id<TYBLEAgent>)delegate;

/**
 Removes a delegate.
 
 @param delegate The delegate.
 */
- (void)removeDelegate:(id<TYBLEAgent>)delegate;


//- (instancetype)initWithType:(TYBLEAgentRole)role;

////////////////////////////////////////////////////////////////////////////////////
#pragma mark - central  methods

/**
 Discovers Bluetooth devices.

 @param services The UUIDs of services.
 @param options The discovery parameters. 
 @param scanFilter The filtering criteria for discovery.
 @param aCallback The callback of discovered devices that meet the filtering criteria.
 */
- (void)discoverServiceUUID:(NSArray<NSString *> *)services
                    options:(NSDictionary<NSString *,id> *)options
                 scanFilter:(BOOL(^)(NSDictionary *advertisementData, NSNumber *rssi))scanFilter
                 completion:(TYBLEAgentCentralDiscoverCallback)aCallback;


/**
 Discovers Bluetooth devices.

 @param scanFilter The filtering criteria for discovery.
 @param aCallback The callback of discovered devices that meet the filtering criteria.
 */
- (void)discoverWithScanFilter:(BOOL(^)(NSDictionary *advertisementData, NSNumber *rssi))scanFilter
                    completion:(TYBLEAgentCentralDiscoverCallback)aCallback;


/**
 *  Stops discovery.
 */
- (void)stopDiscovering;

/**
 *  Connects to a discovered Bluetooth device.
 *
 *  @param peripheral      The Bluetooth device to be connected.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param aCallback       The callback.
 */
- (void)connectPeripheral:(TYBLEPeripheral *)peripheral
              CharactUUID:(NSString *)aCharacteristic
              serviceUUID:(NSString *)aService
               completion:(TYBLEAgentCentralConnectionCallback)aCallback;

/**
 *  Connects to a discovered Bluetooth device.
 *
 *  @param peripheral      The Bluetooth device to be connected.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param timeout         The connection timed out.
 *  @param aCallback       The callback.
 */
- (void)connectPeripheral:(TYBLEPeripheral *)peripheral
              CharactUUID:(NSString *)aCharacteristic
              serviceUUID:(NSString *)aService
                  timeout:(NSTimeInterval)timeout
               completion:(TYBLEAgentCentralConnectionCallback)aCallback;

/**
 *  Disconnects from a Bluetooth device.
 *
 *  @param peripheral The connected Bluetooth device.
 */
- (void)disconnectPeripheral:(TYBLEPeripheral *)peripheral;

/**
 Disconnects from a Bluetooth device.

 @param peripheral The connected Bluetooth device.
 @param timeout The disconnection timed out.
 */
- (void)disconnectPeripheral:(TYBLEPeripheral *)peripheral timeout:(NSTimeInterval)timeout;

/**
 Disconnects from a Bluetooth device.

 @param peripheral The connected Bluetooth device.
 @param aCallback The callback.
 */
- (void)disconnectPeripheral:(TYBLEPeripheral *)peripheral
                  completion:(TYBLEAgentCentralConnectionCallback)aCallback
                     timeout:(NSTimeInterval)timeout;

/**
 *  Writes to a Bluetooth device.
 *
 *  @param aData           The binary data to be written.
 *  @param aPeripheral     The Bluetooth device to which data is written.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param aCallback       The callback.
 */
- (void)writeData:(NSData *)aData
     toPeripheral:(TYBLEPeripheral *)aPeripheral
      charactUUID:(NSString *)aCharacteristic
      serviceUUID:(NSString *)aService
       completion:(TYBLEAgentCentralWriteCallback)aCallback;

/**
 *  Reads from a Bluetooth device.
 *
 *  @param aPeripheral     The Bluetooth device from which data is read.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param aCallback       The callback.
 */
- (void)readDataFromPeriphreral:(TYBLEPeripheral *)aPeripheral
                    CharactUUID:(NSString *)aCharacteristic
                    serviceUUID:(NSString *)aService
                     completion:(TYBLEAgentCentralReadCallback)aCallback;

/**
 *  Receives data that is pushed by the Bluetooth device.
 *
 *  @param b               The switch that enables or disables data transfers.
 *  @param aPeripheral     The connected Bluetooth device.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param aCallback       The callback.
 */
- (void)notifyData:(BOOL)b
     FromPeriphral:(TYBLEPeripheral *)aPeripheral
       CharactUUID:(NSString *)aCharacteristic
       serviceUUID:(NSString *)aService
        completion:(TYBLEAgentCentralNotifyCallback)aCallback;


@end
