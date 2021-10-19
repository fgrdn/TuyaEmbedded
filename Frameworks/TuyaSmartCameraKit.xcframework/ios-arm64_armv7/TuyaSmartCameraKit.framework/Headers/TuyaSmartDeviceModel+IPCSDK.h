//
//  TuyaSmartDeviceModel+IPCSDK.h
//  TuyaSmartCameraKit
//
//  Created by 傅浪 on 2020/11/16.
//

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
#import <TuyaSmartCameraKit/TuyaSmartCameraKit.h>

@interface TuyaSmartDeviceModel (IPCSDK)

/// Whether device is an IPC
- (BOOL)isIPCDevice;

/// Whether device is a low power device
- (BOOL)isLowPowerDevice;

/// p2p type of the ipc device
- (NSInteger)p2pType;

- (NSArray *)rangeForEnumDpName:(TuyaSmartCameraDPKey)dpName;

- (TuyaSmartSchemaModel *)schemaModelForDpName:(TuyaSmartCameraDPKey)dpName;

- (NSArray *)rangeForEnumDpCode:(TuyaSmartCameraDPKey)dpCode;

- (TuyaSmartSchemaModel *)schemaModelForDpCode:(TuyaSmartCameraDPKey)dpCode;

/// Whether device is support multi play
- (BOOL)isSupportMultiPlay;

@end

