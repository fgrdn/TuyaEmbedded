//
//  TYMp4RecorderCAPI.h
//  TuyaCameraSDK
//
//  Created by Jim on 2020/1/6.
//  Copyright © 2020 Tuya. All rights reserved.
//

#ifndef __TYMp4RecorderCAPI_H__
#define __TYMp4RecorderCAPI_H__

#include <stdio.h>
#include <list>

#include "TYFrameInfo.h"

void *initMp4Writer(long cxxMp4RecorderHandler);
void deinitMp4Writer(void *handler);

int mp4StartRecord(void *handler, const char *videoPath, const char *fileName, bool mute, bool audioOnly);
int mp4ProcessAudioPacket(void *handler, std::shared_ptr<TYAudioFrameInfo> audioFrame);
int mp4ProcessVideoPacket(void *handler, std::shared_ptr<TYVideoPacketInfo> videoPacket);
int mp4StopRecord(void *handler);

std::list<std::shared_ptr<TYVideoPacketInfo>> GetVideoPackets(long cxxMp4Handler);
std::list<std::shared_ptr<TYAudioFrameInfo>> GetAudioFrames(long cxxMp4Handler);


#endif // __TYMp4RecorderCAPI_H__
