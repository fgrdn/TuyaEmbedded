//
//  TuyaSmartCameraMessageMediaPlayer.h
//  TuyaSmartCameraM
//
//  Created by 傅浪 on 2020/7/1.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartCameraBase/TuyaSmartCameraBase.h>
#import "TuyaSmartCameraMessageModel.h"

@class TuyaSmartCameraMessageMediaPlayer;
@protocol TuyaSmartCameraMessageMediaPlayerDelegate <NSObject>

@optional
- (void)mediaPlayer:(TuyaSmartCameraMessageMediaPlayer *)player didReceivedFrame:(CMSampleBufferRef)frameBuffer videoFrameInfo:(TuyaSmartVideoFrameInfo)frameInfo;

- (void)mediaPlayer:(TuyaSmartCameraMessageMediaPlayer *)player  didReceivedAudioFrameInfo:(TuyaSmartAudioFrameInfo)frameInfo;

@end

@interface TuyaSmartCameraMessageMediaPlayer : NSObject

@property (nonatomic, weak) id<TuyaSmartCameraMessageMediaPlayerDelegate> delegate;

- (instancetype)initWithDeviceId:(NSString *)devId;

/**
[^en]
video frame render view
[$en]

[^zh]
视频帧渲染视图
[$zh]

@return render view
*/
- (UIView<TuyaSmartVideoViewType> *)videoView;

#pragma mark - audio and video

/**
 [^en]
 play attachment in detect message
 [$en]

 [^zh]
 播放报警消息中的附件
 [$zh]
 
 @param messageModel [^en]message model[$en] [^zh]消息模型[$zh]
 @param attachmentType [^en]attachment type[$en] [^zh]附件类型[$zh]
 @param success success callback
 @param failure failure callback
 @param onFinish finish callback
 
*/
- (void)playMessage:(TuyaSmartCameraMessageModel *)messageModel attachmentType:(TuyaCameraMessageAttachmentType)attachmentType success:(void(^)(void))success failure:(void(^)(int errCode))failure finished:(void(^)(int errCode))onFinish;

/**
 [^en]
 play attachment in detect message
 [$en]

 [^zh]
 播放报警消息中的附件
 [$zh]
 
 @param attachmentPath [^en]attachment path[$en] [^zh]附件地址[$zh]
 @param attachmentType [^en]attachment type[$en] [^zh]附件类型[$zh]
 @param success success callback
 @param failure failure callback
 @param onFinish finish callback
 
*/
- (void)playMessageAttachment:(NSString *)attachmentPath type:(TuyaCameraMessageAttachmentType)attachmentType success:(void(^)(void))success failure:(void(^)(int errCode))failure finished:(void(^)(int errCode))onFinish;

/**
 [^en]
 play attachment in detect message
 [$en]

 [^zh]
 播放报警消息中的附件
 [$zh]
 
 @param attachmentPath  [^en]attachment path[$en] [^zh]附件地址[$zh]
 @param attachmentType  [^en]attachment type[$en] [^zh]附件类型[$zh]
 @param startTime       [^en]start time to play[$en] [^zh]开始播放的时间点[$zh]
 @param success success callback
 @param failure failure callback
 @param onFinish finish callback
 
*/
- (void)playMessageAttachment:(NSString *)attachmentPath type:(TuyaCameraMessageAttachmentType)attachmentType startTime:(NSInteger)startTime success:(void(^)(void))success failure:(void(^)(int errCode))failure finished:(void(^)(int errCode))onFinish;

/**
 [^en]
 pause play attachment
 [$en]

 [^zh]
 暂停播放
 [$zh]
 
 @return error code
*/
- (int)pausePlay:(TuyaCameraMessageAttachmentType)attachmentType;

/**
 [^en]
 resume play attachment
 [$en]

 [^zh]
 恢复播放
 [$zh]
 
 @return error code
*/
- (int)resumePlay:(TuyaCameraMessageAttachmentType)attachmentType;

/**
 [^en]
 stop play attachment
 [$en]

 [^zh]
 停止播放
 [$zh]

*/
- (void)stopPlay:(TuyaCameraMessageAttachmentType)attachmentType;

/**
 [^en]
 set mute.
 [$en]

 [^zh]
 设置静音
 [$zh]
 @param mute [^en]mute sound.[$en] [^zh]是否静音[$zh]
 @param success success call back.
 @param failure failed call back.
 */
- (void)enableMute:(BOOL)mute success:(void(^)(void))success failure:(void (^)(NSError * error))failure;

@end

