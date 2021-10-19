//
//  TuyaSmartCameraType.h
//  TYCameraLibrary
//
//  Created by Tuya on 2018/7/2.
//  Copyright © 2018 TuyaSmart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuyaSmartCameraDefines.h"
#import "TuyaSmartVideoViewType.h"
#import <CoreMedia/CoreMedia.h>

IPC_EXTERN NSString * const kTuyaSmartTimeSliceStartDate;

IPC_EXTERN NSString * const kTuyaSmartTimeSliceStopDate;

IPC_EXTERN NSString * const kTuyaSmartTimeSliceStartTime;

IPC_EXTERN NSString * const kTuyaSmartTimeSliceStopTime;

IPC_EXTERN NSString * const kTuyaSmartTimeSliceRecordType;

typedef NS_ENUM(NSUInteger, TuyaSmartCameraConnectMode) {
    TuyaSmartCameraConnectAuto,
    TuyaSmartCameraConnectFromInternet,
    TuyaSmartCameraConnectFromLocal
};

typedef NS_ENUM(NSUInteger, TuyaSmartVideoRotateDirection) {
    TuyaSmartVideoRotateDirectionUp = 0,
    TuyaSmartVideoRotateDirectionRight = 1,
    TuyaSmartVideoRotateDirectionDown = 2,
    TuyaSmartVideoRotateDirectionLeft = 3
};

@protocol TuyaSmartCameraType;

@protocol TuyaSmartCameraDelegate <NSObject>

@optional

/**
 [^en]
 the p2p channel did connected.
 [$en]

 [^zh]
 p2p 通道已连接
 [$zh]

 @param camera camera
 */
- (void)cameraDidConnected:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the p2p channel did disconnected.
 [$en]

 [^zh]
 p2p 通道已断开
 [$zh]

 @param camera camera
 */
- (void)cameraDisconnected:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the playback channel did connected.
 [$en]

 [^zh]
 回放通道已经连接
 [$zh]

 @param camera camera
 */
- (void)cameraDidConnectPlaybackChannel:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the camera did began play live video.
 [$en]

 [^zh]
 摄像头已经开始播放实时视频
 [$zh]

 @param camera camera
 */
- (void)cameraDidBeginPreview:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the camera did stop live video.
 [$en]

 [^zh]
 摄像头实时视频已停止
 [$zh]

 @param camera camera
 */
- (void)cameraDidStopPreview:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the camera did began playback record video in the SD card.
 [$en]

 [^zh]
 摄像头SD卡视频回放已开始
 [$zh]

 @param camera camera
 */
- (void)cameraDidBeginPlayback:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the camera did pause playback record video in the SD card.
 [$en]

 [^zh]
 摄像头SD卡视频回放已暂停
 [$zh]

 @param camera camera
 */
- (void)cameraDidPausePlayback:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the camera did resume playback record video in the SD card.
 [$en]

 [^zh]
 摄像头SD卡视频回放已恢复播放
 [$zh]

 @param camera camera
 */
- (void)cameraDidResumePlayback:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the camera did stop playback record video in the SD card.
 [$en]

 [^zh]
 摄像头SD卡视频回放已中止
 [$zh]

 @param camera camera
 */
- (void)cameraDidStopPlayback:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the record video in the SD card playback finished.
 [$en]

 [^zh]
 摄像头SD卡视频回放已结束
 [$zh]

 @param camera camera
 */
- (void)cameraPlaybackDidFinished:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the record video in the SD card playback finished
 [$en]

 [^zh]
 摄像头SD卡视频回放结束时状态
 [$zh]

 @param camera camera
 @param status finished status
 */
- (void)camera:(id<TuyaSmartCameraType>)camera playbackDidFinishedWithStatus:(NSInteger)status;

- (void)camera:(id<TuyaSmartCameraType>)camera playbackTimeSlice:(NSDictionary *)timeSlice didFinishedWithStatus:(NSInteger)status;

