//
// TYApiMergeModel.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TYApiMergeModel_h
#define TYApiMergeModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief TYApiMergeModel is an object of response data from TYApiMergeService.
@interface TYApiMergeModel : NSObject

/// Success.
@property (nonatomic, assign) BOOL      success;

/// Api name.
@property (nonatomic, strong) NSString  *apiName;

/// Error.
@property (nonatomic, strong) NSError   *error;

/// Response result.
@property (nonatomic, strong) id        result;

/// Timestamp.
@property (nonatomic, assign) NSTimeInterval time;

@end

NS_ASSUME_NONNULL_END

#endif /* TYApiMergeModel_h */
