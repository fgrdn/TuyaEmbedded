//
//  TYBLECharacteristic.h
//  TuyaSmartPublic
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>



typedef void (^TYBLECentralCharacteristicReadCallback)  (NSData*data, NSError *error);
typedef void (^TYBLECentralCharacteristicNotifyCallback)(NSData* data, NSError *error);
typedef void (^TYBLECentralCharacteristicWriteCallback) (NSError *error);




@interface TYBLECharacteristic : NSObject

/**
 * The CBCharacteristic object.
 */
@property (strong, nonatomic, readonly) CBCharacteristic *cbCharacteristic;

/**
 * The UUID string.
 */
@property (weak, nonatomic, readonly) NSString *UUIDString;

/**
 *  The characteristic value.
 */
@property (nonatomic, assign) CBCharacteristicProperties properties;

@property (nonatomic, copy  ) TYBLECentralCharacteristicNotifyCallback notifyCallback;
@property (nonatomic, copy  ) TYBLECentralCharacteristicReadCallback readCallback;
@property (nonatomic, copy  ) TYBLECentralCharacteristicWriteCallback writeCallback;

/**
 *  Creates a TYBLECharacteristic object.
 *
 *  @param aCharacteristic The CBCharacteristic object.
 *
 *  @return The TYBLECharacteristic object.
 */
- (instancetype)initWithCharacteristic:(CBCharacteristic *)aCharacteristic;


/**
 *  Notifies the peripheral to push data to the central manager.
 *
 *  @param notifyValue The switch flag.
 *  @param aCallback   The callback.
 */
- (void)notifyValue:(BOOL)notifyValue
     Withcompletion:(TYBLECentralCharacteristicNotifyCallback)aCallback;

/**
 *  Writes to the peripheral.
 *
 *  @param data      The binary streams to be written.
 *  @param aCallback The callback.
 */
- (void)writeData:(NSData *)data
   Withcompletion:(TYBLECentralCharacteristicWriteCallback)aCallback;

/**
 *  Writes bytes to the peripheral.
 *
 *  @param aByte     The bytes to be written.
 *  @param aCallback The callback.
 */
- (void)writeByte:(int8_t)aByte
   Withcompletion:(TYBLECentralCharacteristicWriteCallback)aCallback;

/**
 *  Reads from the peripheral.
 *
 *  @param aCallback The callback.
 */
- (void)readValueWithBlock:(TYBLECentralCharacteristicReadCallback)aCallback;


@end

@interface TYBLECharacteristic(ToolMethods)

// ----- Used for input events -----/

- (void)handleSetNotified:(NSData*)data WithError:(NSError *)anError;

- (void)handleReadValue:(NSData *)aValue error:(NSError *)anError;

- (void)handleWrittenValueWithError:(NSError *)anError;

- (void)handleNotfiyStateUpdate:(NSError *)anError;

@end



