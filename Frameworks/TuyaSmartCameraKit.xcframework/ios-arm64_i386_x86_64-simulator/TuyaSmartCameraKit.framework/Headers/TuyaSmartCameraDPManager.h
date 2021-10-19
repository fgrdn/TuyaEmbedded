//
//  TuyaSmartCameraDPManager.h
//  TuyaSmartCamera
//
//  Created by 傅浪 on 2019/3/8.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartCameraBase/TuyaSmartCameraBase.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

typedef NSString * TuyaSmartCameraDPKey NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * TuyaSmartCameraNightvision NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * TuyaSmartCameraPIR NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * TuyaSmartCameraMotion NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * TuyaSmartCameraDecibel NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * TuyaSmartCameraRecordMode NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * TuyaSmartCameraPTZDirection NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * TuyaSmartCameraPowerMode NS_EXTENSIBLE_STRING_ENUM;

/// [^en]basic setting dp[$en] [^zh]基础设置dp[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraBasicIndicatorDPName;      // [^en]indicator light switch, Value is BOOL[$en] [^zh]指示器高亮开关，BOOL值类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraBasicFlipDPName;           // [^en]video flip vertical switch, Value is BOOL[$en] [^zh]视频垂直翻转开关，BOOL值类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraBasicOSDDPName;            // [^en]time watermark switch, Value is BOOL[$en] [^zh]时间水印开关，BOOL值类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraBasicPrivateDPName;        // [^en]private mode switch, Value is BOOL[$en] [^zh]隐私模式开关，BOOL值类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraBasicNightvisionDPName;    // [^en]nightvision state, Value is TuyaSmartCameraNightvision[$en] [^zh]夜间模式状态，TuyaSmartCameraNightvision 枚举类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraBasicPIRDPName;            // [^en]PIR sensitivity[$en] [^zh]PIR 灵敏度[$zh]

/// [^en]motion detecting alarm[$en] [^zh]移动侦测告警[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraMotionDetectDPName;        // [^en]motion detecting switch, Value is BOOL[$en] [^zh]移动侦测开关，BOOL值类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraMotionSensitivityDPName;   // [^en]motion detecting sensitivity state, value is TuyaSmartCameraMotion[$en] [^zh]移动侦测灵敏度状态，TuyaSmartCameraMotion 枚举类型[$zh]

/// [^en]decibel detecting alarm[$en] [^zh]分贝侦测告警[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraDecibelDetectDPName;       // [^en]decibel detecting switch, value is BOOL[$en] [^zh]分贝侦测开关，BOOL值类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraDecibelSensitivityDPName;  // [^en]decibel detecting sensitivity, value is TuyaSmartCameraDecibel[$en] [^zh]分贝侦测灵敏度，TuyaSmartCameraDecibel 枚举类型[$zh]

/// [^en]SD card[$en] [^zh]SD 卡[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraSDCardStatusDPName;        // [^en]sd card status, value is TuyaSmartCameraSDCardStatus, just for read[$en] [^zh]SD 卡状态，TuyaSmartCameraSDCardStatus 枚举类型，只读[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraSDCardStorageDPName;       // [^en]sd card capacity state, Value is String, just for read[$en] [^zh]SD卡能力状态， String 类型，只读[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraSDCardFormatDPName;        // [^en]sd card format command, Value is YES, just for publish[$en] [^zh]SD卡格式化命令，值为YES，只供 publish[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraSDCardUnmountDPName;       // [^en]sd card unmount command, Value is YES, just for publish[$en] [^zh]SD卡卸载命令，值为YES，只供publish[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraSDCardFormatStateDPName;   // [^en]sd card format state, Value is long : 0 - 100. if negative，is error[$en] [^zh]SD卡格式化状态，值为 0 - 100， 如果是负数则出错[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraSDCardRecordDPName;        // [^en]sd card record switch, value is BOOL[$en] [^zh]SD卡记录开关，值为BOOL类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraSDCardMuteRecordDPName;        // [^en]sd card MuteRecord switch, value is BOOL[$en] [^zh]SD卡静音录制开关，值为BOOL类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraRecordModeDPName;          // [^en]sd card record mode, value is TuyaSmartCameraRecordMode[$en] [^zh]SD卡录制模式，值为TuyaSmartCameraRecordMode枚举类型[$zh]

