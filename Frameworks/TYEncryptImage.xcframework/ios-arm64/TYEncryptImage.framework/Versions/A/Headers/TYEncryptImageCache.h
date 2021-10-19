//
//  TYEncryptImageCache.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2020/1/22.
//

#import "TYEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Image cache type
typedef NS_OPTIONS(NSUInteger, TYEncryptImageCacheType) {
    /// No value.
    TYEncryptImageCacheTypeNone   = 0,
    
    /// Get/store image with memory cache.
    TYEncryptImageCacheTypeMemory = 1 << 0,
    
    /// Get/store image with disk cache.
    TYEncryptImageCacheTypeDisk   = 1 << 1,
    
    /// Get/store image with both memory cache and disk cache.
    TYEncryptImageCacheTypeAll    = TYEncryptImageCacheTypeMemory | TYEncryptImageCacheTypeDisk,
};

@class TYEncryptMemoryCache, TYEncryptDiskCache;
@interface TYEncryptImageCache : NSObject

/** The underlying memory cache. see `TYEncryptMemoryCache` for more information.*/
@property (strong, readonly) TYEncryptMemoryCache *memoryCache;

/** The underlying disk cache. see `TYEncryptDiskCache` for more information.*/
@property (strong, readonly) TYEncryptDiskCache *diskCache;

/**
 Whether decode animated image when fetch image from disk cache. Default is YES.
 
 @discussion When fetch image from disk cache, it will use 'TYInternalEncryptImage' to decode
 animated image such as WebP/APNG/GIF. Set to 'NO' to ignore animated image.
 */
@property BOOL allowAnimatedImage;

/**
 Whether decode the image to memory bitmap. Default is YES.
 
 @discussion If the value is YES, then the image will be decoded to memory bitmap
 for better display performance, but may cost more memory.
 */
@property BOOL decodeForDisplay;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 Returns global shared image cache instance.
 @return  The singleton TYImageCache instance.
 */
+ (instancetype)sharedCache;

#pragma mark - getImage Cache

/**
 Returns the image associated with a given key.
 If the image is not in memory, this method may blocks the calling thread until
 file read finished.
 
 @param key A string identifying the image. If nil, just return nil.
 @return The image associated with key, or nil if no image is associated with key.
 */
- (nullable UIImage *)getImageForKey:(NSString *)key;

/**
 Returns the image associated with a given key.
 If the image is not in memory and the `type` contains `TYEncryptImageCacheTypeDisk`,
 this method may blocks the calling thread until file read finished.
 
 @param key A string identifying the image. If nil, just return nil.
 @return The image associated with key, or nil if no image is associated with key.
 */
- (nullable UIImage *)getImageForKey:(NSString *)key withType:(TYEncryptImageCacheType)type;

/**
 Asynchronously get the image associated with a given key.
 
 @param key   A string identifying the image. If nil, just return nil.
 @param type  The cache type.
 @param block A completion block which will be called on main thread.
 */
- (void)getImageForKey:(NSString *)key
              withType:(TYEncryptImageCacheType)type
             withBlock:(void(^)(UIImage * _Nullable image, TYEncryptImageCacheType type))block;

/**
 Returns the image data associated with a given key.
 This method may blocks the calling thread until file read finished.
 
 @param key A string identifying the image. If nil, just return nil.
 @return The image data associated with key, or nil if no image is associated with key.
 */
- (nullable NSData *)getImageDataForKey:(NSString *)key;

/**
 Asynchronously get the image data associated with a given key.
 
 @param key   A string identifying the image. If nil, just return nil.
 @param block A completion block which will be called on main thread.
 */
- (void)getImageDataForKey:(NSString *)key
                 withBlock:(void(^)(NSData * _Nullable imageData))block;

#pragma mark - setImage Cache

/**
 Sets the image with the specified key in the cache (both memory and disk).
 This method returns immediately and executes the store operation in background.
 
 @param image The image to be stored in the cache. If nil, this method has no effect.
 @param key   The key with which to associate the image. If nil, this method has no effect.
 */
- (void)setImage:(UIImage *)image forKey:(NSString *)key;

/**
 Sets the image with the specified key in the cache (both memory and disk).
 This method returns immediately and executes the store operation in background.
 
 @param image The image to be stored in the cache. If nil, this method has no effect.
 @param key   The key with which to associate the image. If nil, this method has no effect.
 @param complete A completion block which will be called on main thread.
 */
- (void)setImage:(UIImage *)image forKey:(NSString *)key complete:(nullable void(^)(void))complete;

/**
 Sets the image with the specified key in the cache.
 This method returns immediately and executes the store operation in background.
 
 @discussion If the `type` contain `TYEncryptImageCacheTypeMemory`, then the `image` will
 be stored in the memory cache; `imageData` will be used instead if `image` is nil.
 If the `type` contain `TYEncryptImageCacheTypeDisk`, then the `imageData` will
 be stored in the disk cache; `image` will be used instead if `imageData` is nil.
 
 @param image     The image to be stored in the cache.
 @param imageData The image data to be stored in the cache.
 @param key       The key with which to associate the image. If nil, this method has no effect.
 @param type      The cache type to store image.
 */
