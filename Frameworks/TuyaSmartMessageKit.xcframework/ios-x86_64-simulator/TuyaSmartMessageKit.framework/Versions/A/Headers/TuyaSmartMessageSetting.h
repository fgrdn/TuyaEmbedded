//
// TuyaSmartMessageSetting.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import "TuyaSmartMessageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN


/// @brief TuyaSmartMessageSetting provides methods for device DND.
///
@interface TuyaSmartMessageSetting : NSObject

/// Set device Do Not Disturb status.
/// @param flags switch status.
/// @param success When successfully set device Do Not Disturb status, this block will be called.
/// @param failure When error occurred, return TYFailureError.
- (void)setDeviceDNDSettingStatus:(BOOL)flags success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Get device Do Not Disturb status.
/// @param success When successfully get device Do Not Disturb status, this block will be called.
/// @param failure When error occurred, return TYFailureError.
- (void)getDeviceDNDSettingstatusSuccess:(TYSuccessBOOL)success failure:(TYFailureError)failure;

/// Get Do Not Disturb list.
/// @param success When successfully get Do Not Disturb list, this block will be called.
/// @param failure When error occurred, return TYFailureError.
- (void)getDNDListSuccess:(TYSuccessList)success failure:(TYFailureError)failure;

/// Get device list.
/// @param success When successfully get device list, this block will be called.
/// @param failure When error occurred, return TYFailureError.
- (void)getDNDDeviceListSuccess:(TYSuccessList)success failure:(TYFailureError)failure;

/// Add device Do Not Disturb time.
/// @param requestModel DND request model.
/// @param success When successfully add Do Not Disturb time, this block will be called.
/// @param failure When error occurred, return TYFailureError.
- (void)addDNDWithDNDRequestModel:(TuyaSmartMessageSettingDNDRequestModel *)requestModel success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Modify device  Do Not Disturb time.
/// @param timerID  time ID.
/// @param requestModel DND request model.
/// @param success When successfully modify device Do Not Disturb time, this block will be called.
/// @param failure When error occurred, return TYFailureError.
- (void)modifyDNDWithTimerID:(long)timerID DNDRequestModel:(TuyaSmartMessageSettingDNDRequestModel *)requestModel success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Remove Do Not Disturb time.
/// @param timerID time ID.
/// @param success When successfully remove Do Not Disturb time, this block will be called.
/// @param failure When error occurred, return TYFailureError.
- (void)removeDNDWithTimerID:(long)timerID success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
