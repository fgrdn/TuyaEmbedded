//
// TuyaSmartHome.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeModel.h"
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
#import "TuyaSmartRoomModel.h"
#import "TuyaSmartHomeMemberModel.h"
#import "TuyaSmartHomeAddMemberRequestModel.h"

@class TuyaSmartHome;

@protocol TuyaSmartHomeDelegate <NSObject>

@optional


/// The delegate of home update information, such as the name and online status.
///
/// @param home The instance.
- (void)homeDidUpdateInfo:(TuyaSmartHome *)home;

/// The delegate of updates on the shared device list.
///
/// @param home The instance.
- (void)homeDidUpdateSharedInfo:(TuyaSmartHome *)home;


/// The delegate that is instantiated when a new room is added.
///
/// @param home The instance.
/// @param room The room model.
- (void)home:(TuyaSmartHome *)home didAddRoom:(TuyaSmartRoomModel *)room;


/// The delegate that is instantiated when an existing room is removed.
///
/// @param home The instance.
/// @param roomId The room ID.
- (void)home:(TuyaSmartHome *)home didRemoveRoom:(long long)roomId;


/// The delegate of room update information, such as the name.
///
/// @param home The instance.
/// @param room The room model.
- (void)home:(TuyaSmartHome *)home roomInfoUpdate:(TuyaSmartRoomModel *)room;


/// The delegate of updates on the relationship among rooms, groups, and devices.
///
/// @param home The instance.
/// @param room The room model.
- (void)home:(TuyaSmartHome *)home roomRelationUpdate:(TuyaSmartRoomModel *)room;


/// The delegate that is instantiated when a new device is added.
///
/// @param home The instance.
/// @param device The device model.
- (void)home:(TuyaSmartHome *)home didAddDeivice:(TuyaSmartDeviceModel *)device;


/// The delegate that is instantiated when an existing device is removed.
///
/// @param home The instance.
/// @param devId The device ID
- (void)home:(TuyaSmartHome *)home didRemoveDeivice:(NSString *)devId;


/// The delegate of device update information, such as the name.
///
/// @param home The instance.
/// @param device The device model.
- (void)home:(TuyaSmartHome *)home deviceInfoUpdate:(TuyaSmartDeviceModel *)device;


/// The delegate of device DPs update.
///
/// @param home The instance.
/// @param device The device model.
/// @param dps The DPs.
- (void)home:(TuyaSmartHome *)home device:(TuyaSmartDeviceModel *)device dpsUpdate:(NSDictionary *)dps;


/// The delegate of warning information updates.
///
/// @param home The instance.
/// @param device The device model.
/// @param warningInfo The warning information.
- (void)home:(TuyaSmartHome *)home device:(TuyaSmartDeviceModel *)device warningInfoUpdate:(NSDictionary *)warningInfo;