- (void)setImage:(nullable UIImage *)image
       imageData:(nullable NSData *)imageData
          forKey:(NSString *)key
        withType:(TYEncryptImageCacheType)type;

/**
 Sets the image with the specified key in the cache.
 This method returns immediately and executes the store operation in background.
 
 @discussion If the `type` contain `TYEncryptImageCacheTypeMemory`, then the `image` will
 be stored in the memory cache; `imageData` will be used instead if `image` is nil.
 If the `type` contain `TYEncryptImageCacheTypeDisk`, then the `imageData` will
 be stored in the disk cache; `image` will be used instead if `imageData` is nil.
 
 @param image     The image to be stored in the cache.
 @param imageData The image data to be stored in the cache.
 @param key       The key with which to associate the image. If nil, this method has no effect.
 @param type      The cache type to store image.
 @param complete A completion block which will be called on main thread.
 */
- (void)setImage:(nullable UIImage *)image
       imageData:(nullable NSData *)imageData
          forKey:(NSString *)key
        withType:(TYEncryptImageCacheType)type
        complete:(nullable void(^)(void))complete;

#pragma mark - Contains and Check Ops

/**
 Returns a Boolean value that indicates whether a given key is in cache.
 If the image is not in memory, this method may blocks the calling thread until
 file read finished.
 
 @param key A string identifying the image. If nil, just return NO.
 @return Whether the image is in cache.
 */
- (BOOL)containsImageForKey:(NSString *)key;

/**
 Returns a Boolean value that indicates whether a given key is in cache.
 If the image is not in memory and the `type` contains `YYImageCacheTypeDisk`,
 this method may blocks the calling thread until file read finished.
 
 @param key  A string identifying the image. If nil, just return NO.
 @param type The cache type.
 @return Whether the image is in cache.
 */
- (BOOL)containsImageForKey:(NSString *)key withType:(TYEncryptImageCacheType)type;

#pragma mark - Remove Ops

/**
 Removes the image of the specified key in the cache (both memory and disk).
 This method returns immediately and executes the remove operation in background.
 
 @param key The key identifying the image to be removed. If nil, this method has no effect.
 */
- (void)removeImageForKey:(NSString *)key;

/**
 Removes the image of the specified key in the cache (both memory and disk).
 This method returns immediately and executes the remove operation in background.
 
 @param key The key identifying the image to be removed. If nil, this method has no effect.
 @param completion A completion block which will be called on main thread.
 */
- (void)removeImageForKey:(NSString *)key completion:(nullable void(^)(void))completion;

/**
 Removes the image of the specified key in the cache.
 This method returns immediately and executes the remove operation in background.
 
 @param key  The key identifying the image to be removed. If nil, this method has no effect.
 @param type The cache type to remove image.
 */
- (void)removeImageForKey:(NSString *)key withType:(TYEncryptImageCacheType)type;

/**
 Removes the image of the specified key in the cache.
 This method returns immediately and executes the remove operation in background.
 
 @param key  The key identifying the image to be removed. If nil, this method has no effect.
 @param type The cache type to remove image.
 @param completion A completion block which will be called on main thread.
 */
- (void)removeImageForKey:(NSString *)key withType:(TYEncryptImageCacheType)type completion:(nullable void(^)(void))completion;

#pragma mark - Cache Info

/**
 * Get the total bytes size of images in the disk cache
 */
- (NSUInteger)totalDiskSize;

/**
 * Get the number of images in the disk cache
 */
- (NSUInteger)totalDiskCount;

#pragma mark - Cache Paths

/**
 *  Get the cache path for a certain key (needs the cache path root folder)
 *
 *  @param key  the key (can be obtained from url using cacheKeyForURL)
 *  @param path the cache path root folder
 *
 *  @return the cache path
 */
- (nullable NSString *)cachePathForKey:(nullable NSString *)key inPath:(nonnull NSString *)path;

/**
 *  Get the default cache path for a certain key
 *
 *  @param key the key (can be obtained from url using cacheKeyForURL)
 *
 *  @return the default cache path
 */
- (nullable NSString *)defaultCachePathForKey:(nullable NSString *)key;

#pragma mark - Cache clean Ops

/**
 Clear all cache, include memory and disk.
 */
- (void)clearAllCache;

/**
 Clear all memory cache.
 */
- (void)clearMemory;

/**
 Clear all disk cache.
 @param completion A completion block which will be called on main thread.
 */
- (void)clearDiskOnCompletion:(void(^)(void))completion;

/**
 Clear the disk cache from SDWebImage.
 Use this method to clear the history cache data, if you are migrating from SDWebImage.
 Only clear the data cache by sharedImageCache instance of SDImageCache, not include the specific cache path.
 */
- (void)clearDiskFromSDWebImage;

@end

NS_ASSUME_NONNULL_END
