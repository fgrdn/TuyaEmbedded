//
// TuyaSmartBLEManager.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)


#import "TuyaSmartBeaconManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBeaconManager (Scan)

- (void)startScan;

- (void)stopScan;

@end

NS_ASSUME_NONNULL_END
