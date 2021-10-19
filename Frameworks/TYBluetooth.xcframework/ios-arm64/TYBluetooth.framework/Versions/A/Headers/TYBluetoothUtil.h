//
//  TYBluetoothUtil.h
//  TYBluetooth
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYBluetoothUtil : NSObject

+ (void)storeAdvertisingData:(NSDictionary *)advertisingData pIdentifier:(NSString *)pIdentifier;

+ (NSDictionary *)getAdvertisingDataWithIdentifier:(NSString *)pIdentifier;

+ (void)storeSNWithUUID:(NSString *)uuid sn:(NSInteger)sn;

+ (int)getSNWithUUID:(NSString *)uuid;

+ (void)removeAdvertisingDataWithIdentifier:(NSString *)pIdentifier uuid:(NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
