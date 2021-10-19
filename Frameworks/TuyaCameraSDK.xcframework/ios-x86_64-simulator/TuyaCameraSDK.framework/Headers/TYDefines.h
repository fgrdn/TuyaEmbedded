//
//  TYDefines.h
//  TYCameraSdk
//
//  Created by Jim on 2018/3/14.
//  Copyright © 2018年 Tuya. All rights reserved.
//

#ifndef __TYDEFINES_H__
#define __TYDEFINES_H__


#define TuyaCameraSDK_version "3.31.0"

#define UNINITIALIZED -1

typedef struct tagTuyaVideoFrameInfo{
    int codecid;
    int nWidth;
    int nHeight;
    
    int nFrameRate;
    int nIsKeyFrame;
    char *sei;
    int nSeiSize;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
}TuyaVideoFrameInfo;

typedef struct tagTuyaAudioFrameInfo{
    int codecid;
    int nChannelNum;
    int nSampleRate;
    int nBitWidth;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
    bool bShowProgressOnly ;
}TuyaAudioFrameInfo;

typedef enum{
    kTuyaErrCode_NoErr                  =  0,       // 错误码 无错
    kTuyaErrCode_FragmentEnd            =  1,       // 错误码 片段播放结束通知
    kTuyaErrCode_Err                    =  -1,      // 错误码 通用错误
    kTuyaErrCode_ModuleNotInitialized   = -10000,   // 错误码 未初始化
    kTuyaErrCode_NotConnected           = -10001,   // 错误码 设备未连接
    kTuyaErrCode_SessionInvalid         = -10002,   // 错误码 无效的session
    kTuyaErrCode_TimeOut                = -10003,   // 错误码 超时
    kTuyaErrCode_ConnectionCancelled    = -10004,   // 错误码 连接被取消

    kTuyaErrCode_DeviceNotOnline        = -10006,   // 错误码 设备不在线
    kTuyaErrCode_CancelByUser           = -10007,   // 错误码 用户取消操作
    kTuyaErrCode_InvalidCommand         = -20001,   // 错误码 无效的命令
    kTuyaErrCode_ParamsInvalid          = -20002,   // 错误码 无效的参数
    kTuyaErrCode_DataInvalid            = -20003,   // 错误码 无效的数据
    kTuyaErrCode_Interrupted            = -20004,   // 错误码 操作被中断
    kTuyaErrCode_OperationNotAllowed    = -20005,   // 错误码 操作不允许
    kTuyaErrCode_VersionNotSupported    = -20006,   // 错误码 当前app版本不支持该协议[需要升级app]
    kTuyaErrCode_Busy                   = -20007,   // 错误码 设备当前繁忙[例:对讲已被其他占用之类]
    kTuyaErrCode_OutOfMemory            = -20008,   // 错误码 内存不足
    kTuyaErrCode_DownloadFailed         = -30001,   // 错误码 下载文件失败
    kTuyaErrCode_NotPlayBacking         = -30002,   // 错误码 不在回放状态
    kTuyaErrCode_SetPlaySpeedFailed     = -30003,   // 错误码 设置播放速度失败
    kTuyaErrCode_NotPlayCloudDataing    = -30004,   // 错误码 不在云存储o播放状态
    kTuyaErrCode_DelPlaybackDataFiled   = -30005,   // 错误码 删除回放数据失败
    kTuyaErrCode_DownLoadFragmentError  = -30006,   // 错误码 回放数据线下载时间片太长或者为0
    kTuyaErrCode_JpgSupportedOnly       = -30007,   // 错误码 回放图片仅支持jpg文件
    kTuyaErrCode_PLDownLoadStateError   = -30008,   // 错误码 回放下载，状态错误。
    kTuyaErrCode_DownLoadImageFailed    = -30009,   // 错误码 回放下载，状态错误。
    kTuyaErrCode_CurlError              = -30010,   // 错误码 Curl连接错误
    /* MP4相关错误 */
    kTuyaErrCode_Mp4NotRecording        = -30011,   // 错误码 当前并未进行文件录制
    kTuyaErrCode_Mp4SetAVConfigFailed   = -30012,   // 错误码 音视频参数有误
    kTuyaErrCode_Mp4HeaderWriteFailed   = -30013,   // 错误码 mp4文件头写入失败
    kTuyaErrCode_Mp4TrailerWriteFailed  = -30014,   // 错误码 mp4文件trailer写入失败
    kTuyaErrCode_StartAudioTalkFailed   = -30050,   // 错误码 开启对讲失败
    kTuyaErrCode_ResponseReturnErr      = -30060,   // 错误码 设备端Response 返回错误
    kTuyaErrCode_ErrOccurDataTransport  = -30061,   // 错误码 数据传输过程中出现错误
    kTuyaErrCode_FileNotExists          = -30062,   // 错误码 文件不存在
    kTuyaErrCode_CreateFileFailed       = -30063,   // 错误码 创建本地文件失败，请检查路径是否存在。
    kTuyaErrCode_TooManyFilesDownload   = -30064,   // 错误码 下载的文件太多或者为0
    kTuyaErrCode_DeleteFilesFailed      = -30065,   // 错误码 删除文件失败
}TuyaErrCode;

