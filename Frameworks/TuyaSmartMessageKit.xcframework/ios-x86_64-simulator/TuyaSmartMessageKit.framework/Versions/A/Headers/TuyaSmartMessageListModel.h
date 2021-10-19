//
// TuyaSmartMessageListModel.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMessageUtils.h"

NS_ASSUME_NONNULL_BEGIN
/// Message attachment model.
@interface TuyaSmartMessageAttachModel : NSObject

/// Is the attachment a video (.mp4 is considered a video).
@property (nonatomic, assign) BOOL isVideo;

/// Attachment url.
@property (nonatomic, strong) NSString *url;

/// Thumbnail url.
@property (nonatomic, strong) NSString *thumbUrl;

@end

/// Message list model.
@interface TuyaSmartMessageListModel : NSObject

/// The Message Identifier.
@property (nonatomic, strong) NSString *msgId;

/// The Message title.
@property (nonatomic, strong) NSString *msgTypeContent;

/// The Message content.
@property (nonatomic, strong) NSString *msgContent;

/// Formatted date and time.
@property (nonatomic, strong) NSString *dateTime;

/// Message timestamp.
@property (nonatomic, assign) NSInteger time;

/// Message icon.
@property (nonatomic, strong) NSString *icon;

/// Attachment list.
@property (nonatomic, strong) NSArray<TuyaSmartMessageAttachModel *> *attachPicList;

@property (nonatomic, assign) BOOL hasNotRead;

/// Device id (note: only alarm type messages will have this field).
@property (nonatomic, strong) NSString  *msgSrcId;

///  1 is Alert message, 2 is Automation message (Note: Only alert type messages will have this field used in alert messages to distinguish between alerts or automation, home and notification messages are ignored).
@property (nonatomic, assign) NSInteger  alarmType;

/// Message Type: 0 is system message, 1 is new devices, 2 is new friend, 4 is device alarm.
@property (nonatomic, assign) NSInteger msgType;

/// The current home id.
@property (nonatomic, assign) long long homeID;

/// The current home name.
@property (nonatomic, copy) NSString *homeName;

@end

NS_ASSUME_NONNULL_END
