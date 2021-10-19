//
// TuyaSmartUser.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartUser_h
#define TuyaSmartUser_h

#import <UIKit/UIKit.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// The notification is sent when the user session is invalid.
extern NSString *const TuyaSmartUserNotificationUserSessionInvalid;

/// The user registration type.
typedef NS_ENUM(NSInteger, TYRegType) {
    /// Register from email.
    TYRegEmailType,
    /// Register from mobile phone.
    TYRegPhoneType,
    /// Register from other methods.
    TYRegOtherType,
    /// Register from QQ.
    TYRegQQType,
    /// Register from Sina Weibo.
    TYRegWeiboType,
    /// Register from Facebook.
    TYRegFacebookType,
    /// Register from Twitter.
    TYRegTwitterType,
    /// Register from WeChat.
    TYRegWechatType,
    /// Register from Apple.
    TYRegAppleIdType,
    /// Register from Google.
    TYRegGoogleType,
    /// Register from Line.
    TYRegLineType,
};

/// The password strength type.
typedef NS_ENUM(NSInteger, TYPasswordRegularType) {
    TYPasswordRegularLow = 1,       // Contains 8-20 characters in length,including letters and numbers.
    TYPasswordRegularMiddle = 2,       // Contains 8-20 characters,including uppercase and lowercase letters and numbers.
    TYPasswordRegularHigh = 3,     // Contains 8-20 characters,including uppercase and lowercase letters, numbers, and special characters.
};

/// @brief TuyaSmartUser is used for user-related functions.
///
/// This class is used to do the user-related things, such as register, login, logout, reset password, and so on.
///
/// Currently we support the following account type:
/// Main:
///     - Email
///     - Phone
/// Third-party:
///     - QQ
///     - Weibo
///     - WeChat
///     - Facebook
///     - Twitter
///     - Google
///     - AppleID
/// Other:
///     - UID (for advance usage)
///     - Anonymous
///     - QRCode
///
/// For email and phone account, usually we need to send a verify code to continue the following steps.
///
/// For uid account, it is designed for developers who already has the account system for their own. The developer can register the uid account without any verification. So please keep your username/password in safe place.
///
/// @warning Tuya server have many regions over the world, China/Europe/America, and so on. Account system between regions are separated. When user is not logged in, Tuya SDK will select a nearest region for the initial API request. During the register step, Tuya Cloud will see the account country code and create it in the right region. After the register or login step, the API request will be sent to the right region. So, the country code is part of the account username, please do not ignore it.
///
@interface TuyaSmartUser : NSObject

/// Returns the singleton of the class.
+ (instancetype)sharedInstance;

/// The session ID.
@property (nonatomic, strong, readonly) NSString *sid;

/// The user ID.
@property (nonatomic, strong, readonly) NSString *uid;

/// The avatar.
@property (nonatomic, strong, readonly) NSString *headIconUrl;

/// The nickname.
@property (nonatomic, strong, readonly) NSString *nickname;

/// The username. If the account is registered with a mobile phone number, the value is set to the mobile phone number. If the account is registered with an email, the value is set to the email.
@property (nonatomic, strong, readonly) NSString *userName;

/// The mobile phone number.
@property (nonatomic, strong, readonly) NSString *phoneNumber;

/// The email.
@property (nonatomic, strong, readonly) NSString *email;

/// The country code. For example, `86` means China, `1` means America.
@property (nonatomic, strong, readonly) NSString *countryCode;

/// The login status.
@property (nonatomic, assign, readonly) BOOL isLogin;

/// The region code of the current account. For example, `AY` means China, `AZ` means America, and `EU` means Europe.
@property (nonatomic, strong, readonly) NSString *regionCode;

/// The API domains of the current account region.
@property (nonatomic, strong, readonly) NSDictionary *domain;

/// The timezone ID, such as `Asia/Shanghai`.
@property (nonatomic, strong, readonly) NSString *timezoneId;

@property (nonatomic, strong, readonly) NSString *partnerIdentity;

/// The MQTT host.
@property (nonatomic, strong, readonly) NSString *mbHost;

@property (nonatomic, strong, readonly) NSString *gwHost;

/// The MQTT port.
@property (nonatomic, assign, readonly) NSInteger port;

/// Specifies whether to enable SSL.
@property (nonatomic, assign, readonly) BOOL useSSL;

/// The QUIC host.
@property (nonatomic, strong, readonly) NSString *quicHost;

/// The QUIC port.
@property (nonatomic, assign, readonly) NSInteger quicPort;

/// Specifies whether to enable QUIC.
@property (nonatomic, assign, readonly) BOOL useQUIC;