/// ptz
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraPTZControlDPName;          // [^en]start ptz, value is TuyaSmartCameraPTZDirection, just for publish[$en] [^zh]开始ptz， 值为TuyaSmartCameraPTZDirection枚举类型，只供publish[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraPTZStopDPName;             // [^en]stop ptz, value is BOOL, just for publish[$en] [^zh]停止ptz，值为BOOL类型，只供 publish[$zh]

/// wireless
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraWirelessElectricityDPName; // [^en]device electricity, value is long 0 - 100, just for read[$en] [^zh]设备电量，值为 0 - 100， 只读[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraWirelessPowerModeDPName;   // [^en]power supply mode, value is TuyaSmartCameraPowerMode[$en] [^zh]供电模式，值为TuyaSmartCameraPowerMode枚举类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraWirelessLowpowerDPName;    // [^en]lowpower alarm threshold, value is long 0 - 100, just for publish. if the electricity is lower than this value, app will receive a push notification[$en] [^zh]低电量阈值，值为0-100，只供publish。 如果电量比这个值更低，app将会收到通知[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraWirelessBatteryLockDPName; // [^en]battery lock switch, value is BOOL[$en] [^zh]电量锁开关，值为BOOL类型[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraWirelessAwakeDPName;       // [^en]awake state, value is BOOL[$en] [^zh]唤醒状态，值为BOOL类型[$zh]

/// [^en]nightvision state values[$en] [^zh]夜间模式状态值[$zh]
IPC_EXTERN TuyaSmartCameraNightvision const TuyaSmartCameraNightvisionAuto;
IPC_EXTERN TuyaSmartCameraNightvision const TuyaSmartCameraNightvisionOff;
IPC_EXTERN TuyaSmartCameraNightvision const TuyaSmartCameraNightvisionOn;

/// [^en]PIR state values[$en] [^zh]PIR 状态值[$zh]
IPC_EXTERN TuyaSmartCameraPIR const TuyaSmartCameraPIRStateOff;
IPC_EXTERN TuyaSmartCameraPIR const TuyaSmartCameraPIRStateLow;
IPC_EXTERN TuyaSmartCameraPIR const TuyaSmartCameraPIRStateMedium;
IPC_EXTERN TuyaSmartCameraPIR const TuyaSmartCameraPIRStateHigh;
IPC_EXTERN TuyaSmartCameraPIR const TuyaSmartCameraPIRStateOn;

/// [^en]motion detecting sensitivity values[$en] [^zh]移动侦测灵敏度值[$zh]
IPC_EXTERN TuyaSmartCameraMotion const TuyaSmartCameraMotionLow;
IPC_EXTERN TuyaSmartCameraMotion const TuyaSmartCameraMotionMedium;
IPC_EXTERN TuyaSmartCameraMotion const TuyaSmartCameraMotionHigh;

/// [^en]decibel detecting sensitivity values[$en] [^zh]分贝检测灵敏度值[$zh]
IPC_EXTERN TuyaSmartCameraDecibel const TuyaSmartCameraDecibelLow;
IPC_EXTERN TuyaSmartCameraDecibel const TuyaSmartCameraDecibelHigh;

/// [^en]sd card record mode values[$en] [^zh]SD卡记录模式值[$zh]
IPC_EXTERN TuyaSmartCameraRecordMode const TuyaSmartCameraRecordModeEvent;
IPC_EXTERN TuyaSmartCameraRecordMode const TuyaSmartCameraRecordModeAlways;

/// [^en]ptz direction values[$en] [^zh]ptz方向控制值[$zh]
IPC_EXTERN TuyaSmartCameraPTZDirection const TuyaSmartCameraPTZDirectionUp;
IPC_EXTERN TuyaSmartCameraPTZDirection const TuyaSmartCameraPTZDirectionRight;
IPC_EXTERN TuyaSmartCameraPTZDirection const TuyaSmartCameraPTZDirectionDown;
IPC_EXTERN TuyaSmartCameraPTZDirection const TuyaSmartCameraPTZDirectionLeft;

