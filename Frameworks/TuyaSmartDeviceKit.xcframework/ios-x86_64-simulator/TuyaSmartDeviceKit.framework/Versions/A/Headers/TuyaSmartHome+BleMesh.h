//
// TuyaSmartHome+BleMesh.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

@interface TuyaSmartHome (BleMesh)

@property (nonatomic, strong, readonly) TuyaSmartBleMeshModel *meshModel;

/// Returns the mesh list for the home.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getMeshListWithSuccess:(void(^)(NSArray <TuyaSmartBleMeshModel *> *list))success
                       failure:(TYFailureError)failure;


@end
