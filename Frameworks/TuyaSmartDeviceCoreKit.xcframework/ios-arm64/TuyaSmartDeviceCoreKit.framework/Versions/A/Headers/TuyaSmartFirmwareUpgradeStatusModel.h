//
// TuyaSmartFirmwareUpgradeStatusModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartDeviceModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

/// The device firmware update status.
@interface TuyaSmartFirmwareUpgradeStatusModel : NSObject

/// The firmware update status.
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;
/// The firmware type.
@property (nonatomic, assign) NSInteger type;
/// The firmware update description.
@property (nonatomic, copy) NSString *statusText;
/// The title of the firmware update description.
@property (nonatomic, copy) NSString *statusTitle;

@end

NS_ASSUME_NONNULL_END
