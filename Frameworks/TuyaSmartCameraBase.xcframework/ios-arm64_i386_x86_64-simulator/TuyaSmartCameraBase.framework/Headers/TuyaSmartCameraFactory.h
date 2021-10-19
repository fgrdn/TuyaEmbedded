//
//  TuyaSmartCameraFactory.h
//  TYCameraLibrary
//
//  Created by 傅浪 on 2018/7/6.
//  Copyright © 2018 TuyaSmart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuyaSmartCameraType.h"

typedef NS_ENUM(NSUInteger, TuyaSmartCameraP2PType) {
    TuyaSmartCameraP2PTypeTUTK = 1,
    TuyaSmartCameraP2PTypePPCS,
    TuyaSmartCameraP2PTypeTUYA
};

@interface TuyaSmartCameraConfig : NSObject

/**
 [^en]
 device id of the camera
 [$en]
 
 [^zh]
 设备id
 [$zh]
 */
@property (nonatomic, strong) NSString *devId;

/**
 [^en]
 Get the configuration data through the "tuya.m.ipc.config.get" api, the value of the "p2pId" field in the data.
 [$en]
 
 [^zh]
 请求 "tuya.m.ipc.config.get" api得到的配置数据中的"p2pId" 字段
 [$zh]
 */
@property (nonatomic, strong) NSString *p2pId;

/**
 [^en]
 Get the configuration data through the "tuya.m.ipc.config.get" api, the value of the "password" field in the data.
 [$en]

 [^zh]
 请求 "tuya.m.ipc.config.get" api得到的配置数据中的"password" 字段
 [$zh]
 */
@property (nonatomic, strong) NSString *password;

/**
 [^en]
 Get the configuration data through the "tuya.m.ipc.config.get" api, the value of the "p2pConfig" field in the data.if there is no "p2pConfig" field, set nil.
 [$en]

 [^zh]
 请求 "tuya.m.ipc.config.get" api得到的配置数据中的"p2pConfig" 字段, 如果不存在 "p2pConfig" 字段，则置为nil
 [$zh]
 */
@property (nonatomic, strong) NSDictionary *p2pConfig;

/**
 [^en]
 Get the configuration data through the "tuya.m.ipc.config.get" api, the value of the "p2pSpecifiedType" field in the data.
 [$en]

 [^zh]
 请求 "tuya.m.ipc.config.get" api得到的配置数据中的"p2pSpecifiedType" 字段
 [$zh]
 */
@property (nonatomic, assign) NSInteger p2pSpecifiedType;

/**
 [^en]
 The "localKey" property in the TuyaSmartDeviceModel object corresponding to the camera device.
 [$en]

 [^zh]
 camera 的 TuyaSmartDeviceModel 对象中的 "localKey" 属性
 [$zh]
 
 */
@property (nonatomic, strong) NSString *localKey;

/**
 [^en]
 TuyaSmartUser.uid
 [$en]

 [^zh]
 TuyaSmartUser 的 uid 属性
 [$zh]
 */
@property (nonatomic, strong) NSString *uid;

/**
 [^en]
 camera station sub device info
  
  NSDictionary *dic = @{@"did" : stationDid,
  @"subDid" : listDevicDid};
 [$en]

 [^zh]
 camera 基站子设备信息
 
 NSDictionary *dic = @{@"did" : stationDid,
 @"subDid" : listDevicDid};
 [$zh]
 */
@property (nonatomic, strong) NSDictionary *subDic;

// [^en]private log trace id[$en] [^zh]私有日志的traceId[$zh]
@property (nonatomic, strong) NSString *traceId;

/// 是否走局域网通道
@property (nonatomic, assign) BOOL isLocalChannel;

/// skills of camera device
@property (nonatomic, strong) NSString *skills;

@end

@protocol TuyaSmartCameraMaker <NSObject>

+ (void)resetSocket;

+ (void)userDidLogOut;

+ (BOOL)handleP2PType:(id)type;

+ (id<TuyaSmartCameraType>)createCameraWithConfig:(TuyaSmartCameraConfig *)ipcConfig delegate:(id<TuyaSmartCameraDelegate>)delegate;

+ (id<TuyaSmartCameraType>)createCameraWithDeviceId:(NSString *)devId delegate:(id<TuyaSmartCameraDelegate>)delegate;

@end

@interface TuyaSmartCameraFactory : NSObject

+ (void)initSDKs __deprecated_msg("SDK will auto init when create camera instance");

+ (void)resetSocket;

+ (void)userDidLogOut;

/**
 [^en]
 get the camera sdk version
 [$en]

 [^zh]
 获取 camera sdk 版本
 [$zh]
 */
+ (NSString *)tuyaSmartCameraVersion;

/**
 [^en]
 create a camera instance
 [$en]

 [^zh]
 创建一个camera实例
 [$zh]

 @param type [^en]p2p type，pass the value of the "p2pType" field in the "skills" attribute of the "TuyaSmartDeviceModel" object corresponding to the camera device.[$en] [^zh]p2p 类型，传递camera设备的"TuyaSmartDeviceModel"对象的"skills"属性中的"p2pType"字段[$zh]
 
 @param ipcConfig camera config
 @param delegate delgate
 @return camera instance
 */
+ (id<TuyaSmartCameraType>)cameraWithP2PType:(id)type config:(TuyaSmartCameraConfig *)ipcConfig delegate:(id<TuyaSmartCameraDelegate>)delegate;

/**
[^en]
create a camera instance
[$en]

[^zh]
创建一个camera实例
[$zh]

@param type [^en]p2p type，pass the value of the "p2pType" field in the "skills" attribute of the "TuyaSmartDeviceModel" object corresponding to the camera device.[$en] [^zh]p2p 类型，传递camera设备的"TuyaSmartDeviceModel"对象的"skills"属性中的"p2pType"字段[$zh]

@param devId device id
@param delegate delgate
@return camera instance
*/
+ (id<TuyaSmartCameraType>)cameraWithP2PType:(id)type deviceId:(NSString *)devId delegate:(id<TuyaSmartCameraDelegate>)delegate;


/**
 [^en]
 create a camera config instance
 [$en]

 [^zh]
 创建一个camera配置实例
 [$zh]

 @param uid [^en]User identifier from [TuyaSmartUser sharedInstance].uid[$en] [^zh]使用 [TuyaSmartUser sharedInstance].uid[$zh]
 @param localKey [^en]from TuyaSmartDeviceModel.localKey[$en] [^zh]使用 TuyaSmartDeviceModel.localKey[$zh]
 @param data [^en]the respond data of API  "tuya.m.ipc.config.get"[$en] [^zh]请求"tuya.m.ipc.config.get" API 返回的数据[$zh]
 @return [^en]camera config[$en] [^zh]camera config对象[$zh]
*/
+ (TuyaSmartCameraConfig *)ipcConfigWithUid:(NSString *)uid localKey:(NSString *)localKey configData:(NSDictionary *)data;

#pragma mark - private, ignore this

+ (NSMutableArray<Class<TuyaSmartCameraMaker>> *)cameraMakers;
+ (void)registerCameraMaker:(Class<TuyaSmartCameraMaker>)maker;

@end
