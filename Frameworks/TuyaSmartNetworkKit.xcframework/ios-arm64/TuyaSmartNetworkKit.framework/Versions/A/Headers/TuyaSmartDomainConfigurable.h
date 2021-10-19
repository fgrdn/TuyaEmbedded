//
//  TuyaSmartDomainConfigurable.h
//  TuyaSmartNetworkKit
//
//  Created by huangkai on 2021/6/7.
//

#ifndef TuyaSmartApiConfigurable_h
#define TuyaSmartApiConfigurable_h

@protocol TuyaSmartDomainConfigurable <NSObject>

@property(nonatomic, strong) NSString  *aispeechHttpsUrl;
@property(nonatomic, strong) NSString  *gwApiUrl;
@property(nonatomic, strong) NSString  *gwMqttUrl;
@property(nonatomic, strong) NSString  *mobileApiUrl;
@property(nonatomic, strong) NSString  *mobileMqttUrl;
@property(nonatomic, strong) NSString  *mobileMqttsUrl;
@property(nonatomic, strong) NSString  *mobileMediaMqttUrl;
@property(nonatomic, strong) NSString  *pxApiUrl;
@property(nonatomic, strong) NSString  *regionCode;
@property(nonatomic, strong) NSString  *mqttQuicUrl;
@property(nonatomic, strong) NSString  *mobileQuicUrl;

@end

@interface TuyaSmartSDK (DomainConfigurable)

@property (nonatomic, strong, readonly) id<TuyaSmartDomainConfigurable> domain;

@property (nonatomic, strong, readonly) NSString *ecode;
@property (nonatomic, strong, readonly) NSString *sid;

@end

@protocol TuyaSmartSDKEvent <NSObject>

- (void)didLoadFinish;

- (void)didReceivedSessionInvalidEvent;

@end

@interface TuyaSmartSDK (Event)

@property (nonatomic, strong, readonly) id<TuyaSmartSDKEvent> eventHandler;

@end

#endif /* TuyaSmartApiConfigurable_h */
