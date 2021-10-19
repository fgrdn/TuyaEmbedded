//
// TuyaSmartShareMemberModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

typedef NS_ENUM(NSInteger, TYShareValidationType) {
    /// Share Forever
    TYShareValidationTypeForever = 0,
    /// Sharing works over a period of time
    TYShareValidationTypePeriod,
};

@interface TuyaSmartShareMemberModel : NSObject

/// The relationship ID.
@property (nonatomic, assign) NSInteger memberId;

/// The nickname.
@property (nonatomic, strong) NSString  *nickName;

/// The username that is the phone number or email address.
@property (nonatomic, strong) NSString  *userName;

/// The URL of the avatar.
@property (nonatomic, strong) NSString *iconUrl;

/// Share Validity.
@property (nonatomic, assign) TYShareValidationType shareMode;

/// End time of sharing.
@property (nonatomic, assign)  long endTime;

@end
