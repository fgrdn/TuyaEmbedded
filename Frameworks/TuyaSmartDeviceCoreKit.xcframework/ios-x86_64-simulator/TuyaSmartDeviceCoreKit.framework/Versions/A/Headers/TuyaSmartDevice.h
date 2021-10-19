//
// TuyaSmartDevice.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartDevice
#define TuyaSmart_TuyaSmartDevice

#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TuyaSmartFirmwareUpgradeModel.h"
#import "TuyaSmartFirmwareUpgradeStatusModel.h"
#import "TuyaSmartDeviceModel.h"
#import "TuyaSmartMQTTMessageModel.h"
#import "TuyaSmartLanMessageModel.h"
#import "TuyaSmartBackupWifiModel.h"
#import "TuyaSmartDeviceOTAModel.h"

NS_ASSUME_NONNULL_BEGIN

/// The device online status.
typedef enum : NSUInteger {
    /// Connected to a LAN.
    TYDeviceOnlineModeLocal,
    /// Connected to the Internet.
    TYDeviceOnlineModeInternet,
    /// Goes offline.
    TYDeviceOnlineModeOffline,
} TYDeviceOnlineMode;

/// The DP sending channel.
typedef enum : NSUInteger {
    /// Over the LAN.
    TYDevicePublishModeLocal,
    /// Over the Internet.
    TYDevicePublishModeInternet,
    /// Automatically selects a channel to send DPs.
    TYDevicePublishModeAuto,
} TYDevicePublishMode;

@class TuyaSmartDevice;

/// The delegate for the TuyaSmartDevice class, used for getting all device status updates.
@protocol TuyaSmartDeviceDelegate<NSObject>

@optional

/// Device information updates, such as the name and online status.
/// @param device The device instance.
- (void)deviceInfoUpdate:(TuyaSmartDevice *)device;

/// Indicates whether the device is removed.
/// @param device The device instance.
- (void)deviceRemoved:(TuyaSmartDevice *)device;

/// The DP data updates.
/// @param device The device instance.
/// @param dps The command dictionary.
- (void)device:(TuyaSmartDevice *)device dpsUpdate:(NSDictionary *)dps;

/// The DP data updates.
/// @param device The device instance.
/// @param dpCodes The DP codes.
- (void)device:(TuyaSmartDevice *)device dpCommandsUpdate:(NSDictionary *)dpCodes;

/// The firmware update progress.
/// @param device The device instance.
/// @param type The device type.
/// @param progress The update progress.
- (void)device:(TuyaSmartDevice *)device firmwareUpgradeProgress:(NSInteger)type progress:(double)progress;

