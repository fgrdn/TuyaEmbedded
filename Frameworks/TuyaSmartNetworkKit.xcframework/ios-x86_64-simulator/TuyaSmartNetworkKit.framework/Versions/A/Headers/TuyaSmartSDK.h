//
// TuyaSmartSDK.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartSDK_h
#define TuyaSmartSDK_h

#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// Server environment.
typedef NS_ENUM(NSInteger, TYEnv) {
    TYEnvDaily,
    TYEnvPrepare,
    TYEnvRelease,
};

/// @brief TuyaSmartSDK is an entry for using the Tuya SDK.
///
/// Before using the SDK, please go to Tuya IoT Platform (https://iot.tuya.com) create a SDK App.
/// We need 4 things from the Platform to initialize the SDK:
///     - Tuya App Key.
///     - Tuya App Secret.
///     - Security Image. Rename to `t_s.bmp` and put it in your project as a resource.
///     - Bundle ID. Must equal to your App's bundle ID.
///
/// If you need to set some params (appGroupId, env, appVersion, lang, etc...) in this class, be sure to set them before initialize the SDK.
///
/// Finally, call this method to initialize the SDK:
///     `[TuyaSmartSDK.sharedInstance startWithAppKey:@"YOUR_APP_KEY" secretKey:@"YOUR_APP_SECRET"];`.
///
@interface TuyaSmartSDK : NSObject

/// Returns the singleton of the class.
+ (instancetype)sharedInstance;

/// Application group identifier.
/// If you want to use the SDK in app extension, set `appGroupId` before SDK initialized both in app & app extension.
@property (nonatomic, strong) NSString *appGroupId;

/// Latitude of the location.
@property (nonatomic, assign) double latitude;

/// Longitude of the location.
@property (nonatomic, assign) double longitude;

/// Server environment, defaults is TYEnvRelease. Please do not set in production environment.
@property (nonatomic, assign) TYEnv env;

/// Request need SSL Pinning, default is `YES`.
@property (nonatomic, assign) BOOL useSSLPinning;

/// TuyaSmart AppKey.
@property (nonatomic, strong, readonly) NSString *appKey;

/// TuyaSmart SecretKey.
@property (nonatomic, strong, readonly) NSString *secretKey;

/// Channel.
@property (nonatomic, strong) NSString *channel;

/// UUID of the iOS/watchOS device. Will be created at app first launch.
@property (nonatomic, strong, readonly) NSString *uuid;

/// App version, default value is from Info.plist -> CFBundleShortVersionString.
@property (nonatomic, strong) NSString *appVersion;

/// Device product name. For example: iPhone XS Max.
@property (nonatomic, strong) NSString *deviceProductName;

/// App SDK lang, default value is from mainBundle -> preferredLocalizations -> [0].
@property (nonatomic, strong) NSString *lang;

@property (nonatomic, strong, readonly) NSString *appEnv;

@property (nonatomic, strong, readonly) NSString *mbUrl;

@property (nonatomic, strong, readonly) NSString *gwHost;
@property (nonatomic, strong, readonly) NSString *mbHost;
@property (nonatomic, assign, readonly) int port;
@property (nonatomic, assign, readonly) BOOL useSSL;

@property (nonatomic, strong, readonly) NSString *quicHost;
@property (nonatomic, assign, readonly) int quicPort;
@property (nonatomic, assign, readonly) BOOL useQUIC;

/// Initialize TuyaSmart SDK.
/// @param appKey TuyaSmart AppKey.
/// @param secretKey TuyaSmart SecretKey.
- (void)startWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey;


/// Report location if needed.
/// @param latitude Latitude.
/// @param longitude Longitude.
- (void)updateLatitude:(double)latitude longitude:(double)longitude;

@end

@interface TuyaSmartSDK (CountryCode)
/// Set env to this country code
/// @param countryCode link 86 for china
+ (void)setCountryCode:(NSString *)countryCode;

+ (NSString *)getCountryCode;

+ (NSString *)getCountryNumWithCountryCode:(NSString *)countryCode;

@end


NS_ASSUME_NONNULL_END

#endif /* TuyaSmartSDK_h */
