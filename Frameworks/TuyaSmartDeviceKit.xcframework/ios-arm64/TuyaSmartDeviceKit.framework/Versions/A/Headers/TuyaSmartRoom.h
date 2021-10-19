//
// TuyaSmartRoom.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartRoomModel.h"
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

@interface TuyaSmartRoom : NSObject

/// The room model.
@property (nonatomic, strong, readonly) TuyaSmartRoomModel *roomModel;

/// The device list.
@property (nonatomic, strong, readonly) NSArray <TuyaSmartDeviceModel *> *deviceList;

/// The group list.
@property (nonatomic, strong, readonly) NSArray <TuyaSmartGroupModel *> *groupList;


/// Returns the room instance.
///
/// @param roomId The room ID.
/// @param homeId The home ID.
/// @return The instance.
+ (instancetype)roomWithRoomId:(long long)roomId homeId:(long long)homeId;


/// Returns the room instance.
///
/// @param roomId The room ID.
/// @param homeId The home ID.
/// @return The instance.
- (instancetype)initWithRoomId:(long long)roomId homeId:(long long)homeId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;


/// Renames the room.
///
/// @param roomName    The room name.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)updateRoomName:(NSString *)roomName success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Edits the room icon.
///
/// @param icon The room icon.
/// @param success  Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIcon:(UIImage *)icon success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Adds a device to the room.
///
/// @param deviceId    The device ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addDeviceWithDeviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Removes a device from the room.
///
/// @param deviceId    The device ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Adds a group to the room.
///
/// @param groupId     The group ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addGroupWithGroupId:(NSString *)groupId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Removes a group from the room
///
/// @param groupId     The group ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeGroupWithGroupId:(NSString *)groupId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Modifies the relationships between rooms, groups, and devices in a call.
///
/// @param deviceGroupList  A list of devices or groups.
/// @param success          Called when the task is finished.
/// @param failure          Called when the task is interrupted by an error.
- (void)saveBatchRoomRelationWithDeviceGroupList:(NSArray <NSString *> *)deviceGroupList
                                         success:(TYSuccessHandler)success
                                         failure:(TYFailureError)failure;


@end
