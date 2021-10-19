//
//  TYSmartBLEModel.h
//  TuyaSmartUtil-iOS-TuyaSmartUtil
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import "TYSmartBLEAPMEnum.h"

@interface TYSmartBLEAPMMessageModel : NSObject <NSCopying>

@property (nonatomic, strong) NSString *devId;
@property (nonatomic, assign) TYSmartBLEAPMType type;
@property (nonatomic, strong) NSDictionary *dps;
@property (nonatomic, assign) NSTimeInterval time; /**< The time when data is reported.  */
@property (nonatomic, strong) NSString *des; /**< The description.  */
@property (nonatomic, strong) NSDictionary *extInfo; /**< Reserved.  */


- (NSDictionary *)attributes;

@end