/**
 [^en]
 receive first video frame
 this method will call when every 'startPreview/startPlayback/resumePlayback' sucess.
 [$en]
 收到的第一帧视频
 此方法将会在每一次 'startPreview/startPlayback/resumePlayback' 成功时被调用
 [^zh]

 [$zh]
 @param camera camera
 @param image  [^en]fisrt frame image[$en] [^zh]第一帧图片[$zh]
 */
- (void)camera:(id<TuyaSmartCameraType>)camera didReceiveFirstFrame:(UIImage *)image;

/**
 [^en]
 begin talk to the device. will call when 'startTalk' success.
 [$en]

 [^zh]
 开始与设备进行对讲，方法会在 'startTalk' 成时被调用
 [$zh]

 @param camera camera
 */
- (void)cameraDidBeginTalk:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 talk to the device did stop. will call when 'stopTalk' success.
 [$en]

 [^zh]
 与设备对讲已经结束，方法会在 'stopTalk' 成功时被调用
 [$zh]

 @param camera camera
 */
- (void)cameraDidStopTalk:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 the video screenshot has saved in the photo album.
 [$en]

 [^zh]
 视频截图已成功保存到相册
 [$zh]

 @param camera camera
 */
- (void)cameraSnapShootSuccess:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 video recording did start success.
 [$en]

 [^zh]
 视频录制已成功开始
 [$zh]

 @param camera camera
 */
- (void)cameraDidStartRecord:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 video recording did stop sucess, and the video has saved in photo album success.
 [$en]

 [^zh]
 视频录制已经成功停止，视频已成功保存到相册
 [$zh]

 @param camera camera
 */
- (void)cameraDidStopRecord:(id<TuyaSmartCameraType>)camera;

/**
 [^en]
 did receive definition state. will call when 'getHD' success or the definition has changed.
 [$en]

 [^zh]
 收到视频清晰度状态，方法会在 'getHD' 成功 或者清晰度改变的时候被调用
 [$zh]

 @param camera camera
 @param isHd [^en]is high definition[$en] [^zh]是否为高清[$zh]
 */
- (void)camera:(id<TuyaSmartCameraType>)camera didReceiveDefinitionState:(BOOL)isHd __deprecated_msg("Use camera:definitionChanged: instead");
- (void)camera:(id<TuyaSmartCameraType>)camera definitionChanged:(TuyaSmartCameraDefinition)definition;

/**
 [^en]
 called when query date of the playback record success.
 [$en]

 [^zh]
 方法会在按日期查询回放视频数据成功后被调用
 [$zh]

 @param camera camera
 @param days [^en]the array of days，ex: [@(1), @(2), @(5), @(6), @(31)]; express in this month, 1，2，5，6，31  has video record.[$en] [^zh]日期的数组， ex: [@(1), @(2), @(5), @(6), @(31)]; 代表这个月中的 1，2，5，6，31 号有视频录制数据[$zh]
 */
- (void)camera:(id<TuyaSmartCameraType>)camera didReceiveRecordDayQueryData:(NSArray<NSNumber *> *)days;

/**
 [^en]
 called when query video record slice of one day success.
 [$en]

 [^zh]
 方法将会在查询一天内视频回放片段数据成功后被调用
 [$zh]

 @param camera camera
 
 @param timeSlices [^en]the array of playback video record information. the element is a NSDictionary, content like this:
 kTuyaSmartPlaybackPeriodStartDate  ： startTime(NSDate)
 kTuyaSmartPlaybackPeriodStopDate   ： stopTime(NSDate)
 kTuyaSmartPlaybackPeriodStartTime  ： startTime(NSNumer, unix timestamp)
 kTuyaSmartPlaybackPeriodStopTime   ： stopTime(NSNumer, unix timestamp)[$en] [^zh]回放视频数据信息数组，数组内元素为NSDictionary类型，如下:
 kTuyaSmartPlaybackPeriodStartDate  ： startTime(NSDate)
 kTuyaSmartPlaybackPeriodStopDate   ： stopTime(NSDate)
 kTuyaSmartPlaybackPeriodStartTime  ： startTime(NSNumer, unix timestamp)
 kTuyaSmartPlaybackPeriodStopTime   ： stopTime(NSNumer, unix timestamp)[$zh]
 */
