//
//  Device.h
//  TYCameraSdk
//
//  Created by Jim on 2018/4/3.
//  Copyright © 2018年 Tuya. All rights reserved.
//

#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>

#include "TYDefines.h"

#import "TYPlayBackFragmentModel.h"

@protocol TYCameraDelegate;

@interface TYCamera : NSObject

@property (nonatomic, strong) NSString                *name;              // device name
@property (nonatomic, strong) NSString                *did;               // device id
@property (nonatomic, strong) NSString                *stationDid;        // device id
@property (nonatomic, strong) NSString                *pid;               // product id
@property (nonatomic, assign) int                     nCameraType;        // 0  --  单品摄像头
                                                                          // 1  --  基站摄像头
@property (nonatomic, strong) NSString                *username;          // p2p username
@property (nonatomic, strong) NSString                *password;          // p2p password
@property (nonatomic, strong) NSString                *p2pToken;          // p2p token
@property (nonatomic, assign) int                     p2pType;            // inner p2p type
@property (nonatomic, assign) int                     session;            // p2p session value
@property (nonatomic, assign) BOOL                    isConnected;        // connect status
@property (nonatomic, assign) BOOL                    isRecording;        // mp4 record status
@property (nonatomic, assign) BOOL                    isTalking;          // voice talk status
@property (nonatomic, assign) BOOL                    isLiving;           // preview status
@property (nonatomic, assign) BOOL                    isPlaybacking;      // sd card playback status
@property (nonatomic, assign) BOOL                    mute;               // mute status
@property (nonatomic,   weak) id<TYCameraDelegate>    delegate;

- (instancetype)init NS_UNAVAILABLE;

/**
 Description Simple camera initializer.
 
 @param did Device did.
 @return TYCamera object.
 */
- (instancetype)initWithDID:(NSString *)did productId:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 Description Station sub camera initializer.
 
 @param subDeviceNodeId subDeviceNodeId
 @param stationDid stationDid
 @return TYCamera object.
 */
- (instancetype)initWithSubdeviceNodeId:(NSString *)subDeviceNodeId stationDid:(NSString*)stationDid productId:(NSString *)pid NS_DESIGNATED_INITIALIZER;


/**
 Description Station sub camera initializer.
 @param did         sub device id
 @param subDeviceNodeId subDeviceNodeId
 @param stationDid stationDid
 @return TYCamera object.
 */
- (instancetype)initWithSubdeviceID:(NSString*)did nodeId:(NSString *)nodeID stationDid:(NSString*)stationDid productId:(NSString *)pid NS_DESIGNATED_INITIALIZER;


/**
 Description P2P 3.0 connect(Normal mode, exchange signal through MQTT 302)

 @param username p2p username.
 @param pwd p2p password.
 @param token tuya p2p token.
 @param traceId p2p fulllink log traceId.
 @return retcode >= 0: session id, retcode < 0: error code
 */
- (int)connectWithUserName:(NSString *)username password:(NSString *)pwd token:(NSString *)token traceId:(NSString *)traceId;

/**
Description P2P 3.0 connect(Normal mode, exchange signal through MQTT 302)

@param username p2p username.
@param pwd p2p password.
@param token tuya p2p token.
@param skills tuya p2p skills for pre connect. supported while  p2p version >= 0xF4030400
@param traceId p2p fulllink log traceId.
@return retcode >= 0: session id, retcode < 0: error code
*/
- (int)connectWithUserName:(NSString *)username password:(NSString *)pwd token:(NSString *)token skills:(NSString *)skills traceId:(NSString *)traceId;


/**
 Description P2P 3.0 connect(LAN mode, exchange signal through LAN udp package)

 @param username p2p username.
 @param pwd p2p password.
 @param token tuya p2p token.
 @param traceId p2p fulllink log traceId.
 @return retcode >= 0: session id, retcode < 0: error code
 */
- (int)connectByLANmodeWithUserName:(NSString *)username password:(NSString *)pwd token:(NSString *)token  traceId:(NSString *)traceId;


