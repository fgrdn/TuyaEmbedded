//
// TuyaSmartGroup+Home.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface TuyaSmartGroup (Home)

/// Creates groups of Wi-Fi devices.
/// @param name The group name.
/// @param productId The product ID.
/// @param homeId The home ID.
/// @param devIdList A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)createGroupWithName:(NSString *)name
                  productId:(NSString *)productId
                     homeId:(long long)homeId
                  devIdList:(NSArray<NSString *> *)devIdList
                    success:(nullable void (^)(TuyaSmartGroup *group))success
                    failure:(nullable TYFailureError)failure;


/// Creates groups of Zigbee devices.
/// @param name The group name.
/// @param homeId The home ID.
/// @param gwId The gateway ID.
/// @param productId The product ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)createGroupWithName:(NSString *)name
                     homeId:(long long)homeId
                       gwId:(NSString *)gwId
                  productId:(NSString *)productId
                    success:(nullable void (^)(TuyaSmartGroup *))success
                    failure:(nullable TYFailureError)failure;

/// Returns a list of Zigbee sub-devices that are grouped by productId and gwId.
/// @param productId The product ID.
/// @param gwId The gateway ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDevListWithProductId:(NSString *)productId
                           gwId:(NSString *)gwId
                         homeId:(long long)homeId
                        success:(nullable void (^)(NSArray<TuyaSmartGroupDevListModel *> *))success
                        failure:(nullable TYFailureError)failure;

/// Returns a list of Wi-Fi devices that are grouped by productId.
/// @param productId The product ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDevList:(NSString *)productId
            homeId:(long long)homeId
           success:(nullable void(^)(NSArray <TuyaSmartGroupDevListModel *> *list))success
           failure:(nullable TYFailureError)failure;


#if TARGET_OS_IOS

/// Adds Zigbee devices to groups that locally interact with gateways.
/// @param nodeList A list of Zigbee sub-device node IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addZigbeeDeviceWithNodeList:(NSArray <NSString *>*)nodeList
                            success:(nullable TYSuccessHandler)success
                            failure:(nullable TYFailureError)failure;


/// Removes Zigbee devices from groups that locally interact with gateways.
/// @param nodeList A list of Zigbee sub-device node IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeZigbeeDeviceWithNodeList:(NSArray <NSString *>*)nodeList
                               success:(nullable TYSuccessHandler)success
                               failure:(nullable TYFailureError)failure;

#endif

@end

NS_ASSUME_NONNULL_END
