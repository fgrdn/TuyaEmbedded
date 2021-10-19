//
//  TYAudioQueuePcmPicker.h
//  Tuya
//
//  Created by Jim on 16/6/21.
//  Copyright (c) 2016年 Tuya. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

#define kNumberBuffers      3
#define t_sample            SInt16
#define kSamplingRate       20000
#define kNumberChannels     1
#define kBitsPerChannels    (sizeof(t_sample) * 8)
#define kBytesPerFrame      (kNumberChannels * sizeof(t_sample))
#define kFrameSize          1024

typedef struct AQCallbackStruct{
    AudioStreamBasicDescription mDataFormat;
    AudioQueueRef               queue;
    AudioQueueBufferRef         mBuffers[kNumberBuffers];
    AudioFileID                 outputFile;
    UInt32                      frameSize;
    int                         run;
}AQCallbackStruct;


@protocol TYAudioQueuePcmPickerDelegate <NSObject>

@required
-(void)audioQueuePcmDataCallBack:(unsigned char *)pData length:(unsigned long)uLength peakPower:(float)peakPower;

@end


@interface TYAudioQueuePcmPicker: NSObject{
    AQCallbackStruct aqc;
    AudioFileTypeID fileFormat;
}
- (id) initWithSampleRate:(NSInteger)sampleRate  atChannels:(UInt32)channels;
- (void)start;
- (void)stop;
- (void)pause;
- (void)destroy;
- (void)processAudioBuffer:(AudioQueueBufferRef) buffer withQueue:(AudioQueueRef) queue;

@property (nonatomic, assign) long audioDataLength;
@property (nonatomic, weak) id<TYAudioQueuePcmPickerDelegate> delegate;

@end