- (void)camera:(id<TuyaSmartCameraType>)camera didReceiveTimeSliceQueryData:(NSArray<NSDictionary *> *)timeSlices;

/**
 [^en]
 did receive mute state. will call when 'enableMute:' success. default is YES.
 [$en]

 [^zh]
 收到静音状态，方法会在 'enableMute:' 成功之后被调用，默认为 YES
 [$zh]

 @param camera camera
 @param isMute [^en]is muted[$en] [^zh]是否为静音[$zh]
 */
- (void)camera:(id<TuyaSmartCameraType>)camera didReceiveMuteState:(BOOL)isMute playMode:(TuyaSmartCameraPlayMode)playMode;

/**
 [^en]
 the control of camera has occurred an error
 [$en]

 [^zh]
 camera控制出现了错误
 [$zh]
 @param camera camera
 @param errCode [^en]reference the TYCameraErrorCode[$en] [^zh]具体参考TYCameraErrorCode[$zh]
 */
- (void)camera:(id<TuyaSmartCameraType>)camera didOccurredError:(TYCameraErrorCode)errCode __deprecated_msg("Use camera:didOccurredErrorAtStep:specificErrorCode: instead");

/**
 [^en]
 the control of camera has occurred an error with specific reason code
 [$en]
 
 [^zh]
 camera 控制出现了一个错误，附带错误码
 [$zh]
 @param camera camera
 @param errStepCode [^en]reference the TYCameraErrorCode[$en] [^zh]具体参考 TYCameraErrorCode [$zh]
 @param errorCode [^en]errorCode reference TuyaCameraSDK.framework/TYDefines[$en] [^zh]具体参考TuyaCameraSDK.framework/TYDefines[$zh]
 */
- (void)camera:(id<TuyaSmartCameraType>)camera didOccurredErrorAtStep:(TYCameraErrorCode)errStepCode specificErrorCode:(NSInteger)errorCode;

/**
 [^en]
 the definition of the video did chagned
 [$en]

 [^zh]
 视频清晰度已经修改
 [$zh]
 @param camera camera
 @param width video width
 @param height video height
 */
- (void)camera:(id<TuyaSmartCameraType>)camera resolutionDidChangeWidth:(NSInteger)width height:(NSInteger)height;

/**
 [^en]
 if 'isRecvFrame' is true, and p2pType is "1", the video data will not decode in the SDK, and could get the orginal video frame data through this method.
 [$en]

 [^zh]
 如果 'isRecvFrame' 是true，并且 'p2pType' 是 1， 视频数据将不会在SDK中解码，通过此方法可以获取到原始视频帧数据
 [$zh]
 @param camera      camera
 @param frameData   [^en]original video frame data[$en] [^zh]原始视频帧数据[$zh]
 @param size        [^en]video frame data size[$en] [^zh]视频帧数尺寸[$zh]
 @param frameInfo   [^en]frame header info[$en] [^zh]视频帧头信息[$zh]
 */

- (void)camera:(id<TuyaSmartCameraType>)camera ty_didReceiveFrameData:(const char *)frameData dataSize:(unsigned int)size frameInfo:(TuyaSmartVideoStreamInfo)frameInfo;

/**
 [^en]
 if 'isRecvFrame' is true, and p2pType is greater than 2, could get the decoded YUV frame data through this method.
 [$en]

 [^zh]
 如果 'isRecvFrame' 为true，并且 'p2pType' 大于 2，可以通过此方法j获得解码后的 YUV 帧数据
 [$zh]
 @param camera          camera
 @param sampleBuffer    [^en]video frame YUV data[$en] [^zh]YUV 视频帧数据[$zh]
 @param frameInfo       [^en]frame header info[$en] [^zh]数据帧头信息[$zh]
 */
- (void)camera:(id<TuyaSmartCameraType>)camera ty_didReceiveVideoFrame:(CMSampleBufferRef)sampleBuffer frameInfo:(TuyaSmartVideoFrameInfo)frameInfo;