/**
Description P2P 3.0 connect(LAN mode, exchange signal through LAN udp package)

@param username p2p username.
@param pwd p2p password.
@param token tuya p2p token.
@param skills tuya p2p skills for pre connect.   supported while  p2p version >= 0xF4030400
@param traceId p2p fulllink log traceId.
@return retcode >= 0: session id, retcode < 0: error code
*/
- (int)connectByLANmodeWithUserName:(NSString *)username password:(NSString *)pwd token:(NSString *)token skills:(NSString *)skills traceId:(NSString *)traceId;


/**
 Description P2P 2.0 connect (PPCS)

 @param username p2p username.
 @param pwd p2p password.
 @param serverString serverString for this camera
 @param traceId p2p fulllink log traceId.
 @return retcode >= 0: session id, retcode < 0: error code
 */
- (int)connectWithUserName:(NSString *)username password:(NSString *)pwd serverString:(NSString *)serverString traceId:(NSString *)traceId;

- (void)disconnect;

- (void)setRemoteOnline;

/**
 Description Get device abilitys.

 @param callback Async result callback. abilitys: fixed abilitys (in bit), see TY_CMD_QUERY_IPC_FIXED_ABILITY_TYPE, errCode see TuyaErrCode.
 */
- (void)getAbilitys:(void (^)(int abilitys, int errCode))callback;


/**
 Description Get audio params from device(sample rate, bitwidth, channels).

 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)getAudioParams:(void (^)(NSString *result, int errCode))callback;


/**
 Description Get video params from deivce.

 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)getVideoParams:(void (^)(NSString *json, int errCode))callback;


/**
 Description Get device current video clarity mode and all support modes.

 @param callback Async result callback. currentClarity see TRANSFER_VIDEO_CLARITY_TYPE_E. supportClarity see TRANSFER_VIDEO_CLARITY_TYPE_E. errCode see TuyaErrCode.
 */
- (void)getVideoClarity:(void (^)(int currentClarity, int supportClarity, int errCode))callback;


/**
 Description Set video clarity to device.

 @param clarityMode See TRANSFER_VIDEO_CLARITY_TYPE_E.
 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)setVideoClarity:(int)clarityMode onResponse:(void (^)(NSString *result, int errCode))callback;


/**
 Description Startup preview.

 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)startPreviewWithClarityMode:(TuyaVideoClarityMode)mode onResponse:(void (^)(int errCode))callback;

/**
 Description Startup preview.
 
 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)stopPreview:(void (^)(int errCode))callback;



/**
 Description Get current camera mute status.

 @return return YES: mute, No: not mute.
 */
- (BOOL)mute;


/**
 Description Set current mute state.

 @param muted YES: mute, No: not mute.
 @param callback errCode see TuyaErrCode.
 */
- (void)setMute:(BOOL)muted onResponse:(void (^)(int errCode))callback;

/**
 Description Get alarm days in one month.

 @param month format:"201804"
 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)getSDRecordDaysWithMonth:(NSString *)month onResponse:(void (^)(int daysOnBit, int errCode))callback;


/**
 Description Get alarms by day.

 @param day format:"20180425"
 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)getSDRecordFragmentsWithDay:(NSString *)day onResponse:(void (^)(NSArray<TYPlayBackFragmentModel *> *fragments, int errCode))callback;


/**
 Description Startup sd card playback.

 @param startTime Alarm fragment start timestamp(unix).
 @param stopTime Alarm fragment end timestamp(unix).
 @param playTime From which time point(unix).
 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)startPlayBackWithStartTime:(int)startTime stopTime:(int)stopTime playTime:(int)playTime onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int startTime,int stopTime,int errCode))finishedCallBack;


/**
 Description Pause current sd card playback.

 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)pausePlayBackWithResponse:(void (^)(int errCode))callback;

/**
 Description Resume current sd card playback.

 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)resumePlayBackWithResponse:(void (^)(int errCode))callback;


/**
 Description Stop current sd card playback.

 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)stopPlayBackWithResponse:(void (^)(int errCode))callback;


/**
Description set the play speed for sd card playback
 
@param speed the play speed.
 
@param callback Async result callback. errCode see TuyaErrCode.
*/
- (int)setPlayBackSpeedWithSpeed:(TuyaPlayBackSpeedMode)speed onResponse:(void (^)(int errCode))callback ;


