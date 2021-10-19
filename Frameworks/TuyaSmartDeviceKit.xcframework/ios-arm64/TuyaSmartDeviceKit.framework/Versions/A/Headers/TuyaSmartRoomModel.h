//
// TuyaSmartRoomModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

@interface TuyaSmartRoomModel : NSObject

// The room ID.
@property (nonatomic, assign) long long roomId;

// The room icon.
@property (nonatomic, strong) NSString *iconUrl;

// The room name.
@property (nonatomic, strong) NSString *name;

// The order.
@property (nonatomic, assign) NSInteger displayOrder;


@end
