//
//  UIImage+YUV.h
//  TuyaSmartCameraBase
//
//  Created by 傅浪 on 2021/4/28.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface UIImage (YUV)

+ (UIImage *)imageWithYUVData:(CVPixelBufferRef)pixelBuffer;

@end
