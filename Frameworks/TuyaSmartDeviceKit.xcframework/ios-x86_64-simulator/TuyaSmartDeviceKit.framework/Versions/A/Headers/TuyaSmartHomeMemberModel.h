//
// TuyaSmartHomeMemberModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeModelUtils.h"

@interface TuyaSmartHomeMemberModel : NSObject

// The member ID.
@property (nonatomic, assign) long long memberId;

// The avatars of members.
@property (nonatomic, strong) NSString *headPic;

// The names of members.
@property (nonatomic, strong) NSString *name;

// The role.
@property (nonatomic, assign) TYHomeRoleType role;

// The home ID.
@property (nonatomic, assign) long long homeId;

// The mobile phone number.
@property (nonatomic, strong) NSString *mobile;

// The username.
@property (nonatomic, strong) NSString *userName;

// The user ID.
@property (nonatomic, strong) NSString *uid;

// The state of the deal.
@property (nonatomic, assign) TYHomeStatus dealStatus;

#pragma mark - deprecated
// Specifies whether the member is an administrator.
@property (nonatomic, assign) BOOL isAdmin __deprecated_msg("The property will be deprecated and remove in a future version. Please use the role");

@end
