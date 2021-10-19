//
//  TuyaSmartSceneModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

#import "TuyaSmartSceneActionModel.h"
#import "TuyaSmartSceneConditionModel.h"
#import "TuyaSmartScenePreConditionModel.h"


/// The two types of condition match. Provides any and all types.
typedef enum : NSUInteger {
    /// The condition match any type, it means any one condition in the scene is be matched, it will be executed.
    TuyaSmartConditionMatchAny = 1,
    /// The condition match all type, it means all conditions in the scene is be matched, it will be executed.
    TuyaSmartConditionMatchAll
} TuyaSmartConditionMatchType;

/// The three types of recommend scene. Provides none, scene and automation types.
typedef enum : NSUInteger {
    /// The none recommend type, indicates it is neither tap-to-run nor automation scene.
    TuyaSmartSceneRecommendTypeNone,
    /// The tap-to-run recommend scene type.
    TuyaSmartSceneRecommendTypeScene,
    /// The automation recommend scene type.
    TuyaSmartSceneRecommendTypeAutomation
} TuyaSmartSceneRecommendType;

/// The three types of collection scene. Provides none, scene and automation types.
typedef enum : NSUInteger {
    /// The none collection type, indicates it is neither tap-to-run nor automation scene.
    TuyaSmartSceneCollectionTypeNone,
    /// The tap-to-run collection scene type.
    TuyaSmartSceneCollectionTypeScene,
    /// The automation collection scene type.
    TuyaSmartSceneCollectionTypeAutomation
} TuyaSmartSceneCollectionType;

/// The two types of device list on the panel when creating scene.
typedef NS_ENUM(NSInteger, TuyaSmartScenePanelType) {
    /// The non all device panel type, indicates you can only add zigbee device in the scene action.
    TuyaSmartScenePanelTypeNonAllDevevice = 0,
    /// The all device panel type, indicates you can add zigbee device and wifi device in the scene action.
    TuyaSmartScenePanelTypeAllDevices
};

/// @brief TuyaSmartSceneModel provides more data attributes for developers to implement business logic of the scene.
@interface TuyaSmartSceneModel : NSObject<NSCoding>

/// The scene id, it's unique. But only custom scene has this property.
@property (nonatomic, strong) NSString *sceneId;

/// The scene code, only default scene has this property.
@property (nonatomic, strong) NSString *code;

/// The scene name, it describes what the scene is used to.
@property (nonatomic, strong) NSString *name;

/// Whether the scene enabled, this status is used to automation scene and default enabled in tap-to-run scene.
@property (nonatomic, assign) BOOL enabled;

/// Whether show scene in first page, the status only can be switched when editing scene.
@property (nonatomic, assign) BOOL stickyOnTop;

/// The pre condition object model list is used to set the valid time period for automation scene. More information about TuyaSmartScenePreConditionModel, you can see TuyaSmartScenePreConditionModel class.
@property (nonatomic, strong) NSArray<TuyaSmartScenePreConditionModel *> *preConditions;

/// The condition model list,
@property (nonatomic, strong) NSArray<TuyaSmartSceneConditionModel *> *conditions;

/// The action model list,
@property (nonatomic, strong) NSArray<TuyaSmartSceneActionModel *> *actions;

/// The device list,
@property (nonatomic, strong) NSArray *devList;

/// The scene background icon URL
@property (nonatomic, copy) NSString *coverIcon;

/// The scene background color hex string.
@property (nonatomic, copy) NSString *displayColor;

/// The scene background URL, when created a new scene, use the URL provided by Tuya.
@property (nonatomic, strong) NSString *background;

/// The condition match type, For detail you can see TuyaSmartConditionMatchType enumeration value introduction.
@property (nonatomic, assign) TuyaSmartConditionMatchType matchType;

/// Whether this scene is bound to a panel. This attribute only supports standard zigbee devices.
@property (nonatomic, assign) BOOL boundForPanel;

/// Whether this scene is bound by a panel with new firmware. The new panel indicates that the scene supports zigbee devices and wifi devices.
@property (nonatomic, assign) BOOL boundForWiFiPanel;

/// Whether the automation scene supports to execute in LAN, If YES indicates the automation scene can be executed when zigbee gateway is offline.
@property (nonatomic, assign) BOOL localLinkage;

/// Whether the tap-to-run scene supports to execute in LAN, If YES indicates you can directly notify the zigbee gateway to execute the scene through TCP or MQTT messages.
@property (nonatomic, assign) BOOL newLocalScene;

/// The bound panel type, For detail you can see TuyaSmartScenePanelType enumeration value introduction.
@property (nonatomic, assign) TuyaSmartScenePanelType panelType;

/// The recommend scene type, For detail you can see TuyaSmartSceneRecommendType enumeration value introduction.
@property (nonatomic, assign) TuyaSmartSceneRecommendType recommendType;

/// The collection scene type, For detail you can see TuyaSmartSceneCollectionType enumeration value introduction.
@property (nonatomic, assign) TuyaSmartSceneCollectionType collectionType;

/// The recommend scene description.
@property (nonatomic, copy) NSString *recomDescription;

/// The recommended coefficient value of recommended scene, the range value is 0-100.
@property (nonatomic, assign) CGFloat recomCoefficient;

/// The timestamp when the automation scene will be automatically closed, The zero means it has not been set.
@property (nonatomic, assign) long long  disableTime;

#pragma mark - Business field

/// Whether the scene has already obtained details.
@property (nonatomic, assign) BOOL cached;

/// The arrow icon URL.
@property (nonatomic, copy) NSString *arrowIconUrl;

/// The hot value of recommended scene
@property (nonatomic, copy) NSString *hotCount;
#pragma mark - Deprecated

/// The scene subtitle.
@property (nonatomic, strong) NSString *subTitle __deprecated;

/// The scene edit icon URL.
@property (nonatomic, strong) NSString *editIcon __deprecated;

/// The scene display icon URL.
@property (nonatomic, strong) NSString *displayIcon __deprecated;

@end
