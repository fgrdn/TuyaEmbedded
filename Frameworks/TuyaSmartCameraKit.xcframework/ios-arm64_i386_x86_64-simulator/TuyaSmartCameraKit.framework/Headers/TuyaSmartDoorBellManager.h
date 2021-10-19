//
//  TuyaSmartDoorBellManager.h
//  TuyaSmartCameraKit
//
//  Created by 傅浪 on 2021/1/13.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, TYDoorBellError) {
    TYDoorBellError_NoError         = 0,
    TYDoorBellError_AnsweredByOther = -1001,
    TYDoorBellError_DidCanceled     = -1002,
    TYDoorBellError_TimeOut         = -1003,
    TYDoorBellError_AnsweredBySelf  = -1004,
    TYDoorBellError_NotAnswered     = -1005,
    TYDoorBellError_NotSupport      = -1006,
    TYDoorBellError_InvalidParam    = -1007,
};

@class TuyaSmartDeviceModel;

@interface TuyaSmartDoorBellCallModel : NSObject

/// call type, "doorbell" or "ac_doorbell", or custom type
@property (nonatomic, strong) NSString *type;
/// the device id of doorbell call
@property (nonatomic, strong) NSString *devId;
/// the sub device's node id which calling
@property (nonatomic, strong) NSString *nodeId;
/// the call event identifier
@property (nonatomic, strong) NSString *messageId;
/// the time of doorbell call be triggered
@property (nonatomic, assign) NSInteger time;
/// did answered
@property (nonatomic, assign, readonly, getter=isAnsweredBySelf) BOOL answeredBySelf;
/// is answered by other user
@property (nonatomic, assign, readonly, getter=isAnsweredByOther) BOOL answeredByOther;
/// is device canceled this call event
@property (nonatomic, assign, readonly, getter=isCanceled) BOOL canceled;

/// is a NVR sub device
@property (nonatomic, assign, readonly) BOOL isSubDevice;

- (NSDictionary *)map;

@end

@protocol TuyaSmartDoorBellObserver <NSObject>

@optional

/// did received a call from the device
- (void)doorBellCall:(TuyaSmartDoorBellCallModel *)callModel didReceivedFromDevice:(TuyaSmartDeviceModel *)deviceModel;

/// the call was refused
- (void)doorBellCallDidRefuse:(TuyaSmartDoorBellCallModel *)callModel;

/// the call was hang up
- (void)doorBellCallDidHangUp:(TuyaSmartDoorBellCallModel *)callModel;
/// the call was answered by other one
- (void)doorBellCallDidAnsweredByOther:(TuyaSmartDoorBellCallModel *)callModel;
/// the device was canceled this call
- (void)doorBellCallDidCanceled:(TuyaSmartDoorBellCallModel *)callModel timeOut:(BOOL)isTimeOut;

@end

@interface TuyaSmartDoorBellManager : NSObject

/// get all observers
@property (nonatomic, strong, readonly) NSArray<id<TuyaSmartDoorBellObserver>> *allObservers;

/// If a device is already in a call, subsequent calls to this device will be automatically ignored when set it YES
@property (nonatomic, assign) BOOL ignoreWhenCalling;

/// set the time out of call, if not answer when time out, the call will be canceled
@property (nonatomic, assign) NSInteger doorbellRingTimeOut;

+ (instancetype)sharedInstance;

/// Add observer for doorbell call
- (void)addObserver:(id<TuyaSmartDoorBellObserver>)observer;

/// answer the doorbell call of specified message id
- (TYDoorBellError)answerDoorBellCall:(NSString *)messageId;

/// refuse the doorbell call of specified message id
- (void)refuseDoorBellCall:(NSString *)messageId;

/// hangup the doorbell call of specified message id
- (TYDoorBellError)hangupDoorBellCall:(NSString *)messageId;

/// generate a doorbell call with call message data
- (void)generateCall:(NSDictionary *)params;

/// get the call model for the specified message id, if no validate call model, return nil
- (TuyaSmartDoorBellCallModel *)callModelWithMessageId:(NSString *)messageId;

/// remove the specified observer for doorbell call
- (void)removeObserver:(id<TuyaSmartDoorBellObserver>)observer;

/// remove all observer
- (void)removeAllObservers;

@end
