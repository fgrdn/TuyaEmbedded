//
// TuyaSmartLanMessageModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The local network message.
@interface TuyaSmartLanMessageModel : NSObject

/// The protocol.
@property (nonatomic, assign) NSInteger    protocol;

/// The device ID.
@property (nonatomic, strong) NSString     *devId;

/// The message body.
@property (nonatomic, strong) NSDictionary *body;

/// The message data.
@property (nonatomic, strong) NSData       *data;

@end

NS_ASSUME_NONNULL_END
