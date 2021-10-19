//
//  AudioQueuePcmPlayer.h
//  TYCameraSdk
//
//  Created by Jim on 18/5/15.
//  Copyright (c) 2018年 Tuya. All rights reserved.
//

#ifndef __AUDIO_QUEUE_PCM_H__
#define __AUDIO_QUEUE_PCM_H__

#include <AudioToolbox/AudioToolbox.h>

#define AUDIO_SAMPLE_TYPE               short
#define PCM_BUFFER_SIZE                 1280
#define MAX_AUDIO_QUEUE_BUFFER_NUM      2

@interface TYAudioQueuePcmPlayer: NSObject{
    
}
@property (nonatomic, assign) BOOL inited;

- (BOOL)constructWithSampleRate:(Float64)fSampleRate channels:(int)nChannels bitWidth:(int)nBitWidth;
- (BOOL)initWithSampleRate:(Float64)fSampleRate channels:(int)nChannels bitWidth:(int)nBitWidth;
- (void)uninit;
- (void)start;
- (void)pause;
- (void)resume;
- (void)stop;
- (void)reset;
- (BOOL)dataEnough:(int)nSize;
- (BOOL)pushPCMData:(const char *)pData size:(UInt32)uSize;
- (BOOL)fillData:(AudioQueueBufferRef)inCompleteAQBuffer;
- (BOOL)fillJitterData:(AudioQueueBufferRef)inCompleteAQBuffer;

@end

#endif // __AUDIO_QUEUE_PCM_H__
