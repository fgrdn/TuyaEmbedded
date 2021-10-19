//
// TuyaSmartSIGMeshManager+Activator.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>

/// @brief The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// This API provides multiple functions such as device scanning and activation.
@interface TuyaSmartSIGMeshManager (Activator)

/// Starts to scan devices.
/// @param scanType The devices to be scanned are classified into the paired devices and the devices that are not paired. The devices that are not paired are added to the network after they are scanned.
/// @param meshModel The mesh model.
- (void)startScanWithScanType:(TuyaSmartSIGScanType)scanType meshModel:(TuyaSmartBleMeshModel *)meshModel;

/// Starts to activate devices.
/// @param devList A list of devices to be activated.
/// @param meshModel The mesh model information.
- (void)startActive:(NSArray<TuyaSmartSIGMeshDiscoverDeviceInfo *> *)devList meshModel:(TuyaSmartBleMeshModel *)meshModel;

/// Stops device activation.
- (void)stopActiveDevice;

/// Stops device scanning.
- (void)stopSerachDevice;

/// Returns the node ID for the current connection.
- (NSString *)currentConnectNodeId;

@end

