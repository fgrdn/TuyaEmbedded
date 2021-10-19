//
// TuyaSmartHomeMember+TYDeprecatedApi.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartHomeMember.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeMember (TYDeprecatedApi)


/// Adds a home member.
///
/// @param homeId      The home ID.
/// @param countryCode The country code.
/// @param account     The user account.
/// @param name        The nickname.
/// @param isAdmin     Specifies whether the member is an administrator.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure: instead.
- (void)addHomeMemberWithHomeId:(long long)homeId
                    countryCode:(NSString *)countryCode
                        account:(NSString *)account
                           name:(NSString *)name
                        isAdmin:(BOOL)isAdmin
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHome -  addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure:] instead");


/// Updates home member information.
///
/// @param memberId    The member ID.
/// @param name        The nickname.
/// @param isAdmin     Specifies whether the member is an administrator.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::updateHomeMemberInfoWithMemberId:name:headPic:isAdmin:success:failure: instead.
- (void)updateHomeMemberNameWithMemberId:(long long)memberId
                                    name:(NSString *)name
                                 isAdmin:(BOOL)isAdmin
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberId:name:headPic:isAdmin:success:failure:] instead");


/// Adds home members.
/// @param groupId The home group ID.
/// @param name The home member's name.
/// @param headPic The home member's avatar.
/// @param countryCode The country code.
/// @param account The user account.
/// @param admin Specifies whether the member is an administrator.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure: instead.
- (void)addHomeMemberWithHomeId:(long long)groupId
                           name:(NSString *)name
                        headPic:(UIImage *)headPic
                    countryCode:(NSString *)countryCode
                    userAccount:(NSString *)account
                        isAdmin:(BOOL)admin
                        success:(TYSuccessDict)success
                        failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHome -  addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure:] instead");



/// Returns a list of home members.
///
/// @param homeId      The home ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::getHomeMemberListWithSuccess:failure: instead.
- (void)getHomeMemberListWithHomeId:(long long)homeId
                            success:(void(^)(NSArray <TuyaSmartHomeMemberModel *> *memberList))success
                            failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHome - (void)getHomeMemberListWithSuccess:failure:] instead");



/// Updates home member information.
///
/// @param memberId    The member ID.
/// @param name        The nickname.
/// @param headPic     The avatar.
/// @param isAdmin     Specifies whether the member is an administrator.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberInfoWithMemberId:(long long)memberId
                                    name:(NSString *)name
                                 headPic:(UIImage *)headPic
                                 isAdmin:(BOOL)isAdmin
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureError)failure  __deprecated_msg("This method will be deprecated and remove, Use [TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Updates the nickname of the home member.
///
/// @param memberId    The member ID.
/// @param name        The nickname.
/// @param isAdmin     Specifies whether the member is an administrator.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberRemarkNameWithMemberId:(long long)memberId
                                          name:(NSString *)name
                                       isAdmin:(BOOL)isAdmin
                                       success:(TYSuccessHandler)success
                                       failure:(TYFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Updates the avatar of the home member.
///
/// @param memberId    The member ID.
/// @param headPic     The avatar.
/// @param isAdmin     Specifies whether the member is an administrator.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberHeadPicWithMemberId:(long long)memberId
                                    headPic:(UIImage *)headPic
                                    isAdmin:(BOOL)isAdmin
                                    success:(TYSuccessHandler)success
                                    failure:(TYFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Updates the management permissions that are granted to the home member.
///
/// @param memberId    The member ID.
/// @param isAdmin     Specifies whether the member is an administrator.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberAdminWithMemberId:(long long)memberId
                                  isAdmin:(BOOL)isAdmin
                                  success:(TYSuccessHandler)success
                                  failure:(TYFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
