//
// TuyaSmartGroup.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartGroup
#define TuyaSmart_TuyaSmartGroup

#import <Foundation/Foundation.h>
#import "TuyaSmartGroupModel.h"
#import "TuyaSmartGroupDevListModel.h"

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartGroup;

/// The delegate of the TuyaSmartGroup class provides the callback of group status updates.
@protocol TuyaSmartGroupDelegate<NSObject>

@optional

/// The update of group DPs data.
/// @param group The instance of TuyaSmartGroup.
/// @param dps The DPs.
- (void)group:(TuyaSmartGroup *)group dpsUpdate:(NSDictionary *)dps;

/// The group information update.
/// @param group The instance of TuyaSmartGroup.
- (void)groupInfoUpdate:(TuyaSmartGroup *)group;

/// Removes the group.
/// @param groupId The group ID.
- (void)groupRemove:(NSString *)groupId;

/// The update of group DP data.
/// @param group The instance of TuyaSmartGroup.
/// @param dpCodes The DP codes.
- (void)group:(TuyaSmartGroup *)group dpCodesUpdate:(NSDictionary *)dpCodes;

/// The group response of Zigbee devices that join the gateway. `1`: exceeds the scenario limit. `2`: sub-device timeout. `3`: specified value out of range. `4`: file writing error. `5`: other errors.
/// @param group The instance of TuyaSmartGroup.
/// @param responseCode The response code.
- (void)group:(TuyaSmartGroup *)group addResponseCode:(NSArray <NSNumber *>*)responseCode;

/// The group response of Zigbee devices that are removed from the gateway. `1`: exceeds the scenario limit. `2`: sub-device timeout. `3`: specified value out of range. `4`: file writing error. `5`: other errors.
/// @param group The instance of TuyaSmartGroup.
/// @param responseCode The response code.
- (void)group:(TuyaSmartGroup *)group removeResponseCode:(NSArray <NSNumber *>*)responseCode;

@end

/// @brief The group of smart devices allows you to create groups, send group commands, and update basic group information.
///
/// You can add multiple devices with the same functions to a group and simultaneously control the devices.
///
@interface TuyaSmartGroup : NSObject

/// Returns the basic group information model.
@property (nonatomic, strong, readonly) TuyaSmartGroupModel *groupModel;

@property (nonatomic, weak, nullable) id<TuyaSmartGroupDelegate> delegate;

/// Returns the TuyaSmartGroup instance.
/// @param groupId The group ID.
+ (nullable instancetype)groupWithGroupId:(NSString *)groupId;

/// Returns the TuyaSmartGroup instance.
/// @param groupId The group ID.
- (nullable instancetype)initWithGroupId:(NSString *)groupId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Returns the device list that belongs to the specified group based on productId.
/// @param productId The product ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevList:(NSString *)productId
           success:(nullable void(^)(NSArray <TuyaSmartGroupDevListModel *> *list))success
           failure:(nullable TYFailureError)failure;

/// Sends group control commands.
/// @param dps The DPs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDps:(NSDictionary *)dps success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Renames the group name.
/// @param name The group name.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateGroupName:(NSString *)name success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Edits the group icon.
/// @param icon The group icon.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIcon:(UIImage *)icon
           success:(nullable TYSuccessHandler)success
           failure:(nullable TYFailureError)failure;

/// Edits the group icon.
/// @param cloudKey The cloud key.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIconWithCloudKey:(NSString *)cloudKey
                       success:(nullable TYSuccessHandler)success
                       failure:(nullable TYFailureError)failure;

/// Modifies the device list of the group.
/// @param devList The device list.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateGroupRelations:(NSArray <NSString *>*)devList
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;

/// Removes the group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)dismissGroup:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;


#pragma mark - zigbee

#if TARGET_OS_IOS

/// Adds sub-devices to groups that locally interact with gateways.
/// @param nodeList A list of sub-device node IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSubDeviceWithSubDeviceNodeList:(NSArray <NSString *>*)nodeList
                                  success:(nullable TYSuccessHandler)success
                                  failure:(nullable TYFailureError)failure;

/// Removes sub-devices from groups that locally interact with gateways.
/// @param nodeList  A list of sub-device node IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeSubDeviceWithSubDeviceNodeList:(NSArray <NSString *>*)nodeList
                                     success:(nullable TYSuccessHandler)success
                                     failure:(nullable TYFailureError)failure;

#endif

/// Cancels the request.
- (void)cancelRequest;


@end

NS_ASSUME_NONNULL_END

#endif
