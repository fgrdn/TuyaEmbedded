//
//  TuyaSmartSDK+Upgrade.h
//  TuyaSmartBaseKit
//
//  Created by huangkai on 2021/6/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartSDK (Upgrade)

/// Check if TuyaSmartKit need to be upgrade to TuyaSmartHomeKit.
/// @return Whether need to upgrade data.
- (BOOL)checkVersionUpgrade;


/// SDK data upgrade.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)upgradeVersion:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