/**
 Description Config cloud data tags.

 @param jsonCloudDataTags Cloud data tags, json get from http server.
 */
- (int)configCloudDataTags:(NSString *)jsonCloudDataTags;


/**
 Description Config cloud data tags (microsoft cloud).
 
 @param jsonCloudDataTags Cloud data tags, json get from http server.
 @return array
 */
- (NSString *)configCloudDataTagsV2:(NSString*)jsonCloudDataTags;

/**
 Description Startup play cloud data.

 @param startTime The start time expect to play(unix time in second).
 @param endTime The end time expect to stop(unix time in second).
 @param isEvent If this is a event.
 @param jsonAuthParams Auth data, get from http server.
 @param encryptKey Encrypt key to tell sdk how to decrypt media data.
 @param callback Async result callback. errCode see TuyaErrCode.
 @param finihedCallBack Async result callback. errCode see TuyaErrCode.
 */
- (int)playCloudDataWithStartTime:(int)startTime endTime:(int)endTime isEvent:(bool)isEvent authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finihedCallBack;


/**
Description set the play speed for cloud data
 
@param speed the play speed.
 
@param callback Async result callback. errCode see TuyaErrCode.
*/
- (int)setForPlayCloudDataSpeedWithSpeed:(TuyaPlayBackSpeedMode)speed onResponse:(void (^)(int errCode))callback ;


/**
 Description Pause to play current cloud data.

 @return errCode see TuyaErrCode.
 */
- (int)pausePlayCloudData;


/**
 Description Resume to play current cloud data.

 @return errCode see TuyaErrCode.
 */
- (int)resumePlayCloudData;


/**
 Description Stop to play current cloud data.

 @return errCode see TuyaErrCode.
 */
- (int)stopPlayCloudData;


- (int)playVideoMessageWithUrl:(NSString *)url startTime:(int)startTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finihedCallBack;


- (int)pausePlayVideoMessage;


- (int)resumePlayVideoMessage;


- (int)stopPlayVideoMessage;


/**
 Description Startup mp4 record.

 @param folderPath Directory path to storage mp4 file(Not include last "/").
 @param fileName Mp4 File name like "xxxx.mp4"
 */
- (void)startRecordWithFolderPath:(NSString *)folderPath fileName:(NSString *)fileName;

/**
 Description Startup mp4 record.

 @param folderPath Directory path to storage mp4 file(Not include last "/").
 @param fileName Mp4 File name like "xxxx.mp4"
 @param rotate the angle for video rotate while recording mp4. anti-clockwise
 */

- (void)startRecordWithFolderPath:(NSString *)folderPath fileName:(NSString *)fileName rotate:(TuyaRotateMode)rotate ;


/**
 Description Stop mp4 recording.

 @return errCode see TuyaErrCode.
 */
- (int)stopRecord;


/**
 Description Startup voice talk.

 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)startAudioTalk:(void (^)(int errCode))callback;


/**
 Description Send audio data to device.

 @param data Audio data.
 @param length Audio data size.
 */
- (void)sendAudioDataWithPCM:(unsigned char *)data length:(int)length sampleRate:(int)sampleRate ;


/**
 Description Stop audio talk.
 */
- (void)stopAudioTalk;


/**
 Description Snapshot

 @param absolutePath Absolute snapshot file path(Include file name).
 @param callback Async result callback. errCode see TuyaErrCode.
 */
- (void)snapshotWithAbsolutePath:(NSString *)absolutePath result:(void (^)(int errCode))callback;


/**
 Description Pass-through data from app to device.

 @param data User data.
 @param nLength Data size.
 */
- (void)sendUserData:(unsigned char *)data length:(int)nLength;


/**
 Description
    drame active object frame supported or not
 
 @param enable drame active object frame supported or not
 */
- (void)enableIVA:(BOOL)enable;


/**
 Description Startup sd card playback download. u can down load mutli fragment every time.
 @param startTime Alarm fragment start timestamp(unix).
 @param stopTime Alarm fragment end timestamp(unix).
 @param callback Async result callback. errCode see TuyaErrCode..
 */
