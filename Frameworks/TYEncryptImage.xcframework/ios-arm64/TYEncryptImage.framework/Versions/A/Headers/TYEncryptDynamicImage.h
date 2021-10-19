//
//  TYEncryptDynamicImage.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2020/1/31.
//

#import "TYEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>
#import "TYEncryptAnimatedImageView.h"
#import "TYEncryptImageDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYEncryptDynamicImage : UIImage <TYEncryptAnimatedImage>

+ (nullable TYEncryptDynamicImage *)imageNamed:(NSString *)name; // no cache!
+ (nullable TYEncryptDynamicImage *)imageWithContentsOfFile:(NSString *)path;
+ (nullable TYEncryptDynamicImage *)imageWithData:(NSData *)data;
+ (nullable TYEncryptDynamicImage *)imageWithData:(NSData *)data scale:(CGFloat)scale;

/**
 If the image is created from data or file, then the value indicates the data type.
 */
@property (nonatomic, readonly) TYEncryptImageType animatedImageType;

/**
 If the image is created from animated image data (multi-frame GIF/APNG/WebP),
 this property stores the original image data.
 */
@property (nullable, nonatomic, readonly) NSData *animatedImageData;

/**
 The total memory usage (in bytes) if all frame images was loaded into memory.
 The value is 0 if the image is not created from a multi-frame image data.
 */
@property (nonatomic, readonly) NSUInteger animatedImageMemorySize;

/**
 Preload all frame image to memory.
 
 @discussion Set this property to `YES` will block the calling thread to decode
 all animation frame image to memory, set to `NO` will release the preloaded frames.
 If the image is shared by lots of image views (such as emoticon), preload all
 frames will reduce the CPU cost.
 
 See `animatedImageMemorySize` for memory cost.
 */
@property (nonatomic) BOOL preloadAllAnimatedImageFrames;


@end

NS_ASSUME_NONNULL_END
