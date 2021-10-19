//
//  TuyaSmartSceneActionModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

/// push message action
static NSString * const ACTION_EXECUTOR_APP_PUSH = @"appPushTrigger";
/// call action
static NSString * const ACTION_EXECUTOR_APP_CALL = @"mobileVoiceSend";
/// sms action
static NSString * const ACTION_EXECUTOR_SMS_SEND = @"smsSend";
/// device dp action
static NSString * const ACTION_EXECUTOR_DP_ISSUE = @"dpIssue";
/// device group dp action
static NSString * const ACTION_EXECUTOR_GROUP_DP_ISSUE = @"deviceGroupDpIssue";
/// ir device dp action
static NSString * const ACTION_EXECUTOR_IR_ISSUE = @"irIssue";
/// ir device dp action(2rd version)
static NSString * const ACTION_EXECUTOR_IR_ISSUE_VII = @"irIssueVii";
/// enable a automation
static NSString * const ACTION_EXECUTOR_RULE_ENABLE = @"ruleEnable";
/// diable a automation
static NSString * const ACTION_EXECUTOR_RULE_DISABLE = @"ruleDisable";
/// execute a scene
static NSString * const ACTION_EXECUTOR_RULE_TRIGGER = @"ruleTrigger";
/// delay action
static NSString * const ACTION_EXECUTOR_DELAY = @"delay";
/// toggle action
static NSString * const ACTION_EXECUTOR_TOGGLE = @"toggle";
/// step action
extern NSString * const ACTION_EXECUTOR_STEP;

/// The five types of action status. Provides loading, success, offline, timeout and delay types.
typedef NS_ENUM(NSInteger, TYSceneActionStatus)
{
    /// The loading action type.
    TYSceneActionStatusLoading = 0,
    /// The success action type.
    TYSceneActionStatusSuccess,
    /// The offline action type.
    TYSceneActionStatusOffline,
    /// The timeout action type.
    TYSceneActionStatusTimeout,
    /// The delay action type.
    TYSceneActionStatusDelay,
};


/// @brief Data model for Scene Base Action.
@interface TuyaSmartSceneActionModel : NSObject<NSCoding>

/// The action id.
@property (nonatomic, copy) NSString *actionId;

/// The entity id. If action is a device, entityId is devId, and groupId for group action, @"delay" for a delay action, sceneId of operated scene for scene action.
@property (nonatomic, copy) NSString *entityId;

/// The entity name, like "lamp", "lamp group".
@property (nonatomic, copy) NSString *entityName;

/// The scene id, can be used to save the scene's Id which this action belonged to.
@property (nonatomic, copy) NSString *scenarioId;

/// Describe what this action will do, like "Switch : Open".
@property (nonatomic, copy) NSString *actionDisplay;

/// Describe what this action will do with origin format like the below example, you can use it to create the description.
/// {
///    1: [
///        "Switch",
///        "Open"
///        ]
/// }
@property (nonatomic, strong) NSDictionary *actionDisplayNew;


/// The action type, can be the followed types:
/// "dpIssue" :execute a device action.
/// "deviceGroupDpIssue": execute a group action.
/// "irIssue": execute an infrared device, like an air conditioner which is controlled by a remote control.
/// "irIssueVii": execute an infrared device, like an air conditioner which is controlled by a remote control.ExecutorProperty is real infrared ray remotes control code.
/// "ruleTrigger": execute a scene.
/// "ruleEnable":  Enable an automation.
/// "ruleDisable": Disable an automation.
/// "delay": Delay for a while.
@property (nonatomic, copy) NSString *actionExecutor;


/// Execute property, like {"1":true, ...}, "1" is dpId, a data point's Id, value is the value you want this datapoint to set. Delay action should be like "executorProperty":{"seconds":"5","minutes":"0"}.
@property (nonatomic, strong) NSDictionary *executorProperty;

/// Local property of scene , save gId and gwId.
@property (nonatomic, strong) NSDictionary *extraProperty;

/// If this action is a device type action and this device has been removed from the current account, this flag is YES.
@property (nonatomic, assign) BOOL devDelMark;

/// If this action is a device type action, and this device has been removed from the current account, then provide this icon url to display the device icon.
@property (nonatomic, copy) NSString *deleteDevIcon;

/// Execute action status, you can use this property to store the execute status when executing.
@property (nonatomic, assign) TYSceneActionStatus status;

#pragma mark - Panel info

/// The panel id, this value will be assigned by cloud server when this action should be oprate by a React Native panel.
@property (nonatomic, copy) NSString *uiid;

#pragma mark - Recommend info

/// The recommend product id.
@property (nonatomic, copy) NSString *productId;

/// The recommend product icon.
@property (nonatomic, copy) NSString *productPic;

/// The recommend product local default icon.
@property (nonatomic, copy) NSString *defaultIconUrl;
@end
