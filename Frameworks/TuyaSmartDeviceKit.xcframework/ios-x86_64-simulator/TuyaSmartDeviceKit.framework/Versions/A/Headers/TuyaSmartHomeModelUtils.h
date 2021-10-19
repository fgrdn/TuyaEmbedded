//
// TuyaSmartHomeModelUtils.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartHomeModelUtils_h
#define TuyaSmartHomeModelUtils_h

typedef NS_ENUM(NSInteger, TYHomeRoleType) {
    TYHomeRoleType_Unknown = -999,  /**< The invalid role. */
    TYHomeRoleType_Custom  = -1,  /**< The customized role. */
    TYHomeRoleType_Member  = 0,   /**< The general home member. */
    TYHomeRoleType_Admin,         /**< The home administrator who is not authorized to add or delete other administrators. */
    TYHomeRoleType_Owner,         /**< The home super administrator and the home owner. */
};

typedef NS_ENUM(NSUInteger, TYHomeStatus) {
    TYHomeStatusPending = 1,      /**< Invitees have not decided whether to join the specified home. */
    TYHomeStatusAccept,           /**< Invitees have agreed to join the specified home. */
    TYHomeStatusReject            /**< Invitees have declined to join the specified home. */
};

#endif /* TuyaSmartHomeModelUtils_h */
