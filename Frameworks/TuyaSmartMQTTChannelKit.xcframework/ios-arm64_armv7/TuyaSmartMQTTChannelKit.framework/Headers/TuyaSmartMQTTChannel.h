//
//  TuyaSmartMQTTChannel.h
//  TuyaSmartMQTTChannelKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import "TuyaSmartMQTTConfigModel.h"

@interface TuyaSmartPublishMessageModel : NSObject

@property (nonatomic, strong) NSString          *devId;

@property (nonatomic, assign) NSTimeInterval    time; // The timestamp.
@property (nonatomic, assign) NSInteger         protocol; // The protocol.
@property (nonatomic, assign) double            pv; // The version.
@property (nonatomic, strong) NSDictionary      *body; // The body.
@property (nonatomic, strong) NSString          *localKey; // The local key.
@property (nonatomic, assign) NSInteger         publishS;// The sequence.
@property (nonatomic, assign) NSInteger         publishR;// The publishing ID.

@end

@interface TuyaSmartResponseMessageModel : NSObject

@property (nonatomic, strong) NSString          *devId;
@property (nonatomic, strong) id                message;  // The mesh array.
@property (nonatomic, assign) NSInteger         protocol; // The protocol.
@property (nonatomic, strong) NSString          *type;
@property (nonatomic, assign) NSInteger         responseS;// The sequence.
@property (nonatomic, assign) NSInteger         responseR;// The response ID.
@property (nonatomic, assign) NSTimeInterval    time;

@end

@class TuyaSmartMQTTChannel;

/**
 The MQTT connection state.
 */
typedef NS_ENUM (NSInteger, TuyaSmartMqttConnectState){
    TuyaSmartMqttConnectStateCreated,
    TuyaSmartMqttConnectStateConnecting,
    TuyaSmartMqttConnectStateConnected,
    TuyaSmartMqttConnectStateDisconnecting,
    TuyaSmartMqttConnectStateClose,
    TuyaSmartMqttConnectStateError,
};

@protocol TuyaSmartMQTTChannelDelegate <NSObject>

@optional

/**
 *  The callback of changes in the MQTT connection channel states.
 */
- (void)mqttChannel:(TuyaSmartMQTTChannel *)mqttChannel connectState:(TuyaSmartMqttConnectState)connectState error:(NSError *)error;

/**
 *  Receives the MTQQ data.
 */
- (void)mqttChannel:(TuyaSmartMQTTChannel *)mqttChannel didReceiveMessage:(TuyaSmartResponseMessageModel *)message topic:(NSString *)topic;

@end


@interface TuyaSmartMQTTChannel : NSObject

+ (instancetype)sharedInstance;

/**
 *  Connects to the MQTT host.
 *
 *  @param mqttConfig The configuration of the MQTT connection.
 */
- (void)startConnectToHostWithMqttConfig:(TuyaSmartMQTTConfigModel *)mqttConfig;

/**
 *  Disconnects from the MQTT host.
 */
- (void)close;

/**
 *  The MQTT connection state.
 */
- (TuyaSmartMqttConnectState)connectState;

/**
 *  Subscribes to a topic.
 *
 *  @param topic   The topic.
 *  @param success Called when the task is finished.
 *  @param failure Called when the task is interrupted by an error.
 */
- (void)subscribeToTopic:(NSString *)topic
                 devInfo:(NSDictionary *)devInfo
                 success:(TYSuccessHandler)success
                 failure:(TYFailureError)failure;

/**
 *  Unsubscribes from a topic.
 *
 *  @param topic   The topic.
 *  @param success Called when the task is finished.
 *  @param failure Called when the task is interrupted by an error.
 */
- (void)unsubscribeToTopic:(NSString *)topic
                   success:(TYSuccessHandler)success
                   failure:(TYFailureError)failure;

/**
 *  Publishes the MQTT data.
 *
 *  @param data    The data.
 *  @param topic   The topic.
 *  @param success Called when the task is finished.
 *  @param failure Called when the task is interrupted by an error.
 *  @return The message identifier of the published message. A value of `zero` is returned at the QoS level 0. A message identifier is returned at the QoS level 1 or 2.
 */
- (UInt16)publishMessage:(NSData *)data
                   topic:(NSString *)topic
                 success:(TYSuccessHandler)success
                 failure:(TYFailureError)failure;

/**
 *  Publishes MQTT data.
 *
 *  @param messageModel The message model.
 *  @param topic        The topic.
 *  @param success      Called when the task is finished.
 *  @param failure      Called when the task is interrupted by an error.
 */
- (void)publishMessageWithMessageModel:(TuyaSmartPublishMessageModel *)messageModel
                                 topic:(NSString *)topic
                               success:(TYSuccessHandler)success
                               failure:(TYFailureError)failure;

/**
 *  Adds an MQTT channel delegate.
 *
 *  @param delegate Delegate
 */
- (void)addDelegate:(id<TuyaSmartMQTTChannelDelegate>)delegate;

/**
 *  Removes an MQTT channel delegate.
 *
 *  @param delegate The delegate.
 */
- (void)removeDelegate:(id<TuyaSmartMQTTChannelDelegate>)delegate;

@end
