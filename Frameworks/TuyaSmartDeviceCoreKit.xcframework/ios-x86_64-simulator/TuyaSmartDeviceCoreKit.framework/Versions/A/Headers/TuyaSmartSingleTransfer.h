//
// TuyaSmartSingleTransfer.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TuyaSmartTransferState) {
    TuyaSmartTransferConnected = 1, // The connected state.
    TuyaSmartTransferDisconnected, // The disconnected state.
};

@class TuyaSmartSingleTransfer;
@protocol TuyaSmartTransferDelegate<NSObject>

/// When the connection state changes, the delegate is executed.
/// @param transfer Data is transferred.
/// @param state The transfer state in Tuya Smart.
- (void)transfer:(TuyaSmartSingleTransfer *)transfer didUpdateConnectState:(TuyaSmartTransferState)state;

/// When device data is received, the delegate is executed.
/// @param transfer Data is transferred.
/// @param devId The device ID.
/// @param data The received data.
- (void)transfer:(TuyaSmartSingleTransfer *)transfer didReciveDataWithDevId:(NSString *)devId data:(NSData *)data;

@end

__deprecated_msg("The channel already merged. We will provide a new way to support it.")
@interface TuyaSmartSingleTransfer : NSObject

/// @deprecated The data flow channel that is currently deprecated.
///
/// You can use TuyaSmartMQTTChannelDelegate to receive data.
///
@property (nonatomic, weak) id<TuyaSmartTransferDelegate> delegate;

#if TARGET_OS_IOS

/// Starts the connection.
- (void)startConnect;

/// The connection state.
/// @return The connection result.
- (BOOL)isConnected;

/// Close the channels. The merged channels are not closed to ensure the normal device subscription process.
- (void)close __deprecated_msg("will remove it");;

/// Subscribes to the device.
/// @param devId The device ID.
- (void)subscribeDeviceWithDevId:(NSString *)devId;

/// Unsubscribes from the device.
/// @param devId The device ID.
- (void)unsubscribeDeviceWithDevId:(NSString *)devId;

#endif

@end

