//
// TuyaSmartMQTTMessageModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The MQTT message.
@interface TuyaSmartMQTTMessageModel : NSObject

/// The protocol.
@property (nonatomic, assign) NSInteger    protocol;

/// The message type.
@property (nonatomic, strong) NSString     *type;

/// The message data.
@property (nonatomic, strong) id           data;

/// The device ID.
@property (nonatomic, strong) NSString     *devId;

@end

NS_ASSUME_NONNULL_END
