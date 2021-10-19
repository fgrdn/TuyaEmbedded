//
//  TuyaSmartQUICClient.h
//  TuyaSmartQUIC
//
//  Created by 高森 on 2020/2/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const TYQUICErrorDomain;

@class TuyaSmartQUICClient;

@protocol TuyaSmartQUICClientDelegate <NSObject>

@optional

- (void)quicClient:(TuyaSmartQUICClient *)client connectionSuccessWithMessage:(NSString *)message;

- (void)quicClient:(TuyaSmartQUICClient *)client connectionError:(nullable NSError *)error;

- (void)quicClient:(TuyaSmartQUICClient *)client connectionClosed:(NSError *)error connectionId:(NSString *)connectionId closedByPeer:(BOOL)closedByPeer;

- (void)quicClient:(TuyaSmartQUICClient *)client dataReceived:(NSData *)data;

@end

@interface TuyaSmartQUICClient : NSObject

@property (nonatomic, weak) id<TuyaSmartQUICClientDelegate> delegate;

@property (nonatomic, strong, nonnull) dispatch_queue_t queue;

- (void)startConnect:(NSString *)host
                  ip:(NSString *)ip
                port:(UInt32)port
             version:(NSUInteger)version
              verify:(BOOL)verify;

- (void)stopConnect;

- (void)sendData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
