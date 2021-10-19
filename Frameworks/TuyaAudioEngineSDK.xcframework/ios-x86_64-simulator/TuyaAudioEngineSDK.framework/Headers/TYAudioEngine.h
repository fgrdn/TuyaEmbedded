//
//  TYAudioEngine.h
//  TuyaAudioEngineSDK
//
//  Created by xucs on 2021/6/23.
//

#import <Foundation/Foundation.h>
#include "TYDefines.h"

@protocol TYAudioEngineDelegate;

@interface TYAudioEngine : NSObject

@property (nonatomic,   weak) id<TYAudioEngineDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
/**
    sharedInstance.
 */
+ (instancetype)sharedInstance ;

/*
    get the sdk version.
 */
-(NSString*) getSDKVersion ;

/*
    create the vad engine.
 */
-(int) createVADEngine ;

/**
    set the vad engine parameters.
 @param sampleRate              sample rate for audio record. 8000、16000 and 32000 supported only.
 @param channels                   channels for audio record.   1 supported only.
 @param level                          vad level . See the VAD_LEVEL .
 @param maxVoiceInMS           the max voice length in ms.
 */
-(int) setVADEngineParametersWithSampleRate:(int)sampleRate channels:(int)channels level:(VAD_LEVEL)level maxVoiceInMS:(int)maxVoiceInMS ;

/**
    start VAD engine.
 */
-(int) startVADEngine ;

/**
    stop vad engine.
 */
-(int) stopVADEngine ;

/**
    destroy vad engine ;
 */
-(int) destroyVADEngine ;

/**
    enable debug or not .
 */
-(int) enableDebugWithEnable:(bool)enable ;

@end

@protocol TYAudioEngineDelegate<NSObject>
@required
- (void)audioEngineDidVoiceDetected:(TYAudioEngine *)engine;
- (void)audioEngine:(TYAudioEngine *)engine didErrorHappendedWithError:(int)error ;
- (void)audioEngine:(TYAudioEngine *)engine didVoiceDataRecvedWithVoiceData:(unsigned char*)voiceData length:(int)length tpye:(AUDIO_TYPE)type;

@end