/**
 [^en]
 if p2pType is greater than 2, could get audio record data when talking through this method. if yout want change the audio data, must keep the audio data length same，and synchronize。
 [$en]

 [^zh]
 p2p2 以上的设备，如果 p2pType 大于 2， 此方法会返回录制的音频数据。如果你需要修改音频数据，务必不要改变音频数据的长度，并在修改操作需要在代理方法中同步进行。
 [$zh] 
 @param camera           camera
 @param pcm              [^en]audio data[$en] [^zh]音频数据[$zh]
 @param length           [^en]date length[$en] [^zh]数据长度[$zh]
 @param sampleRate       [^en]audio sample rate[$en] [^zh]音频样本比率[$zh]
*/
- (void)camera:(id<TuyaSmartCameraType>)camera ty_didRecieveAudioRecordDataWithPCM:(const unsigned char*)pcm length:(int)length sampleRate:(int)sampleRate;

- (void)camera:(id<TuyaSmartCameraType>)camera ty_didSpeedPlayWithSpeed:(TuyaSmartCameraPlayBackSpeed)playBackSpeed;

@end

@protocol TuyaSmartCameraType <NSObject>

@property (nonatomic, weak) id<TuyaSmartCameraDelegate> delegate;

@property (nonatomic, strong) NSString *devId;

/// [^en]if you want get the original video frame data, set isRecvFrame YES.[$en] [^zh]如果需要获取原始视频帧数据，设置 isRecvFrame 为 YES[$zh]
@property (nonatomic, assign) BOOL isRecvFrame;

/* [^en]
with p2p 2.0, could get YUV data with - (void)camera:(id<TuyaSmartCameraType>)camera ty_didReceiveVideoFrame:(CMSampleBufferRef)sampleBuffer frameInfo:(TuyaSmartVideoFrameInfo)frameInfo; set autoRender NO，you can render the video by yourself.
[$en]

[^zh]
在 p2p 2.0下，可以通过 - (void)camera:(id<TuyaSmartCameraType>)camera ty_didReceiveVideoFrame:(CMSampleBufferRef)sampleBuffer frameInfo:(TuyaSmartVideoFrameInfo)frameInfo; 获取 YUV 数据，设置 autoRender 为NO，可以自行渲染视频
[$zh]
 */
@property (nonatomic, assign) BOOL autoRender;

/**
 [^en]
 destory resources, should call this method when exit the camera panel.
 [$en]

 [^zh]
 销毁资源，退出摄像头面板的时候应该调用此方法
 [$zh]
 */
- (void)destory;

/**
 [^en]
 start connect p2p channel
 [$en]

 [^zh]
 开始连接 p2p 通道
 [$zh]
 */
- (void)connect;

/**
 [^en]
 connnect playback channel, call this method before start playback video record.
 [$en]

 [^zh]
 连接回放通道，在开始回放视频之前调用此方法
 [$zh]
 */
- (void)enterPlayback;

/**
 [^en]
 disconnect p2p channel
 [$en]

 [^zh]
 断开 p2p 通道
 [$zh]
 */
- (void)disConnect;

/**
 [^en]
 get current video width
 [$en]

 [^zh]
 获取当前视频宽度
 [$zh]
 
 @return video width
 */
- (CGFloat)getCurViewWidth;

/**
 [^en]
 get current video height
 [$en]

 [^zh]
 获取当前视频高度
 [$zh]
 
 @return video height
 */
- (CGFloat)getCurViewHeight;

/**
 [^en]
 start live video
 [$en]

 [^zh]
 开始视频实时预览
 [$zh]
 */
- (void)startPreview;

/**
[^en]
 start live video
[$en]

[^zh]
 开始视频实时预览
 @param definition definition
[$zh]
*/
- (void)startPreviewWithDefinition:(TuyaSmartCameraDefinition)definition;

/**
 [^en]
 stop live video
 [$en]

 [^zh]
 停止视频实时预览
 [$zh]
 */
- (void)stopPreview;

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

/**
 [^en]
 enable mute state, the default is YES
 [$en]

 [^zh]
 开启静音状态，默认为YES
 [$zh]
 
 @param mute is mute
 */
