//
// TuyaSmartBaseKitErrors.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartBaseKitErrors_h
#define TuyaSmartBaseKitErrors_h

/*
 *  TYBaseKitError
 *
 *  Discussion:
 *    Error returned as code to NSError from TuyaSmartBaseKit.
 */

extern NSString *const kTYBaseKitErrorDomain;

typedef NS_ENUM(NSInteger, TYBaseKitError) {
    /// Request Error.
    kTYBaseKitErrorAPIRequestError                       = 2000,
    /// Return data type is illegal.
    kTYBaseKitErrorAPIResponseDataTypeIllegal            = 2001,
    /// The returned data sign is inconsistent.
    kTYBaseKitErrorAPIResponseDataSignInconsistent       = 2002,
    /// Return data decode error.
    kTYBaseKitErrorAPIResponseDataDecodeError            = 2003,
    /// Network Error.
    kTYBaseKitErrorNetworkError                          = 2004,
    
};

#endif /* TuyaSmartBaseKitErrors_h */