- (int)startPlayBackDownloadWithStartTime:(int)startTime stopTime:(int)stopTime FolderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName onResponse:(void (^)(int errCode))callback onProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(int errCode))finishedCallBack;

- (int)startPlayBackDownloadWithStartTime:(int)startTime stopTime:(int)stopTime FolderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName rotate:(TuyaRotateMode)rotate onResponse:(void (^)(int errCode))callback onProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(int errCode))finishedCallBack;

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


/**
Description Stop current sd card playback.
@param day  : the day need to delete.
@param callback : Async result callback. errCode see TuyaErrCode.
@param finishedCallBack : Async delete result callback. errCode see TuyaErrCode
*/
- (int)deletePlayBackDataWithDay:(NSString *)day onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finishedCallBack;


/**
 Description                download the playback event image.
 @param startTime           fragment start timestamp(unix).
 @param stopTime            fragment end timestamp(unix).
 @param folder              the local folder u need to save it.
 @param saveFileName        the local file name u need to save it .
 @param callback Async result callback. errCode see TuyaErrCode..
*/
- (int)downloadPlayBackImageWithStartTime:(int)startTime stopTime:(int)stopTime  FolderPath:(NSString *)folder saveFileName:(NSString *)saveFileName onResponse:(void (^)(int errCode))callback ;

/**
Description
   enable audio process or not
@param enable enable audio preprocess for client or not
*/
- (void)enableAudioProcess:(BOOL)enable ;
// for audio message start
// 开始播放纯音频消息
- (int)startPlayAudioMessageWithUrl:(NSString *)url startTime:(int)startTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback  onFinish:(void (^)(int errCode))finihedCallBack ;
// 暂停播放纯音频消息
- (int)pausePlayAudioVideoMessage ;
// 恢复纯音频消息
- (int)resumePlayAudioMessage;

// 停止播放纯音频消息
- (int)stopPlayAudioMessage ;
// for audio message end

/*
 Description
 @param nStartTime 云存储视频的起始时间
 @param nStopTime 云存储视频的结束时间
 @param folderPath 存放mp4文件的文件夹
 @param mp4FileName mp4文件名
 @param callback 成功失败回调
 @param progressCallBack 进度回调
 @param finishedCallBack 结束回调
*/
- (void)startCloudDataDownloadWithStartTime:(int)startTime stopTime:(int)stopTime folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onnProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(int errCode))finishedCallBack;

- (void)startCloudDataDownloadWithStartTime:(int)startTime stopTime:(int)stopTime folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey rotate:(TuyaRotateMode)rotate onResponse:(void (^)(int errCode))callback onnProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(int errCode))finishedCallBack;


/*
 Description 暂停云存储视频下载
*/
- (void)pauseCloudDataDownloadWithResponse:(void (^)(int))callback;

/*
 Description 恢复云存储视频下载
*/
- (void)resumeCloudDataDownloadWithResponse:(void (^)(int))callback;

/*
 Description 取消云存储视频下载
*/
- (void)cancelCloudDataDownloadWithResponse:(void (^)(int))callback;

/*
 Description
 @param url
 @param encryptKey
 @param folderPath
 @param mp4FileName
 @param callback
 @param progressCallBack
 @param finishedCallBack
*/
- (void)startVideoMessageDownloadWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName onResponse:(void (^)(int errCode))callback onnProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(int errCode))finishedCallBack;

- (void)startVideoMessageDownloadWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName rotate:(TuyaRotateMode)rotate onResponse:(void (^)(int errCode))callback onnProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(int errCode))finishedCallBack;

/*
 Description pause download
*/
- (void)pauseVideoMessageDownloadWithResponse:(void (^)(int))callback;

/*
 Description resume download
*/
- (void)resumeVideoMessageDownloadWithResponse:(void (^)(int))callback;

/*
 Description cancel download
*/
- (void)cancelVideoMessageDownloadWithResponse:(void (^)(int))callback;

/*
 Description get current bitrate
 */
- (double)getInstantaneousBitRateKBps;


-(int)switchChannelWithChannel:(int)channel onResponse:(void (^)(int errCode))callback ;