/// The temperature unit. For example, `1` means `°C` and `2` means `°F`.
@property (nonatomic, assign) NSInteger tempUnit;

/// The user registration type.
@property (nonatomic, assign, readonly) TYRegType regFrom;

/// The nickname of the SNS account.
@property (nonatomic, strong, readonly) NSString *snsNickname;

@property (nonatomic, strong, readonly) NSString *ecode;

/// The user type.
@property (nonatomic, assign, readonly) NSInteger userType;

/// Extra parameters.
@property (nonatomic, strong, readonly) NSDictionary *extras;


#pragma mark - Mobile phone verification code login

/// Sends the verification code to register, log in, or reset the password.
/// @param userName The mobile phone number or email address.
/// @param region To enable required registration, use [TuyaSmartUser regionListWithCountryCode:success:failure:] or [TuyaSmartUser getDefaultRegionWithCountryCode:] to get the region.
/// @param countryCode The country code.
/// @param type Valid values: `1`: Register with the mobile phone verification code. `2`: Log in with the mobile phone verification code. `3`: Reset the password with the mobile phone number. `5`: Complete account information in trial mode. `7`: Change the account. `8`: Cancel the account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVerifyCodeWithUserName:(NSString *)userName
                            region:(NSString *_Nullable)region
                       countryCode:(NSString *)countryCode
                              type:(NSInteger)type
                           success:(TYSuccessHandler)success
                           failure:(TYFailureError)failure;


/// Enables login with the mobile phone verification code.
/// @param mobile The mobile phone number.
/// @param countryCode The country code.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithMobile:(NSString *)mobile
            countryCode:(NSString *)countryCode
                   code:(NSString *)code
                success:(TYSuccessHandler)success
                failure:(TYFailureError)failure;


#pragma mark - Mobile phone binding

/// Sends the verification code to bind a mobile phone number or change the mobile phone number.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindVerifyCode:(NSString *)countryCode
               phoneNumber:(NSString *)phoneNumber
                   success:(nullable TYSuccessHandler)success
                   failure:(nullable TYFailureError)failure;


/// Sends the verification code to bing a mobile phone and enable more services.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindVasVerifyCode:(NSString *)countryCode
                  phoneNumber:(NSString *)phoneNumber
                      success:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;

/// Binds a mobile phone number.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)mobileBinding:(NSString *)countryCode
          phoneNumber:(NSString *)phoneNumber
                 code:(NSString *)code
              success:(nullable TYSuccessHandler)success
              failure:(nullable TYFailureError)failure;

#pragma mark - Mobile phone password login

/// Registers with a mobile phone number.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param password The password.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)registerByPhone:(NSString *)countryCode
            phoneNumber:(NSString *)phoneNumber
               password:(NSString *)password
                   code:(NSString *)code
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureError)failure;

/// Enables login with the mobile phone password.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param password The password.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByPhone:(NSString *)countryCode
         phoneNumber:(NSString *)phoneNumber
            password:(NSString *)password
             success:(nullable TYSuccessHandler)success
             failure:(nullable TYFailureError)failure;

/// Resets the mobile phone password.
/// @param countryCode The country code.
/// @param phoneNumber The mobile phone number.
/// @param newPassword The new password.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)resetPasswordByPhone:(NSString *)countryCode
                 phoneNumber:(NSString *)phoneNumber
                 newPassword:(NSString *)newPassword
                        code:(NSString *)code
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;

#pragma mark - Email login

/// Enables login with an email.
/// @param countryCode The country code.
/// @param email The email.
/// @param password The password.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByEmail:(NSString *)countryCode
               email:(NSString *)email
            password:(NSString *)password
             success:(nullable TYSuccessHandler)success
             failure:(nullable TYFailureError)failure;


/// Resets the email password.
/// @param countryCode The country code.
/// @param email The email.
/// @param newPassword The new password.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)resetPasswordByEmail:(NSString *)countryCode
                       email:(NSString *)email
                 newPassword:(NSString *)newPassword
                        code:(NSString *)code
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;


#pragma mark - Email register 2.0

/// Email register 2.0.
/// @param countryCode The country code.
/// @param email The email.
/// @param password The password.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)registerByEmail:(NSString *)countryCode
                  email:(NSString *)email
               password:(NSString *)password
                   code:(NSString *)code
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureError)failure;

#pragma mark - Email verification code login

/// Enables login with an email verification code.
/// @param email The email.
/// @param countryCode The country code.
/// @param code The verification code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithEmail:(NSString *)email countryCode:(NSString *)countryCode code:(NSString *)code success:(TYSuccessHandler)success failure:(TYFailureError)failure;

#pragma mark - Email bind

