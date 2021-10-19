//
//  TuyaSmartCameraMessage.h
//  TuyaSmartCameraKit
//
//  Created by 傅浪 on 2019/8/12.
//

#import <Foundation/Foundation.h>
#import "TuyaSmartCameraMessageModel.h"
#import <TuyaSmartCameraM/TuyaSmartCameraM.h>

@interface TuyaSmartCameraMessage : NSObject

/**
 [^en]
 default is [NSTimeZone systemTimeZone]
 [$en]

 [^zh]
 默认为 [NSTimeZone systemTimeZone]
 [$zh]
 */
@property (nonatomic, strong) NSTimeZone *timeZone;

/**
[^en]
Enable image encryption, which is disabled by default. After opening, the pictures carried in the message will be encrypted, and you need to use the TYEncryptImage component to display or download the pictures.
[$en]

[^zh]
开启图片加密，默认为关闭。打开后，消息中携带的图片会加密，需要使用 TYEncryptImage 组件显示或者下载图片。
[$zh]
*/
@property (nonatomic, assign) BOOL enableEncryptedImage;

- (instancetype)initWithDeviceId:(NSString *)devId timeZone:(NSTimeZone *)timeZone;


/**
 [^en]
 get day list which has messages
 [$en]

 [^zh]
 获取有消息的日期
 [$zh]
 

 @param year [^en]year[$en] [^zh]年[$zh]
 @param month [^en]month[$en] [^zh]月[$zh]
 @param success callback
 @param failure callback
 */
- (void)messageDaysForYear:(NSInteger)year
                     month:(NSInteger)month
                   success:(void (^)(NSArray<NSString *> *result))success
                   failure:(void (^)(NSError *error))failure;

/**
 [^en]
 get message list
 [$en]

 [^zh]
 获取消息列表
 [$zh]
 

 @param msgCodes msgCodes
 @param offset [^en]offset[$en] [^zh]偏移量[$zh]
 @param limit [^en]page size[$en] [^zh]页大小[$zh]
 @param startTime [^en]pass 0 for no time limit[$en] [^zh]传入0代表没有时间限制[$zh]
 @param endTime [^en]end time[$en] [^zh]结束时间[$zh]
 @param success callback
 @param failure callback
 */
- (void)messagesWithMessageCodes:(NSArray *)msgCodes
                          Offset:(NSInteger)offset
                           limit:(NSInteger)limit
                       startTime:(NSInteger)startTime
                         endTime:(NSInteger)endTime
                         success:(void (^)(NSArray<TuyaSmartCameraMessageModel *> *result))success
                         failure:(void (^)(NSError *error))failure;

/**
[^en]
remove messages by message id list
[$en]

[^zh]
删除消息
[$zh]

 @param msgIds [^zh] 需要删除的消息的id数组 [$zh] [^en] message id array whitch need removed [$en]
 @param success callback
 @param failure callback
*/
- (void)removeMessagesWithMessageIds:(NSArray *)msgIds
                             success:(void (^)(void))success
                             failure:(void (^)(NSError *))failure;

/**
 [^en]
 get message schemes list
 [$en]

 [^zh]
 获取消息分类列表
 [$zh]
 
 @param success callback
 @param failure callback
 */
- (void)getMessageSchemes:(void (^)(NSArray<TuyaSmartCameraMessageSchemeModel *> *result))success
                  failure:(void (^)(NSError *error))failure;

/**
 [^en]
 start download attachment of message
 [$en]
 
 [^zh]
 开始下载消息中的附件
 [$zh]
 
 @param messageModel [^en]message model[$en] [^zh]消息模型[$zh]
 @param type [^en]attachment type[$en] [^zh]附件类型[$zh]
 @param filePath [^en]file path to save attachment[$en] [^zh]附件保存的文件路径[$zh]
 @param successCallback [^en]success callbak[$en] [^zh]成功回调[$zh]
 @param progressCallBack [^en]progress callbak[$en] [^zh]进度回调[$zh]
 @param failureCallBack [^en]failure callbak[$en] [^zh]失败回调[$zh]
*/
- (void)startDownloadMessageAttachmentWithMeesageModel:(TuyaSmartCameraMessageModel *)messageModel attachType:(TuyaCameraMessageAttachmentType)type filePath:(NSString *)filePath success:(void(^)(void))successCallback progress:(void (^)(int progress))progressCallBack failure:(void (^)(int errCode))failureCallBack;

/**
 [^en]
 start download attachment of message
 [$en]
 
 [^zh]
 开始下载消息中的附件
 [$zh]
 
 @param attachPath [^en]attachment path[$en] [^zh]附件地址[$zh]
 @param type [^en]attachment type[$en] [^zh]附件类型[$zh]
 @param filePath [^en]file path to save attachment[$en] [^zh]附件保存的文件路径[$zh]
 @param successCallback [^en]success callbak[$en] [^zh]成功回调[$zh]
 @param progressCallBack [^en]progress callbak[$en] [^zh]进度回调[$zh]
 @param failureCallBack [^en]failure callbak[$en] [^zh]失败回调[$zh]
*/
- (void)startDownloadMessageAttachmentWithUrl:(NSString *)attachPath attachType:(TuyaCameraMessageAttachmentType)type filePath:(NSString *)filePath success:(void(^)(void))successCallback progress:(void (^)(int progress))progressCallBack failure:(void (^)(int errCode))failureCallBack;

- (void)startDownloadMessageAttachmentWithUrl:(NSString *)attachPath attachType:(TuyaCameraMessageAttachmentType)type filePath:(NSString *)filePath rotateDirection:(TuyaSmartVideoRotateDirection)rotateDirection   success:(void (^)(void))successCallback progress:(void (^)(int))progressCallBack failure:(void (^)(int))failureCallBack;

/**
 [^en]
 cancel download
 [$en]
 
 [^zh]
 取消下载
 [$zh]
*/
- (void)cancelDownloadMessageAttachment:(TuyaCameraMessageAttachmentType)type;

@end

