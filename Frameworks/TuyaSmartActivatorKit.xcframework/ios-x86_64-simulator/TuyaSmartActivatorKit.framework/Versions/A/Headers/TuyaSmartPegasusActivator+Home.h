//
// TuyaSmartPegasusActivator+Home.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartPegasusActivator (Home)

/// Returns the devices that support Pegasus.
/// @param homeID The home ID.
/// @return A list of devices that support Pegasus.
+ (NSArray <TuyaSmartDeviceModel *> *)pegasusDeviceListWithHomeID:(long long)homeID;


@end

NS_ASSUME_NONNULL_END
