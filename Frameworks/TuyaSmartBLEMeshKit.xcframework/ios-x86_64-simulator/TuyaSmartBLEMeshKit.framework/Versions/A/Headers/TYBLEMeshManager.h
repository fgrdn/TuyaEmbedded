//
// TYBLEMeshManager.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TYBLEMeshManager
#define TuyaSmart_TYBLEMeshManager

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "TYBleMeshDeviceModel.h"
#import "TYBLEMeshCommand.h"

#define kInitMeshName @"out_of_mesh"

NS_ASSUME_NONNULL_BEGIN

@class TYBLEMeshManager;

/// The Bluetooth LE mesh delegate that is instantiated when the Bluetooth LE mesh manager performs a specific action and receives messages.
@protocol TYBLEMeshManagerDelegate <NSObject>

@optional

/// The callback of the Bluetooth status.
/// @param status The Bluetooth status.
- (void)centralManagerStatusChange:(CBManagerState)status;

/// The callback that is used to activate a sub-device.
/// @param name The device name.
/// @param deviceId The device ID.
/// @param error An error occurs while activating the sub-device. The values of `name' and 'deviceid' are empty in the response.
- (void)activeDeviceSuccessWithName:(NSString *)name deviceId:(NSString *)deviceId error:(NSError *)error;

/// The callback that is used when a sub-device is activated.
/// @param manager The value of TYBLEMeshManager.
/// @param device The value of TYBleMeshDeviceModel.
/// @param devId The device ID.
/// @param error An error occurs while activating the sub-device. The values of `name' and 'deviceid' are empty in the response.
- (void)bleMeshManager:(TYBLEMeshManager *)manager didActiveSubDevice:(TYBleMeshDeviceModel *)device devId:(NSString *)devId error:(NSError *)error;

/// The callback that is used to activate a gateway device.
/// @param name The device name.
/// @param address The device address.
/// @param mac The gateway MAC.
/// @param error An error occurs while processing the request.
- (void)activeWifiDeviceWithName:(NSString *)name address:(NSInteger)address mac:(NSInteger)mac error:(NSError *)error;

/// The callback that is used when a device failed to be activated.
/// @param manager The value of TYBLEMeshManager.
/// @param device The device.
/// @param error An error occurs while processing the request.
- (void)bleMeshManager:(TYBLEMeshManager *)manager didFailToActiveDevice:(TYBleMeshDeviceModel *)device error:(NSError *)error;

/// The callback that is used when the activation is completed.
- (void)didFinishToActiveDevList;

/// The callback that is used when a device is disconnected.
- (void)notifyCentralManagerDidDisconnectPeripheral;

/// The callback of the version number.
/// @param version The version number.
- (void)notifyFirmwareWithVersion:(NSString *)version;

/// The notification of login success. Updates are required.
/// @param address The address of the connected device.
- (void)notifyLoginSuccessWithAddress:(uint32_t)address;

/// The callback of group operations. For example, this callback is used when devices are added to or deleted from the group.
/// @param address The device address.
/// @param error An error occurs while managing the devices in the group.
- (void)deviceAddGroupAddress:(uint32_t)address error:(NSError *)error;

/// Scans the devices to be paired.
/// @param manager The value of TYBLEMeshManager.
/// @param device The value of TYBleMeshDeviceModel.
- (void)bleMeshManager:(TYBLEMeshManager *)manager didScanedDevice:(TYBleMeshDeviceModel *)device;

- (void)notifyQueryGroupAddress:(uint32_t)localId nodeId:(uint32_t)nodeId;

/// The callback that is used when a mesh network is connected. This enables subsequent local communication.
- (void)didConnectMeshNodeAndLoginMesh;

@end

/// @brief The Bluetooth mesh manager supports common Bluetooth mesh management classes and enables multiple functions. For example, the classes can be called to create groups, send control commands, and remove devices.
///
/// A large number of extension APIs are available to support various methods and scenarios.
///
@interface TYBLEMeshManager : NSObject

/// The shared instance.
+ (instancetype)sharedInstance;

/// Indicates the Bluetooth status of the system.
@property (nonatomic, assign) BOOL isPoweredOn;

/// Indicates the mesh connection status.
@property (nonatomic, assign) BOOL isLogin;

/// Indicates whether a Wi-Fi device is activated.
@property (nonatomic, assign) BOOL isWifiDevice;

/// Returns the node address of the Wi-Fi device if it is activated.
@property (nonatomic, assign) uint32_t wifiAddress;

/// Returns the node address of the device that receives and installs over-the-air (OTA) updates.
@property (nonatomic, assign) uint32_t otaAddress;

/// The service set identifier (SSID) of the activator.
@property (nonatomic, strong) NSString *ssid;

/// The password of the activator.
@property (nonatomic, strong) NSString *password;

/// The token of the activator.
@property (nonatomic, strong) NSString *token;

/// The device authorization key (AuthKey) that is used for activation.
@property (nonatomic, strong) NSString *authKey;

/// The UUID of the mesh node.
@property (nonatomic, strong) NSString *uuid;

/// The product of the mesh node.
@property (nonatomic, strong) NSString *productId;

/// The version of the mesh device.
@property (nonatomic, strong) NSString *version;

/// Adds a Wi-Fi address.
@property (nonatomic, assign) uint32_t wifiMac;

/// The delegate of the Bluetooth LE mesh manager.
@property (nonatomic, weak) id<TYBLEMeshManagerDelegate> delegate;

/// The mesh entrance.
/// To pair the device, enter the default mesh name and password. In this case, only the value of 
/// `-(void) blemeshmanager: (tyblemeshmanager *) manager didscaneddevice: (tyblemeshdevicemodel *) device;` is returned as the scanning result.
/// @param name The mesh name.
/// @param pwd The mesh password.
/// @param active Specifies whether to activate the gateway for pairing.
/// @param wifiAddress The Wi-Fi address that is used for gateway pairing. Set the value to `0` for other operations.
/// @param otaAddress The device address for OTA updates. Set the value to `0` for other operations.
- (void)startScanWithName:(NSString *)name
                      pwd:(NSString *)pwd
                   active:(BOOL)active
              wifiAddress:(uint32_t)wifiAddress
               otaAddress:(uint32_t)otaAddress;

/// Activates the device.
/// @param includeGateway Specifies whether to activate the gateway. If the value is set to `yes`, the scanned gateway device is activated and the sub-devices are not activated.
/// If the value is set to `no`, all scanned sub-devices are activated and the gateway is not activated.
- (void)activeMeshDeviceIncludeGateway:(BOOL)includeGateway;

/// Activates a specific device.
/// @param deviceModel The device model.
- (void)activeMeshDevice:(TYBleMeshDeviceModel *)deviceModel;

/// Stops activating devices.
- (void)stopActiveDevice;

- (void)getLightAllStatus;
- (BOOL)isConnected;
- (void)stopScan;
- (void)clearScanData;

/// Sends a command.
/// @param command The command.
- (void)sendCommand:(TYBLEMeshCommand *)command;

/// Writes Wi-Fi information to the gateway. This method is automatically called after activation with the SDK.
/// @param ssid The name of the router hotspot.
/// @param pwd The password of the router hotspot.
/// @param token The pairing token.
- (void)startConfigWiFiWithSsid:(NSString *)ssid
                            pwd:(NSString *)pwd
                          token:(NSString *)token;

/// Reads the firmware version number.
- (void)readFirmwareFeature;

/// Sends the update package.
/// @param address The device address.
/// @param version The version.
/// @param otaData The OTA data.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendOTAPackWithAddress:(NSInteger)address
                       version:(NSString *)version
                       otaData:(NSData *)otaData
                       success:(TYSuccessHandler)success
                       failure:(TYFailureHandler)failure;

/// To get the mesh product name, you must associate the product with the app in advance. Otherwise, null is returned.
/// @param productId The product ID.
/// @param completion Completes the callback.
- (void)getProductNameByProductId:(NSString *)productId
                       completion:(void(^)(NSString *))completion;

@end

@interface TYBLEMeshManager (Command)

/// Sets the mode of the light (exclusive for the lighting class).
/// @param address The address.
/// @param type The device size class.
/// @param isGroup Indicates whether a group is used.
/// @param param The parameter.
- (void)setLightModelWithAddress:(uint32_t)address
                            type:(NSString *)type
                         isGroup:(BOOL)isGroup
                           param:(NSArray<NSString *> *)param;

/// Reads the scene mode of the light (exclusive for the lighting class).
/// @param address The device address.
/// @param type The device size class.
- (void)getLightSceneModelWithAddress:(uint32_t)address
                                 type:(NSString *)type;

/// Returns the state of the low-power contact sensor.
/// @param deviceAddress The device address.
/// @param dps The DPs.
/// @param type The type.
- (void)getSensorStateWithAddress:(uint32_t)deviceAddress
                              dps:(NSArray *)dps
                             type:(NSString *)type;

/// Adds a device to a group.
/// @param deviceAddress The device address.
/// @param type The type.
/// @param groupAddress The group address.
- (void)addDeviceAddress:(uint32_t)deviceAddress
                    type:(NSString *)type
            groupAddress:(uint32_t)groupAddress;

/// Removes a device from a group.
/// @param deviceAddress The device address.
/// @param type The type.
/// @param groupAddress The group address.
- (void)deleteDeviceAddress:(uint32_t)deviceAddress
                       type:(NSString *)type
               groupAddress:(uint32_t)groupAddress;

/// Deletes a group from the mesh network.
/// @param groupAddress The group address.
/// @param type The group type.
- (void)deleteGroupAddress:(uint32_t)groupAddress
                      type:(NSString *)type;

- (NSMutableArray<NSString *> *)findAllDevicesByVendorIdArray:(NSArray *)vendorIdArray;

/// Returns the group address for the device.
/// @param deviceAddress The device address.
/// @param type The type.
- (void)getGroupAddressWithDeviceAddress:(uint32_t)deviceAddress
                                    type:(NSString *)type;

/// Returns all devices in a group.
/// @param groupAddress The group address.
/// @param type The group type.
- (void)getDevicesAddressWithGroupAddress:(uint32_t)groupAddress
                                     type:(NSString *)type;

/// Removes a device from the mesh network.
/// @param address The device address.
/// @param type The type.
- (void)kickoutLightWithAddress:(uint32_t)address
                           type:(NSString *)type;

/// Returns the status of a device, such as the RGB of a light.
/// @param address The device address.
/// @param type The type.
- (void)getDeviceStatusAllWithAddress:(uint32_t)address
                                 type:(NSString *)type;

/// Returns the countdown data of a device (exclusive for electrical devices).
/// @param address The device address.
/// @param type The type.
- (void)getDeviceCountdownWithAddress:(uint32_t)address
                                 type:(NSString *)type;

@end

@interface TYBLEMeshManager (Raw)

/** The commands are sent and controlled through the gateway. */

/// Deletes a group from the mesh network.
/// @param groupAddress The group address.
/// @param type The type.
- (NSString *)rawDataDeleteGroupAddress:(uint32_t)groupAddress
                                   type:(NSString *)type;

/// Removes a device from a group.
/// @param deviceAddress The device address.
/// @param groupAddress The group address.
/// @param type The type.
- (NSString *)rawDataDeleteDeviceAddress:(uint32_t)deviceAddress
                            groupAddress:(uint32_t)groupAddress
                                    type:(NSString *)type;

/// Adds a device to a group.
/// @param deviceAddress The device address.
/// @param groupAddress The group address.
/// @param type The type.
- (NSString *)rawDataAddDeviceAddress:(uint32_t)deviceAddress
                         groupAddress:(uint32_t)groupAddress
                                 type:(NSString *)type;

/// Returns all devices in the specified group.
/// @param groupAddress The group address.
/// @param type The type.
- (NSString *)rawDataGetDevicesAddressWithGroupAddress:(uint32_t)groupAddress
                                                  type:(NSString *)type;

/// Kicks a device out of the mesh network.
/// @param address The device address.
/// @param type The type.
- (NSString *)rawDataKickoutLightWithAddress:(uint32_t)address
                                        type:(NSString *)type;

/// Returns the status of the specified device.
/// @param address The device address.
/// @param type The type.
- (NSString *)rawDataGetStatusAllWithAddress:(uint32_t)address
                                        type:(NSString *)type;

/// Returns the device countdown (exclusive for electrical devices).
/// @param address Teh device address.
/// @param type The type.
- (NSString *)rawDataCountDownWithAddress:(uint32_t)address
                                     type:(NSString *)type;

@end

#endif

NS_ASSUME_NONNULL_END
