//
//  TuyaSmartCameraMessageModel.h
//  TuyaSmartCameraKit
//
//  Created by 傅浪 on 2019/8/14.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TuyaCameraMessageAttachmentType) {
    TuyaCameraMessageAttachmentPicture,
    TuyaCameraMessageAttachmentVideo,
    TuyaCameraMessageAttachmentAudio,
};

@interface TuyaSmartCameraMessageModel : NSObject

/**
 [^en]
 date string
 [$en]

 [^zh]
 日期
 [$zh]
 
*/
@property (nonatomic, copy) NSString *dateTime;

/**
 [^en]
 message type description
 [$en]

 [^zh]
 消息类型描述
 [$zh]
 
 */
@property (nonatomic, copy) NSString *msgTypeContent;

/**
 [^en]
 picture path
 [$en]

 [^zh]
 图片地址
 [$zh]
 
*/
@property (nonatomic, copy) NSString *attachPic;

/**
 [^en]
 video list
 [$en]

 [^zh]
 视频地址
 [$zh]
 
*/
@property (nonatomic, copy) NSArray *attachVideos;

/**
 [^en]
 audio list
 [$en]

 [^zh]
 音频地址
 [$zh]
 
*/
@property (nonatomic, copy) NSArray *attachAudios;

/**
 [^en]
 message source id (device id)
 [$en]

 [^zh]
 消息来源
 [$zh]
 
*/
@property (nonatomic, copy) NSString *msgSrcId;

/**
 [^en]
 message content text
 [$en]

 [^zh]
 消息内容
 [$zh]
 
*/
@property (nonatomic, copy) NSString *msgContent;

/**
 [^en]
 message title text
 [$en]

 [^zh]
 消息标题
 [$zh]
 
*/
@property (nonatomic, copy) NSString *msgTitle;

/**
 [^en]
 message id
 [$en]

 [^zh]
 消息id
 [$zh]
 
*/
@property (nonatomic, copy) NSString *msgId;

/**
 [^en]
 message code
 [$en]

 [^zh]
 消息类型码
 [$zh]
 
*/
@property (nonatomic, copy) NSString *msgCode;

/**
 [^en]
 date unix stamp
 [$en]

 [^zh]
 日期的时间戳
 [$zh]
 
*/
@property (nonatomic, assign) NSInteger time;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

+ (NSArray<TuyaSmartCameraMessageModel *> *)messageModesWithDataArray:(NSArray<NSDictionary *> *)datas;

@end


@interface TuyaSmartCameraMessageSchemeModel : NSObject

/**
 [^en]
 description text
 [$en]

 [^zh]
 类型描述
 [$zh]
 
 */
@property (nonatomic, strong) NSString *describe;

/**
 [^en]
 message codes
 [$en]

 [^zh]
 包含的消息类型
 [$zh]
 
*/
@property (nonatomic, strong) NSArray *msgCodes;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

+ (NSArray<TuyaSmartCameraMessageSchemeModel *> *)messageSchemeModesWithDataArray:(NSArray<NSDictionary *> *)datas;

@end
