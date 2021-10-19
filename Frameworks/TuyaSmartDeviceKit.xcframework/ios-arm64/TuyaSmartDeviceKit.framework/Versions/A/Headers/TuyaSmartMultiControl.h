//
// TuyaSmartMultiControl.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMultiControlLinkModel.h"
#import "TuyaSmartMultiControlModel.h"
#import "TuyaSmartMultiControlDpRelationModel.h"
#import "TuyaSmartMultiControlDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControl : NSObject

/// Queries the multi-control and automation functions that are associated with the specified device DP.
/// @param devId The main device ID.
/// @param dpId The DP ID.
/// @param success Called when the task is finished. TuyaSmartMultiControlLinkModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryDeviceLinkInfoWithDevId:(NSString *)devId
                                dpId:(NSString *)dpId
                             success:(void (^)(TuyaSmartMultiControlLinkModel *))success
                             failure:(TYFailureError)failure;

/// Adds a multi-control group.
/// @param devId The main device ID.
/// @param groupName The group name.
/// @param groupDetail The multi-control group association details.
/// @param success Called when the task is finished. TuyaSmartMultiControlModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addMultiControlWithDevId:(NSString *)devId
                       groupName:(NSString *)groupName
                     groupDetail:(NSArray<TuyaSmartMultiControlDetailModel *> *)groupDetail
                         success:(void (^)(TuyaSmartMultiControlModel *))success
                         failure:(TYFailureError)failure;

//// Updates the multi-control group.
/// @param devId The main device ID.
/// @param model The data model of the multi-control group.
/// @param success Called when the task is finished. TuyaSmartMultiControlModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)updateMultiControlWithDevId:(NSString *)devId
                  multiControlModel:(TuyaSmartMultiControlModel *)model
                            success:(void (^)(TuyaSmartMultiControlModel *))success
                            failure:(TYFailureError)failure;

/// Returns the DP information of attached devices, the associated multi-control, and the scene automation information.
/// @param devId The device ID.
/// @param success Called when the task is finished. TuyaSmartMultiControlDpRelationModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryDeviceDpRelationWithDevId:(NSString *)devId
                               success:(void (^)(TuyaSmartMultiControlDpRelationModel *))success
                               failure:(TYFailureError)failure;


/// Enables or disables multi-control groups.
/// @param multiControlId The multi-control group ID.
/// @param enable A Boolean value that specifies whether to enable or disable the group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)enableMultiControlWithMultiControlId:(NSString *)multiControlId
                                      enable:(BOOL)enable
                                     success:(TYSuccessBOOL)success
                                     failure:(TYFailureError)failure;


/// Queries a list of device IDs and device groups that support specific actions. The data is returned by home ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished. A list of TuyaSmartMultiControlDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getMultiControlDeviceListWithHomeId:(long long)homeId
                                    success:(void (^)(NSArray<TuyaSmartMultiControlDeviceModel *> *))success
                                    failure:(TYFailureError)failure;


/// Returns information about all DPs of the specified device.
/// @param devId The device ID.
/// @param success Called when the task is finished. A list of TuyaSmartMultiControlDatapointModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceDpInfoWithDevId:(NSString *)devId
                         success:(void (^)(NSArray<TuyaSmartMultiControlDatapointModel *> *))success
                         failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
