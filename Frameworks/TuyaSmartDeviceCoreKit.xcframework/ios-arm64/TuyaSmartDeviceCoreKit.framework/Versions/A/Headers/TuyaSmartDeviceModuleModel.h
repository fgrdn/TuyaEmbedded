//
// TuyaSmartDeviceModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_BleMeshSubDeviceModuleModel
#define TuyaSmart_BleMeshSubDeviceModuleModel

#import <Foundation/Foundation.h>
#import "TuyaSmartDeviceModelUtils.h"

/// The microcontroller unit (MCU) device.
@interface TuyaSmartDeviceMcuModel : NSObject

@property (nonatomic, assign) BOOL     isOnline;
@property (nonatomic, strong) NSString *verSw;

@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;

@end

/// The Zigbee device.
@interface TuyaSmartDeviceZigbeeModel : NSObject

@property (nonatomic, assign) BOOL     isOnline;
@property (nonatomic, strong) NSString *verSw;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;

@end

/// The Bluetooth device.
@interface TuyaSmartDeviceBluetoothModel : NSObject

@property (nonatomic, assign) BOOL          isOnline;
@property (nonatomic, strong) NSString      *verSw;
@property (nonatomic, strong) NSString      *pv;
@property (nonatomic, strong) NSString      *type;
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;

@end

/// The Wi-Fi device.
@interface TuyaSmartDeviceWifiModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *cadv;
@property (nonatomic, strong) NSString     *cdv;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;

@end

/// The infrared device.
@interface TuyaSmartDeviceInfraredModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *cadv;
@property (nonatomic, strong) NSString     *cdv;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;

@end

/// The GPRS device.
@interface TuyaSmartDeviceGprsModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;

@end

/// The subpieces.
@interface TuyaSmartDeviceSubpiecesModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;

@end

/// The NB-IoT device.
@interface TuyaSmartDeviceNBIoTModel : NSObject

@property (nonatomic, assign) BOOL         isOnline;
@property (nonatomic, strong) NSString     *bv;
@property (nonatomic, strong) NSString     *pv;
@property (nonatomic, strong) NSString     *verSw;
@property (nonatomic, strong) NSString     *type;
@property (nonatomic, assign) NSInteger    upgradeStatus;

@end

/// The device module.
@interface TuyaSmartDeviceModuleModel : NSObject

@property (nonatomic, strong) TuyaSmartDeviceWifiModel           *wifi;
@property (nonatomic, strong) TuyaSmartDeviceNBIoTModel          *nbIot;
@property (nonatomic, strong) TuyaSmartDeviceBluetoothModel      *bluetooth;
@property (nonatomic, strong) TuyaSmartDeviceMcuModel            *mcu;
@property (nonatomic, strong) TuyaSmartDeviceGprsModel           *gprs;
@property (nonatomic, strong) TuyaSmartDeviceZigbeeModel         *zigbee;
@property (nonatomic, strong) TuyaSmartDeviceInfraredModel       *infrared;
@property (nonatomic, strong) TuyaSmartDeviceSubpiecesModel      *subpieces;

@end

#endif
