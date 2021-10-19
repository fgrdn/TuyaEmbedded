//
//  TYCameraP2pCommandProxy.h
//  TuyaSmartCameraM
//
//  Created by 傅浪 on 2020/10/26.
//

#import <Foundation/Foundation.h>

@class TuyaSmartMQTTMessageModel;

typedef void(^TYMQTTMessageCallback)(TuyaSmartMQTTMessageModel *mesageModel);

@interface TYCameraP2pCommandProxy : NSObject

+ (instancetype)sharedInstance;

- (void)setMQTTCallback:(TYMQTTMessageCallback)callback forProtocol:(int)protocol deviceId:(NSString *)devId;

- (void)removeMQTTCallbackForProtocol:(int)protocol deviceId:(NSString *)devId;


@end