/// [^en]Wireless device power mode values[$en] [^zh]无线设备电量模式值[$zh]
IPC_EXTERN TuyaSmartCameraPowerMode const TuyaSmartCameraPowerModeBattery;
IPC_EXTERN TuyaSmartCameraPowerMode const TuyaSmartCameraPowerModePlug;

/// [^en]Object outline[$en] [^zh]智慧画框[$zh]
IPC_EXTERN TuyaSmartCameraDPKey const TuyaSmartCameraOutlineDPName;

/// [^en]sd card state[$en] [^zh]SD卡状态[$zh]
typedef NS_ENUM(NSUInteger, TuyaSmartCameraSDCardStatus) {
    TuyaSmartCameraSDCardStatusNormal = 1,
    TuyaSmartCameraSDCardStatusException = 2,
    TuyaSmartCameraSDCardStatusMemoryLow = 3,
    TuyaSmartCameraSDCardStatusFormatting = 4,
    TuyaSmartCameraSDCardStatusNone = 5             // not detected sd card
};

@class TuyaSmartCameraDPManager;

@protocol TuyaSmartCameraDPObserver <NSObject>

@optional

/**
 [^en]
 device dps data did update
 [$en]

 [^zh]
 设备 dps 数据已经更新
 [$zh]

 @param manager dpManger
 @param dpsData @{dpName: dpValue}
 */
- (void)cameraDPDidUpdate:(TuyaSmartCameraDPManager *)manager dps:(NSDictionary *)dpsData;

@end

@interface TuyaSmartCameraDPManager : NSObject

@property (nonatomic, strong, readonly) NSString *deviceId;

@property (nonatomic, strong, readonly) NSArray *observers;

@property (nonatomic, strong, readonly) TuyaSmartDevice *device;

- (instancetype)initWithDevice:(TuyaSmartDevice *)device __deprecated_msg("Use initWithDeviceId: instead");

- (instancetype)initWithDeviceId:(NSString *)devId;

- (void)addObserver:(id<TuyaSmartCameraDPObserver>)observer;

- (void)removeObserver:(id<TuyaSmartCameraDPObserver>)observer;

/**
 [^en]
 does the device support this dp
 [$en]

 [^zh]
 当前设备是否支持此dp点
 [$zh]

 @param dpName dpName
 @return BOOL
*/
- (BOOL)isSupportDP:(TuyaSmartCameraDPKey)dpName;

/**
 [^en]
 get the value of dp, if support the dp, else return nil.
 [$en]

 [^zh]
 获取dp的值，如果支持则返回dp值，否则返回nil
 [$zh]

 @param dpName dpName
 @return dp value
 */
- (id)valueForDP:(TuyaSmartCameraDPKey)dpName;


/**
 [^en]
 will publish query command to device for the dp,
 [$en]

 [^zh]
 将会 publish 查询命令到该设备的dp点
 [$zh]

 @param dpName dpName
 @param success success callback
 @param failure failure callback
 */
- (void)valueForDP:(TuyaSmartCameraDPKey)dpName success:(TYSuccessID)success failure:(TYFailureError)failure;

/**
[^en]
set the value of dp, if support the dp, else return nil
[$en]

[^zh]
设置dp点的值，如果设备支持该dp点，否则返回nil
[$zh]

 @param value value
 @param dpName [^en]dpName[$en] [^zh]dpName[$zh]
 @param success success callback
 @param failure failure callback
*/
- (void)setValue:(id)value forDP:(TuyaSmartCameraDPKey)dpName success:(TYSuccessID)success failure:(TYFailureError)failure;

#pragma mark - Deprecated

- (BOOL)isSurpportDP:(TuyaSmartCameraDPKey)dpName __deprecated_msg("Use isSupportDP instead");

@end

