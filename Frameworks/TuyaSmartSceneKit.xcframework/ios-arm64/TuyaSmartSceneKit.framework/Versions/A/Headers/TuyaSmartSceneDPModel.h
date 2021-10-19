//
//  TuyaSmartSceneDPModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <CoreLocation/CoreLocation.h>

/// The seven types of datapoint display style.
typedef enum : NSUInteger {
    /// The normal style, indicates display numeric UI.
    SceneDisplayNormal = 1,
    /// The first percent style, indicates the content show numeric UI and the unit show percent. The datapoint minimum value is 0.
    SceneDisplayPercent = (1 << 1),
    /// The second percent style, indicates the content show numeric UI and the unit show percent. The datapoint minimum value is 1.
    SceneDisplayNewPercent = (1 << 2),
    /// The first countdown style, indicates the content only shows hours and minutes.
    SceneDisplayCountDown = (1 << 3),
    /// The brightness value style, indicates the content shows a color slider and you can select value as the brightness value. For example, brightness value is 500.
    SceneDisplayBrightness = (1 << 4),
    /// The warm cold value style, indicates the content shows a color slider and you can select value as the warm cold value. For example, warm cold value is 500.
    SceneDisplayTemp = (1 << 5),
    /// The second countdown style, indicates The content shows hours, minutes and seconds.
    SceneDisplayCountDown1 = (1<< 6)
} SceneDisplayType;

@class TuyaSmartSchemaModel;

/// @brief TuyaSmartSceneDPModel provides more attributes for developers to implement the datapoint of device.
///
/// @note It is mainly used to describe the detail information of the device's data-points.
@interface TuyaSmartSceneDPModel : NSObject

/// The dp id, it maybe condition id or device id.
@property (nonatomic, assign) NSInteger dpId;

/// The product ID.This property represent the product's id this data-points belongs to. Only device's datapoints has this value.
@property (nonatomic, strong) NSString *entityId;

/// The entity name, it maybe condition name or datapoint name of device.
@property (nonatomic, strong) NSString *entityName;

/// The entity type, device as condition it will be NSInteger 1, 3 for meteorological condition, 6 for timer condition, 7 for human body detector condition, 10 for  geofencing condition.
@property (nonatomic, assign) NSInteger entityType;

/// The icon URL of condition.
@property (nonatomic, strong) NSString *iconUrl;

/// Condition's or device's data point' value range, like "value:{"unit":"","min":10,"max":1000,"scale":0,"step":1,"type":"value"}"
@property (nonatomic, strong) NSArray *valueRangeJson;

/// Properties of device, like {"id":1,"desc":"","name":"Switch","property":{"type":"bool"},"attr":3,"code":"switch_on","type":"obj","mode":"rw"}
@property (nonatomic, strong) NSString *actDetail;

/// Description of data point and selected value.
@property (nonatomic, strong) TuyaSmartSchemaModel *dpModel;

/// The operation description, operators like "["=="]".
@property (nonatomic, strong) NSString *operators;

/// The condition name, code, properties. For details check the dpModel property.
@property (nonatomic, strong) NSDictionary *property;

/// The entity sub id of condition or datapoint of device, condition's subId like @"humidity", device data point's subId like "1".
@property (nonatomic, strong) NSString *entitySubId;

/// Multi control information, value is nil if not belong to any multi control group, format:[{"id":123,"groupName":"more control group 1"}]
@property (nonatomic, strong) NSArray *mcGroups;

/// Extra information about dp value's calculate type and other extra information, calType's range is ["sum","average","max","min","count","duration"].
@property (nonatomic, strong) NSDictionary *condCalExtraInfo;


#pragma mark - Logic properties blow can be ignored.
/*******Properties below are used to store user selected value, you can ignore.********/

/// The selected row, -1 means haven't selected, set by you.
@property (nonatomic, assign) NSInteger selectedRow;

/// The selected operator, -1 means haven't selected, set by you.
@property (nonatomic, assign) NSInteger selectedOperationRow;

/// The device Id，set by you.
@property (nonatomic, strong) NSString *devId;

/// The displayType of this datapoint‘s value.
@property (nonatomic, assign) SceneDisplayType displayType;

#pragma mark - Deprecated

/// Expression, eg:(("$humidity","==","comfort"), (“$dp1”，“==”，“1”), ...), set by you.
@property (nonatomic, strong) NSArray *expr __deprecated;

/// The city Id, set by you.
@property (nonatomic, strong) NSString *cityId __deprecated;

/// The city name, set by you.
@property (nonatomic, strong) NSString *cityName __deprecated;

/// The city's latitude, set by you.
@property (nonatomic, assign) CLLocationDegrees cityLatitude __deprecated;

/// The city's longitude, set by you.
@property (nonatomic, assign) CLLocationDegrees cityLongitude __deprecated;

/// The deprecated property.
@property (nonatomic, assign) NSInteger sceneDPId __deprecated;

/// The percent datapoint information.
@property (nonatomic, strong) NSDictionary *percentDp __deprecated;

@end
