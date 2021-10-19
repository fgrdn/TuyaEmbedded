//
//  TuyaSmartDeviceEventUtil.h
//  TuyaSmartDeviceCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TYEventPipelineType) {
    /// LAN
    TYEventPipelineTypeLAN      = 1,
    
    /// MQTT
    TYEventPipelineTypeMQTT     = 2,
    
    /// HTTP
    TYEventPipelineTypeHTTP     = 3,
    
    /// Single Point Bluetooth
    TYEventPipelineTypeBLE      = 4,
    
    /// Sig Mesh
    TYEventPipelineTypeSIGMesh  = 5,
    
    /// Tuya Private Mesh
    TYEventPipelineTypeBLEMesh  = 6,
    
    /// others
    TYEventPipelineTypeOther    = 9,
};


@interface TuyaSmartDeviceEventUtil : NSObject

/// The message sending request is successful.
///
/// @param pipelineType The message sending pipeline.
+ (void)successEventWithPipelineType:(TYEventPipelineType)pipelineType;

/// The message sending request failed.
///
/// @param pipelineType The message sending pipeline.
/// @param pv The device protocol version that is used when the message is sent.
/// @param error An error occurs while processing the request.
/// @param extendInfo Detailed error information, in which you can easily check the status of the error and the app condition.
+ (void)failedEventWithPipelineType:(TYEventPipelineType)pipelineType
                                 pv:(double)pv
                              error:(NSError *)error
                         extendInfo:(NSDictionary *)extendInfo;

/// The message for public demend
///
/// @param attribute The attribute dictionary.
+ (void)tysdkControlEventWithAttribute:(NSDictionary *)attribute;
@end

NS_ASSUME_NONNULL_END