/// The delegate of changes in device firmware update status.
///
/// @param home The home instance.
/// @param device The device model.
/// @param upgradeStatusModel The update status model.
- (void)home:(TuyaSmartHome *)home device:(TuyaSmartDeviceModel *)device firmwareUpgradeStatusModel:(TuyaSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;


/// The delegate of over-the-air (OTA) updates for homes or shared devices.
/// @param home The home instance.
/// @param otaModelList The OTA model list.
- (void)home:(TuyaSmartHome *)home didUpdateOTAModelList:(NSArray<TuyaSmartDeviceOTAModel *> *)otaModelList;

/// The delegate that is instantiated when a new group is added.
///
/// @param home The instance.
///  @param group The group model.
- (void)home:(TuyaSmartHome *)home didAddGroup:(TuyaSmartGroupModel *)group;


/// The delegate of group DP updates.
///
/// @param home The instance.
/// @param group The group model.
/// @param dps The DPs.
- (void)home:(TuyaSmartHome *)home group:(TuyaSmartGroupModel *)group dpsUpdate:(NSDictionary *)dps;


/// The delegate that is instantiated when a group is removed.
///
/// @param home The instance.
/// @param groupId The group ID.
- (void)home:(TuyaSmartHome *)home didRemoveGroup:(NSString *)groupId;


/// The delegate of the group update information, such as the name.
///
/// @param home The instance.
/// @param group The group model.
- (void)home:(TuyaSmartHome *)home groupInfoUpdate:(TuyaSmartGroupModel *)group;

#pragma mark - deprecated

/// The delegate of the update on the relationship between homes and rooms. (deprecated)
///
/// @param home The instance.
/// @deprecated This method is deprecated. Use TuyaSmartHomeDelegate::home:didAddRoom: or TuyaSmartHomeDelegate::home:didRemoveRoom: instead.
- (void)homeDidUpdateRoomInfo:(TuyaSmartHome *)home __deprecated_msg("Use -[TuyaSmartHomeDelegate home:didAddRoom:] or [TuyaSmartHomeDelegate home:didRemoveRoom:] instead.");

/// The delegate of changes in device firmware update status.
///
/// @param home The instance.
/// @param device The device model.
/// @param upgradeStatus The update status.
/// @deprecated This method is deprecated. Use TuyaSmartHomeDelegate::home:device:firmwareUpgradeStatusModel: instead.
- (void)home:(TuyaSmartHome *)home device:(TuyaSmartDeviceModel *)device upgradeStatus:(TuyaSmartDeviceUpgradeStatus)upgradeStatus __deprecated_msg("This method is deprecated, Use home:device:firmwareUpgradeStatusModel: instead");

@end

@interface TuyaSmartHome : NSObject

@property (nonatomic, weak) id <TuyaSmartHomeDelegate> delegate;

@property (nonatomic, strong, readonly) TuyaSmartHomeModel *homeModel;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartRoomModel *> *roomList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceModel *> *deviceList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartGroupModel *> *groupList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceModel *> *sharedDeviceList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartGroupModel *>  *sharedGroupList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceOTAModel *> *deviceOtaList;

/// Initializes the home.
///
/// @param homeId The home ID.
/// @return The instance.
+ (instancetype)homeWithHomeId:(long long)homeId;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Home

/// After the home object is initialized, you must get the details of the home, homeModel, roomList, deviceList, and groupList to set the data.
/// @param success Called when the task is finished. TuyaSmartHomeModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomeDetailWithSuccess:(void (^)(TuyaSmartHomeModel *homeModel))success
                         failure:(TYFailureError)failure;

/// After the home details are returned, the device OTA update status is changed.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure  Called when the task is interrupted by an error.
- (void)getDeviceOTAStatusWithHomeId:(long long)homeId
                             success:(void (^)(NSArray<TuyaSmartDeviceOTAModel *> *))success
                             failure:(TYFailureError)failure;


/// Updates the home information. API version 2.0 is used.
///
/// @param homeName    The home name.
/// @param geoName     The city name.
/// @param latitude    The latitude.
/// @param longitude   The longitude.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                       success:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;



/// Updates the home information. API version 3.0 is used.
///
/// @param homeName    The home name.
/// @param geoName     The city name.
/// @param latitude    The latitude.
/// @param longitude   The longitude.
/// @param rooms       The array of room names.
/// @param overWriteRoom     NSDictionary only supports "overWriteRoom":boolean.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                         rooms:(NSArray *)rooms
                 overWriteRoom:(BOOL)overWriteRoom
                       success:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;


/// Removes a home.
///
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)dismissHomeWithSuccess:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;


/// Sorts devices and groups for the home.
/// @param orderList The order list [@{@"bizId": @"XXX", @"bizType": @"XXX"},@{@"bizId": @"XXX",@"bizType": @"XXX"}], where bizId is the device's device ID or group's group ID, device's bizType = @"6" group's bizType = @"5".
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sortDeviceOrGroupWithOrderList:(NSArray<NSDictionary *> *)orderList
                               success:(TYSuccessHandler)success
                               failure:(TYFailureError)failure;


#pragma mark - Room


/// Adds a new room.
///
/// @param name        The room name.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addHomeRoomWithName:(NSString *)name
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;


/// Remove a room
///
/// @param roomId      The home ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeHomeRoomWithRoomId:(long long)roomId
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;


/// Sorts the homes.
///
/// @param roomList    A list of homes.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)sortRoomList:(NSArray <TuyaSmartRoomModel *> *)roomList
             success:(TYSuccessHandler)success
             failure:(TYFailureError)failure;


#pragma mark - home member

/// Returns a list of home members
///
/// @param success     Called when the task is finished. A list of TuyaSmartHomeMemberModel is returned.
/// @param failure     Called when the task is interrupted by an error.
- (void)getHomeMemberListWithSuccess:(void(^)(NSArray <TuyaSmartHomeMemberModel *> *memberList))success
                             failure:(TYFailureError)failure;


/// Adds a home member.
///
/// @param requestModel The member model.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)addHomeMemberWithAddMemeberRequestModel:(TuyaSmartHomeAddMemberRequestModel *)requestModel
                                        success:(TYSuccessDict)success
                                        failure:(TYFailureError)failure;

/// Accepts or rejects to share the home.
///
/// @param accept       A Boolean value that specifies whether to accept the invitation.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)joinFamilyWithAccept:(BOOL)accept
                     success:(TYSuccessBOOL)success
                     failure:(TYFailureError)failure;


/// Synchronizes the home device list.
///
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)syncHomeDeviceListWithSuccess:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;

@end
