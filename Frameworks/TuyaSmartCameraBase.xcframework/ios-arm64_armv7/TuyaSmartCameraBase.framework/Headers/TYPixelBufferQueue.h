//
//  tyQueue.h
//  TYCameraLibrary
//
//  Created by 傅浪 on 2018/6/11.
//

#ifndef tyQueue_h
#define tyQueue_h

#include <stdio.h>

typedef struct TYFeatureRect {
    float x;
    float y;
    float width;
    float height;
} TYFeatureRect;

TYFeatureRect TYFeatureRectMake(float x, float y, float width, float height);

typedef struct TYPixelBufferItem {
    TYFeatureRect rect;
    void *data;
} TYPixelBufferItem;

typedef TYPixelBufferItem * TYPixelBufferItemRef;

typedef struct TYPixelBufferQueue {
    int maxSize;
    int size;
    int front;
    int rear;
    void * datas[];
} TYPixelBufferQueue;

typedef TYPixelBufferQueue * TYPixelBufferQueueRef;

void TYPixelBufferItemCreate(TYPixelBufferItemRef *pixelBufferItem, TYFeatureRect rect, void *data);

void TYPixelBufferItemRelease(TYPixelBufferItemRef pixelBufferItem);

void TYPixelBufferQueueCreate(TYPixelBufferQueueRef *pixelBufferQueue, int maxSize);

void TYPixelBufferQueueEnqueueOut(TYPixelBufferQueueRef pixelBufferQueue, void *enBuffer, void **deBuffer);

int TYPixelBufferQueueEnQueue(TYPixelBufferQueueRef pixelBufferQueue, void *pixelBuffer);

int TYPixelBufferQueueDeQueue(TYPixelBufferQueueRef pixelBufferQueue, void **pixelBuffer);

int TYPixelBufferQueueGetFront(TYPixelBufferQueueRef pixelBufferQueue, void **pixelBuffer);

void TYPixelBufferQueueClear(TYPixelBufferQueueRef pixelBufferQueue);

void TYPixelBufferQueueRelease(TYPixelBufferQueueRef pixelBufferQueue);

#endif /* tyQueue_h */
