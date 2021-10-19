//
// TuyaSmartUser+LoginByQRCode.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartUser_LoginByQRCode_h
#define TuyaSmartUser_LoginByQRCode_h

#import "TuyaSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (LoginByQRCode)

#pragma mark - Scan code to authorize third-party app login

/// Authorizes third-party apps to support login with QR code.
/// @param codeInfo The QR code information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByQRcode:(NSDictionary *)codeInfo success:(nullable TYSuccessID)success failure:(nullable TYFailureError)failure;

/// Returns information about third-party apps.
/// @param codeInfo The QR code information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)userInfo:(NSDictionary *)codeInfo success:(nullable TYSuccessID)success failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartUser_LoginByQRCode_h */
