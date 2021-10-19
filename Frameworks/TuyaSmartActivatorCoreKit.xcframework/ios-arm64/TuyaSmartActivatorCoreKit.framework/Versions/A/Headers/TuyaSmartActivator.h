//
// TuyaSmartActivator.h
// TuyaSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartActivator
#define TuyaSmart_TuyaSmartActivator

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

/// This notification is sent after receiving a broadcast from a wired distribution device. Object is dictionary, @{@"productId":productId, @"gwId":gwId}
extern NSString *const TuyaSmartActivatorNotificationFindGatewayDevice;

typedef enum : NSUInteger {
    TYActivatorModeEZ,///< smart config mode
    TYActivatorModeAP,///< access point mode
    TYActivatorModeQRCode,///< QR Code mode
    TYActivatorModeWired, ///< wired mode
} TYActivatorMode;

typedef enum : NSUInteger {
    TYActivatorStepFound = 1,///< device found
    TYActivatorStepRegisted = 2,///< device registered
    TYActivatorStepIntialized = 3,///< device initialized
    TYActivatorStepTimeOut = 4, ///< device config timeout
} TYActivatorStep;

@class TuyaSmartActivator;

@protocol TuyaSmartActivatorDelegate<NSObject>

@required

/// Callback for distribution status update, wifi single product, zigbee gateway, zigbee sub device.
/// @param activator instance
/// @param deviceModel deviceModel
/// @param error error
- (void)activator:(TuyaSmartActivator *)activator didReceiveDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@optional

/// Callback for distribution status update, wifi single product, zigbee gateway, zigbee sub device.
/// @param activator instance
/// @param deviceModel deviceModel
/// @param step activator step
/// @param error error
- (void)activator:(TuyaSmartActivator *)activator didReceiveDevice:(TuyaSmartDeviceModel *)deviceModel step:(TYActivatorStep)step error:(NSError *)error;

/// Callback for distribution status update mesh gateway, deprecated.
/// @param activator instance
/// @param deviceId devId
/// @param meshId meshId
/// @param error error
/// @deprecated This method is deprecated, Use TuyaSmartActivatorDelegate::activator:didReceiveDevice:error: instead `deviceId` is `deviceModel.devId`, `meshId` is `deviceModel.parentId`.
- (void)meshActivator:(TuyaSmartActivator *)activator didReceiveDeviceId:(NSString *)deviceId meshId:(NSString *)meshId error:(NSError *)error __deprecated_msg("Use -[TuyaSmartActivatorDelegate activator:didReceiveDevice:error:] instead. `deviceId` is `deviceModel.devId`, `meshId` is `deviceModel.parentId`.");

@end

@interface TuyaSmartActivator : NSObject

/// Returns a singleton of the class.
+ (instancetype)sharedInstance;

#pragma mark - SSID

/// Get the SSID of the current Wi-Fi.
///
/// Starting with iOS 12, calls to this function will return nil by default, and will only return the correct value if "Access WiFi Information" is enabled in the Xcode project. This function needs to be activated in the App IDs on the developer page in order to use it.
/// Starting with iOS 13, at least one of the following three conditions must also be met.
///   - An app that has been granted Location Services permissions.
///   - A VPN application that is currently enabled.
///   - Use of NEHotspotConfiguration (only Wi-Fi networks configured through the app are supported).
///
/// @see https://developer.apple.com/videos/play/wwdc2019/713/
///
/// @return Wi-Fi SSID
+ (NSString *)currentWifiSSID;

/// Get the BSSID of the current Wi-Fi.
/// @see TuyaSmartActivator::currentWifiSSID.
/// @return Wi-Fi BSSID
+ (NSString *)currentWifiBSSID;

/// Get the SSID of the current Wi-Fi asynchronously.
/// @see TuyaSmartActivator::currentWifiSSID
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getSSID:(TYSuccessString)success
        failure:(TYFailureError)failure;

/// Asynchronously get the BSSID of the current Wi-Fi.
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getBSSID:(TYSuccessString)success
         failure:(TYFailureError)failure;

#pragma mark - Delegate

@property (nonatomic, weak) id<TuyaSmartActivatorDelegate> delegate;

#pragma mark - active gateway

/// Start configuration (Wireless config).
/// @param mode Config mode, EZ or AP.
/// @param ssid Name of route.
/// @param password Password of route.
/// @param token Config Token.
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFi:(TYActivatorMode)mode
                   ssid:(NSString *)ssid
               password:(NSString *)password
                  token:(NSString *)token
                timeout:(NSTimeInterval)timeout;

/// Start configuration (Wired config).
/// @param token Token
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFiWithToken:(NSString *)token
                         timeout:(NSTimeInterval)timeout;

/// Start configuring the network to activate only one category of devices (Wired config).
/// @param token Config Token.
/// @param productId ProductId of device.
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFiWithToken:(NSString *)token
                       productId:(NSString *)productId
                         timeout:(NSTimeInterval)timeout;

/// Start EZ mode multi-device configuration network
/// @param ssid Name of route.
/// @param password Password of route.
/// @param token Config Token.
/// @param timeout Timeout, default 100 seconds.
- (void)startEZMultiConfigWiFiWithSsid:(NSString *)ssid
                              password:(NSString *)password
                                 token:(NSString *)token
                               timeout:(NSTimeInterval)timeout;

/// Stop configuring the network.
- (void)stopConfigWiFi;

#pragma mark - active sub device

/// Activate sub-devices e.g. zigbee, Wi-Fi sub-devices.
/// @param gwId     Gateway Id
/// @param timeout  Timeout, default 100 seconds
- (void)activeSubDeviceWithGwId:(NSString *)gwId timeout:(NSTimeInterval)timeout;

/// Activate zigbee sub-devices with installCode
/// @param gwId Gateway Id
/// @param mac mac
/// @param installCode installCode
/// @param timeout Timeout, default 100 seconds
- (void)activeSubDeviceWithGwId:(NSString *)gwId
                            mac:(NSString *)mac
                    installCode:(NSString *)installCode
                        timeout:(NSTimeInterval)timeout;

/// Stop activate sub device with gateway ID.
/// @param gwId Gateway Id
- (void)stopActiveSubDeviceWithGwId:(NSString *)gwId;

#pragma mark - optimize Activator
/// Activates wired gateway
/// @param gwId      The gateway ID.
/// @param productId The gateway PID
/// @param token     The pairing token.
/// @param timeout   The timeout value. Unit: seconds. Default value: 100
- (void)activeGatewayDeviceWithGwId:(NSString *)gwId
                          productId:(NSString *)productId
                              token:(NSString *)token
                            timeout:(NSTimeInterval)timeout;


@end

#endif
