//
//  PlayBackFragment.h
//  TYCameraSdk
//
//  Created by Jim on 2018/5/12.
//  Copyright © 2018年 Tuya. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYPlayBackFragmentModel : NSObject

@property (nonatomic, assign) int type;                 // 参见 TuyaPlayBackEventType 定义
@property (nonatomic, assign) int startTime;            // 时间片 开始时间
@property (nonatomic, assign) int endTime;              // 时间片 结束时间

@end
