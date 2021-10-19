//
// TuyaSmartMessage.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TuyaSmartMessageListModel.h"
#import "TuyaSmartMessageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN
/// @brief TuyaSmartMessage provides methods for developers to implement message functionalities.
///
/// TuyaSmartMessage contains message center and push-related functions, and its messages are mainly divided into three major categories: alarms, families, and notifications, each of which is supported to be turned on or off respectively.
@interface TuyaSmartMessage : NSObject

/// Fetch message list.
/// @param listRequestModel Provide listRequestModel to fetch the TuyaSmartMessageListModel.
/// @param success Called when the task finishes successfully. A list of TuyaSmartMessageListModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageListWithListRequestModel:(TuyaSmartMessageListRequestModel *)listRequestModel
                                     success:(void (^)(NSArray<TuyaSmartMessageListModel *> *messageList))success
                                     failure:(TYFailureError)failure;

/// Fetch message detail list.
/// @param detailListRequestModel Provide a listRequestModel to fetch the TuyaSmartMessageListModel.
/// @param success Called when the task finishes successfully. A list of TuyaSmartMessageListModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageDetailListWithListRequestModel:(TuyaSmartMessageDetailListRequestModel *)detailListRequestModel
                                           success:(void (^)(NSArray<TuyaSmartMessageListModel *> *messageList))success
                                           failure:(TYFailureError)failure;

/// Get three types of messages if there are new ones.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getLatestMessageWithSuccess:(TYSuccessDict)success failure:(TYFailureError)failure;

/// Set the message center list data to read.
/// @param readRequestModel List of read messages (support all read).
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)readMessageWithReadRequestModel:(TuyaSmartMessageListReadRequestModel *)readRequestModel success:(TYSuccessBOOL)success failure:(TYFailureError)failure;


/// Delete message center list data.
/// @param deleteRequestModel List of deleted messages (delete all is not supported).
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteMessageWithDeleteRequestModel:(TuyaSmartMessageListDeleteRequestModel *)deleteRequestModel success:(TYSuccessBOOL)success failure:(TYFailureError)failure;

/// Canceling the ongoing operation.
- (void)cancelRequest;

@end
NS_ASSUME_NONNULL_END
