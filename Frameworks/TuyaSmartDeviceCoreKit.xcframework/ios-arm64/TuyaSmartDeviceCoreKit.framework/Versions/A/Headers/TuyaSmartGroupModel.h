//
// TuyaSmartGroupModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartGroupModel
#define TuyaSmart_TuyaSmartGroupModel

/// The group type.
typedef enum : NSUInteger {
    TuyaSmartGroupTypeWifi = 0,
    TuyaSmartGroupTypeMesh,
    TuyaSmartGroupTypeZigbee,
    TuyaSmartGroupTypeSIGMesh,
    TuyaSmartGroupTypeBeacon,
} TuyaSmartGroupType;

#import <Foundation/Foundation.h>
#import "TuyaSmartDevice.h"

/// The group information.
@interface TuyaSmartGroupModel : NSObject

/// The group ID.
@property (nonatomic, strong) NSString  *groupId;

/// The product ID.
@property (nonatomic, strong) NSString  *productId;

/// The time when the group was created.
@property (nonatomic, assign) long long    time;

/// The name of the group.
@property (nonatomic, strong) NSString  *name;

/// The URL of the icon.
@property (nonatomic, strong) NSString  *iconUrl;

/// The type of group.
@property (nonatomic, assign) TuyaSmartGroupType  type;

@property (nonatomic, assign) BOOL      isShare;

/// The DPs.
@property (nonatomic, strong) NSDictionary *dps;

/// The DP codes.
@property (nonatomic, strong) NSDictionary *dpCodes;

/// The local key.
@property (nonatomic, strong) NSString     *localKey;

/// The protocol version.
@property (nonatomic, assign) double        pv;

/// The number of devices,
@property (nonatomic, assign) NSInteger    deviceNum;

/// The product information.
@property (nonatomic, strong) NSDictionary *productInfo;

/// The home ID.
@property (nonatomic, assign) long long    homeId;

/// The room ID.
@property (nonatomic, assign) long long    roomId;

/// The custom DP name.
@property (nonatomic, copy)   NSDictionary *dpName;

/// The order.
@property (nonatomic, assign) NSInteger displayOrder;

/// The order of all home groups.
@property (nonatomic, assign) NSInteger homeDisplayOrder;

/// The device list.
@property (nonatomic, strong) NSArray<TuyaSmartDeviceModel *> *deviceList;

/// The local short address of groups.
@property (nonatomic, strong) NSString     *localId;

/// The subclass.
@property (nonatomic, strong) NSString     *pcc;

/// The mesh ID or gateway ID.
@property (nonatomic, strong) NSString     *meshId;

/// The schema array.
@property (nonatomic, strong) NSArray      *schemaArray;

/// Indicates whether the standard DP ID is used.
@property (nonatomic, assign) BOOL         standard;

/// The standard schema.
@property (nonatomic, strong, readonly) TuyaSmartStandSchemaModel *standSchemaModel;

// Add the beacon beaconKey.
@property (nonatomic, strong) NSString *groupKey;

@end

#endif
