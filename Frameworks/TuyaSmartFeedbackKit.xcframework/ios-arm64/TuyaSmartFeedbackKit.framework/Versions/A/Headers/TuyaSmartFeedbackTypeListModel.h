//
// TuyaSmartFeedbackTypeListModel.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc (https://developer.tuya.com)

#import "TuyaSmartFeedbackItemModel.h"

@interface TuyaSmartFeedbackTypeListModel : NSObject

/// Feedback type, e.g. "faulty device", "more".
@property (nonatomic, strong) NSString *type;

/// List of items included in the feedback type.
@property (nonatomic, strong) NSArray<TuyaSmartFeedbackItemModel *> *list;

@end
