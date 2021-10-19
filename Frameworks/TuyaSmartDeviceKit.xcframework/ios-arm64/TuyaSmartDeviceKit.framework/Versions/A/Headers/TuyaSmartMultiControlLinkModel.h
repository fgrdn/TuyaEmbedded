//
// TuyaSmartMultiControlLinkModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMultiControlParentRuleModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControlGroupDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *multiControlId;///< The ID of the multi-control group.
@property (copy, nonatomic) NSString *devId;///< The ID of the attached device.
@property (copy, nonatomic) NSString *devName;///< The name of the attached device.
@property (copy, nonatomic) NSString *dpId;///< The DP ID of the associated attached device.
@property (copy, nonatomic) NSString *dpName;///< The DP name of the associated attached device.
@property (assign, nonatomic) BOOL enabled;///< Specifies whether the associated attached devices support the multi-control function.
@property (strong, nonatomic) NSArray<TuyaSmartMultiControlDatapointModel *> *datapoints;

@end


@interface TuyaSmartMultiControlGroupModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< The multi-control group ID.
@property (copy, nonatomic) NSString *groupName;///< The multi-control group name.
@property (strong, nonatomic) NSArray<TuyaSmartMultiControlGroupDetailModel *> *groupDetail;///< The multi-control group details.

@property (assign, nonatomic) BOOL enabled;
@property (assign, nonatomic) NSInteger groupType;///< The multi-control group type.
@property (copy, nonatomic) NSString *multiRuleId;
@property (copy, nonatomic) NSString *ownerId;///< The home ID.
@property (copy, nonatomic) NSString *uid;///< The user ID.

@end


@interface TuyaSmartMultiControlLinkModel : NSObject

@property (strong, nonatomic) TuyaSmartMultiControlGroupModel *multiGroup;
@property (strong, nonatomic) NSArray<TuyaSmartMultiControlParentRuleModel *> *parentRules;

@end

NS_ASSUME_NONNULL_END
