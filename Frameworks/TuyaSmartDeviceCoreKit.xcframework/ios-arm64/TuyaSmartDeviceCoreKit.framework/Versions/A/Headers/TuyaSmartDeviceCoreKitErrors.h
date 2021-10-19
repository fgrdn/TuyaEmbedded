//
// TuyaSmartDeviceCoreKitErrors.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartDeviceCoreKitErrors_h
#define TuyaSmartDeviceCoreKitErrors_h

/*
 *  TYDeviceCoreKitError
 *
 *  Discussion:
 *    Error returned as code to NSError from TuyaSmartDeviceKit.
 */
extern NSString *const kTYDeviceCoreKitErrorDomain;

/// The definitions of device core kit errors.
typedef NS_ENUM(NSInteger, TYDeviceCoreKitError) {
    /// The device does not support a certain capability that is reported on the device dimensions.
    kTYDeviceCoreKitErrorDeviceNotSupport                      = 3000,
    /// The LAN downstream data failure.
    kTYDeviceCoreKitErrorSocketSendDataFailed                  = 3001,
    /// The DP data is empty.
    kTYDeviceCoreKitErrorEmptyDpsData                          = 3002,
    /// The group devices are empty.
    kTYDeviceCoreKitErrorGroupDeviceListEmpty                  = 3003,
    /// The group ID length error.
    kTYDeviceCoreKitErrorGroupIdLengthError                    = 3004,
    /// Illegal DPs. See the product DP definition.
    kTYDeviceCoreKitErrorIllegalDpData                         = 3005,
    /// The device ID length error.
    kTYDeviceCoreKitErrorDeviceIdLengthError                   = 3006,
    /// The local key is not found.
    kTYDeviceCoreKitErrorDeviceLocalKeyNotFound                = 3007,
    /// The product ID length error.
    kTYDeviceCoreKitErrorDeviceProductIDLengthError            = 3008,
    /// Illegal communication type, see the enum TYCommunicationType.
    kTYDeviceCoreKitErrorIllegalCommunicationType              = 3009,
    
};

#endif /* TuyaSmartDeviceCoreKitErrors_h */
