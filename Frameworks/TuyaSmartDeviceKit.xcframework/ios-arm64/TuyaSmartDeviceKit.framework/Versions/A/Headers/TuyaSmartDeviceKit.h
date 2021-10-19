//
// TuyaSmartDeviceKit.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartDeviceKit_h
#define TuyaSmartDeviceKit_h

/// The latest Internet communication protocol that is supported by clients.
//#define TUYA_CURRENT_GW_PROTOCOL_VERSION 2.2

/// The latest LAN communication protocol that is supported by clients.
//#define TUYA_CURRENT_LAN_PROTOCOL_VERSION 3.4

#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

#if TARGET_OS_IOS
    #import <TuyaSmartMQTTChannelKit/TuyaSmartMQTTChannelKit.h>
    #import <TuyaSmartSocketChannelKit/TuyaSmartSocketChannelKit.h>
#elif TARGET_OS_WATCH
    #define TuyaSmartMQTTChannelDelegate NSObject
    #define TuyaSmartSocketChannelDelegate NSObject
#endif

#import "TuyaSmartHome.h"
#import "TuyaSmartHome+Weather.h"
#import "TuyaSmartHome+TYDeprecatedApi.h"
#import "TuyaSmartWeatherModel.h"
#import "TuyaSmartWeatherOptionModel.h"
#import "TuyaSmartWeatherSketchModel.h"

#import "TuyaSmartHomeManager.h"
#import "TuyaSmartHomeMember.h"
#import "TuyaSmartHomeInvitation.h"
#import "TuyaSmartRoom.h"
#import "TuyaSmartHomeDeviceShare.h"

#import "TuyaSmartHomeMemberModel.h"
#import "TuyaSmartHomeMemberRequestModel.h"
#import "TuyaSmartHomeMember+TYDeprecatedApi.h"

#import "TuyaSmartGroup+DpCode.h"

#import "TuyaSmartMultiControl.h"

#import "TuyaSmartDeviceShareModel.h"
#import "TuyaSmartHomeDeviceShare+TYDeprecatedApi.h"

#import "TuyaSmartDevice+Home.h"
#import "TuyaSmartDeviceModel+Home.h"
#import "TuyaSmartGroup+Home.h"

#import "TuyaSmartHome+BleMesh.h"
#import "TuyaSmartHome+SIGMesh.h"

#endif /* TuyaSmartDeviceKit_h */
