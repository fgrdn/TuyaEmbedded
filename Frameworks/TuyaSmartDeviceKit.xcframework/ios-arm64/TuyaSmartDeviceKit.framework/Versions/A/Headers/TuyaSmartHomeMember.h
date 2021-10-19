//
// TuyaSmartHomeMember.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeMemberModel.h"
#import "TuyaSmartHomeMemberRequestModel.h"

@interface TuyaSmartHomeMember : NSObject

#pragma mark - public


/// Removes a home member.
///
/// @param memberId    The member ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeHomeMemberWithMemberId:(long long)memberId
                             success:(TYSuccessHandler)success
                             failure:(TYFailureError)failure;



/// Updates the home member information.
///
/// @param memberRequestModel The request model. Set the required properties.
/// @param success            Called when the task is finished.
/// @param failure            Called when the task is interrupted by an error.
- (void)updateHomeMemberInfoWithMemberRequestModel:(TuyaSmartHomeMemberRequestModel *)memberRequestModel
                                           success:(TYSuccessHandler)success
                                           failure:(TYFailureError)failure;


/// Returns a list of optional rooms.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
 - (void)getAuthRoomListWithHomeId:(long long)homeID
                         memberID:(long long)memberID
                          success:(TYSuccessList)success
                          failure:(TYFailureError)failure;

/// Returns a list of optional scenes or automations.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getAuthSceneListWithHomeID:(long long)homeID
                          memberID:(long long)memberID
                           success:(TYSuccessList)success
                           failure:(TYFailureError)failure;


/// Updates a list of rooms to which custom roles have access.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param roomIDs A list of room IDs with permissions.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
 - (void)saveAuthRoomListWithHomeId:(long long)homeID
                          memberID:(long long)memberID
                           roomIDs:(NSArray <NSNumber *> *)roomIDs
                           success:(TYSuccessID)success
                           failure:(TYFailureError)failure;


/// Updates a list of scenes to which custom roles have access.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param ruleIDs A list of scene IDs with permissions.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)saveAuthSceneListWithHomeId:(long long)homeID
                           memberID:(long long)memberID
                            ruleIDs:(NSArray <NSString *> *)ruleIDs
                            success:(TYSuccessID)success
                            failure:(TYFailureError)failure;

@end
