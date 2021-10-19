//
// TuyaSmartHomeModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeModelUtils.h"

@interface TuyaSmartHomeModel : NSObject

// The home ID.
@property (nonatomic, assign) long long homeId;

// The home name.
@property (nonatomic, strong) NSString *name;

// The home geographic location.
@property (nonatomic, strong) NSString *geoName;

// The latitude.
@property (nonatomic, assign) double latitude;

// The longitude.
@property (nonatomic, assign) double longitude;

// The home background pictures.
@property (nonatomic, strong) NSString *backgroundUrl;

// The order.
@property (nonatomic, assign) NSInteger displayOrder;

// The role type.
@property (nonatomic, assign) TYHomeRoleType role;

// The state of the deal.
@property (nonatomic, assign) TYHomeStatus dealStatus;

// The inviter's name.
@property (nonatomic, strong) NSString *nickName;

#pragma mark - deprecated
// Specifies whether the member is an administrator.
@property (nonatomic, assign) BOOL admin __deprecated_msg("This property is deprecated, Use role property");

@end

