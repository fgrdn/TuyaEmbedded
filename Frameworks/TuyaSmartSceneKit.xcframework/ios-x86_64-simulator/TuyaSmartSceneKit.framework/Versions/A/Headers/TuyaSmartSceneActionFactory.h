//
//  TuyaSmartSceneActionFactory.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartSceneKit/TuyaSmartSceneKit.h>

/// The two types of automation state. Provides enable and disable types.
typedef enum : NSInteger {
    /// The enable type.
    kAutoSwitchTypeEnable,
    /// The disable type.
    kAutoSwitchTypeDisable
}AutoSwitchType;

NS_ASSUME_NONNULL_BEGIN

/// @brief A factory design mode for create TuyaSmartSceneActionModel.
///
/// @note In order to facilitate the handling of multiple languages, this class does not handle the actionDisplay and actionDisplayNew fields of the TuyaSmartSceneActionModel. These two properties are spliced by the developer themselves when they are created. When saving, the server will generate them according to the executiveProperty and the language environment of the interface. The property saved by the developer will not be used.
@interface TuyaSmartSceneActionFactory : NSObject

/// Create a device action with all param.
///
/// @param devId The device id.
/// @param devName The device name.
/// @param executerProperty Action to execute, format:{dpId: <dpId's value>} eg: {"1":true}.
/// @param extraProperty The optional parameters, extraProperty of action.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createDeviceDpActionWithDevId:(NSString *)devId devName:(NSString *)devName executerProperty:(NSDictionary *)executerProperty extraProperty:(NSDictionary *)extraProperty;

/// Create a group action with group's params.
///
/// @param groupId The group id.
/// @param groupName The group name.
/// @param executerProperty Action to execute, format:{dpId: <dpId's value>} eg: {"1":true}.
/// @param extraProperty The  optional parameters, extraProperty of action.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createGroupDpActionWithGroupId:(NSString *)groupId groupName:(NSString *)groupName executerProperty:(NSDictionary *)executerProperty extraProperty:(NSDictionary *)extraProperty;

/// Create an action to trigger a scene.
///
/// @param sceneId The sceneId id.
/// @param sceneName The sceneName name.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createTriggerSceneActionWithSceneId:(NSString *)sceneId sceneName:(NSString *)sceneName;

/// Create an action to enable/disable an automation.
///
/// @param sceneId The sceneId id.
/// @param sceneName The sceneName name.
/// @param type AutoSwitchType.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createSwitchAutoActionWithSceneId:(NSString *)sceneId sceneName:(NSString *)sceneName type:(AutoSwitchType)type;

/// Create a delay action.
///
/// @param hours hours,range 0-5.
/// @param minutes minutes,range 0-59.
/// @param seconds seconds,range 0-59.
/// 
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createDelayActionWithHours:(NSString *)hours minutes:(NSString *)minutes seconds:(NSString *)seconds;

/// Create a push notification action.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createSendNotificationAction;

/// Create a call notification action(internal use, not open).
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createCallAction;

/// Create a send sms action(internal use, not open).
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createSmsAction;

@end

NS_ASSUME_NONNULL_END

