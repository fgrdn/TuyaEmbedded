//
//  TuyaSmartNetworkKitErrors.h
//  Pods
//
//  Created by huangkai on 2021/6/9.
//

#ifndef TuyaSmartNetworkKitErrors_h
#define TuyaSmartNetworkKitErrors_h

extern NSString *const kTYNetworkKitErrorDomain;

typedef NS_ENUM(NSInteger, TYNetworkKitError) {
    /// Request Error.
    kTYNetworkKitErrorAPIRequestError                       = 2000,
    /// Return data type is illegal.
    kTYNetworkKitErrorAPIResponseDataTypeIllegal            = 2001,
    /// The returned data sign is inconsistent.
    kTYNetworkKitErrorAPIResponseDataSignInconsistent       = 2002,
    /// Return data decode error.
    kTYNetworkKitErrorAPIResponseDataDecodeError            = 2003,
    /// Network Error.
    kTYNetworkKitErrorNetworkError                          = 2004,
    
};

#endif /* TuyaSmartNetworkKitErrors_h */
