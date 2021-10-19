//
// TuyaSmartUser+Anonymous.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartUser_Anonymous_h
#define TuyaSmartUser_Anonymous_h

#import "TuyaSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (Anonymous)

/// Enables anonymous registration.
/// @param countryCode The country code.
/// @param userName The username, such as [UIDevice currentDevice].name.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)registerAnonymousWithCountryCode:(NSString *)countryCode
                                userName:(NSString *)userName
                                 success:(nullable TYSuccessHandler)success
                                 failure:(nullable TYFailureError)failure;

/// Deletes an anonymous account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteAnonymousAccountWithSuccess:(TYSuccessHandler)success
                                  failure:(TYFailureError)failure;

/// Binds a username.
/// @param countryCode The country code.
/// @param userName The mobile phone number or email address.
/// @param code The verification code.
/// @param password The password.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)usernameBindingWithCountryCode:(NSString *)countryCode
                              userName:(NSString *)userName
                                  code:(NSString *)code
                              password:(NSString *)password
                               success:(nullable TYSuccessHandler)success
                               failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartUser_Anonymous_h */
