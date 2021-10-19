//
// TuyaSmartSIGMeshManager+OTA.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartFirmwareUpgradeModel.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// This API provides multiple group management functions. For example, devices can be added to groups or removed from groups.
///
@interface TuyaSmartSIGMeshManager (OTA)

/// Prepares for OTA updates for a specific device.
/// @param targetNodeId The node ID of the device to be updated.
- (void)prepareForOTAWithTargetNodeId:(NSString *)targetNodeId;

/// Start sending upgrade package.
/// @param data Data.
/// @param upgradeModel Firmware upgrade model.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startSendOTAPack:(NSData *)data
            upgradeModel:(TuyaSmartFirmwareUpgradeModel *)upgradeModel
                 success:(TYSuccessHandler)success
                 failure:(TYFailureHandler)failure;

/// Starts to send the update package.
/// @param data The data.
/// @param targetVersion The version to which the device is updated.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartSIGMeshManager startSendOTAPack:upgradeModel:success:failure: instead.
- (void)startSendOTAPack:(NSData *)data
           targetVersion:(NSString *)targetVersion
                 success:(TYSuccessHandler)success
                 failure:(TYFailureHandler)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartSIGMeshManager startSendOTAPack:upgradeModel:success:failure:] instead");


@end

NS_ASSUME_NONNULL_END
