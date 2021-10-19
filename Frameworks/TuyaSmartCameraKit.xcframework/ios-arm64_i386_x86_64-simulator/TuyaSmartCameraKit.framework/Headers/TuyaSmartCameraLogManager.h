//
//  TuyaSmartCameraLogManager.h
//  TuyaSmartCameraKit
//
//  Created by 傅浪 on 2020/3/28.
//

#import <Foundation/Foundation.h>


@interface TuyaSmartCameraLogManager : NSObject

+ (instancetype)sharedInstance;

- (NSArray *)SDKVersions;

- (void)enableDebug:(BOOL)enabled;

@end

