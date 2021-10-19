//
//  TYP2PSdk.h
//  TuyaCameraSDK
//
//  Created by xu cunshu on 2020/12/17.
//  Copyright © 2020 Tuya. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void (^TYMQTTSender)(BOOL LANmode, NSString *remoteId, NSString *signal);
typedef void (^TYApmLogSender)(NSString *eventName, NSString *value);
typedef void (^TYNativeLogSender)(NSInteger level, NSString *module, const char *file, const char *function, NSUInteger line, NSString *message);
typedef void (^TYFullLinkLogSender)(NSString *type, NSDictionary *attribute, NSDictionary *infos, NSString *trackType, NSString *identifier);
typedef void (^TYHttpsRequest)(NSString *api, NSString *devId, NSDictionary *postData);

@interface TYP2PSdk : NSObject
+(int)initLoggerWithApmLogSender:(TYApmLogSender)apmLogSender
                    nativeLogSender:(TYNativeLogSender)nativeLogSender
                  fullLinkLogSender:(TYFullLinkLogSender)fullLinkLogSender;

+(void)deinitLogModule;

/**
    Description get the p2p version.
 */
+(int)getVersion;

/**
    Description init the p2p module.

    @param localId : The local Id
    @param mqttSender :
 */
+(int)initWithLocalId:(NSString*)localId mqttSendBlock:(TYMQTTSender)mqttSender httpsRequest:(TYHttpsRequest)httpsRequest;

/**
    Description deinit the p2p module.
 */
+(int)deInit;

/**
    Description : connect to the device such as camera.
    @param remoteId : the did
    @param token : token for p2p connect
    @param traceId : traceId for p2p connect
    @param lanMode :    0  -- not lan mode
                        1  -- lan mode
    @param timeout : time out for connect operation.
 
    @return retcode >= 0: handle, retcode < 0: error code
 */
+(int)connectWithRemoteId:(NSString*)remoteId token:(NSString*)token traceId:(NSString*)traceId lanMode:(int)lanMode timeout:(int)timeout;

/**
    Description : break connect while connecting .
    @param traceId : traceId for p2p connect
    
 */
+(int)connectBreakWithTraceId:(NSString*)traceId ;

/**
    Description : disconnect with the device
    @param handle  : handle .The return value of connect operation.
 */
+(int)disConnectWithHandle:(int)handle ;

/**
    Description     : read data from p2p channel.
    @param handle   : handle .The return value of connect operation.
    @param channel  : the p2p channel
    @param buffer   : buffer pointer
    @param bufferLen : len of buffer
    @param timeOut  : timeout in ms
    @return
                    < 0 错误发生 返回TUYA_P2P_ERROR_TIME_OUT（-3）表示超时，上层可以做重新读取操作。其他错误表示session已经断开
                    >= 0 实际读到的数据长度
 */
+(int)recvWithHandle:(int)handle channel:(int)channel buffer:(unsigned char*)buffer bufferLen:(int)bufferLen timeOut:(int)timeOut ;

/**
    Description     : send data from p2p channel.
    @param handle   : handle .The return value of connect operation.
    @param channel  : the p2p channel
    @param buffer   : buffer pointer
    @param bufferLen : len of buffer
    @param timeOut  : timeout in ms
    @return
                    < 0 错误发生  返回TUYA_P2P_ERROR_TIME_OUT（-3）表示超时，上层可以做重新发送操作。其他错误表示session已经断开
                    >= 0 发送成功的数据长度
*/
+(int)sendWithHandle:(int)handle channel:(int)channel buffer:(unsigned char*)buffer bufferLen:(int)bufferLen timeOut:(int)timeOut ;
/**
 Description     : send data from p2p channel.
 @param handle   : handle .The return value of connect operation.
 @param channel  : the p2p channel
 @param requestid   :requestid
 @param username :  username
 @param password  : password
 @param timeOut  : timeout in ms
 @return
                 < 0 错误发生  返回TUYA_P2P_ERROR_TIME_OUT（-3）表示超时，上层可以做重新发送操作。其他错误表示session已经断开
                 >= 0 发送成功的数据长度
 */
+(int)sendAuthorizationInfoWithHandle:(int)handle channel:(int)channel requestId:(int)requestid username:(NSString *)username password:(NSString*)password timeOut:(int)timeOut ;

/**
    Description     : set the p2p signaling msg
    @param  msg     : p2p signaling msg
    @param  msgLen  : msg length
*/
+(int)setSignalingWithMsg:(const char*)msg msgLen:(int)msgLen ;

/**
    Description     : ?
    @param remoteId   : the did .
 */
+(int)setRemoteOnlineWithHandle:(const char*)remoteId ;

/**
    Description     : check the p2p active or not
    @param handle   : handle .The return value of connect operation.
 */
+(int)activeCheckWithHandle:(int)handle ;

/**
 Description     : check the p2p active or not
 @param api :
 @param code :
 @param content :
 */
+(int)setHttpsResponseWithApi:(const char *)api code:(int)code content:(const char *)content;

@end

