//
// TuyaSmartHomeDeviceShare.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <UIKit/UIKit.h>
#import "TuyaSmartShareMemberModel.h"
#import "TuyaSmartShareMemberDetailModel.h"
#import "TuyaSmartReceiveMemberDetailModel.h"
#import "TuyaSmartShareDeviceModel.h"
#import "TuyaSmartDeviceShareModel.h"


/// Shares devices based on device types.
@interface TuyaSmartHomeDeviceShare : NSObject

/// Adds a device to be shared.
/// @param requestModel Adds a device model to be shared.
/// @param success Called when the task is finished. TuyaSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addDeviceShareWithRequestModel:(TuyaSmartDeviceShareRequestModel *)requestModel
                               success:(void(^)(TuyaSmartShareMemberModel *model))success
                               failure:(TYFailureError)failure;


/// Adds extra devices to be shared. The existing shared devices are not overwritten.
/// @param memberId The member ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addShareWithMemberId:(NSInteger)memberId
                      devIds:(NSArray <NSString *> *)devIds
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;


/// Returns all users who initiate device sharing for a home.
/// @param homeId The home ID.
/// @param success Called when the task is finished. A list of TuyaSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getShareMemberListWithHomeId:(long long)homeId
                             success:(void(^)(NSArray<TuyaSmartShareMemberModel *> *list))success
                             failure:(TYFailureError)failure;


/// Returns all users who receive shared devices.
/// @param success Called when the task is finished. A list of TuyaSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getReceiveMemberListWithSuccess:(void(^)(NSArray<TuyaSmartShareMemberModel *> *list))success
                                failure:(TYFailureError)failure;


/// Returns the shared device data of a single user who initiates sharing.
/// @param memberId The member ID.
/// @param success Called when the task is finished. TuyaSmartShareMemberDetailModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getShareMemberDetailWithMemberId:(NSInteger)memberId
                                 success:(void(^)(TuyaSmartShareMemberDetailModel *model))success
                                 failure:(TYFailureError)failure;


/// Returns the shared device data of a single user who receives shared devices.
/// @param memberId The member ID.
/// @param success Called when the task is finished. TuyaSmartShareMemberDetailModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getReceiveMemberDetailWithMemberId:(NSInteger)memberId
                                   success:(void(^)(TuyaSmartReceiveMemberDetailModel *model))success
                                   failure:(TYFailureError)failure;



/// Removes users who initiate device sharing.
/// @param memberId The member ID.
/// @param success  Called when the task is finished.
/// @param failure  Called when the task is interrupted by an error.
- (void)removeShareMemberWithMemberId:(NSInteger)memberId
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Removes users who receive shared devices.
/// @param memberId The member ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeReceiveShareMemberWithMemberId:(NSInteger)memberId
                                     success:(TYSuccessHandler)success
                                     failure:(TYFailureError)failure;


/// Changes the nickname of the user who initiates device sharing.
/// @param memberId The member ID.
/// @param name The nickname.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)renameShareMemberNameWithMemberId:(NSInteger)memberId
                                     name:(NSString *)name
                                  success:(TYSuccessHandler)success
                                  failure:(TYFailureError)failure;


/// Changes the nickname of the user who receives shared devices.
/// @param memberId The member ID.
/// @param name The nickname.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)renameReceiveShareMemberNameWithMemberId:(NSInteger)memberId
                                            name:(NSString *)name
                                         success:(TYSuccessHandler)success
                                         failure:(TYFailureError)failure;


#pragma mark -


/// Deletes the device that is shared.
/// @param memberId The member ID.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeDeviceShareWithMemberId:(NSInteger)memberId
                                devId:(NSString *)devId
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Returns a list of users who share a specific device.
/// @param devId The device ID.
/// @param success Called when the task is finished. A list of TuyaSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceShareMemberListWithDevId:(NSString *)devId
                                  success:(void(^)(NSArray<TuyaSmartShareMemberModel *> *list))success
                                  failure:(TYFailureError)failure;


/// Sends an invitation to other users to share a device.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)inviteShareWithCountryCode:(NSString *)countryCode
                       userAccount:(NSString *)userAccount
                             devId:(NSString *)devId
                           success:(TYSuccessInt)success
                           failure:(TYFailureError)failure;


/// Confirms the sharing invitation.
/// @param shareId The shareId that is returned by the sharing invitation API operation.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)confirmInviteShareWithShareId:(NSInteger)shareId
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;

#pragma mark - Group Share

/// Returns a list of device-sharing users by group ID. The group ID is displayed on the panel.
/// @param groupId The group ID.
/// @param success Called when the task is finished. A list of TuyaSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getGroupShareMemberListWithGroupId:(NSString *)groupId
                                   success:(void(^)(NSArray<TuyaSmartShareMemberModel *> *list))success
                                   failure:(TYFailureError)failure;


/// Shares groups to other users.
/// @param homeId The home ID.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addGroupShareToMemberWithHomeId:(long long)homeId
                             countyCode:(NSString *)countryCode
                            userAccount:(NSString *)userAccount
                                groupId:(NSString *)groupId
                                success:(TYSuccessID)success
                                failure:(TYFailureError)failure;

/// Removes the device sharing group from a member.
/// @param relationId The member ID.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeGroupShareWithRelationId:(NSInteger)relationId
                               groupId:(NSString *)groupId
                               success:(TYSuccessHandler)success
                               failure:(TYFailureError)failure;

@end
