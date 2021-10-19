//
//  TYBLEService.h
//  TuyaSmartPublic
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class TYBLECharacteristic;

typedef void(^TYBLECentralServiceDiscoverCharacteristcsCallback)(NSArray *characteristics, NSError *error);

@interface TYBLEService : NSObject

/**
 *  The CBService object.
 */
@property (strong, nonatomic, readonly) CBService *cbService;

/**
 * The UUID string.
 */
@property (strong, nonatomic, readonly) NSString *UUIDString;

/**
 *  A list of characteristics.
 */
@property (strong, nonatomic) NSArray *characteristics;

/**
 *  Indicates whether the device information is returned.
 */
@property (assign, nonatomic) BOOL isDeviceInfo;


/**
 *  Indicates whether the timer information is returned.
 */
@property (nonatomic, assign) BOOL isTimerInfo;



/**
 *  Indicates whether the battery information is returned.
 */
@property (assign, nonatomic) BOOL isBatteryInfo;
    
    
/**
 *  Creates a TYBLESerice object.
 *
 *  @param aService The CBservice object.
 *
 *  @return The TYBLESerice object.
 */
- (instancetype)initWithService:(CBService *)aService;

/**
 *  Returns a list of characteristics.
 *
 *  @param aCallback The callback.
 */
- (void)discoverCharacteristicsWithCompletion:(TYBLECentralServiceDiscoverCharacteristcsCallback)aCallback;



/**
 *  Returns a list of characteristics.
 *
 *  The synchronization method.
 *
 *  @return The TYBLECharacteristic list.
 */
- (NSArray <TYBLECharacteristic *> *)discoverCharacteristics;
    
/**
 *  Returns the characteristics with specific UUIDs.
 *
 *  @param aCallback The callback.
 */
- (void)discoverCharacteristicsWithUUIDs:(NSArray *)uuids
                              completion:(TYBLECentralServiceDiscoverCharacteristcsCallback)aCallback;

/**
 *  Cancels the characteristic operation.
 */
- (void)cancelCharacteristicOperations;
/**
 *  Stores the returned characteristics.
 *
 *  @param aCharacteristics A list of CBCharacteristics objects.
 *  @param aError           An error occurs while processing the request.
 */
- (void)handleDiscoveredCharacteristics:(NSArray *)aCharacteristics error:(NSError *)aError;
/**
 *  Returns the characteristic with a specific UUID.
 *
 *  @param uuid The UUID to be returned.
 *
 *  @return The TYBLECharacteristic object.
 */
- (TYBLECharacteristic*)retrieveCharacteristicByUUID:(NSString *)uuid;

@end
