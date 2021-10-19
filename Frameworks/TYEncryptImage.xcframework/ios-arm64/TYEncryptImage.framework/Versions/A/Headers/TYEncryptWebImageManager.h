//
//  TYEncryptWebImageManager.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2020/1/22.
//

#import "TYEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>
#import "TYEncryptImageDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class TYEncryptWebImageOperation,TYEncryptImageCache;

@interface TYEncryptWebImageManager : NSObject

/**
 The image cache used by image operation.
 You can set it to nil to avoid image cache.
 */
@property (nullable, nonatomic, strong) TYEncryptImageCache *cache;

/**
 The image HTTP request header. Default is "Accept:image/webp,image/\*;q=0.8".
 */
@property (nullable, nonatomic, copy) NSDictionary<NSString *, NSString *> *headers;

+ (instancetype)sharedManager;

/**
 Creates a manager with an image cache and operation queue.
 
 @param cache  Image cache used by manager (pass nil to avoid image cache).
 @return A new manager.
 */
- (instancetype)initWithCache:(nullable TYEncryptImageCache *)cache queue:(NSOperationQueue *)queue;

/**
Returns the cache key for a specified URL.

@param url A specified URL
@return Cache key used in TYEncryptImageCache.
*/

- (NSString *)cacheKeyForURL:(NSURL *)url;

/**
 The username used by NSURLCredential, default is nil.
 */
@property (nullable, nonatomic, copy) NSString *username;

/**
 The password used by NSURLCredential, default is nil.
 */
@property (nullable, nonatomic, copy) NSString *password;

/**
 A block which will be invoked for each image HTTP request to do additional
 HTTP header process. Default is nil.
 
 Use this block to add or remove HTTP header field for a specified URL.
 */
@property (nullable, nonatomic, copy) NSDictionary<NSString *, NSString *> *(^headersFilter)(NSURL *url, NSDictionary<NSString *, NSString *> * _Nullable header);

/**
 A block which will be invoked for each image operation. Default is nil.
 
 Use this block to provide a custom image cache key for a specified URL.
 */
@property (nullable, nonatomic, copy) NSString *(^cacheKeyFilter)(NSURL *url);

/**
 Creates and returns a new image operation, the operation will start immediately.
 
 @param url        The image url (remote or local file path).
 @param progress   Progress block
 @param completion Completion block
 @return A new image operation.
 */
- (TYEncryptWebImageOperation *)requestImageWithURL:(NSURL *)url
                                           progress:(nullable TYEncryptWebImageProgressBlock)progress
                                         completion:(nullable TYEncryptWebImageCompletionBlock)completion;

/**
 * Assign list of URLs to let TYEncryptWebImageManager to queue the prefetching.
 * Attention that call this will not cancel previous fetched urls.
 *
 * @param urls list of URLs to prefetch
 */
- (void)prefetchURLs:(nullable NSArray<NSURL *> *)urls;

/**
 Clear all cached files
 */
- (void)clearAllCache;

@end

NS_ASSUME_NONNULL_END
