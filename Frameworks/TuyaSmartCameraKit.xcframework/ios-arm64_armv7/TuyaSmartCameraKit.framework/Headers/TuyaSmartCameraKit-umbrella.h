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

#import "TuyaSmartCameraAbility.h"
#import "TuyaSmartCameraDPManager+DPCode.h"
#import "TuyaSmartCameraDPManager.h"
#import "TuyaSmartCameraKit.h"
#import "TuyaSmartCameraLogManager.h"
#import "TuyaSmartCameraMessage.h"
#import "TuyaSmartCameraMessageMediaPlayer.h"
#import "TuyaSmartCameraMessageModel.h"
#import "TuyaSmartCloudManager.h"
#import "TuyaSmartCloudModels.h"
#import "TuyaSmartCloudService.h"
#import "TuyaSmartDevice+doorbell.h"
#import "TuyaSmartDeviceModel+IPCSDK.h"
#import "TuyaSmartDoorBellManager.h"
#import "TuyaSmartPlaybackDate.h"
#import "TuyaSmartPTZManager.h"

FOUNDATION_EXPORT double TuyaSmartCameraKitVersionNumber;
FOUNDATION_EXPORT const unsigned char TuyaSmartCameraKitVersionString[];