/// The delegate of changes in device firmware update status.
/// @param device The device instance.
/// @param upgradeStatusModel The model of the device update status.
- (void)device:(TuyaSmartDevice *)device firmwareUpgradeStatusModel:(TuyaSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;

/// The callback of Wi-Fi signal strength.
/// @param device The device instance.
/// @param signal The signal strength.
- (void)device:(TuyaSmartDevice *)device signal:(NSString *)signal;

/// Receives MQTT custom messages.
/// @param device The device instance.
/// @param message The custom message.
- (void)device:(TuyaSmartDevice *)device didReceiveCustomMessage:(TuyaSmartMQTTMessageModel *)message;

/// Receives LAN custom messages.
- (void)device:(TuyaSmartDevice *)device didReceiveLanMessage:(TuyaSmartLanMessageModel *)message;

/// The delegate of warning information updates.
/// @param device The device instance.
/// @param warningInfo The warning information.
- (void)device:(TuyaSmartDevice *)device warningInfoUpdate:(NSDictionary *)warningInfo;

#pragma - deprecated

/// The delegate of changes in device firmware update status.
/// @param device The device instance.
/// @param type The device type.
/// @param upgradeStatus The device update status.
/// @deprecated This method is deprecated. Use TuyaSmartDeviceDelegate::device:firmwareUpgradeStatusModel: instead.
- (void)device:(TuyaSmartDevice *)device type:(NSInteger)type upgradeStatus:(TuyaSmartDeviceUpgradeStatus)upgradeStatus __deprecated_msg("This method is deprecated, Use device:firmwareUpgradeStatusModel: instead");

/// Success of device firmware updates.
/// @param device The device instance.
/// @param type The device type.
/// @deprecated This method is deprecated. Use TuyaSmartDeviceDelegate::device:upgradeStatus: instead.
- (void)deviceFirmwareUpgradeSuccess:(TuyaSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

/// Failure of device firmware updates.
/// @param device The device instance.
/// @param type The device type.
/// @deprecated This method is deprecated. Use TuyaSmartDeviceDelegate::device:upgradeStatus: instead.
- (void)deviceFirmwareUpgradeFailure:(TuyaSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

/// Device firmware updating.
/// @param device The device instance.
/// @param type The device type.
/// @deprecated This method is deprecated. Use TuyaSmartDeviceDelegate::device:upgradeStatus: instead.
- (void)deviceFirmwareUpgrading:(TuyaSmartDevice *)device type:(NSInteger)type __deprecated_msg("This method is deprecated, Use device:upgradeStatus: instead");

@end

/// @brief The basic operation class of TuyaSmartDevice contains the model of basic information, including the device, DPs to send, update device information, and other common API operations.
///
/// All types of devices can be controlled after you initialize an instance of this class if the function is supported.
///
@interface TuyaSmartDevice : NSObject

/// Returns the model of basic device information.
@property (nonatomic, strong, readonly) TuyaSmartDeviceModel *deviceModel;

@property (nonatomic, weak, nullable) id<TuyaSmartDeviceDelegate> delegate;

/// Returns the TuyaSmartDevice instance. If the current user does not have this device, a value of nil is returned.
/// @param devId The device ID.
+ (nullable instancetype)deviceWithDeviceId:(NSString *)devId;

/// Returns the TuyaSmartDevice instance. If the current user does not have this device, a value of nil is returned.
/// @param devId The device ID.
- (nullable instancetype)initWithDeviceId:(NSString *)devId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Returns the device online status.
- (TYDeviceOnlineMode)onlineMode;

/// Sends DPs.
/// @param dps The DP dictionary.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDps:(NSDictionary *)dps
           success:(nullable TYSuccessHandler)success
           failure:(nullable TYFailureError)failure;

/// Sends DPs.
/// @param dps The DP dictionary.
/// @param mode Publish mode(Lan/Internet/Auto).
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDps:(NSDictionary *)dps
              mode:(TYDevicePublishMode)mode
           success:(nullable TYSuccessHandler)success
           failure:(nullable TYFailureError)failure;

/// Sends DPs.
/// @param dps The dp dictionary.
/// @param communicationTypes Use communication order to publish dps. (Array element's value  reference enum TYCommunicationType)
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDps:(NSDictionary *)dps
communicationTypes:(NSArray *)communicationTypes
           success:(nullable TYSuccessHandler)success
           failure:(nullable TYFailureError)failure;

/// Edits the device name.
/// @param name The device name.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateName:(NSString *)name
           success:(nullable TYSuccessHandler)success
           failure:(nullable TYFailureError)failure;

/// Edits the device icon.
/// @param icon The device icon.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIcon:(UIImage *)icon
           success:(nullable TYSuccessHandler)success
           failure:(nullable TYFailureError)failure;

/// Edits the device icon.
/// @param cloudKey The cloud key.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIconWithCloudKey:(NSString *)cloudKey
                       success:(nullable TYSuccessHandler)success
                       failure:(nullable TYFailureError)failure;

/// Synchronizes device information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)syncWithCloud:(nullable TYSuccessHandler)success
              failure:(nullable TYFailureError)failure;


/// Synchronizes device information.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)syncDeviceInfoWithDevId:(NSString *)devId
                        success:(nullable void (^)(TuyaSmartDeviceModel *device))success
                        failure:(nullable TYFailureError)failure;

/// Synchronizes sub-device information.
/// @param gatewayId The gateway ID.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)syncSubDeviceInfoWithGatewayId:(NSString *)gatewayId
                                 devId:(NSString *)devId
                               success:(nullable TYSuccessHandler)success
                               failure:(nullable TYFailureError)failure;

/// Removes the device and unbinds the device from the current user.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)remove:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Restores factory settings.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)resetFactory:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Returns a sub-device list of the current gateway.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getSubDeviceListFromCloudWithSuccess:(nullable void (^)(NSArray <TuyaSmartDeviceModel *> *subDeviceList))success failure:(nullable TYFailureError)failure;

/// Synchronizes the longitude and latitude of the mobile phone to the device.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)syncLocationToDeviceWithSucecess:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

#pragma mark - firmware upgrade

/// Returns firmware update information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getFirmwareUpgradeInfo:(nullable void (^)(NSArray <TuyaSmartFirmwareUpgradeModel *> *upgradeModelList))success
                       failure:(nullable TYFailureError)failure;

/// Updates the firmware and receives a success or failure callback from TuyaSmartDeviceDelegate.
/// @param type The device type of "TuyaSmartFirmwareUpgradeModel".
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)upgradeFirmware:(NSInteger)type success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Cancels the firmware updates. Only the update tasks that have not been published can be canceled.
/// @param type The device type of `TuyaSmartFirmwareUpgradeModel`.
/// @param success  Called when the task is finished.
/// @param failure  Called when the task is interrupted by an error.
- (void)cancelUpgradeFirmware:(NSInteger)type success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Cancels the firmware update request.
- (void)cancelFirmwareRequest;

/// Reports the device firmware version.
/// @param version The device version.
/// @param type The device type.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateDeviceVersion:(NSString *)version
                       type:(NSInteger)type
                    success:(nullable TYSuccessHandler)success
                    failure:(nullable TYFailureError)failure;

/// Returns the switch value for the automatic device OTA updates.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getAutoUpgradeSwitchInfoWithSuccess:(nullable TYSuccessID)success
                                    failure:(nullable TYFailureError)failure;

/// Saves the switch value for automatic device over-the-air (OTA) updates.
/// @param switchValue The value of the auto switch. 0 means off, and 1 means on.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)saveUpgradeInfoWithSwitchValue:(NSInteger)switchValue
                               success:(nullable TYSuccessHandler)success
                               failure:(nullable TYFailureError)failure;


/// Manages the device custom data, such as recording and storing of custom data information.
/// @param success  Called when the task is finished. The device property is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevPropertyWithSuccess:(TYSuccessDict)success
                          failure:(nullable TYFailureError)failure;


/// Sets the device custom data to record and store custom data information.
/// @param code The custom data key.
/// @param value The custom data value.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setDevPropertyWithCode:(NSString *)code
                         value:(id)value
                       success:(TYSuccessBOOL)success
                       failure:(nullable TYFailureError)failure;

#if TARGET_OS_IOS

/// Returns the Wi-Fi signal strength. Receives the signal strength from `-[TuyaSmartDeviceDelegate device:signal:]`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getWifiSignalStrengthWithSuccess:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Publishes messages over the LAN.
/// @param body The message body.
/// @param type The message type.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishMessageInLanWithBody:(NSDictionary *)body
                               type:(NSInteger)type
                            success:(nullable TYSuccessDict)success
                            failure:(nullable TYFailureError)failure;

/// Queries the DPs. Some DPs do not report the initial data when settings are changed.
/// @param dpsArray The array of DP IDs. If the value is set to nil or an empty array, all DPs are queried.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getInitiativeQueryDpsInfoWithDpsArray:(nullable NSArray *)dpsArray
                                      success:(nullable TYSuccessHandler)success
                                      failure:(nullable TYFailureError)failure;

/// Awakes the low-energy device.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)awakeDeviceWithSuccess:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

#pragma mark - publish custom message

/// Adds the custom message delegate. Receives the custom message from `- (void)device:(TuyaSmartDevice *)device didReceiveCustomMessage:(TuyaSmartMQTTMessageModel *)message`.
/// @param delegate The delegate of TuyaSmartDevice.
/// @param protocol The protocol.
- (void)addDelegate:(id<TuyaSmartDeviceDelegate>)delegate forProtocol:(NSInteger)protocol;

/// Removes the custom message delegate.
/// @param delegate The delegate of TuyaSmartDevice.
/// @param protocol The protocol.
- (void)removeDelegate:(id<TuyaSmartDeviceDelegate>)delegate forProtocol:(NSInteger)protocol;

/// Sends custom messages.
/// @param data The data.
/// @param protocol The protocol.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishCustomMessageWithData:(NSDictionary *)data
                            protocol:(NSInteger)protocol
                             success:(nullable TYSuccessHandler)success
                             failure:(nullable TYFailureError)failure;

#endif

/// Sends DPs.
/// @param commands The dictionary of DP values.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDpWithCommands:(NSDictionary *)commands
                      success:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif
