//
// TuyaSmartDeviceModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartDeviceModel
#define TuyaSmart_TuyaSmartDeviceModel

#import "TuyaSmartSchemaModel.h"
#import "TuyaSmartDeviceModuleModel.h"
#import "TuyaSmartStandSchemaModel.h"
#import "TuyaSmartCommunication.h"

/// The device types.
typedef enum : NSUInteger {
    
    /// Wi-Fi
    TuyaSmartDeviceModelTypeWifiDev,
    
    /// Single Point Bluetooth Device
    TuyaSmartDeviceModelTypeBle,
    
    /// GPRS
    TuyaSmartDeviceModelTypeGprs,
    
    /// NB-IoT
    TuyaSmartDeviceModelTypeNBIoT,
    
    /// Zigbee Gateway
    TuyaSmartDeviceModelTypeZigbeeGateway,
    
    /// Zigbee subDevice
    TuyaSmartDeviceModelTypeZigbeeSubDev,
    
    /// Mesh
    TuyaSmartDeviceModelTypeMeshBleSubDev,
    
    /// Infrared gateway
    TuyaSmartDeviceModelTypeInfraredGateway,
    
    /// Infrared subDevice
    TuyaSmartDeviceModelTypeInfraredSubDev,
    
    /// Wi-Fi Gateway
    TuyaSmartDeviceModelTypeWifiGateway,
    
    /// Wi-Fi subDevice
    TuyaSmartDeviceModelTypeWifiSubDev,
    
    /// SIG Mesh Gateway
    TuyaSmartDeviceModelTypeSIGMeshGateway,
    
    /// SIG Mesh subDevice
    TuyaSmartDeviceModelTypeSIGMeshSubDev,

    /// Ble Beacon
    TuyaSmartDeviceModelTypeBeacon,
    
    /// Cat.1
    TuyaSmartDeviceModelTypeCat1,
} TuyaSmartDeviceModelType;


typedef NS_OPTIONS(NSUInteger, TuyaSmartDeviceOnlineType) {
    /// Offline
    TuyaSmartDeviceOnlineTypeOffline = 0,
    /// Wi-Fi online
    TuyaSmartDeviceOnlineTypeWifi = 1 << 0,
    /// Local online
    TuyaSmartDeviceOnlineTypeLan = 1 << 1,
    /// Bluetooth LE online
    TuyaSmartDeviceOnlineTypeBLE = 1 << 2,
    /// Bluetooth LE mesh online
    TuyaSmartDeviceOnlineTypeMeshBLE = 1 << 3
};

/// The information about the device.
@interface TuyaSmartDeviceModel : NSObject

/// The ID of the device.
@property (nonatomic, strong) NSString     *devId;

/// The name of the device.
@property (nonatomic, strong) NSString     *name;

/// The URL of the device icon.
@property (nonatomic, strong) NSString     *iconUrl;

/// The capability of the device.
@property (nonatomic, assign) NSInteger    ability;

/// Specifies whether the device is online.
@property (nonatomic, assign) BOOL         isOnline;

/// Specifies whether the device is connected to the cloud.
@property (nonatomic, assign) BOOL         isCloudOnline;

@property (nonatomic, assign) TuyaSmartDeviceOnlineType onlineType;

/// The communication information, the information about the gateway sub-devices and mesh-like device communication nodes, the communication priority, and the device connectivity.
@property (nonatomic, strong) TuyaSmartCommunication *communication;

/// Specifies whether the device is shared.
@property (nonatomic, assign) BOOL         isShare;

@property (nonatomic, strong) NSString     *verSw;

/// The DP of the device.
@property (nonatomic, strong) NSDictionary *dps;

/// The DP execution time of the device.
@property (nonatomic, strong) NSDictionary *dpsTime;

/// The product ID.
@property (nonatomic, strong) NSString     *productId;

/// Specifies whether to support groups.
@property (nonatomic, assign) BOOL         supportGroup;

/// Specifies whether to support standard groups.
@property (nonatomic, assign) BOOL         supportSGroup;

/// The type of gateway.
@property (nonatomic, strong) NSString     *gwType;

/// The protocol version of the gateway.
@property (nonatomic, assign) double       pv;

#if TARGET_OS_IOS

/// The LAN online status.
@property (nonatomic, assign) BOOL         isLocalOnline;

/// The LAN gateway protocol version.
@property (nonatomic, assign) double       lpv;

#endif

/// The hardware baseline version.
@property (nonatomic, assign) double       bv;

/// The latitude of the device.
@property (nonatomic, strong) NSString     *latitude;

/// The longitude of the device.
@property (nonatomic, strong) NSString     *longitude;

/// The DP name.
@property (nonatomic, strong) NSDictionary *dpName;

/// The schema of the device.
@property (nonatomic, strong) NSString     *schema;
@property (nonatomic, strong) NSString     *schemaExt;
@property (nonatomic, strong) NSArray<TuyaSmartSchemaModel *> *schemaArray;

@property (nonatomic, strong) NSString     *runtimeEnv;

/// The attribute.
@property (nonatomic, assign) NSUInteger   attribute;

@property (nonatomic, strong) NSString     *localKey;

@property (nonatomic, strong) NSString     *uuid;

/// The media access control address.
@property (nonatomic, strong) NSString     *mac;

/// The network communication capability. Valid values: `0`: Wi-Fi. `1`: wired. `2`: GPRS. `3`: NB-IoT. `10`: Bluetooth. `11`: Bluetooth mesh. `12`: Zigbee.
@property (nonatomic, assign) NSUInteger   capability;

@property (nonatomic, strong) NSString     *timezoneId;

@property (nonatomic, assign) long long    homeId;
@property (nonatomic, assign) long long    roomId;
@property (nonatomic, assign) long long    sharedTime;

/// The order.
@property (nonatomic, assign) NSInteger    displayOrder;
@property (nonatomic, assign) NSInteger    homeDisplayOrder;

@property (nonatomic, strong) NSString     *ip;

/// The skills.
@property (nonatomic, strong) NSDictionary *skills;

@property (nonatomic, strong) NSString     *cloudId;

#pragma mark - panel

@property (nonatomic, assign) BOOL         rnFind;
@property (nonatomic, assign) long long    i18nTime;
@property (nonatomic, strong) NSString     *ui;
@property (nonatomic, strong) NSString     *uiId;
@property (nonatomic, strong) NSString     *uiVersion;
@property (nonatomic, strong) NSString     *uiPhase;
@property (nonatomic, strong) NSString     *uiType;
@property (nonatomic, strong) NSString     *uiName;
@property (nonatomic, strong) NSDictionary *uiConfig;
@property (nonatomic, strong) NSDictionary *panelConfig;
@property (nonatomic, strong) NSString     *category;
@property (nonatomic, strong) NSString     *categoryCode;
@property (nonatomic, strong) NSArray      *quickOpDps;
@property (nonatomic, strong) NSArray      *displayDps;
@property (nonatomic, strong) NSArray      *faultDps;
@property (nonatomic, strong) NSDictionary *displayMsgs;
@property (nonatomic, strong) NSString     *switchDp __deprecated_msg("Use switchDps instead");
@property (nonatomic, strong) NSArray<NSNumber *> *switchDps;

/// creates a dictionary containing entries constructed from `self.switchDps` and `self.dps`
- (NSDictionary<NSString *, NSNumber *> *)switchDpsMap;
/// return `or` operation on all values from `self.switchDpsMap`
- (BOOL)switchDpsValue;

/// creates a dictionary containing entries constructed from `self.switchDps` and `dps`
/// @param dps the dps which contains the dp value
- (NSDictionary<NSString *, NSNumber *> *)switchDpsMapFromDps:(NSDictionary<NSString *, id> *)dps;

/// return `or` operation on all values from  `self.switchDps` and `dps`
/// @param dps the dps which contains the dp value
- (BOOL)switchDpsValueFromDps:(NSDictionary<NSString *, id> *)dps;

@property (nonatomic, assign) BOOL         isNewFirmware;
@property (nonatomic, assign) NSTimeInterval activeTime;
@property (nonatomic, assign) long         errorCode;

@property (nonatomic, assign) TuyaSmartDeviceModelType deviceType;
@property (nonatomic, assign) BOOL         upgrading  __deprecated_msg("Use TuyaSmartDeviceOTAModel.otaUpgradeStatus instead");

@property (nonatomic, strong) NSDictionary *originJson;

@property (nonatomic, strong) TuyaSmartDeviceModuleModel *moduleMap;

@property (nonatomic, assign) NSUInteger    bizAttribute;

@property (nonatomic, strong) NSDictionary *meta;

- (BOOL)attributeIsSupport:(NSUInteger)i;
- (BOOL)capabilityIsSupport:(NSUInteger)i;
- (BOOL)devAttributeIsSupport:(NSUInteger)i;
- (BOOL)baseAttributeIsSupport:(NSUInteger)i;
- (BOOL)protocolAttributeIsSupport:(NSUInteger)i;

#pragma mark - subdevice
/// The node ID.
@property (nonatomic, strong) NSString     *nodeId;
@property (nonatomic, strong) NSString     *parentId;

/// The information about Bluetooth mesh.
@property (nonatomic, strong) NSString     *vendorInfo;
@property (nonatomic, assign) BOOL         isMeshBleOnline;
@property (nonatomic, strong) NSString     *pcc;

#pragma mark - discovery device
/// Mark:  0: 1<<0 auto. 3: 1<<3 route.
@property (nonatomic, assign) NSUInteger devAttribute;

/// The Bluetooth mesh device key.
@property (nonatomic, strong) NSString     *devKey;

/// Specifies whether to standardize the schema.
@property (nonatomic, assign) BOOL standard;
@property (nonatomic, strong) TuyaSmartStandSchemaModel *standSchemaModel;

/// The DP codes.
@property (nonatomic, strong, readonly) NSDictionary *dpCodes;

/// The last DP update time.
@property (nonatomic, assign) NSTimeInterval dpMaxTime;

/// Specifies whether the device is a virtual device.
@property (nonatomic, assign) BOOL isVirtualDevice;

// Use `baseAttributeIsSupport: index` to check the feature.
//
// Index rules:
// 9: Tuya Bluetooth mesh device.
// 10: supports network checks.
@property (nonatomic, assign) NSUInteger baseAttribute;

// Use `protocolAttributeIsSupport: index` to check the feature.
//
// Index rules:
// 0: supports the Bluetooth mesh feature.
// 1: supports the Zigbee feature.
// 2: supports the subpieces feature.
@property (nonatomic, assign) NSInteger protocolAttribute;

/// Specifies whether automatic updates are supported. Currently, NB-IoT and Bluetooth mesh devices do not support automatic updates.
@property (nonatomic, assign) BOOL supportAuto;

/// Supports the following over-the-air (OTA) update methods that are listed in descending priority from left to right:
/// `0`: Wi-Fi. `1`: Bluetooth LE. `2`: Bluetooth mesh. `3`: NB-IoT.
@property (nonatomic, strong) NSArray *otaUpgradeModes;

/// The Bluetooth connection configuration.
@property (nonatomic, strong) NSDictionary *configMetas;

@end

#endif
