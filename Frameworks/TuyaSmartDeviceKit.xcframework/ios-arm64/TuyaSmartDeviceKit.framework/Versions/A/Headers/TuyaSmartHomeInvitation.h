//
// TuyaSmartHomeInvitation.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeInvitation : NSObject

/// Invites new members by invitation code.
/// @param createRequestModel The request model.
/// @param success Called when the task is finished. TuyaSmartHomeInvitationResultModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)createInvitationWithCreateRequestModel:(TuyaSmartHomeInvitationCreateRequestModel *)createRequestModel
                                       success:(void(^)(TuyaSmartHomeInvitationResultModel *invitationResultModel))success
                                       failure:(TYFailureError)failure;

/// Cancels an invitation.
/// @param invitationID The invitation ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelInvitationWithInvitationID:(NSNumber *)invitationID
                                 success:(TYSuccessBOOL)success
                                 failure:(TYFailureError)failure;

/// Reinvites members.
/// @param reinviteRequestModel The reinvitation request model.
/// @param success Called when the task is finished. TuyaSmartHomeInvitationResultModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)reinviteInvitationWithReinviteRquestModel:(TuyaSmartHomeInvitationReinviteRequestModel *)reinviteRequestModel
                                          success:(void(^)(TuyaSmartHomeInvitationResultModel *invitationResultModel))success
                                          failure:(TYFailureError)failure;

/// Returns a list of invitation records.
/// @param homeID The home ID.
/// @param success Called when the task is finished. A list of TuyaSmartHomeInvitationRecordModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchInvitationRecordListWithHomeID:(long long)homeID
                                    success:(void(^)(NSArray<TuyaSmartHomeInvitationRecordModel *> *invitationRecordList))success
                                    failure:(TYFailureError)failure;

/// Updates invitation information.
/// @param invitationInfoRequestModel The invitation information request model.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateInvitationInfoWithInvitationInfoRequestModel:(TuyaSmartHomeInvitationInfoRequestModel *)invitationInfoRequestModel
                                                   success:(TYSuccessBOOL)success
                                                   failure:(TYFailureError)failure;


/// Returns home information of the invitee.
/// @param invitationCode The invitation code.
/// @param success Called when the task is finished. TuyaSmartHomeModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchInvitationHomeInfoWithInvitationCode:(NSString *)invitationCode
                                          success:(void(^)(TuyaSmartHomeModel *homeModel))success
                                          failure:(TYFailureError)failure;

/// Joins the home.
/// @param invitationCode The invitation code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)joinHomeWithInvitationCode:(NSString *)invitationCode
                           success:(TYSuccessBOOL)success
                           failure:(TYFailureError)failure;
@end

NS_ASSUME_NONNULL_END
