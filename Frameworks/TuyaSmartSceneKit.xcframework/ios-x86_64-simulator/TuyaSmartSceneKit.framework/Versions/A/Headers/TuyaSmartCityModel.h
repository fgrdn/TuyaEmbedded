//
//  TuyaSmartCityModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <CoreLocation/CoreLocation.h>

/// @brief TuyaSmartCityModel is used to save a city base info.
@interface TuyaSmartCityModel : NSObject

/// The city id
@property (nonatomic, assign) long long cityId;

/// The city name
@property (nonatomic, strong) NSString *city;

/// The city info , achieved from map, for temporary storage.
@property (nonatomic, copy) NSString *cityNameFromMap;

/// The city latitude, set by mapView centerCoordinate.
@property (nonatomic, assign) CLLocationDegrees tempLatitude;

/// The city longitude, set by mapView centerCoordinate.
@property (nonatomic, assign) CLLocationDegrees tempLongitude;

/// Area or city, like a county.
@property (nonatomic, copy) NSString *area;

/// Chinese pinyin for city.
@property (nonatomic, copy) NSString *pinyin;

/// The province or state name.
@property (nonatomic, copy) NSString *province;

@end
