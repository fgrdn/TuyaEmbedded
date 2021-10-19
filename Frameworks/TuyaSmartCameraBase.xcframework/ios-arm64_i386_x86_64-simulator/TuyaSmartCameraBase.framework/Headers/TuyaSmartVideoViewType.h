//
//  TuyaSmartVideoViewType.h
//  TYCameraLibrary
//
//  Created by 傅浪 on 2018/6/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol TuyaSmartVideoViewType <NSObject>

/**
 [^en]
 set it YES, video image will stretch to fill the video view.
 [$en]

 [^zh]
 设为 YES，视频画面将会拉伸填充整个video view
 [$zh]
 */
@property (nonatomic, assign) BOOL scaleToFill;

/**
 [^en]
 video scale factory
 [$en]

 [^zh]
 视频缩放
 [$zh]

 @param scaled [^en]scale factory[$en] [^zh]视频缩放[$zh]
 */
- (void)tuya_setScaled:(float)scaled;

/**
 [^en]
 video offset
 [$en]

 [^zh]
 视频偏移量
 [$zh]

 @param offset [^en]offset point[$en] [^zh]视频偏移量[$zh]
 */
- (void)tuya_setOffset:(CGPoint)offset;

/**
 [^en]
 clear video content, and reset scale and offset
 [$en]

 [^zh]
 清空视频内容，重置 scale 和 offset
 [$zh]
 */
- (void)tuya_clear;

/**
 [^en]
 get a screenshot from current video frame
 [$en]

 [^zh]
 从当前视频帧获取截图
 [$zh]
 
 @return [^en]screenshot image[$en] [^zh]视频截图[$zh]
 */
- (UIImage *)screenshot;

@optional

- (void)startPlay;
- (void)stopPlay;

/**
 Render YUV
 */
- (void)displayPixelBuffer:(CVPixelBufferRef)pixelBuffer;

- (void)displayPixelBuffer:(CVPixelBufferRef)pixelBuffer featureRect:(CGRect)rect;

- (void)tuya_setRotate:(float)rotateZ;

- (void)enableFeatureTracking:(BOOL)enabled animated:(BOOL)animated;

@end
