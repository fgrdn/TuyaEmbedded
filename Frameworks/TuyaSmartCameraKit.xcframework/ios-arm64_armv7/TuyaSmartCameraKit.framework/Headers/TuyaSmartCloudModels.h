//
//  TuyaSmartCloudModels.h
//  TuyaSmartCamera_Example
//
//  Created by 傅浪 on 2019/3/29.
//  Copyright © 2019 fulang@tuya.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TuyaSmartCloudDayModel : NSObject

// [^en]video total length, (seconds).[$en] [^zh]视频总时长，单位秒[$zh]
@property (nonatomic, assign) NSInteger sumDuration;

// [^en]date, yyyy-MM-dd[$en] [^zh]日期，格式：yyyy-MM-dd[$zh]
@property (nonatomic, strong) NSString *uploadDay;

// [^en]unix timestamp of 00:00[$en] [^zh]00:00的unix timestamp[$zh]
@property (nonatomic, assign) NSInteger startTime;

// [^en]unix timestamp of 23:59[$en] [^zh]23:59的unix timestamp[$zh]
@property (nonatomic, assign) NSInteger endTime;

- (instancetype)initWithDict:(NSDictionary *)dict;

+ (NSArray<TuyaSmartCloudDayModel *> *)modelsWithDictArray:(NSArray<NSDictionary *> *)dictArray;

@end

@interface TuyaSmartCloudTimeEventModel : NSObject

// [^en]event description[$en] [^zh]事件描述[$zh]
@property (nonatomic, strong) NSString *describe;

// [^en]event start time[$en] [^zh]事件开始时间[$zh]
@property (nonatomic, assign) NSInteger startTime;

// [^en]event end time[$en] [^zh]事件结束时间[$zh]
@property (nonatomic, assign) NSInteger endTime;

// [^en]snapshot path[$en] [^zh]截图路径[$zh]
@property (nonatomic, strong) NSString *snapshotUrl;

- (instancetype)initWithDict:(NSDictionary *)dict;

@property (nonatomic, assign) BOOL isEncypt;

+ (NSArray<TuyaSmartCloudTimeEventModel *> *)modelsWithDictArray:(NSArray<NSDictionary *> *)dictArray;

@end

@interface TuyaSmartCloudTimePieceModel : NSObject

// [^en]video start time[$en] [^zh]视频开始时间[$zh]
@property (nonatomic, assign) NSInteger startTime;

// [^en]start date[$en] [^zh]开始日期[$zh]
@property (nonatomic, strong) NSDate *startDate;

// [^en]video end time[$en] [^zh]视频结束时间[$zh]
@property (nonatomic, assign) NSInteger endTime;

// [^en]end date[$en] [^zh]结束日期[$zh]
@property (nonatomic, strong) NSDate *endDate;

// [^en]start play time[$en] [^zh]开始播放时间[$zh]
@property (nonatomic, assign) NSInteger playTime;

// [^en]prefix[$en] [^zh]前缀[$zh]
@property (nonatomic, strong) id prefix;

- (instancetype)initWithDict:(NSDictionary *)dict;

+ (NSArray<TuyaSmartCloudTimePieceModel *> *)modelsWithDictArray:(NSArray<NSDictionary *> *)dictArray;

@end
