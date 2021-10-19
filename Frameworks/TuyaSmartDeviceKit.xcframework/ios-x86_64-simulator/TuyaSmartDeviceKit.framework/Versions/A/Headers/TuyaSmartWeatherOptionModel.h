//
// TuyaSmartWeatherOptionModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    TuyaSmartWeatherOptionPressureUnit_unknown = 0,
    TuyaSmartWeatherOptionPressureUnit_hPa = 1,
    TuyaSmartWeatherOptionPressureUnit_inHg = 2,
    TuyaSmartWeatherOptionPressureUnit_mmHg = 3,
    TuyaSmartWeatherOptionPressureUnit_mb = 4,
} TuyaSmartWeatherOptionPressureUnit;

typedef enum : NSUInteger {
    TuyaSmartWeatherOptionWindSpeedUnit_unknown = 0,
    TuyaSmartWeatherOptionWindSpeedUnit_mph = 1,
    TuyaSmartWeatherOptionWindSpeedUnit_m_s = 2,// m/s
    TuyaSmartWeatherOptionWindSpeedUnit_kph = 3,
    TuyaSmartWeatherOptionWindSpeedUnit_km_h = 4// km/h
} TuyaSmartWeatherOptionWindSpeedUnit;

typedef enum : NSUInteger {
    TuyaSmartWeatherOptionTemperatureUnit_unknown = 0,
    TuyaSmartWeatherOptionTemperatureUnit_Centigrade = 1,// °C
    TuyaSmartWeatherOptionTemperatureUnit_Fahrenheit = 2,// °F
} TuyaSmartWeatherOptionTemperatureUnit;

NS_ASSUME_NONNULL_BEGIN

/// Returns the requested home weather entries.
@interface TuyaSmartWeatherOptionModel : NSObject

/// The barometric unit.
@property (nonatomic, assign) TuyaSmartWeatherOptionPressureUnit pressureUnit;

/// The wind speed unit.
@property (nonatomic, assign) TuyaSmartWeatherOptionWindSpeedUnit windspeedUnit;

/// The temperature unit.
@property (nonatomic, assign) TuyaSmartWeatherOptionTemperatureUnit temperatureUnit;

/// The number of requests for weather details. If you do not set the value, all requests are returned.
@property (nonatomic, assign) NSInteger limit;

@end

NS_ASSUME_NONNULL_END
