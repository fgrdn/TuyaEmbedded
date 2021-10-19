//
//  TYBLEAgentHub.h
//  Pods
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

CB_EXTERN NSString * _Nonnull const TY_BLE_AGENT_SIGEL_BLE;
CB_EXTERN NSString * _Nonnull const TY_BLE_AGENT_BLE_MESH;
CB_EXTERN NSString * _Nonnull const TY_BLE_AGENT_SIG_MESH;
CB_EXTERN NSString * _Nonnull const TY_BLE_AGENT_BLE_BEACON;

NS_ASSUME_NONNULL_BEGIN

@class TYBLEAgent;
@interface TYBLEAgentHub : NSObject

+ (TYBLEAgent *)getAgentWithAgentKey:(NSString *)AgentKey;

+ (NSArray *)getServiceUUIDsWithAgentKey:(NSString *)AgentKey;

@end

NS_ASSUME_NONNULL_END
