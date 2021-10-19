//
//  TuyaSmartCameraDPManager+DPCode.h
//  TuyaSmartCameraKit
//
//  Created by lialong on 2019/9/12.
//

#import "TuyaSmartCameraDPManager.h"

@interface TuyaSmartCameraDPManager (DPCode)

- (BOOL)isSupportDPCode:(TuyaSmartCameraDPKey)DPCode;

- (id)valueForDPCode:(TuyaSmartCameraDPKey)DPCode;

- (void)valueForDPCode:(TuyaSmartCameraDPKey)DPCode success:(TYSuccessID)success failure:(TYFailureError)failure;

- (void)setValue:(id)value forDPCode:(TuyaSmartCameraDPKey)DPCode success:(TYSuccessID)success failure:(TYFailureError)failure;

+ (TuyaSmartCameraDPKey)convertDPCodeToDPIDwithDPCode:(TuyaSmartCameraDPKey)DPCode withDevice:(TuyaSmartDevice *)device;

+ (TuyaSmartCameraDPKey)convertDPIDToDPCodewithDPID:(TuyaSmartCameraDPKey)DPID withDevice:(TuyaSmartDevice *)device;

@end
