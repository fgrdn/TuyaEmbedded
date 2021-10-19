//
//  TuyaSmartCameraDefines.h
//  TuyaSmartCamera
//
//  Created by 傅浪 on 2019/1/10.
//

#ifndef TuyaSmartCameraDefines_h
#define TuyaSmartCameraDefines_h

#ifdef __cplusplus
#define IPC_EXTERN        extern "C" __attribute__((visibility ("default")))
#else
#define IPC_EXTERN        extern __attribute__((visibility ("default")))
#endif

#import <Foundation/Foundation.h>

typedef enum
{
    TUYA_MEDIA_CODEC_UNKNOWN           = 0x00,
    TUYA_MEDIA_CODEC_VIDEO_MPEG4       = 0x4C,
    TUYA_MEDIA_CODEC_VIDEO_H263        = 0x4D,
    TUYA_MEDIA_CODEC_VIDEO_H264        = 0x4E,
    TUYA_MEDIA_CODEC_VIDEO_MJPEG       = 0x4F,
    TUYA_MEDIA_CODEC_VIDEO_H265        = 0x50,

}TUYA_ENUM_CODECID;

typedef struct {
    TUYA_ENUM_CODECID      codec_id;           // [^en]video coding mode[$en] [^zh]视频编码模式[$zh]
    unsigned long          timeStamp;          // [^en]video time stamp[$en] [^zh]视频时间戳[$zh]
} TuyaSmartVideoStreamInfo;

typedef struct {
    int nWidth;
    int nHeight;
    
    int nFrameRate;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
} TuyaSmartVideoFrameInfo;

typedef struct {
    int codecid;
    int nChannelNum;
    int nSampleRate;
    int nBitWidth;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
} TuyaSmartAudioFrameInfo;

typedef enum {
    TY_ERROR_NONE,                      // 0
    TY_ERROR_CONNECT_FAILED,            // 1    [^en]connect failed[$en] [^zh]连接失败[$zh]
    TY_ERROR_CONNECT_DISCONNECT,        // 2    [^en]connect did disconnected[$en] [^zh]连接已断开[$zh]
    TY_ERROR_ENTER_PLAYBACK_FAILED,     // 3    [^en]connect playback channel failed[$en] [^zh]连接回放通道失败[$zh]
    TY_ERROR_START_PREVIEW_FAILED,      // 4    [^en]preview failed. if the connection is broken during the preview process, it will alse call back this error.[$en] [^zh]预览失败。 如果在预览建立连接过程中失败了，也会抛出此错误[$zh]
    TY_ERROR_START_PLAYBACK_FAILED,     // 5    [^en]playback failed. if the connection is broken during the playback process, it will alse call back this error.[$en] [^zh]回放失败。 如果在回放建立连接过程中失败了，也会抛出此错误[$zh]
    TY_ERROR_PAUSE_PLAYBACK_FAILED,     // 6    [^en]pause playabck failed[$en] [^zh]暂停回放失败[$zh]
    TY_ERROR_RESUME_PLAYBACK_FAILED,    // 7    [^en]resume playabck failed[$en] [^zh]恢复回放失败[$zh]
    TY_ERROR_ENABLE_MUTE_FAILED,        // 8    [^en]mute failed.[$en] [^zh]静音失败[$zh]
    TY_ERROR_START_TALK_FAILED,         // 9    [^en]start talk to device failed[$en] [^zh]开启对讲失败[$zh]
    TY_ERROR_SNAPSHOOT_FAILED,          // 10   [^en]get screenshot failed[$en] [^zh]获取截屏失败[$zh]
    TY_ERROR_RECORD_FAILED,             // 11   [^en]record video failed[$en] [^zh]录制视频失败[$zh]
    TY_ERROR_ENABLE_HD_FAILED,          // 12   [^en]set definition state failed[$en] [^zh]设置清晰度失败[$zh]
    TY_ERROR_GET_HD_FAILED,             // 13   [^en]get definition state failed[$en] [^zh]获取清晰度失败[$zh]
    TY_ERROR_QUERY_RECORD_DAY_FAILED,   // 14   [^en] query video record date failed[$en] [^zh]查询录制视频日期失败[$zh]
    TY_ERROR_QUERY_TIMESLICE_FAILED,    // 15   [^en]query video record slice failed[$en] [^zh]查询录制视频片段失败[$zh]
} TYCameraErrorCode;

typedef NS_ENUM(NSUInteger, TuyaSmartCameraPlayMode) {
    TuyaSmartCameraPlayModeNone,
    TuyaSmartCameraPlayModePreview,     // [^en]live[$en] [^zh]直播[$zh]
    TuyaSmartCameraPlayModePlayback     // [^en]playback[$en] [^zh]回放[$zh]
};

typedef NS_ENUM(NSUInteger, TuyaSmartCameraTalkbackMode) {
    TuyaSmartCameraTalkbackNone,
    TuyaSmartCameraTalkbackOneWay,
    TuyaSmartCameraTalkbackTwoWay
};

typedef NS_ENUM(NSUInteger, TuyaSmartCameraDefinition) {
    TuyaSmartCameraDefinitionProflow    = 0x1,      // [^en]Data Save[$en] [^zh]省流量[$zh]
    TuyaSmartCameraDefinitionStandard   = 0x2,      // [^en]SD[$en] [^zh]标清[$zh]
    TuyaSmartCameraDefinitionHigh       = 0x4,      // [^en]HD[$en] [^zh]高清[$zh]
    TuyaSmartCameraDefinitionSuper      = 0x8,      // [^en]FHD[$en] [^zh]超清[$zh]
    TuyaSmartCameraDefinitionSSuper     = 0x10,     // [^en]FFHD[$en] [^zh]超超清[$zh]
    TuyaSmartCameraDefinitionAudioOnly  = 0xFFFF    // [^en]Audio Only[$en] [^zh]语音模式[$zh]
};

typedef NS_ENUM(NSUInteger, TuyaSmartCameraPlayBackSpeed) {
    TuyaSmartCameraPlayBackSpeed_05TIMES = 0,   // [^en]0.5 times [$en] [^zh]0.5倍速[$zh]
    TuyaSmartCameraPlayBackSpeed_10TIMES,       // [^en]1.0 times [$en] [^zh]1.0倍速[$zh]
    TuyaSmartCameraPlayBackSpeed_15TIMES,       // [^en]1.5 times [$en] [^zh]1.5倍速[$zh]
    TuyaSmartCameraPlayBackSpeed_20TIMES,       // [^en]2.0 times [$en] [^zh]2.0倍速[$zh]
    TuyaSmartCameraPlayBackSpeed_25TIMES,       // [^en]2.5 times [$en] [^zh]2.5倍速[$zh]
    TuyaSmartCameraPlayBackSpeed_30TIMES,       // [^en]3.0 times [$en] [^zh]3.0倍速[$zh]
    TuyaSmartCameraPlayBackSpeed_35TIMES,       // [^en]3.5 times [$en] [^zh]3.5倍速[$zh]
    TuyaSmartCameraPlayBackSpeed_40TIMES,       // [^en]4.0 times [$en] [^zh]4.0倍速[$zh]
};

#endif /* TuyaSmartCameraDefines_h */
