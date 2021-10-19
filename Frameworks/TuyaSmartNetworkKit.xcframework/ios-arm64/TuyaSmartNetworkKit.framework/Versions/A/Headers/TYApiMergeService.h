//
// TYApiMergeService.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TYApiMergeService_h
#define TYApiMergeService_h

#import "TYApiMergeModel.h"
#import "TuyaSmartRequest.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief TYApiMergeService is used for making several requests in one HTTP request.
///
/// This class is used for reduce the number of network requests. Use it with the following steps:
///     1. Create a TYApiMergeService instance
///     2. Add several request by `-[TYApiMergeService addApiRequest:postData:version:]`
///     3. SendRequests by `- [TYApiMergeService sendRequest:success:failure]`. requests will be sent and received together.
///
/// @discussion Due to HTTP/2 multiplexing technology, it is not recommend for use now.
///
@interface TYApiMergeService : TuyaSmartRequest

@property (nonatomic, strong) TYSDKSafeMutableArray *requestList;


/// Add api request.
/// @param apiName Api name.
/// @param postData Post data.
/// @param version Version.
- (void)addApiRequest:(NSString *)apiName postData:(NSDictionary *)postData version:(NSString *)version;


/// Send request.
/// @param getData Get data.
/// @param success Called when the task finishes successfully. A list of TYApiMergeModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)sendRequest:(NSDictionary *)getData success:(nullable void (^)(NSArray <TYApiMergeModel *> *list))success failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* TYApiMergeService_h */
