//
//  TYEncryptImageDefine.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2020/5/26.
//

#import "TYEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>

#ifndef TYEncryptImageDefine_h
#define TYEncryptImageDefine_h

/// Indicated where the image came from.
typedef NS_ENUM(NSUInteger, TYEncryptWebImageFromType) {
    
    /// No value.
    TYWebImageFromNone = 0,
    
    /// Fetched from memory cache immediately.
    /// If you called "setImageWithURL:..." and the image is already in memory,
    /// then you will get this value at the same call.
    TYWebImageFromMemoryCacheFast,
    
    /// Fetched from memory cache.
    TYWebImageFromMemoryCache,
    
    /// Fetched from disk cache.
    TYWebImageFromDiskCache,
    
    /// Fetched from remote (web or file path).
    TYWebImageFromRemote,
};

/// Indicated image fetch complete stage.
typedef NS_ENUM(NSInteger, TYEncryptWebImageStage) {
    
    /// Incomplete, progressive image.
    TYWebImageStageProgress  = -1,
    
    /// Cancelled.
    TYWebImageStageCancelled = 0,
    
    /// Finished (succeed or failed).
    TYWebImageStageFinished  = 1,
};

/**
 Image file type.
 */
typedef NS_ENUM(NSUInteger, TYEncryptImageType) {
    TYEncryptImageTypeUnknown = 0, ///< unknown
    TYEncryptImageTypeJPEG,        ///< jpeg, jpg
    TYEncryptImageTypeJPEG2000,    ///< jp2
    TYEncryptImageTypeTIFF,        ///< tiff, tif
    TYEncryptImageTypeBMP,         ///< bmp
    TYEncryptImageTypeICO,         ///< ico
    TYEncryptImageTypeICNS,        ///< icns
    TYEncryptImageTypeGIF,         ///< gif
    TYEncryptImageTypePNG,         ///< png
    TYEncryptImageTypeWebP,        ///< webp
    TYEncryptImageTypeOther,       ///< other image format
};

/**
 The block invoked when image fetch finished or cancelled.
 
 @param image       The image.
 @param url         The image url (remote or local file path).
 @param from        Where the image came from.
 @param stage       Current download stage.
 @param error       Error during image fetching.
 */
typedef void (^TYEncryptWebImageCompletionBlock)(UIImage * _Nullable image, NSURL * _Nullable url, TYEncryptWebImageFromType from, TYEncryptWebImageStage stage, NSError * _Nullable error);

/**
 The block invoked in remote image fetch progress.
 
 @param receivedSize Current received size in bytes.
 @param expectedSize Expected total size in bytes (-1 means unknown).
 */
typedef void(^TYEncryptWebImageProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);

#endif /* TYEncryptImageDefine_h */
