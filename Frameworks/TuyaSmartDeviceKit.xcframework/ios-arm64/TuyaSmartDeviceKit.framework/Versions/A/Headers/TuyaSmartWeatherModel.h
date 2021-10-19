//
// TuyaSmartWeatherModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartWeatherModel : NSObject

/// The weather icon.
@property (nonatomic, copy) NSString *icon;

/// The weather parameter name.
@property (nonatomic, copy) NSString *name;

/// The parameter unit.
@property (nonatomic, copy) NSString *unit;

/// The parameter ID.
@property (nonatomic, assign) long long objId;

/// Specifies whether to display the weather and does not apply to the business layer.
@property (nonatomic, assign) BOOL show;

/// The weather parameter value.
@property (nonatomic, copy) NSString *value;

@property (nonatomic, copy) NSString *metaValue;
@property (nonatomic, copy) NSString *fieldName;
@property (nonatomic, copy) NSString *roomName;

@end

NS_ASSUME_NONNULL_END
