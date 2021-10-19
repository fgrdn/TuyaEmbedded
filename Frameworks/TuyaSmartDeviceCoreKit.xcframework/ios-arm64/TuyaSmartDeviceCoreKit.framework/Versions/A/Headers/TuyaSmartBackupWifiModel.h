//
// TuyaSmartBackupWifiModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBackupWifiModel : NSObject

@property (nonatomic, strong) NSString *ssid;
@property (nonatomic, strong) NSString *hashValue;
@property (nonatomic, strong) NSString *password;

+ (NSString *)getBase64HashValueWithLocalKey:(NSString *)localKey ssid:(NSString *)ssid psw:(NSString *)psw;

@end

NS_ASSUME_NONNULL_END
