//
//  TuyaSmartCloudVideoPlayer.h
//  TuyaSmartCameraM
//
//  Created by 傅浪 on 2019/3/22.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartCameraBase/TuyaSmartCameraBase.h>
#import <CoreMedia/CoreMedia.h>

@class TuyaSmartCloudVideoPlayer;
@protocol TuyaSmartCloudVideoPlayerDelegate <NSObject>

- (void)cloudVideoPlayer:(TuyaSmartCloudVideoPlayer *)player didReceivedFrame:(CMSampleBufferRef)frameBuffer videoFrameInfo:(TuyaSmartVideoFrameInfo)frameInfo;

- (void)cloudVideoPlayer:(TuyaSmartCloudVideoPlayer *)player  didReceivedAudioFrameInfo:(TuyaSmartAudioFrameInfo)frameInfo;

@end

@interface TuyaSmartCloudVideoPlayer : NSObject

@property (nonatomic, strong, readonly) NSString *devId;

@property (nonatomic, assign, getter=isAutoPlay) BOOL autoPlay;

@property (nonatomic, weak) id<TuyaSmartCloudVideoPlayerDelegate> delegate;

- (instancetype)initWithDeviceId:(NSString *)devId;

/**
 [^en]
 config cloud data tags.
 [$en]

 [^zh]
 配置云端数据标签
 [$zh]
 */
- (void)configCloudDataTags:(NSString *)jsonCloudDataTags;

- (NSString *)configCloudDataTagsV2:(NSString *)jsonCloudDataTags;

/**
 [^en]
 start play cloud video.
 [$en]

 [^zh]
 开始播放云视频
 [$zh]
 */
- (void)playCloudDataWithStartTime:(int)nStartTime
                           endTime:(int)nEndTime
                           isEvent:(BOOL)isEvent
                        authParams:(NSString *)jsonAuthParams
                        encryptKey:(NSString *)encryptKey
                        onResponse:(void (^)(int errCode))responseCallback
                          onFinish:(void (^)(int errCode))finishCallBack;
/**
 [^en]
 pause play cloud video.
 [$en]

 [^zh]
 暂停播放云视频
 [$zh]
 @return [^en]error Code, 0 is success.[$en] [^zh]错误码，0代表成功[$zh]
 */
- (int)pausePlayCloudVideo;

/**
 [^en]
 resume play cloud video.
 [$en]

 [^zh]
 恢复播放云视频
 [$zh]
 @return [^en]error Code, 0 is success.[$en] [^zh]错误码，0代表成功[$zh]
 */
- (int)resumePlayCloudVideo;

/**
 [^en]
 stop play cloud video.
 [$en]

 [^zh]
 停止播放云视频
 [$zh]
 @return [^en]error Code, 0 is success.[$en] [^zh]错误码，0代表成功[$zh]
 */
- (int)stopPlayCloudVideo;

/**
 [^en]
 video frame render view
 [$en]

 [^zh]
 视频帧数据渲染视图
 [$zh]
 
 @return render view
 */
- (UIView<TuyaSmartVideoViewType> *)videoView;

/**
 [^en]
 set mute.
 [$en]

 [^zh]
 设置静音
 [$zh]
 @param mute [^en]mute sound.[$en] [^zh]禁用声音[$zh]
 @param success success call back.
 @param failure failed call back.
 */
- (void)enableMute:(BOOL)mute success:(void(^)(void))success failure:(void (^)(NSError * error))failure;

/**
 [^en]
 get mute state.
 [$en]

 [^zh]
 获取设备静音状态
 [$zh]
 @return [^en]BOOL[$en] [^zh]是否静音BOOL值[$zh]
 */
- (BOOL)isMuted;

/**
 [^en]
 start record. video will save to photo album. photo asset collection name is bundle name, "[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]".
 [$en]

 [^zh]
 开始录制。视频将会存储到系统相册，相片 asset collection 名称为bundle name，"[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]"
 [$zh]
 */
- (void)startRecord;

/**
 [^en]
 start record and the video will save to the file path.
 [$en]

 [^zh]
 开始录制并且视频将会存储到指定 filepath
 [$zh]

 @param filePath [^en]save path[$en] [^zh]保存路径[$zh]
 */
- (void)startRecordAtPath:(NSString *)filePath;

/**
 [^en]
 stop record.
 [$en]

 [^zh]
 停止录制
 [$zh]
 @return [^en]error code. return 0 as record success.[$en] [^zh]错误码。返回0代表录制成功[$zh]
 */
- (int)stopRecord;

/**
 [^en]
 get a screenshot of the video and save it to photo album. photo asset collection name is bundle name, "[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]".
 [$en]

 [^zh]
 获取视频的截图并且将它存储到系统相册，相片 asset collection 名称为 bundle name，"[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]"
 [$zh]
 */
- (UIImage *)snapShoot;

/**
 [^en]
  get a screenshot of the video and save it to file path. if you do not need a thumbnil, set thumbnilPath nil.
 [$en]

 [^zh]
 获取视频的截图并保存到指定的路径，如果您不需要缩略图，将thumbnilPath置为nil
 [$zh]
 */
- (UIImage *)snapShootAtPath:(NSString *)filePath thumbnilPath:(NSString *)thumbnilPath;

/**
 [^en]
 release resources.
 [$en]

 [^zh]
 释放资源
 [$zh]
 */
