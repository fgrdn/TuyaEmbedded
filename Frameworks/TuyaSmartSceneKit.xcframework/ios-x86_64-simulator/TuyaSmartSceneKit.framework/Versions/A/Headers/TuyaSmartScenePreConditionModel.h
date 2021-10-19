//
//  TuyaSmartScenePreConditionModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

/// @brief TuyaSmartScenePreConditionModel provides more attributes for developers to create pre-conditions for automation scene.
@interface TuyaSmartScenePreConditionModel : NSObject<NSCoding>

/// The scene id.
@property (nonatomic, copy) NSString *scenarioId;

/// The condition id in the scene.
@property (nonatomic, copy) NSString *conditionId;

/// The precondition type for automation scene.
@property (nonatomic, copy) NSString *condType;

/// The precondition expression information, it contains more fields. For detail:
///
/// timeInterval: it's enumeration string type, you can select custom/daytime/night/allDay. eg: "timeInterval": "allDay"
/// timeZoneId: it's string type, indicates the time zone id. eg: "timeZoneId": "Asia/Shanghai"
/// loops: it's string type, every bit representing from Sunday to Saturday, "1" means for valid. eg: "1111111".
/// start: it's string type, if type is timeCheck and timeInterval is custom, this property will be useful. eg: "start": "20:30".
/// end: it's string type, if type is timeCheck and timeInterval is custom, this property will be useful. eg: "end": "06:30".
/// cityId: it's string type, the city id. eg: "cityId": "793409534348627968".
/// cityName: it's string type, the city name. eg: "cityName": "hangzhou".
@property (nonatomic, strong) NSDictionary *expr;

@end

