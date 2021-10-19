//
//  TYEncryptImageDownloader.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2020/4/21.
//

#import "TYEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>
#import "TYEncryptImageDefine.h"
#import "TYEncryptWebImageManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYEncryptImageDownloader : NSObject

@property (nonatomic, strong) TYEncryptWebImageManager *manager;

+ (instancetype)sharedManager;

/// Downloads the image at the given imagePath and encryptKey
/// @param imagePath image url
/// @param encryptKey encrypt key string. Can be nil if the image is not encryptd
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)downloadEncryptImageWithPath:(NSString *)imagePath
                          encryptKey:(nullable NSString *)encryptKey
                           completed:(nullable TYEncryptWebImageCompletionBlock)completedBlock;

/// Downloads the image at the given imageURL
/// @param imageURL image url
/// @param completedBlock A block called when operation has been completed. This block has no return value and takes the requested UIImage as first parameter. The second parameter is the original image url. The third parameter is a Boolean indicating if the image was retrieved from the local cache or from the network. The fourth parameter is current download stage of the download image. In case of error the image parameter is nil and the fifth parameter may contain an NSError.
- (void)downloadImageWithURL:(NSURL *)imageURL
                          completed:(nullable TYEncryptWebImageCompletionBlock)completedBlock;

/// Clear all cached files
- (void)clearAllCache;


/// Get original image data from cache
/// @param imagePath  A url string of image separate from `?`. If the image's url contain the symbol `?`, cut out the first part of the string.
- (NSData *)getCachedImageData:(NSString *)imagePath;

@end

NS_ASSUME_NONNULL_END
