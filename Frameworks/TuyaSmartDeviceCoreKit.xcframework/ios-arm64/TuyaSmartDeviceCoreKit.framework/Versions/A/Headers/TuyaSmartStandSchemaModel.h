//
// TuyaSmartStatusSchemaModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The reported mapping policies.
@interface TuyaSmartStatusSchemaModel : NSObject

/// The mapping rules.
@property (nonatomic, strong) NSString     *strategyValue;

/// The policy designators. Currently, more than 10 designators are supported.
@property (nonatomic, strong) NSString     *strategyCode;

/// The reported DP ID corresponds to a DP code that is not a standard DP code.
@property (nonatomic, strong) NSString     *dpCode;

/// The standard DP value type.
@property (nonatomic, strong) NSString     *standardType;

/// The value range.
@property (nonatomic, strong) NSString     *valueRange;

/// The mapping relationship between DP codes and DP IDs.
@property (nonatomic, strong) NSDictionary *relationDpIdMaps;

@end

/// The distributed mapping strategy.
@interface TuyaSmartFunctionSchemaModel : NSObject

/// Currently, more than 10 kinds of policy codes are supported.
@property (nonatomic, strong) NSString     *strategyCode;

/// The mapping rules.
@property (nonatomic, strong) NSString     *strategyValue;

/// The standardized DP codes.
@property (nonatomic, strong) NSString     *standardCode;

/// The standard DP value type.
@property (nonatomic, strong) NSString     *standardType;

/// The value range.
@property (nonatomic, strong) NSString     *valueRange;

/// The mapping relationship between DP codes and DP IDs.
@property (nonatomic, strong) NSDictionary *relationDpIdMaps;

@end

/// The standard schema.
@interface TuyaSmartStandSchemaModel : NSObject

@property (nonatomic, assign) BOOL isProductCompatibled;

@property (nonatomic, strong) NSArray<TuyaSmartStatusSchemaModel *> *statusSchemaList;

@property (nonatomic, strong) NSArray<TuyaSmartFunctionSchemaModel *> *functionSchemaList;

@end

NS_ASSUME_NONNULL_END
