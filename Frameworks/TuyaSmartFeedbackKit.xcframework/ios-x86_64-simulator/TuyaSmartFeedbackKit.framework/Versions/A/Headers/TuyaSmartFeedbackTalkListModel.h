//
// TuyaSmartFeedbackTalkListModel.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc (https://developer.tuya.com)

@interface TuyaSmartFeedbackTalkListModel : NSObject

/// The time of the feedback talk.
@property (nonatomic, strong) NSString          *dateTime;

/// The talk ID.
@property (nonatomic, strong) NSString          *hdId;

/// The type of the feedback talk.
@property (nonatomic, assign) NSUInteger        hdType;

/// A string title for the feedback talk.
@property (nonatomic, strong) NSString          *title;

/// The string content of the feedback talk.
@property (nonatomic, strong) NSString          *content;

@end
