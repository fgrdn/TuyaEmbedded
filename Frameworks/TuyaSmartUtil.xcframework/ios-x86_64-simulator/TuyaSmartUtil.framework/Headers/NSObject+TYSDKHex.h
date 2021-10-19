//
//  NSObject+TYHex.h
//  TuyaSmartBaseKit
//
//  Created by 高森 on 2018/6/14.
//

#import <Foundation/Foundation.h>

@interface NSString (TYSDKHex)

+ (instancetype)tysdk_stringFromHexString:(NSString *)hexString;

- (NSString *)tysdk_hexString;

/// Big or Small Data Transform，like this 510a3b -> 3b0a51
- (NSString *)tysdk_dataTransformBigSmall;

@end

@interface NSData (TYSDKHex)

+ (instancetype)tysdk_dataFromHexString:(NSString *)hexString;

- (NSString *)tysdk_hexString;

@end
