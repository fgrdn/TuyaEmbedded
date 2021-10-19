//
// TuyaSmartSchemaPropertyModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartSchemaPropertyModel
#define TuyaSmart_TuyaSmartSchemaPropertyModel

#import <Foundation/Foundation.h>

/// The device schema property.
@interface TuyaSmartSchemaPropertyModel : NSObject

/// The type of object. enum: enumerated | bool: Boolean | string: character | value: numeric | bitmap: fault.
@property (nonatomic, strong) NSString   *type;

/// The unit, such as °C.
@property (nonatomic, strong) NSString   *unit;

/// The minimum value of the numeric type.
@property (nonatomic, assign) double     min;

/// The maximum value of the value type.
@property (nonatomic, assign) double     max;

/// The numerical step.
@property (nonatomic, assign) double     step;

/// The exponent of 10 in the numeric type, multiplied by the corresponding transmission value, is equal to the actual value and is used to avoid fractional transmission.
@property (nonatomic, assign) NSInteger  scale;

/// The maximum number of bits of the fault type.
@property (nonatomic, assign) NSInteger  maxlen;

/// Detailed description of the fault type.
@property (nonatomic, strong) NSArray    *label;

/// The scope of the enumeration type.
@property (nonatomic, strong) NSArray    *range;

/// The specified value.
@property (nonatomic, assign) NSInteger selectedValue;

@end

#endif
