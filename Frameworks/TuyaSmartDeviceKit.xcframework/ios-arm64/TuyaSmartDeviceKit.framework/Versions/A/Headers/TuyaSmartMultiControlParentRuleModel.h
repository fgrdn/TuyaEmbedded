//
// TuyaSmartMultiControlParentRuleModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControlParentRuleDpModel : NSObject

@property (copy, nonatomic) NSString *dpId;///< The DP ID.
@property (copy, nonatomic) NSString *dpName;///< The DP name.

@end

@interface TuyaSmartMultiControlParentRuleModel : NSObject

@property (copy, nonatomic) NSString *ruleId;///< The automation ID.
@property (copy, nonatomic) NSString *name;///< The automation name.

@property (strong, nonatomic) NSArray<TuyaSmartMultiControlParentRuleDpModel *> *dpList;

@end

NS_ASSUME_NONNULL_END
