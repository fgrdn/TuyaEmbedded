//
//  TYBLEPeripheral.h
//  TuyaSmartPublic
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class TYBLEService;

typedef void(^TYBLECentralPeripheralDiscoverServicesCallback)(NSArray *services, NSError *error);
typedef void(^TYBLECentralPeripheralRSSIValueCallback)(NSNumber *RSSI, NSError *error);


@interface TYBLEPeripheral : NSObject <CBPeripheralDelegate>

/**
 *  The internal cbPeripheral object.
 */
@property (strong, nonatomic, readonly) CBPeripheral *cbPeripheral;
/**
 *  A list of service UUIDs.
 */
@property (strong, nonatomic, readonly) NSArray *services;
/**
 *  The UUID string of the peripheral.
 */
@property (weak, nonatomic, readonly) NSString *UUIDString;

/**
 * The signal strength of the peripheral.
 */
@property (assign, nonatomic) NSInteger RSSI;

/**
 * The advertisement data that was tracked from the peripheral.
 */
@property (strong, nonatomic) NSDictionary *advertisingData;

@property (nonatomic, assign) BOOL isConnectedNotOpenApp;

/**
 *  The connection flag.
 */
@property (nonatomic, assign) BOOL isConnected;
/**
 *  Specifies whether to restore the connection status of the device.
 */
@property (nonatomic, assign) BOOL isWillRestoreState;

/**
 *  Creates a TYBLEPeripheral object.
 *
 *  @param p The CBPeripheral object.
 *
 *  @return The TYBLEPeripheral object.
 */
- (instancetype)initWithCBPeripheral:(CBPeripheral *)p;

/**
 *  Discovers all supported services.
 *
 *  @param block The callback.
 */
- (void)discoverServicesWithCompletion:(TYBLECentralPeripheralDiscoverServicesCallback)block;

/**
 *  Discovers the service with a specific UUID.
 *
 *  @param serviceUUIDs The service UUID
 *  @param block        The callback.
 */
- (void)discoverServices:(NSArray *)serviceUUIDs
              completion:(TYBLECentralPeripheralDiscoverServicesCallback)block;

/**
 *  Reads the Received Signal Strength Indicator (RSSI) value.
 *
 *  @param aCallback The callback.
 */
- (void)readRSSIValueCompletion:(TYBLECentralPeripheralRSSIValueCallback)aCallback;
/**
 *  Discovers the service with a specific UUID.
 *
 *  @param uuid The UUID to be discovered.
 *
 *  @return The TYBLEService object.
 */
- (TYBLEService *)retrieveServiceByUUID:(NSString *)uuid;

@property (nonatomic, copy) void(^readyToSendWriteWithoutResponseBlock)(CBPeripheral *p);

@end


