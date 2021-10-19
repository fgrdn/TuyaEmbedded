//
// TuyaSmartMultiControlModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControlDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *devId;///< The ID of the attached device.
@property (copy, nonatomic) NSString *dpId;///< The DP ID of the associated attached device.
@property (assign, nonatomic) BOOL enable;///< Specifies whether the associated attached devices support the multi-control function.

@end


@interface TuyaSmartMultiControlModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< The ID of the multi-control group.
@property (copy, nonatomic) NSString *groupName;///< The name of the multi-control group.
@property (strong, nonatomic) NSArray<TuyaSmartMultiControlDetailModel *> *groupDetail;

@property (assign, nonatomic, readonly) NSInteger groupType;///< The type of the multi-control group. Default value: 1.
@property (copy, nonatomic, readonly) NSString *ownerId;///< The home ID.
@property (copy, nonatomic, readonly) NSString *uid;///< The user ID.

@end

NS_ASSUME_NONNULL_END
