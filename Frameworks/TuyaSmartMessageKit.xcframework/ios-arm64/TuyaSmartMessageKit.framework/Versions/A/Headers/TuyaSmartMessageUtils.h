//
// TuyaSmartMessageUtils.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartMessageUtils_h
#define TuyaSmartMessageUtils_h

/// The three types of message. Provides alarm, family and notice types.
typedef NS_ENUM(NSInteger, TYMessageType) {
    /// The alarm message type.
    TYMessageTypeAlarm = 1,
    /// The family message type.
    TYMessageTypeFamily,
    /// The notice message type.
    TYMessageTypeNotice,
};

#endif /* TuyaSmartMessageUtils_h */
