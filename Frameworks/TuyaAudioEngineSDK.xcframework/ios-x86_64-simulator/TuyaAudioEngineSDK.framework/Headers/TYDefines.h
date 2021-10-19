//
//  Defines.h
//  TuyaAudioEngineSDK
//
//  Created by xucs on 2021/6/28.
//

#ifndef Defines_h
#define Defines_h

#define TuyaAudioEngine_version "1.0.1"

typedef enum{
    VERY_LOW = 0 ,
    LOW,
    MEDIUM,
    HIGH
}VAD_LEVEL;

typedef enum{
    AUDIO_PCM = 0 ,
}AUDIO_TYPE ;

typedef enum{
    kTuyaVADErrCode_NoErr                   =  0,       // 错误码 无错
    kTuyaVADErrCode_DetectedErr             = -10001 ,  // 做voiceDetect时发生错误，原因未知
}TuyaVADErrCode;

#endif /* Defines_h */
