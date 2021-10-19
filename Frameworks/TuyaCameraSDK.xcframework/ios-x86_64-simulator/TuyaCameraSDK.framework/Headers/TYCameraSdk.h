//
//  TYSmartCameraSdk.h
//  TYCameraSdk
//
//  Created by Jim on 2018/4/3.
//  Copyright © 2018年 Tuya. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TYCamera.h"

typedef void (^TYMQTTSender)(BOOL LANmode, NSString *remoteId, NSString *signal);
typedef void (^TYApmLogSender)(NSString *eventName, NSString *value);
typedef void (^TYNativeLogSender)(NSInteger level, NSString *module, const char *file, const char *function, NSUInteger line, NSString *message);
typedef void (^TYFullLinkLogSender)(NSString *type, NSDictionary *attribute, NSDictionary *infos, NSString *trackType, NSString *identifier);

typedef void (^TYHttpsRequest)(NSString *api, NSString *devId, NSDictionary *postData);

@interface TYCameraSdk : NSObject

+(int)initLogModuleWithApmLogSender:(TYApmLogSender)apmLogSender
                    nativeLogSender:(TYNativeLogSender)nativeLogSender
                  fullLinkLogSender:(TYFullLinkLogSender)fullLinkLogSender;

+(void)deinitLogModule;

/**
 Description 初始化sdk(p2p使用ppcs)，initSDKWithServerString/initSDKWithLocalId只需调用其一

 @param serverString 服务器string
 */
+(int)initP2pModuleV1WithServerString:(NSString *)serverString;

// 清理P2pModuleV1模块
+(void)deinitP2pModuleV1;

/**
 Description 初始化sdk(p2p使用tuya)，initSDKWithServerString/initSDKWithLocalId只需调用其一

 @param localId localId
 @param mqttSender 需要外部调用MQTT send操作
 */
+(void)initP2pModuleV2WithLocalId:(NSString *)localId mqttSendBlock:(TYMQTTSender)mqttSender;

/**
 Description 初始化sdk(p2p使用tuya)，initSDKWithServerString/initSDKWithLocalId只需调用其一

 @param localId localId
 @param mqttSender 需要外部调用MQTT send操作
 @param httpsRequest 需要外部发起云端接口请求       for p2p preconnect
 */
+(void)initP2pModuleV2WithLocalId:(NSString *)localId mqttSendBlock:(TYMQTTSender)mqttSender httpsRequest:(TYHttpsRequest)httpsRequest;

// 清理P2pModuleV2模块
+(void)deinitP2pModuleV2;

// 初始化云存储、视频消息模块
+(int)initCloudModule;

+(int)deinitCloudModule;

// 清理所有module
+(void)deinitAllModules;

+(int)SetMqttMsg:(const char *)msg length:(int)nLen;

+(int)setHttpsResponseWithApi:(const char *)api code:(int)code content:(const char *)content;

// tymedia 初始化
+(void)initTymedia;
+(void)deinitTymedia;

+(int)setLoudspeakerStatus:(bool)enable ;
+(bool)getLoudspeakerStatus;


// 软件使能标志 debug only
+(bool)getSoftDecodeEnableStatus ;                          // 获取当前设置的状态
+(void)setSoftDecodeEnableStatusWithStatus:(bool) status ;  // 设置软件解码优先状态
+(bool)getCurVideoSoftDecodeStatus ;                        // 获取当前视频真正是否使用软件

+(NSString *)getSystemVersion;

@end
