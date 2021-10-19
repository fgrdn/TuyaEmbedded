//
//  TYCameraUtil.h
//  BlocksKit
//
//  Created by 冯晓 on 2017/11/16.
//

#import <Foundation/Foundation.h>

@interface TYCameraUtil : NSObject

+ (void)activeAudioSession;

+ (void)unactiveAudioSession;

+ (NSString *)libCachePath;

+ (NSString *)getAtCachePath:(NSString *)fileName;

+ (NSString *)md5WithString:(NSString *)string;

+ (BOOL)saveImageToPhotoLibrary:(UIImage *)image;

+ (BOOL)saveVideoToPhotoLibrary:(NSString *)videoPath;

+ (NSString *)recordCacheDirectory;

+ (void)removeAllRecordCacheFiles;

@end