/*
 Description query the all file by albumeName
 @param albumName   :   the name of album. The album max length is 48.
 @param callback    :   the response for p2p message
*/
-(int)queryAlbumFileIndexWithAlbumName:(NSString*)albumName onResponse:(void (^)(NSString *jsonindex, int errCode))callback ;

/*
 Description start download album file.
 @param albumName   :   the name of album. The album max length is 48.
 @param jsonfiles   :   the files we will download. and json formatted. the file name is the real file name or thumbnail file.The form for jsonfiles: {"files":["xxx.jpg","xxx.mp4"]} or {"files":[]} indicate the all files in the album（not supported this version）.
 @param thumbnail   :   the file we download is thumbnail or not. if the thumbnail is true ,the suffix of the file must be jpg.
 @param reponse     :   the response for p2p message
 @param onAllProgressCallBack   :   the progress of all file download .
 @param onSingleFileProgress    :   the progress of single file download.
 @param onFileDownloadFinish    :   the callback for all file download finished.
*/
-(int)startDownloadAlbumFileWithAlbumName:(NSString*)albumName folder:(NSString*)folder jsonfiles:(NSString*)jsonfiles thumbnail:(Boolean)thumbnail onResponse:(void (^)(int errCode))callback onAllProgress:(void (^)(int errCode, int nPos))onAllProgressCallBack onSingleFileProgress:(void (^)(int errCode, int nPos,NSString* filename))onSingleFileProgress onFileDownloadFinish:(void (^)(NSString* filename,int index ,int errCode))finishedCallBack;
/*
 Description cancel download album file.
 @param callback  : the response for p2p message
*/
-(int)cancelDownloadAlbumFileWithCallback:(void (^)(int errCode))callback ;

/*
 Description delete the album file. we will delete the thumbnail file too.
 @param albumName           :   the name of album. The album max length is 48.
 @param jsonfiles           :   the files we will download. and json formatted. the file name is the real file name. The form for jsonfiles: {"files":["xxx.jpg","xxx.mp4"]} or {"files":[]} indicate the all files in the album.
 @param callback            :   the response for p2p message
 @param finishedCallBack    :   the callback for all file delete finished.
*/
-(int)deleteAlbumFileWithAlbumName:(NSString*)albumName jsonfiles:(NSString*)jsonfiles onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finishedCallBack;

@end


@protocol TYCameraDelegate<NSObject>
@optional

/**
 Description The decoded image data callback.

 @param device Which camera the data belong to.
 @param sampleBuffer One decoded CMSampleBufferRef image data.
 @param videoFrameInfo Video frame metadata, see TuyaVideoFrameInfo.
 */
- (void)device:(TYCamera *)device didVideoFrameRecvedWithSampleBuffer:(CMSampleBufferRef)sampleBuffer videoFrameInfo:(TuyaVideoFrameInfo *)videoFrameInfo;


/**
 Description The decoded audio data callback

 @param device Which camera the data belong to.
 @param pcm PCM data
 @param PCMLength PCM data size
 @param audioInfo Audio metadata, see TuyaAudioFrameInfo.
 */
- (void)device:(TYCamera *)device didAudioDataRecvedWithPCM:(const unsigned char *)pcm length:(unsigned int)PCMLength audioFrameInfo:(TuyaAudioFrameInfo *)audioInfo;

/**
Description The decoded audio data callback

@param device Which camera the data belong to.
@param audioInfo Audio metadata, see TuyaAudioFrameInfo.
*/

- (void)device:(TYCamera *)device didAudioPlayWithAudioInfo:(TuyaAudioFrameInfo *)audioInfo;


/**
 Description session Session status callback immediately when it changes.
 
 @param device Which camera.
 @param status Current session status.
 */
- (void)device:(TYCamera *)device didSessionStatusChangedWithStatus:(NSInteger)status;


/**
 Description The audo record data callback

 @param device Which camera the data belong to.
 @param pcm the audio data.
 @param length the pcm length. size in byte
 @param samplRate the sample rate of the audio data
 */
- (void)device:(TYCamera *)device didAudioRecordDataReceiveWithPCM:(const unsigned char*)pcm length:(int)length sampleRate:(int)samplRate ;


@end
