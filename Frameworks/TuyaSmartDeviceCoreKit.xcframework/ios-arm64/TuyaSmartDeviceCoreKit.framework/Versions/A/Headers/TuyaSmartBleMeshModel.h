//
// TuyaSmartBleMeshModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartBleMeshModel
#define TuyaSmart_TuyaSmartBleMeshModel

#import <Foundation/Foundation.h>

@interface TuyaSmartBleMeshModel : NSObject

// The generic mesh information.
@property (nonatomic, strong) NSString     *name;

// The mesh ID.
@property (nonatomic, strong) NSString     *meshId;

// The local key.
@property (nonatomic, strong) NSString     *localKey;

//The protocol version.
@property (nonatomic, strong) NSString     *pv;

@property (nonatomic, strong) NSString     *code;

@property (nonatomic, strong) NSString     *password;

@property (nonatomic, assign) BOOL         share;

@property (nonatomic, assign) long long    homeId;

// --------- The Bluetooth mesh information
@property (nonatomic, strong) NSString *netKey;

@property (nonatomic, strong) NSString *appKey;

@end

#endif
