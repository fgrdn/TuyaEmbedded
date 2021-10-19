#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "TuyaSmartCameraBase.h"
#import "TuyaSmartCameraDefines.h"
#import "TuyaSmartCameraFactory.h"
#import "TuyaSmartCameraType.h"
#import "TuyaSmartVideoViewType.h"
#import "TYCameraUtil.h"
#import "tyMatrix.h"
#import "TYPixelBufferQueue.h"
#import "UIImage+YUV.h"

FOUNDATION_EXPORT double TuyaSmartCameraBaseVersionNumber;
FOUNDATION_EXPORT const unsigned char TuyaSmartCameraBaseVersionString[];

