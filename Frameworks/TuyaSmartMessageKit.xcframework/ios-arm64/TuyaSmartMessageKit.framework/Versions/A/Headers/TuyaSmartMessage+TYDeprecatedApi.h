//
// TuyaSmartMessage+TYDeprecatedApi.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMessage (TYDeprecatedApi)


/// Get the message list.
///
/// @param msgType      Message type
/// @param limit        Limit
/// @param offset       Offset  start from zero
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartMessage::fetchMessageListWithListRequestModel:success:failure: instead.
- (void)getMessageListWithType:(TYMessageType)msgType limit:(NSInteger)limit offset:(NSInteger)offset success:(void (^)(NSArray<TuyaSmartMessageListModel *> *list))success failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartMessage fetchMessageListWithListRequestModel:success:failure:] instead");


/// Get the message list by message type.
///
/// @param msgType      Message type
/// @param msgSrcId     Detail message Id
/// @param limit        Limit
/// @param offset       Offset  start from zero
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartMessage::fetchMessageDetailListWithListRequestModel:success:failure: instead.
- (void)getMessageDetailListWithType:(NSInteger)msgType msgSrcId:(NSString *)msgSrcId limit:(NSInteger)limit offset:(NSInteger)offset success:(void (^)(NSArray<TuyaSmartMessageListModel *> *list))success failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartMessage fetchMessageDetailListWithListRequestModel:success:failure:] instead");


/// Get the message list.
///
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartMessage::getMessageListWithType:limit:offset:success:failure: or TuyaSmartMessage::getMessageDetailListWithType:msgSrcId:limit:offset:success:failure: instead.
- (void)getMessageList:(void (^)(NSArray<TuyaSmartMessageListModel *> *list))success
               failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartMessage getMessageListWithType:limit:offset:success:failure:] or -[TuyaSmartMessage getMessageDetailListWithType:msgSrcId:limit:offset:success:failure:] instead");



/// Get next page message list.
///
/// @param limit        Limit
/// @param offset       Offset  start from zero
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartMessage::getMessageListWithType:limit:offset:success:failure: or TuyaSmartMessage::getMessageDetailListWithType:msgSrcId:limit:offset:success:failure: instead.
- (void)getMessageList:(NSInteger)limit
                offset:(NSInteger)offset
               success:(void (^)(NSArray<TuyaSmartMessageListModel *> *list))success
               failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartMessage getMessageListWithType:limit:offset:success:failure:] or -[TuyaSmartMessage getMessageDetailListWithType:msgSrcId:limit:offset:success:failure:] instead");



/// Delete a batch of messages
///
/// @param messgeIdList Message Id list
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartMessage::deleteMessageWithType:ids:msgSrcIds:success:failure: instead.
- (void)deleteMessage:(NSArray <NSString *> *)messgeIdList
              success:(TYSuccessHandler)success
              failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartMessage deleteMessageWithType:ids:msgSrcIds:success:failure:] instead");



/// Get the timestamp of the newest message
///
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartMessage::getLatestMessageWithSuccess:failure: instead.
- (void)getMessageMaxTime:(TYSuccessInt)success
                  failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartMessage getLatestMessageWithSuccess:failure:] instead");


/// Delete a batch of messages
///
/// @param msgType      Message type
/// @param ids          Delete message Id list
/// @param msgSrcIds    Delete alarm message Id list
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartMessage::deleteMessageWithDeleteRequestModel:failure: instead.
- (void)deleteMessageWithType:(NSInteger)msgType ids:(NSArray *)ids msgSrcIds:(NSArray *)msgSrcIds success:(TYSuccessHandler)success failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartMessage deleteMessageWithDeleteRequestModel:failure:] instead");

@end

NS_ASSUME_NONNULL_END
