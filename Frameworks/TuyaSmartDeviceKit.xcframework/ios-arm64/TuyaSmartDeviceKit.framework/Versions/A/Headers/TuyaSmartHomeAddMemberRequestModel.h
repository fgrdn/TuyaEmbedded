//
// TuyaSmartHomeAddMemberRequestModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeAddMemberRequestModel : NSObject

/// The nicknames for invitees.
@property (nonatomic, copy) NSString *name;

/// The invited accounts.
@property (nonatomic, copy) NSString *account;

/// The invitee account for the specified country code.
@property (nonatomic, copy) NSString *countryCode;

/// The member role. Set the required role type.
@property (nonatomic, assign) TYHomeRoleType role;

/// The avatar for the invitee. If the value is set to nil, the invitee's personal avatar is used.
@property (nonatomic, strong) UIImage *headPic;

/// Specifies whether the invitee must accept the invitation. Valid values: `YES`: The invited account automatically accepts the home invitation without the invitee's confirmation. `NO`: The invitee's consent is required to join the home.
@property (nonatomic, assign) BOOL autoAccept;

@end

@interface TuyaSmartHomeInvitationCreateRequestModel : NSObject

/// The home ID.
@property (nonatomic, assign) long long homeID;

/// A Boolean value that specifies whether an invitation message is required.
@property (nonatomic, assign) BOOL needMsgContent;

@end

@interface TuyaSmartHomeInvitationReinviteRequestModel : NSObject

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationID;

/// A Boolean value that specifies whether an invitation message is required.
@property (nonatomic, assign) BOOL needMsgContent;

@end

@interface TuyaSmartHomeInvitationInfoRequestModel : NSObject

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationID;

/// The name in the invitation remarks.
@property (nonatomic, copy) NSString *name;

@end

@interface TuyaSmartHomeInvitationResultModel : NSObject

/// The invitation message.
@property (nonatomic, copy) NSString *invitationMsgContent;

/// The invitation code.
@property (nonatomic, copy) NSString *invitationCode;

@end


@interface TuyaSmartHomeInvitationRecordModel : NSObject;

/// The validity period of the invitation code. Unit: hours.
@property (nonatomic, assign) NSInteger validTime;

/// The invitation ID.
@property (nonatomic, strong) NSNumber *invitationID;

/// The invitation code.
@property (nonatomic, copy) NSString *invitationCode;

/// The name in the invitation remarks.
@property (nonatomic, copy) NSString *name;

@end
NS_ASSUME_NONNULL_END

