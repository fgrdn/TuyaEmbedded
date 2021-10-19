//
// TuyaSmartSchemaModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartSchemaModel
#define TuyaSmart_TuyaSmartSchemaModel

#import <Foundation/Foundation.h>
#import "TuyaSmartSchemaPropertyModel.h"

/// The device schema.
@interface TuyaSmartSchemaModel : NSObject

/// The DP ID.
@property (nonatomic, strong) NSString     *dpId;

/// The DP code.
@property (nonatomic, strong) NSString     *code;

/// The name of the DP.
@property (nonatomic, strong) NSString     *name;

/// Reads and writes attributes of the DP. rw: send and report | ro: only report | wr: only send.
@property (nonatomic, strong) NSString     *mode;

/// The type of DP. obj: numeric, character, Boolean, enumeration, and fault | raw: the pass-through type.
@property (nonatomic, strong) NSString     *type;

/// The icon name of the DP.
@property (nonatomic, strong) NSString     *iconname;

/// The DP property.
@property (nonatomic, strong) TuyaSmartSchemaPropertyModel *property;

/// The extra content.
@property (nonatomic, strong, nullable) NSString *extContent;

@end

#endif
