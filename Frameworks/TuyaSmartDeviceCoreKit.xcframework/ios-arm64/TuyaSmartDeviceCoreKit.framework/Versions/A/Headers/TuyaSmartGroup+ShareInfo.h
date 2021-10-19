//
//  TuyaSmartGroup+ShareInfo.h
//  TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartGroup.h"

@interface TuyaSmartGroup (ShareInfo)

/// Get sharing information of the group.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareGroupFromInfoWithSuccess:(TYSuccessID)success
                                 failure:(TYFailureError)failure;


/// Remove sharing groups.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeShareGroupWithSuccess:(TYSuccessID)success
                            failure:(TYFailureError)failure;

@end