/// Returns the email verification code.
/// @param email The email.
/// @param countryCode The country code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindingVerificationCodeWithEmail:(NSString *)email
                                 countryCode:(NSString *)countryCode
                                     success:(nullable TYSuccessHandler)success
                                     failure:(nullable TYFailureError)failure;

/// Binds an email.
/// @param email The email.
/// @param countryCode The country code.
/// @param code The verification Code.
/// @param sId The user session ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindEmail:(NSString *)email
  withCountryCode:(NSString *)countryCode
             code:(NSString *)code
              sId:(NSString *)sId
          success:(nullable TYSuccessHandler)success
          failure:(nullable TYFailureError)failure;

#pragma mark - uid login

/// The user ID that is used to log in or register. The account is registered at the first login.
/// @param countryCode The country code.
/// @param uid The user ID.
/// @param password The password.
/// @param createHome Creates the default home.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              password:(NSString *)password
                            createHome:(BOOL)createHome
                               success:(nullable TYSuccessID)success
                               failure:(nullable TYFailureError)failure;

#pragma mark - Social login

/// Enables login with the QQ account.
/// @param countryCode The country code.
/// @param userId The user ID that is authorized for login with the QQ account.
/// @param accessToken AccessToken that is used for login with the QQ account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByQQ:(NSString *)countryCode
           userId:(NSString *)userId
      accessToken:(NSString *)accessToken
          success:(nullable TYSuccessHandler)success
          failure:(nullable TYFailureError)failure;

/// Enables login with the WeChat account.
/// @param countryCode The country code.
/// @param code The code that is used for login with the WeChat account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByWechat:(NSString *)countryCode
                 code:(NSString *)code
              success:(nullable TYSuccessHandler)success
              failure:(nullable TYFailureError)failure;

/// Enables login with the Facebook account.
/// @param countryCode The country code.
/// @param token The token that is used for login with the Facebook account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByFacebook:(NSString *)countryCode
                  token:(NSString *)token
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureError)failure;

/// Enables login with the Twitter account.
/// @param countryCode The country code.
/// @param key The key that is used for login with the Twitter account.
/// @param secret The secret that is used for login with the Twitter account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByTwitter:(NSString *)countryCode
                   key:(NSString *)key
                secret:(NSString *)secret
               success:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

/// Enables login with the third-party account.
/// @param type The login type. For example, `ap` means "login with apple".
/// @param countryCode The country code.
/// @param accessToken  The token that is used for login with the third-party account.
/// @param extraInfo Extra parameters.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByAuth2WithType:(NSString *)type
                 countryCode:(NSString *)countryCode
                 accessToken:(NSString *)accessToken
                   extraInfo:(NSDictionary *)extraInfo
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;

#pragma mark -

/// Logout.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginOut:(nullable TYSuccessHandler)success
         failure:(nullable TYFailureError)failure;

/// Edits the nickname.
/// @param nickName The nickname.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateNickname:(NSString *)nickName
               success:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

/// Edits the avatar.
/// @param headIcon The avatar.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateHeadIcon:(UIImage *)headIcon
               success:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

/// Updates user information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateUserInfo:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

/// Edits user time zone information.
/// @param timeZoneId The time zone ID, such as `Asia/Shanghai`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimeZoneWithTimeZoneId:(NSString *)timeZoneId
                             success:(nullable TYSuccessHandler)success
                             failure:(nullable TYFailureError)failure;

/// Edits the user temperature unit.
/// @param tempUnit The temperature unit. For example, `1` means `°C` and `2` means `°F`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTempUnitWithTempUnit:(NSInteger)tempUnit
                           success:(nullable TYSuccessHandler)success
                           failure:(nullable TYFailureError)failure;

/// Destroys an account. One week after the operation, all of the account information is permanently removed from the server. After login before the information is removed, the destroying request is canceled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelAccount:(nullable TYSuccessHandler)success
              failure:(nullable TYFailureError)failure;


/**
 * Checks whether the password format meets the password strength requirements.
 * @param password The password to be checked.
 * @param regularType The recommended password type.
 * @return The result of the check.
 */
- (BOOL)checkPasswordFormat:(NSString *)password withPasswordRegularType:(TYPasswordRegularType)regularType;


#pragma mark - Ticket from third cloud login

/// Login with ticket.
/// Ticket is created from a third-party cloud platform, for more information, please refer to the tuya cloud-to-cloud solution.
///
/// @param ticket User ticket from service.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithTicket:(NSString *)ticket
                success:(TYSuccessHandler)success
                failure:(TYFailureError)failure;

#pragma mark -

/// Cancels the network request.
- (void)cancelRequest;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartUser_h */
