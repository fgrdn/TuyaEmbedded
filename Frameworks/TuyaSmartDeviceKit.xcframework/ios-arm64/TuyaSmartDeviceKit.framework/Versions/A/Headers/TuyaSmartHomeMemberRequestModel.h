//
// TuyaSmartHomeMemberRequestModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeMemberRequestModel : NSObject

/// The member ID. It is a required field.
@property (nonatomic, assign) long long memberId;

/// The member's name. If the value is set to nil, the existing name is not updated.
@property (nonatomic, strong) NSString *name;

/// The member's role. Set the required role type. If you do not want to update the role type, keep the current role type or set it to "TYHomeRoleType_Unknown".
@property (nonatomic, assign) TYHomeRoleType role;

/// The members' avatars. If the value is set to nil, the existing avatars are not updated.
@property (nonatomic, strong) UIImage *headPic;

@end

NS_ASSUME_NONNULL_END
