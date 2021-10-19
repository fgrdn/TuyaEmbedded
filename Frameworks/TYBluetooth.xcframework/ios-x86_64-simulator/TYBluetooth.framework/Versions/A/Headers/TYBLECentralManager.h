//
//  TYBLECentralManager.h
//  TuyaSmartPublic
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface TYBLECentralManager : NSObject <CBCentralManagerDelegate>

/**
 *  Specifies whether to enable Bluetooth.
 */
@property (nonatomic, assign, readonly) BOOL isPoweredOn;

- (instancetype)initWithAgentKey:(NSString *)agentKey;

/**
 *  The CBCentralManager object.
 */
@property (nonatomic, strong, readonly) CBCentralManager *cbManager;

- (void)tyble_performSelector:(SEL)aSelector withObject:(id)anArgument afterDelay:(NSTimeInterval)delay;

- (void)tyble_cancelPreviousPerformRequestsWithTarget:(id)aTarget selector:(SEL)aSelector object:(nullable id)anArgument;

@end