- (void)enableMute:(BOOL)mute forPlayMode:(TuyaSmartCameraPlayMode)playMode;

/**
 [^en]
 start talk to device
 [$en]

 [^zh]
 开始与设备对讲
 [$zh]
 */
- (void)startTalk;

/**
 [^en]
 stop talk to device.
 [$en]

 [^zh]
 停止与设备对讲
 [$zh]
 */
- (void)stopTalk;

/**
 [^en]
 start record video, the video record will saved in photo album.
 [$en]

 [^zh]
 开始录制视频，视频将会存储在系统相册
 [$zh]
 */
- (void)startRecord;

/**
 [^en]
 stop record video.
 [$en]

 [^zh]
 停止录制视频
 [$zh]
 */
- (void)stopRecord;

/**
 [^en]
 get a screenshot of the video and save it to photo album. photo asset collection name is bundle name, "[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]".
 [$en]

 [^zh]
 获取视频的截图，图片将存储在系统相册。photo asset collection 名字为 bundle 名。"[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]"
 [$zh]
 */
- (UIImage *)snapShoot;

/**
 [^en]
 enbale high definition
 [$en]

 [^zh]
 开启高清分辨率
 [$zh]
 
 @param hd is high definition
 */
- (void)enableHD:(BOOL)hd;

/**
[^en]
set definition
[$en]

[^zh]
设置分辨率
[$zh]

@param definition definition
*/
- (void)setDefinition:(TuyaSmartCameraDefinition)definition;

/**
 [^en]
 get the definition state
 [$en]

 [^zh]
 获取当前分辨率
 [$zh]
 */
- (void)getHD;

/**
[^en]
get the definition state
[$en]

[^zh]
获取当前分辨率
[$zh]
*/
- (void)getDefinition;

/**
 [^en]
 query the date of video recording in a month.
 [$en]

 [^zh]
 获取当月的存在录制视频数据的日期
 [$zh]

 @param year ex: 2019
 @param month ex: 1
 */
- (void)queryRecordDaysWithYear:(NSUInteger)year month:(NSUInteger)month;

/**
 [^en]
 query all video record slices for a particular day.
 [$en]

 [^zh]
 查询某一天所有的录制视频片段
 [$zh]
 
 @param year ex: 2019
 @param month ex: 1
 @param day ex: 3
 */
- (void)queryRecordTimeSliceWithYear:(NSUInteger)year month:(NSUInteger)month day:(NSUInteger)day;

/**
 [^en]
 start playback from a point in time, using unix timestamp
 [$en]

 [^zh]
 从某个时间开始回放，使用 unix 时间戳
 [$zh]
 
 @param playTime [^en]play time[$en] [^zh]开始播放的时间[$zh]
 @param startTime [^en]start time of a video slice[$en] [^zh]视频片段的开始时间[$zh]
 @param stopTime [^en]end time of a video slice[$en] [^zh]视频片段的结束时间[$zh]
 */
- (void)startPlayback:(NSInteger)playTime startTime:(NSInteger)startTime stopTime:(NSInteger)stopTime;

/**
 [^en]
 pause playback
 [$en]

 [^zh]
 暂停回放
 [$zh]
 */
- (void)pausePlayback;

/**
 [^en]
 resume play back
 [$en]

 [^zh]
 恢复回放
 [$zh]
 */
- (void)resumePlayback;

/**
 [^en]
 stop play back
 [$en]

 [^zh]
 停止回放
 [$zh]
 */
- (void)stopPlayback;

@optional

- (void)registerVideoRenderView:(UIView<TuyaSmartVideoViewType> *)videoView;
- (void)uninstallVideoRenderView:(UIView<TuyaSmartVideoViewType> *)videoView;

/**
[^en]
connect p2p with specified mode
[$en]

[^zh]
以指定的模式连接 p2p 通道
[$zh]
*/
- (void)connectWithMode:(TuyaSmartCameraConnectMode)mode;

- (double)getVideoBitRateKBPS;

