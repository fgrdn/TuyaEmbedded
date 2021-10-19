//
// TuyaSmartSIGMeshManager.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The type of Bluetooth mesh manager for inactive and active devices.
typedef NS_ENUM(NSUInteger, TuyaSmartSIGScanType) {
    /// Scans devices that are not paired.
    ScanForUnprovision,
    /// Scans paired devices.
    ScanForProxyed,
};

@class TuyaSmartSIGMeshManager;

@class TuyaSmartSIGMeshDiscoverDeviceInfo;

/// The delegate of the Bluetooth mesh manager. The delegate is instantiated when the Bluetooth mesh manager processes messages.
@protocol TuyaSmartSIGMeshManagerDelegate <NSObject>

@optional;

/// The callback that is used when a sub-device is activated.
/// @param manager The value of TuyaSmartSIGMeshManager.
/// @param device The value of TuyaSmartSIGMeshDiscoverDeviceInfo.
/// @param devId The device ID.
/// @param error An error occurs while activating the sub-device. The values of `name' and 'deviceid' are empty in the response.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didActiveSubDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device devId:(NSString *)devId error:(NSError *)error;

/// The callback that is used when a device failed to be activated.
/// @param manager The value of TuyaSmartSIGMeshManager.
/// @param device The value of TuyaSmartSIGMeshDiscoverDeviceInfo.
/// @param error An error occurs while activating the device.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didFailToActiveDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device error:(NSError *)error;

/// The callback that is used when the activation is completed.
- (void)didFinishToActiveDevList;

/// The callback that is used when a device is disconnected.
- (void)notifyCentralManagerDidDisconnectPeripheral;

/// Scans a device for pairing.
/// @param manager The value of TuyaSmartSIGMeshManager.
/// @param device The value of TuyaSmartSIGMeshDiscoverDeviceInf.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didScanedDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device;

/// Completes the group operation.
/// @param manager The value of TuyaSmartSIGMeshManager.
/// @param groupAddress The group mesh address in the hexadecimal format.
/// @param nodeId The device mesh node address in the hexadecimal format.
/// @param error An error occurs while processing the request.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didHandleGroupWithGroupAddress:(NSString *)groupAddress deviceNodeId:(NSString *)nodeId error:(NSError *)error;

- (void)newSigMeshManager:(TuyaSmartSIGMeshManager *)manager didHandleGroupWithGroupAddress:(NSString *)groupAddress deviceNodeId:(NSString *)nodeId error:(NSError *)error;

/// Queries a list of device groups.
/// @param manager The value of TuyaSmartSIGMeshManager.
/// @param groupList A list of group addresses.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager
        queryGroupList:(NSArray<NSString *> *)groupList
           deviceModel:(TuyaSmartDeviceModel *)deviceModel
                 error:(NSString * _Nullable)error;

/// The notification of login success. This parameter is required for an update.
- (void)notifySIGLoginSuccess;

/// The callback that is used when a mesh network is connected. This enables subsequent local communication.
- (void)didConnectMeshNodeAndLoginMesh;

- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager queryDeviceModel:(TuyaSmartDeviceModel *)deviceModel groupAddress:(uint32_t)groupAddress;

// Returns the values of `opCode` and `payload`.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didReceivedCustomOpCodeData:(NSData *)opCode payload:(NSData *)payload;

// A list of model IDs to be managed over the mesh network.
- (NSArray<NSNumber *> *)listOfCustomModelIdWithSigMeshManager:(TuyaSmartSIGMeshManager *)manager;

@end


/// @brief The Bluetooth mesh manager supports common Bluetooth mesh management classes and enables multiple functions. For example, the classes can be called to create groups, send control commands, and remove devices.
///
/// A large number of extension APIs are available to support various methods and scenarios.
/// 
@interface TuyaSmartSIGMeshManager : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, assign, readonly) BOOL isLogin;

@property (nonatomic, strong) TuyaSmartBleMesh *sigMesh;

@property (nonatomic, weak) id<TuyaSmartSIGMeshManagerDelegate> delegate;

@property (nonatomic, copy) NSString *otaTargetNodeId; /// The node ID of the updated device.

@end

NS_ASSUME_NONNULL_END