- (void)destroy;

/*
 start download cloud video, saved as mp4
 @param nStartTime Expected start time of the downloaded video  欲下载的云存储视频的起始时间
 @param nStopTime Expected end time of the downloaded video 欲下载的云存储视频的结束时间
 @param folderPath the folder path to save mp4. 存放mp4文件的文件夹
 @param mp4FileName video file name. mp4文件名
 @param callback 成功失败回调
 @param progressCallBack 进度回调
 @param finishedCallBack 结束回调
*/
- (void)startCloudDataDownloadWithStartTime:(int)startTime stopTime:(int)stopTime folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(int errCode))finishedCallBack;

/*
 pause download cloud video
 暂停云存储视频下载
*/
- (void)pauseCloudDataDownloadWithResponse:(void (^)(int))callback;

/*
 resume download cloud video
 恢复云存储视频下载
*/
- (void)resumeCloudDataDownloadWithResponse:(void (^)(int))callback;

/*
 cancel download cloud video
 取消云存储视频下载
*/
- (void)cancelCloudDataDownloadWithResponse:(void (^)(int))callback;

/**
 [^en] Set cloud storage multiplier playback speed[$en]
 [^zh] 设置云存储倍速播放速率 [$zh]
 @param speed [^en] multiplier playback speed [$en] [^zh] 倍速播放速率 [$zh]
 @return [^en]error code[$en] [^zh]错误码[$zh]
 */
- (int)setCloudVideoPlaySpeed:(TuyaSmartCameraPlayBackSpeed)speed;

#pragma mark - Video Message

/**
 [^en]
 play encrypt video in detect message
 [$en]

 [^zh]
 在侦测消息中播放加密视频
 [$zh]
 
 @param url [^en]video path[$en] [^zh]视频地址[$zh]
 @param nStartTime [^en]Start time to play[$en] [^zh]开始播放的时间[$zh]
 @param encryptKey [^en]encrypt key[$en] [^zh]加密key[$zh]
 @param callback start callback
 @param finihedCallBack finish callback

 @return [^en]error code[$en] [^zh]错误码[$zh]
*/
- (int)playVideoMessageWithUrl:(NSString *)url startTime:(int)nStartTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finihedCallBack;

/**
 [^en]
 pause play video
 [$en]

 [^zh]
 暂停播放视频
 [$zh]
 
 @return [^en]error code[$en] [^zh]错误码[$zh]
*/
- (int)pausePlayVideoMessage;

/**
 [^en]
 resume play video
 [$en]

 [^zh]
 恢复播放视频
 [$zh]
 
 @return [^en]error code[$en] [^zh]错误码[$zh]
*/
- (int)resumePlayVideoMessage;

/**
 [^en]
 stop play video
 [$en]

 [^zh]
 停止播放视频
 [$zh]
 
 @return [^en]error code[$en] [^zh]错误码[$zh]
*/
- (int)stopPlayVideoMessage;

/**
 [^en]
 play encrypt audio in detect message
 [$en]

 [^zh]
 在侦测消息中播放加密音频
 [$zh]
 
 @param url [^en]audio path[$en] [^zh]音频地址[$zh]
 @param nStartTime [^en]Start time to play[$en] [^zh]开始播放时间[$zh]
 @param encryptKey [^en]encrypt key[$en] [^zh]加密key[$zh]
 @param callback start callback
 @param finihedCallBack finish callback

 @return [^en]error code[$en] [^zh]错误码[$zh]
*/
- (int)playAudioMessageWithUrl:(NSString *)url startTime:(int)nStartTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finihedCallBack;

- (void)startVideoMessageDownloadWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey filePath:(NSString *)filePath rotateDirection:(TuyaSmartVideoRotateDirection)rotateDirection success:(void (^)(void))successCallback progress:(void (^)(int))progressCallBack failure:(void (^)(int))failureCallBack;

/**
 [^en]
 pause play audio
 [$en]

 [^zh]
 暂停播放s音频
 [$zh]
 
 @return [^en]error code[$en] [^zh]错误码[$zh]
*/
- (int)pausePlayAudioMessage;

/**
 [^en]
 resume play audio
 [$en]

 [^zh]
 恢复播放音频
 [$zh]
 
 @return [^en]error code[$en] [^zh]错误码[$zh]
*/
- (int)resumePlayAudioMessage;

/**
 [^en]
 stop play audio
 [$en]

 [^zh]
 停止播放音频
 [$zh]
 
 @return [^en]error code[$en] [^zh]错误码[$zh]
*/
- (int)stopPlayAudioMessage;

/*
 start download audio or video in message
 @param url
 @param encryptKey
 @param folderPath
 @param mp4FileName
 @param callback
 @param progressCallBack
 @param finishedCallBack
*/
- (void)startVideoMessageDownloadWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey filePath:(NSString *)filePath success:(void(^)(void))successCallback progress:(void (^)(int progress))progressCallBack failure:(void (^)(int errCode))failureCallBack;

/*
 pause download
*/
- (void)pauseVideoMessageDownload:(void (^)(int errCode))callback;

/*
 resume download
*/
- (void)resumeVideoMessageDownload:(void (^)(int errCode))callback;

/*
 cancel download
*/
- (void)cancelVideoMessageDownload;

@end
