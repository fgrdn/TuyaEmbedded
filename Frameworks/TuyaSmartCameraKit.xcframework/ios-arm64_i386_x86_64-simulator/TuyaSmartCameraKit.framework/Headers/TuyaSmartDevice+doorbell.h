//
//  TuyaSmartDevice+doorbell.h
//  TuyaSmartCameraKit
//
//  Created by 傅浪 on 2021/4/2.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

typedef NSString * TuyaSmartDoorBellType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXTERN TuyaSmartDoorBellType const TuyaSmartDoorBell;
FOUNDATION_EXTERN TuyaSmartDoorBellType const TuyaSmartACDoorBell;
FOUNDATION_EXTERN TuyaSmartDoorBellType const TuyaSmartDoorLock;

@interface TuyaSmartDevice (doorbell)

- (void)answerDoorBellCallWithType:(TuyaSmartDoorBellType)type messageId:(NSString *)messageId;

- (void)hangupDoorBellCallWithType:(TuyaSmartDoorBellType)type messageId:(NSString *)messageId;

- (void)sendHeartbeatWithType:(TuyaSmartDoorBellType)type messageId:(NSString *)messageId;


@end
