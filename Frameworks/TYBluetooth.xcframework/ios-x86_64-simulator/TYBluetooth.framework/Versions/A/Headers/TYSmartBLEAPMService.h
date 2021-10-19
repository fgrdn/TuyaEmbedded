//
//  TYSmartBLEAPMService.h
//  Bolts
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import "TYSmartBLEAPMMessageModel.h"
#import "TYSmartBLEAPMEnum.h"

// The reconnection event tracking.
#define TY_LOG_EVENT_BLE_RECONNECTION                   @"af66d2469918c8d55dc6346598fd7d4f"  // The reconnection event tracking ID.

#define TY_RECONNECT_LOG_TYPE_BLE_SUCCESS               @"ble_log_connect_success"  // The initial connection is successful.
#define TY_RECONNECT_LOG_TYPE_BLE_RETRY_SUCCESS         @"ble_log_reconnect_success"  // The reconnection is successful.
#define TY_RECONNECT_LOG_TYPE_BLE_FAILURE               @"ble_log_reconnect_failure"  // The reconnection failed.

@interface TYSmartBLEAPMService : NSObject

+ (instancetype)sharedInstance;

- (void)putBLEAPMInDevId:(NSString *)devId type:(TYSmartBLEAPMType)type des:(NSString *)des dps:(NSDictionary *)dps extInfo:(NSDictionary *)extInfo;
 
- (void)putBLEAPMWithMessageModel:(TYSmartBLEAPMMessageModel *)messageModel;

- (void)logReconnectEvent:(NSString *)type reconnectCount:(NSInteger)reconnectCount;

@end
