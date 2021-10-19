//
//  UIImageView+TYAESImage.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2019/5/31.
//

#import "TYEncryptWebImageCompat.h"
#import "TYEncryptImageDefine.h"

@interface UIImageView (TYAESImage)

#pragma mark - image

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
- (void)ty_setImageWithURL:(nonnull NSURL *)imageUrl;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param tintColor image's tintColor and the image's rendingMode will automatically be set to UIImageRenderingModeAlwaysTemplate
- (void)ty_setImageWithURL:(nonnull NSURL *)imageUrl
                 tintColor:(nullable UIColor *)tintColor;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
- (void)ty_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage;

/// Set the imageView `image` with an unencrypted image `imageUrl` .
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param tintColor image's tintColor and the image's rendingMode will automatically be set to UIImageRenderingModeAlwaysTemplate
- (void)ty_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                 tintColor:(nullable UIColor *)tintColor;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)ty_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                 completed:(nullable TYEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)ty_setImageWithURL:(nonnull NSURL *)imageUrl
                 completed:(nullable TYEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an unencrypted image `imageUrl`.
/// @param imageUrl image's URL, the image must be not encrypted.
/// @param placeholderImage placeholder image before network request response
/// @param progress The block invoked (on main thread) during image request.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)ty_setImageWithURL:(nonnull NSURL *)imageUrl
          placeholderImage:(nullable UIImage *)placeholderImage
                  progress:(nullable TYEncryptWebImageProgressBlock)progress
                 completed:(nullable TYEncryptWebImageCompletionBlock)completedBlock;

#pragma mark - encrypt image

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
/// @param placeholderImage placeholder image before network request response
- (void)ty_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
              placeholderImage:(nullable UIImage *)placeholderImage;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
- (void)ty_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)ty_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
                     completed:(nullable TYEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
/// @param placeholderImage placeholder image before network request response
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)ty_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
              placeholderImage:(nullable UIImage *)placeholderImage
                     completed:(nullable TYEncryptWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `imageUrl` and  an 'encrypt key string'.
/// @param imagePath image's URL
/// @param encryptKey image's encrypt key string
/// @param placeholderImage placeholder image before network request response
/// @param progress The block invoked (on main thread) during image request.
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)ty_setAESImageWithPath:(nonnull NSString *)imagePath
                    encryptKey:(nullable NSString *)encryptKey
              placeholderImage:(nullable UIImage *)placeholderImage
                      progress:(nullable TYEncryptWebImageProgressBlock)progress
                     completed:(nullable TYEncryptWebImageCompletionBlock)completedBlock;

@end

