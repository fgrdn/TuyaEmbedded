//
// TuyaSmartFeedback.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TuyaSmartFeedbackTalkListModel.h"
#import "TuyaSmartFeedbackModel.h"
#import "TuyaSmartFeedbackTypeListModel.h"

/// @brief TuyaSmartFeedback provides methods for developers to implement feedback functionalities.
///
/// When the user finds a problem and needs to submit feedback, he/she can add it. When adding feedback, he/she should first select the feedback type, then write the feedback content and submit it.
///
/// All functions related to feedback correspond to the TuyaSmartFeedback class, which supports the following list of functions:
///
/// - TuyaSmartFeedback::getFeedbackTalkList:failure: for getting a list of feedback sessions
/// - TuyaSmartFeedback::getFeedbackList:hdType:success:failure: for getting a list of feedback contents in a session
/// - TuyaSmartFeedback::getFeedbackTypeList:failure: for getting a list of feedback types
/// - adding feedback
@interface TuyaSmartFeedback : NSObject

/// Get a list of sessions that users have submitted feedback on.
///
/// @param success      When success, return feedback session list.
/// @param failure      When error occurred, return TYFailureError.
- (void)getFeedbackTalkList:(void (^)(NSArray<TuyaSmartFeedbackTalkListModel *> *list))success
                    failure:(TYFailureError)failure;


/// Get a list of the corresponding feedback contents in the feedback session. The `hdId` and `hdType` can be obtained from TuyaSmartFeedbackTalkListModel.
///
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param success      When success, return feedback list.
/// @param failure      When error occurred, return TYFailureError.
- (void)getFeedbackList:(NSString *)hdId
                 hdType:(NSUInteger)hdType
                success:(void (^)(NSArray<TuyaSmartFeedbackModel *> *list))success
                failure:(TYFailureError)failure;


/// Get feedback type list. When adding feedback, select the type of feedback first.
///
/// @param success      When success, return TuyaSmartFeedbackTypeListModel.
/// @param failure      When error occurred, return TYFailureError.
- (void)getFeedbackTypeList:(void (^)(NSArray<TuyaSmartFeedbackTypeListModel *> *list))success
                    failure:(TYFailureError)failure;


/// Add feedback and submit the content of the feedback entered by the user.
///
/// The `hdId` and `hdType` can be obtained from TuyaSmartFeedbackTalkListModel.
///
/// @note This is suggested for App related issues and devices that do not need strong bindings.
///
/// @param content      The feedback content.
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param contact      The contact information.
/// @param success      When successfully add the feedback, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
            success:(TYSuccessHandler)success
            failure:(TYFailureError)failure;


/// Add feedback and submit the content of the feedback entered by the user.
///
/// The `hdId` and `hdType` can be obtained from TuyaSmartFeedbackTalkListModel.
///
/// @note This is suggested for devices that need strong bindings, for example IP cameras.
///
/// @param content      The feedback content.
/// @param hdId         The feedback ID.
/// @param hdType       The feedback type.
/// @param contact      The contact information.
/// @param uuid         The UUID for the device.
/// @param region       The user's region.
/// @param success      When successfully add the feedback, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
               uuid:(NSString *)uuid
             region:(NSString *)region
            success:(TYSuccessHandler)success
            failure:(TYFailureError)failure;


/// Canceling an ongoing operation.
- (void)cancelRequest;

@end
