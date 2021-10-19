//
// TYLoginRegionModel.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TYRegionModel_h
#define TYRegionModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief TYRegionModel is an object of server region.
@interface TYRegionModel : NSObject

/// The region name.
@property (nonatomic, strong) NSString *name;

/// The region code.
@property (nonatomic, strong) NSString *region;

/// Indicates whether the region is the default region.
@property (nonatomic, assign) BOOL isDefault;

@end

NS_ASSUME_NONNULL_END

#endif /* TYRegionModel_h */
