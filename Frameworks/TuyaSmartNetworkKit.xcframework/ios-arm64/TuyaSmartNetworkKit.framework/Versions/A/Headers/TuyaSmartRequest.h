//
// TuyaSmartRequest.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartRequest_h
#define TuyaSmartRequest_h

#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief TuyaSmartRequest is used for invoke Tuya Cloud API.
///
/// All of the Tuya Cloud API (atop) is made from this class.
///
/// Usually, a request need these params:
///   - API name.
///   - API version.
///   - API params (aka postData). A serializable dictionary object.
///   - Common params (aka getData). A serializable dictionary object. Optional.
///
/// And a response will be back through `success` or `failure` callback.
/// A success callback will give any kind of object, which depends on the specific API.
/// An error callback will give an error object, `error.userInfo[NSLocalizedFailureReasonErrorKey]` is for Tuya error code, `error.localizedDescription` is for detailed reasons.
///
/// @warning The `error.localizedDescription` is not recommend for display, please handle every possible error types and prepare the error messages for your own.
///
@interface TuyaSmartRequest : NSObject

/// Network request for Tuya server API.
/// @param apiName API name.
/// @param postData API params.
/// @param version  API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   version:(NSString *)version
                   success:(nullable TYSuccessID)success
                   failure:(nullable TYFailureError)failure;


/// Network request for Tuya server API.
/// @param apiName API name.
/// @param postData API params.
/// @param getData Common params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   getData:(nullable NSDictionary *)getData
                   version:(NSString *)version
                   success:(nullable TYSuccessID)success
                   failure:(nullable TYFailureError)failure;

/// Cancel network request.
- (void)cancel;

/// Remove network cache.
+ (void)removeAllCache;

@end


@interface TuyaSmartRequest (ApiMerge)

/// Invoke multiple api in one network request.
/// @param apiName API name.
/// @param postData API params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addMergeRequestWithApiName:(NSString *)apiName
                          postData:(nullable NSDictionary *)postData
                           version:(NSString *)version
                           success:(nullable TYSuccessID)success
                           failure:(nullable TYFailureError)failure;


/// Send multiple api request.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithSuccess:(nullable TYSuccessList)success
                            failure:(nullable TYFailureError)failure;


/// Send multiple api request.
/// @param getData Common params.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithGetData:(nullable NSDictionary *)getData
                            success:(nullable TYSuccessList)success
                            failure:(nullable TYFailureError)failure;


/// Remove all multiple api request.
- (void)removeAllMergeRequest;

@end

@interface TuyaSmartRequest (Encryption)

/// Network request for Tuya server API with post data encrypt.
/// @param apiName API name.
/// @param postData API params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                 postData:(nullable NSDictionary *)postData
                                  version:(NSString *)version
                                  success:(nullable TYSuccessID)success
                                  failure:(nullable TYFailureError)failure;

@end

@interface TuyaSmartRequest (Speech)

- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                parameter:(nullable NSDictionary *)param
                                voiceData:(nullable NSData *)data
                                  version:(NSString *)version
                                  success:(nullable TYSuccessID)success
                                  failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartRequest_h */
