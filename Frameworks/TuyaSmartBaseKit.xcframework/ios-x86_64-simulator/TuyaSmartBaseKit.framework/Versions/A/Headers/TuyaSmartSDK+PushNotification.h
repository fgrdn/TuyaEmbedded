//
//  TuyaSmartSDK+PushNotification.h
//  TuyaSmartBaseKit
//
//  Created by huangkai on 2021/6/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartSDK (PushNotification)

/// Pushes a token.
/// @deprecated Use +[TuyaSmartSDK sharedInstance].deviceToken instead.
@property (nonatomic, strong) NSString *pushToken DEPRECATED_MSG_ATTRIBUTE("Use +[TuyaSmartSDK sharedInstance].deviceToken instead.");

/// Pushes deviceToken.
@property (nonatomic, strong) NSData *deviceToken;


/// Sets the device token pushing and error information.
/// @param token The device token.
/// @param error An error occurs while processing the request.
- (void)setDeviceToken:(nullable NSData *)token withError:(nullable NSError *)error;


/// Indicates whether the app messages pushing function is enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app message pushing.
/// @param enable A Boolean value indicates whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setPushStatusWithStatus:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Indicates whether device alert notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevicePushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app device alert pushing messages.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setDevicePushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Indicates whether app home notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getFamilyPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app home push messages.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setFamilyPushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Indicates whether app message notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getNoticePushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app message pushing.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setNoticePushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Indicates whether app marketing messages are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getMarketingPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app marketing message pushing.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setMarketingPushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
