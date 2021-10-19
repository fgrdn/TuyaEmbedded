//
// TuyaSmartDevice+OfflineReminder.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartDevice.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief Tuya Smart device offline alerts: You can specify whether to support the offline alert function, set the status of the offline alert switch, and set the offline alert rules.
///
/// When offline alerts are enabled for the device, the device sends an offline notification to the specified user when the device goes offline. You can subscribe to the message push function to enable this feature.
///
@interface TuyaSmartDevice (OfflineReminder)

/// Checks whether the device supports offline alerts.
///
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getOfflineReminderSupportStatusWithSuccess:(nullable TYSuccessBOOL)success failure:(nullable TYFailureError)failure;


/// Returns the device offline notification status.
///
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getOfflineReminderStatusWithSuccess:(nullable TYSuccessBOOL)success failure:(nullable TYFailureError)failure;


/// Sets the device offline notification.
///
/// @param status  Sends a notification when the device goes offline. 
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setOfflineReminderStatus:(BOOL)status success:(nullable TYSuccessBOOL)success failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
