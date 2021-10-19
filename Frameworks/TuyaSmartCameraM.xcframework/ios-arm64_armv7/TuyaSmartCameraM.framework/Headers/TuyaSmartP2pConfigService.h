//
//  TuyaSmartP2pConfigService.h
//  TuyaSmartCameraM
//
//  Created by 傅浪 on 2020/10/26.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartCameraBase/TuyaSmartCameraType.h>

@class TuyaSmartDeviceModel;
@interface TuyaSmartP2pConfigService : NSObject

/// 获取 p2p config，如果本地有缓存，会从缓存获取
+ (void)requestConfigWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel
                             traceId:(NSString *)traceId
                             success:(void(^)(NSDictionary *config, BOOL fromCache))success
                             failure:(void(^)(NSInteger errCode))failure;

/// 获取缓存的 p2p config
+ (NSDictionary *)getCachedConfigWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel;
/// 将 p2p config 缓存到本地
+ (void)cacheConfig:(NSDictionary *)config forDeviceModel:(TuyaSmartDeviceModel *)deviceModel;
/// 移除本地缓存的 p2p config
+ (void)removeCachedConfigForDeviceModel:(TuyaSmartDeviceModel *)deviceModel;

@end

