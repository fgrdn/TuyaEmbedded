//
// TuyaSmartFeedbackItemModel.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc (https://developer.tuya.com)

@interface TuyaSmartFeedbackItemModel : NSObject


/// The feedback item id.
@property (nonatomic, strong) NSString      *hdId;

/// The feedback item type.
@property (nonatomic, assign) NSUInteger    hdType;

/// The feedback item title.
@property (nonatomic, strong) NSString      *title;

@end
