//
// TuyaSmartBLEDeviceProtocol.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TYBluetooth/TYBluetooth.h>
#import "TuyaSmartBLEDeviceProtocol.h"
#import "TuyaSmartBLEManager.h"

@class TYBLEScan;
@class TYBLEAgent;
@protocol TuyaSmartBLEDeviceProtocol;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Scan Protocol

/// @brief TuyaSmartBLEDeviceProtocol provides protocol methods to implement multiple functions, such as activation, device control, and over-the-air (OTA) updates.
@protocol TuyaSmartBLEScanProtocol <NSObject>

typedef void(^TYBLEScanResultHandher)(id<TuyaSmartBLEDeviceProtocol> deviceInfo);

/// Results of inactive device scanning.
///
/// @param agent        The scanning agent.
/// @param scan         The scanning class.
/// @param peripheral   The scanned Bluetooth peripheral.
/// @param error        The scan error.
/// @param handler      The scan callback.
- (void)bleAgent:(TYBLEAgent *)agent bleScan:(TYBLEScan *)scan didScanBLEDevicePeripheral:(TYBLEPeripheral *)peripheral error:(NSError *)error scanResultHandher:(TYBLEScanResultHandher)handler;

@end

#pragma mark -------------------------------------------------------------


#pragma mark - Active Protocol

@protocol TuyaSmartBLEActiveProtocol <NSObject>

/// Activates the Bluetooth LE device.
///
/// @param deviceInfo       The advertisingData model for the Bluetooth LE device.
/// @param homeId           The ID of the current home.
/// @param success          Called when the task is finished. DeviceModel is returned.
/// @param failure          Called when the task is interrupted by an error.
- (void)startActiveWithDevice:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                       homeId:(long long)homeId
                      success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                      failure:(TYFailureError)failure;

@end

#pragma mark -------------------------------------------------------------


#pragma mark - Config Protocol

@protocol TuyaSmartBLEConfigProtocol <NSObject>

/// Sends a DP.
///
/// @param deviceInfo   The Tuya Bluetooth LE-based device object.
/// @param dps          The DP dictionary.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)publishDpsWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                             dps:(NSDictionary *)dps
                             success:(TYSuccessHandler)success
                             failure:(TYFailureError)failure;

/// Queries device DP data through Bluetooth channels.
///
/// @param deviceInfo   The Tuya Bluetooth LE-based device object.
/// @param dpIds        The array of DP IDs to be queried.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)publishQueryDpCommand:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                        dpIds:(NSArray *)dpIds
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Connects to a device.
///
/// @param deviceInfo   The Tuya Bluetooth LE-based device object.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)connectWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Disconnects a device.
///
/// @param deviceInfo   The Tuya Bluetooth LE-based device object.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)disconnectWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;

/// Removes a device.
///
/// @param deviceInfo   The Tuya Bluetooth LE-based device object.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)removeWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;

/// Restores factory settings
///
/// @param deviceInfo   The Tuya Bluetooth LE-based device object.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)resetWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;

/// Sends an OTA package to update the firmware.
///
/// The values of `otaData`, `otaType`, and `otaVersion` can be obtained from TuyaSmartFirmwareUpgradeModel. You can get TuyaSmartFirmwareUpgradeModel by using TuyaSmartDevice::getFirmwareUpgradeInfo:failure:.
///
/// @note Your device must be connected over Bluetooth before the update.
///
/// @param deviceInfo   The Tuya Bluetooth LE-based device object.
/// @param otaData      The OTA package data.
/// @param otaType      The OTA update type.
/// @param otaVersion   The OTA version.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)sendOTAPackWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                          otaData:(NSData *)otaData
                          otaType:(TuyaSmartBLEOTAType)otaType
                       otaVersion:(NSString *)otaVersion
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;

/// Returns the Received Signal Strength Indicator (RSSI) value of the Bluetooth LE device.
///
/// @param deviceInfo       The Tuya Bluetooth LE-based device object.
///
/// @return The RSSI value of the Bluetooth LE device.
- (NSInteger)peripheralRSSI:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo;

/// Returns the local connection status of the Bluetooth LE device by deviceInfo.
///
/// @param deviceInfo       The Tuya Bluetooth LE-based device object.
///
/// @return The local connection status of the Bluetooth LE device.
- (BOOL)deviceOnlineState:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo;

/// Ability to acquire Bluetooth device: hexadecimal.
/// @param uuid The device uuid.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getBLECapabilityWithUUID:(NSString *)uuid success:(TYSuccessString)success failure:(TYFailureError)failure;

@end

#pragma mark -------------------------------------------------------------


#pragma mark - Device Protocol

@protocol TuyaSmartBLEDeviceProtocol <NSObject>

/// The Tuya Bluetooth LE agent.
@property (nonatomic, strong) TYBLEAgent                        *agent;

/// The Tuya Bluetooth LE peripheral.
@property (nonatomic, strong) TYBLEPeripheral                   *peripheral;

/// The Tuya Bluetooth LE advertising model.
@property (nonatomic, strong) TYBLEAdvModel                     *advModel;

/// The Tuya active protocol-based manager object.
@property (nonatomic, strong) id<TuyaSmartBLEActiveProtocol>    activeManager;

/// The Tuya config protocol-based manager object.
@property (nonatomic, strong) id<TuyaSmartBLEConfigProtocol>    configManager;


@optional
/// The methods to initialize TuyaSmartBLEDeviceProtocol-based device objects.
///
/// @param activeManager      The Tuya active protocol-based manager object.
/// @param configManager      The Tuya config protocol-based manager object.
- (instancetype)initWithActiveManager:(id<TuyaSmartBLEActiveProtocol>)activeManager
                        configManager:(id<TuyaSmartBLEConfigProtocol>)configManager;

@end

NS_ASSUME_NONNULL_END