/**
[^en]
if you want processing the audio data of talking, call this with YES and implement the delegate method:
 - (void)camera: ty_didRecieveAudioRecordDataWithPCM: length: sampleRate:
[$en]

[^zh]
如果需要处理对讲的音频数据，调用此方法并传入YES，实现 - (void)camera: ty_didRecieveAudioRecordDataWithPCM: length: sampleRate: 代理方法获取数据
[$zh]
*/
- (void)enableAudioProcess:(BOOL)enable;

/**
 [^en]
 Description Send audio data to device.
 [$en]
 [^zh]
 发送音频数据给设备
 [$zh]
 @param data Audio data.
 @param length Audio data size.
 @param sampleRate Audio sample rate.
 */
- (void)sendAudioDataWithPCM:(unsigned char *)data length:(int)length sampleRate:(int)sampleRate;

/**
[^en]
start record video, the video record will saved in filepath
[$en]

[^zh]
开始录制视频，视频将会存储在指定目录
[$zh]
*/
- (void)startRecordWithFilePath:(NSString *)filePath;

- (void)startRecordWithRotateDirection:(TuyaSmartVideoRotateDirection)direction filePath:(NSString *)filePath;

/**
[^en]
get a screenshot of the video and save it to filepah. if you do not need a thumbnil, set thumbnilPath nil.
[$en]

[^zh]
获取视频截图并存储到指定目录。如果你不需要缩略图，请将thumbnilPath置为nil
[$zh]
*/
- (UIImage *)snapShootSavedAtPath:(NSString *)filePath thumbnilPath:(NSString *)thumbnilPath;

- (int)downloadPlayBackVideoWithRange:(NSRange)timeRange filePath:(NSString *)videoPath success:(void(^)(NSString *filePath))success progress:(void(^)(NSUInteger progress))progress failure:(void(^)(NSError *error))failure;

/**
    pause download
 */
- (int)pausePlayBackDownloadWithResponse:(void (^)(int))callback;

/**
    resume download
 */
- (int)resumePlayBackDownloadWithResponse:(void (^)(int))callback;

/**
 Description Stop current sd card playback.
 
 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (int)stopPlayBackDownloadWithResponse:(void (^)(int errCode))callback;


- (int)deletePlayBackDataWithDay:(NSString *)day onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finishedCallBack;

- (void)speedPlayWithPlayBackSpeed:(TuyaSmartCameraPlayBackSpeed)playBackSpeed;

/**
 Enable speaker

 @param enabled Speaker enabled
 @return error code, 0 is success
*/
- (int)enableSpeaker:(BOOL)enabled;

/**
  Get speaker enabled status
*/
- (BOOL)speakerEnabled;

#pragma mark - private, please igore these method

- (void)getSupportedDefinitions:(void(^)(NSArray *definitions))success failure:(void(^)(NSError *error))failure;

//- (void)getDefinition:(void(^)(TuyaSmartCameraDefinition definitions))success failure:(void(^)(NSError *error))failure;

//- (void)setDefinition:(TuyaSmartCameraDefinition)definition success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)setOutLineEnable:(BOOL)enable;

- (void)switchChannel:(int)channel success:(void (^)(void))success failure:(void(^)(int errCode))failure;

- (void)queryAlbumFileIndexWithAlbumName:(NSString *)albumName success:(void(^)(NSDictionary *index))success failure:(void(^)(int errCode))failure;

- (void)startDownloadAlbumFileWithAlbumName:(NSString *)albumName
                                     folder:(NSString *)folder
                                   fileList:(NSArray *)fileList
                                isThumbnail:(BOOL)isThumbnail
                          onOverAllProgress:(void(^)(int progress))overallProgress
                             onFileProgress:(void(^)(NSString *fileName, int progress, BOOL finished))fileProgress
                              onFileFailure:(void(^)(NSString *filename, int errCode))fileFailure
                                 onFinished:(void(^)(int errCode))finished;

-(void)cancelDownloadAlbumFile;

-(void)deleteAlbumFileWithAlbumName:(NSString*)albumName fileList:(NSArray *)fileList success:(void(^)(void))success failure:(void(^)(int errCode))failure;

@end
