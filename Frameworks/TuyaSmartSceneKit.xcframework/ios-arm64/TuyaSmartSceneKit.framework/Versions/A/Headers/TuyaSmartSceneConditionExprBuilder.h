//
//  TuyaSmartSceneConditionExprBuilder.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartSceneExprModel.h"

/// The two types of expr data model. Provides whether and device types.
typedef enum : NSInteger {
    /// The whether expr model type
    kExprTypeWhether,
    /// The device expr model type
    kExprTypeDevice
}ExprType;

/// The Three types of expr data model. Provides not determine, rise and set types.
typedef enum : NSInteger {
    /// The sun not determine type
    kSunTypeNotDetermin,
    /// The sun rise
    kSunTypeRise,
    /// The sun set type
    kSunTypeSet
}SunType;

NS_ASSUME_NONNULL_BEGIN

/// @brief Create TuyaSmartSceneExprModel by difference type values.
@interface TuyaSmartSceneConditionExprBuilder : NSObject

/// Create a exprModel with bool value and condition type.
///
/// @param type Whether type or device's dpId.
/// @param isTrue BOOL value
/// @param exprType To distinguish the entity type.
/// 
/// @return A TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createBoolExprWithType:(NSString *)type isTrue:(BOOL)isTrue exprType:(ExprType)exprType;

/// Create a exprModel with enum string value and condition type.
///
/// @param type Whether type or device's dpId.
/// @param chooseValue enum string value, get it in TuyaSmartSceneDPModel.dpModel.property.range
/// @param exprType To distinguish the entity type.
///
/// @return A TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createEnumExprWithType:(NSString *)type chooseValue:(NSString *)chooseValue exprType:(ExprType)exprType;

/// Create exprModel like "temp <= 40".
///
/// @param type Whether type or device's dpId.
/// @param operateString @">=",@"<=",@"=="
/// @param value selected value
/// @param exprType To distinguish the entity type.
///
/// @return A TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createValueExprWithType:(NSString *)type operater:(NSString *)operateString chooseValue:(NSInteger )value exprType:(ExprType)exprType;

/// Create exprModel like "rawType".
///
/// @param type Whether type or device's dpId.
/// @param exprType To distinguish the entity type.
///
/// @return A TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createRawExprWithType:(NSString *)type exprType:(ExprType)exprType;

/// Create timer condition.
///
/// @param timeZoneId timeZoneId like @"Asia/Shanghai".
/// @param loops eg: @"0111110", each character represent from Sunday to Monday. @"0000000" represent only once.
/// @param date eg: @"20190501".
/// @param time eg: @"20:40".
///
/// @return A TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createTimerExprWithTimeZoneId:(NSString *)timeZoneId loops:(NSString *)loops date:(NSString *)date time:(NSString *)time;

/// Create a timer condition's expression related to sunrise or sunset times, For example, "x minutes before sunrise". "at sunrise" is still handled as a normal weather condition.
///
/// @param city City that needs to be set.
/// @param type Identify sunrise or sunset.
/// @param minutes From -300 minutes to 300 minutes.
///
/// @return A TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createSunsetriseTimerExprWithCity:(TuyaSmartCityModel *)city type:(SunType)type deltaMinutes:(NSInteger)minutes;

@end

NS_ASSUME_NONNULL_END

