//
// TuyaSmartWeatherSketchModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartWeatherSketchModel : NSObject

/// The weather conditions, such as sunny, cloudy, and rainy.
@property (nonatomic, strong) NSString *condition;

/// The default weather icon.
@property (nonatomic, strong) NSString *iconUrl;

/// The highlighted weather icon.
@property (nonatomic, strong) NSString *inIconUrl;

/// Compatible with the parameters of earlier versions and does not apply to the business layer.
@property (nonatomic, strong) NSString *city;

/// The weather conditions, such as sunny, cloudy, rainy, and other property values. For example, `Sunny` indicates sunny, and `Cloudy` indicates cloudy. This parameter does not apply to the business layer.
@property (nonatomic, strong) NSString *mark;

/// The temperature.
@property (nonatomic, strong) NSString *temp;

@end

NS_ASSUME_NONNULL_END
