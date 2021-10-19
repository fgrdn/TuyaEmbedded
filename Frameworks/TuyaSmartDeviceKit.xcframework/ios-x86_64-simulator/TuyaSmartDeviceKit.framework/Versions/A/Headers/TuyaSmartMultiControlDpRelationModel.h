//
// TuyaSmartMultiControlDpRelationModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMultiControlParentRuleModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMcGroupDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *dpId;///< The DP ID.
@property (copy, nonatomic) NSString *dpName;///< The DP name.
@property (copy, nonatomic) NSString *devId;///< The device ID.
@property (copy, nonatomic) NSString *devName;///< The device name.
@property (assign, nonatomic) BOOL enabled;///< The availability.
@property (copy, nonatomic) NSString *multiControlId;///< The multi-control group ID.

@end


@interface TuyaSmartMcGroupModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< The multi-control group ID.
@property (copy, nonatomic) NSString *groupName;///< The multi-control group name.
@property (strong, nonatomic) NSArray<TuyaSmartMcGroupDetailModel *> *groupDetail;///< The multi-control group association details.

@property (assign, nonatomic) BOOL enabled;
@property (assign, nonatomic) NSInteger groupType;///< The multi-control group type.
@property (copy, nonatomic) NSString *multiRuleId;
@property (copy, nonatomic) NSString *ownerId;///< The home ID.
@property (copy, nonatomic) NSString *uid;///< The user ID.

@end


@interface TuyaSmartMultiControlDpRelationModel : NSObject

@property (strong, nonatomic) NSArray<TuyaSmartMultiControlDatapointModel *> *datapoints;
@property (strong, nonatomic) NSArray<TuyaSmartMcGroupModel *> *mcGroups;
@property (strong, nonatomic) NSArray<TuyaSmartMultiControlParentRuleModel *> *parentRules;

@end

NS_ASSUME_NONNULL_END
