//
//  TYMp4Recorder.h
//  TuyaCameraSDK
//
//  Created by Jim on 2020/1/4.
//  Copyright © 2020 Tuya. All rights reserved.
//

#ifndef TYMp4Writer_h
#define TYMp4Writer_h

#import <Foundation/Foundation.h>

@interface TYMp4Writer : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCxxMp4Recorder:(long)cxxMp4Handler NS_DESIGNATED_INITIALIZER;

- (int)startRecordWithPath:(NSString *)videoPath fileName:(NSString *)fileName mute:(BOOL)mute audioOnly:(BOOL)audioOnly;

- (int)processAudioPacket:(std::shared_ptr<TYAudioFrameInfo>)audioFrame;

- (int)processVideoPacket:(std::shared_ptr<TYVideoPacketInfo>)videoPacket;

- (int)stopRecord;

- (int)recordCompensativelyBeforeStop;

@end


#endif /* TYMp4Writer_h */