typedef enum{
    kTuyaSessionStatus_Connected        =  0,       // 链接成功
    kTuyaSessionStatus_ConnectTimeout   = -3,       // 链接超时
    kTuyaSessionStatus_ClosedRemote     = -12,      // 链接断开
    kTuyaSessionStatus_ClosedTimeOut    = -13,      // 链接超时
    kTuyaSessionStatus_ClosedCalled     = -14,      // 链接关闭
}TuyaSessionStatus;

typedef enum{
    kTuyaVideoClarityProflow            = 0x1,      // 省流量
    kTuyaVideoClarityStandard           = 0x2,      // 标清
    kTuyaVideoClarityHigh               = 0x4,      // 高清
    kTuyaVideoClaritySuperHigh          = 0x8,      // 超清
    kTuyaVideoClarityAudioOnly          = 0xFFFF,   // 语音模式(只有语音没有视频)
}TuyaVideoClarityMode;

typedef enum{
    TY_VIDEO_CLARITY_PROFLOW            = 0x1,      // 省流量
    TY_VIDEO_CLARITY_STANDARD           = 0x2,      // 标清
    TY_VIDEO_CLARITY_HIGH               = 0x4,      // 高清
    TY_VIDEO_CLARITY_S_HIGH             = 0x8,      // 超清
    TY_VIDEO_CLARITY_SS_HIGH            = 0x10,     // 超超清
}TRANSFER_VIDEO_CLARITY_TYPE_E;

typedef enum{
    TY_VIDEO_OUTPUT_FORMAT_RAWDATA,                 // 视频裸流(H.264/H.265)
    TY_VIDEO_OUTPUT_FORMAT_YUV,                     // 解码后的数据
}TuyaVideoOutputFormat;

typedef enum{
    TY_AUDIO_OUTPUT_FORMAT_RAWDATA,                 // 音频裸流(G.711a/u/pcm/aac)
    TY_AUDIO_OUTPUT_FORMAT_PCM,                     // 解码后的数据
}TuyaAudioOutputFormat;

typedef struct __fragmentSection__{
    int startTime ;
    int endTime ;
}FragmentSection;

typedef enum{
    TY_SPEED_05TIMES = 0,               // 半倍速
    TY_SPEED_10TIMES ,                  // 正常速度
    TY_SPEED_15TIMES ,                  // 1.5倍
    TY_SPEED_20TIMES ,                  // 2.0倍
    TY_SPEED_25TIMES ,                  // 2.5倍         暂不支持
    TY_SPEED_30TIMES ,                  // 3.0倍         暂不支持
    TY_SPEED_35TIMES ,                  // 3.5倍         暂不支持
    TY_SPEED_40TIMES ,                  // 4.0倍         暂不支持
}TuyaPlayBackSpeedMode;


typedef enum
{
    TY_PLAYBACK_EVENT_TYPE_NONE = 0,                // 无事件
    TY_PLAYBACK_EVENT_TYPE_MD,                      // 移动侦测
    TY_PLAYBACK_EVENT_TYPE_FACE,                    // 人脸检测
    TY_PLAYBACK_EVENT_TYPE_BODY,                    // 人形物
    TY_PLAYBACK_EVENT_TYPE_MAX
}TuyaPlayBackEventType ;

typedef enum {
    TY_ROTATE_NORMAL        =   0 ,                     // 正常
    TY_ROTATE_90_ANGLE      =   1 ,                     // 顺时针旋转90度
    TY_ROTATE_180_ANGLE     =   2 ,                     // 顺时针旋转180度
    TY_ROTATE_270_ANGLE     =   3 ,                     // 顺时针旋转270度
}TuyaRotateMode;

#endif // __TYDEFINES_H__
