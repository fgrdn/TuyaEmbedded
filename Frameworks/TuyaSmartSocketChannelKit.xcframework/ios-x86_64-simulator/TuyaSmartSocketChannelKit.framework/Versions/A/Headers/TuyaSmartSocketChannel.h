//
//  TuyaSmartSocketChannel.h
//  TuyaSmartSocketChannelKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import "TuyaSmartSocketReadModel.h"
#import "TuyaSmartSocketWriteModel.h"
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>

// The protocol.
#define SOCKET_TYPE_BROADCAST             0x00
#define SOCKET_TYPE_BROADCAST_V4          0x13
#define SOCKET_TYPE_BROADCAST_V34         0x23
#define SOCKET_TYPE_AP_ERROR              0x15
#define SOCKET_TYPE_AP_CONFIG             0x01
#define SOCKET_TYPE_AP_ACTIVATE           0x02
#define SOCKET_TYPE_DP_PUBLISH            0x07
#define SOCKET_TYPE_DP_REPORT             0x08
#define SOCKET_TYPE_HEARTBEAT             0x09
#define SOCKET_TYPE_QUERY_DEV_INFO        0x0a
#define SOCKET_TYPE_QUERY_SSID_LIST       0x0b
#define SOCKET_TYPE_DP_CAD_PUBLISH        0x0d
#define SOCKET_TYPE_LOCL_SCENE_EXE        0x11
#define SOCKET_TYPE_ENABLE_LOG            0x20
#define SOCKET_TYPE_BIND_TOKEN            0x0c
#define SOCKET_TYPE_ACTIVE_SUBDEV         0x0e
#define SOCKET_TYPE_QUERY_CAD_DEV_INFO    0x10
#define SOCKET_TYPE_INITIATIVE_QUERY_DPS  0x12
#define SOCKET_TYPE_AP_CONFIG             0x01
#define SOCKET_TYPE_AP_CONFIG_NEW         0x14
#define SOCKET_TYPE_AP_CONFIG_BROADCAST   0x11

#define SOCKET_TYPE_HANDSHAKE_RAND_A      0x03
#define SOCKET_TYPE_HANDSHAKE_RAND_B      0x04
#define SOCKET_TYPE_HANDSHAKE_RAND_ACK_B  0x05

#define SOCKET_TYPE_IPC_AP_SET_PWD        0x21


@class TuyaSmartSocketChannel;

@protocol TuyaSmartSocketChannelDelegate <NSObject>

@optional

#pragma mark - TCP Delegate

// The TCP connection is successful.
- (void)socketDidTcpConnected:(TuyaSmartSocketChannel *)socket devId:(NSString *)devId;

// Receives a TCP message.
- (void)socket:(TuyaSmartSocketChannel *)socket didReceiveTcpData:(TuyaSmartSocketReadModel *)tcpData tag:(long)tag devId:(NSString *)devId;

// Closes the TCP connection.
- (void)socketDidTcpDisconnect:(TuyaSmartSocketChannel *)socket devId:(NSString *)devId error:(NSError *)error;


#pragma mark - UDP Delegate

// Receives a UDP message.
- (void)socket:(TuyaSmartSocketChannel *)socket didReceiveUdpData:(TuyaSmartSocketReadModel *)udpData;

// Closes a UDP connection.
- (void)socketDidUdpClose:(TuyaSmartSocketChannel *)socket error:(NSError *)error;

@end

@interface TuyaSmartSocketChannel : NSObject

+ (instancetype)sharedInstance;

/**
 *  A list of inactive devices.
 */
@property (nonatomic, strong) TYSDKSafeMutableDictionary   *inactiveDevices;

@property (nonatomic, strong) TYSDKSafeMutableDictionary    *HKDFDic;

#pragma mark - TCP

// Establishes a TCP connection.
- (void)initTcpClientWithHost:(NSString *)host devInfo:(NSDictionary *)devInfo;

// Sends a TCP message.
- (void)sendTcpRequest:(TuyaSmartSocketWriteModel *)request
               success:(TYSuccessDict)success
               failure:(TYFailureHandler)failure __deprecated_msg("This method is deprecated, Use sendTcpWithRequest:success:failure: instead");

// Sends a TCP message.
- (void)sendTcpWithRequest:(TuyaSmartSocketWriteModel *)request
                   success:(TYSuccessDict)success
                   failure:(TYFailureError)failure;

- (void)removeInactiveDevice:(NSString *)gwId;

- (void)removeAllInactiveDevice;

// Indicates whether the TCP connection is established.
- (BOOL)hasTcpClientWithDevId:(NSString *)devId;

// Closes a TCP connection.
- (void)closeTcpClientWithDevId:(NSString *)devId;

// Closes all TCP connections.
- (void)closeAllTcpClient;

#pragma mark - UDP

// Initializes a UDP server.
- (void)initUdpServerWithPort:(NSInteger)port;

// Sends a UDP message.
- (void)sendUdpRequestWithHost:(NSString *)host port:(NSInteger)port type:(int)type body:(NSDictionary *)body success:(TYSuccessHandler)success failure:(TYFailureHandler)failure;

- (void)sendUdpRequestWithHost:(NSString *)host port:(NSInteger)port type:(int)type body:(NSDictionary *)body lpv:(NSString *)lpv success:(TYSuccessHandler)success failure:(TYFailureHandler)failure;

// Closes a UDP server.
- (void)closeUdpServerWithPort:(uint16_t)port;

#pragma mark - Delegate

// Adds a socket channel delegate.
- (void)addDelegate:(id<TuyaSmartSocketChannelDelegate>)delegate;

// Removes a socket channel delegate.
- (void)removeDelegate:(id<TuyaSmartSocketChannelDelegate>)delegate;

@end

