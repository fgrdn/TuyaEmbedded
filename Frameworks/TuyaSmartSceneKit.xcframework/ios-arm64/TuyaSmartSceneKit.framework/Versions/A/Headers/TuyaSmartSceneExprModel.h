//
//  TuyaSmartSceneExprModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

/// @brief Scene expression model, it can be defined as any type.
@interface TuyaSmartSceneExprModel : NSObject

/// Used to store expression data, it can be used as any type.
@property (nonatomic, strong) NSArray *expr;

@end

