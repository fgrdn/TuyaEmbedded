//
// TuyaSmartSIGMeshManager+Config.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>
NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartDeviceModel;

/// @brief The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// This API provides multiple functions such as device node control and resetting. The core channels are also used to send generic mesh messages.
@interface TuyaSmartSIGMeshManager (Config)

/// Resets the node.
/// @param deviceModel The value of TuyaSmartDeviceModel.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendNodeResetWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel
                             success:(nullable TYSuccessHandler)success
                             failure:(nullable TYFailureError)failure;

/// Controls the switch.
/// @param nodeId The node ID.
/// @param state The switch status.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendOnoffWithNodeId:(NSString *)nodeId
                      state:(BOOL)state
          useUnacknowledged:(BOOL)useUnacknowledged
                    success:(nullable TYSuccessHandler)success
                    failure:(nullable TYFailureError)failure;

/// Controls the brightness.
/// @param nodeId The node ID.
/// @param brightValue The brightness value. Valid values: `0` to `65535`.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightBrightWithNodeId:(NSString *)nodeId
                      brightValue:(int)brightValue
                useUnacknowledged:(BOOL)useUnacknowledged
                          success:(nullable TYSuccessHandler)success
                          failure:(nullable TYFailureError)failure;

/// Controls the heating and cooling functions.
/// @param nodeId The node ID.
/// @param tempValue Specifies the warm and cool temperatures. Valid values: 300 to 20000.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightCTLTempeValueWithNodeId:(NSString *)nodeId
                               tempValue:(int)tempValue
                       useUnacknowledged:(BOOL)useUnacknowledged
                                 success:(nullable TYSuccessHandler)success
                                 failure:(nullable TYFailureError)failure;

/// Controls the hue, lightness, and saturation (HLS) color model.
/// @param nodeId The node ID.
/// @param aHue The Hue. Valid values: `0` to `65535`.
/// @param aSaturation The saturation. Valid values: `0` to `65535`.
/// @param aLightness The brightness. Valid values: `l` and `v`, `0` to `65535`.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightHSLWithNodeId:(NSString *)nodeId
                           hue:(int)aHue
                 andSaturation:(int)aSaturation
                     lightness:(int)aLightness
             useUnacknowledged:(BOOL)useUnacknowledged
                       success:(nullable TYSuccessHandler)success
                       failure:(nullable TYFailureError)failure;

/// The setup mode.
/// @param nodeId The node ID.
/// @param alightModel The light model. Valid values: `0`: the white light mode. `1`: the colored light mode.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightModelWithNodeId:(NSString *)nodeId
                      lightModel:(int)alightModel
               useUnacknowledged:(BOOL)useUnacknowledged
                         success:(nullable TYSuccessHandler)success
                         failure:(nullable TYFailureError)failure;

/// The generic vendor protocol.
/// @param nodeId The node ID.
/// @param vendorData The data content.
/// @param isisQuery Specifies whether a query command is sent.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVendorDataWithNodeId:(NSString *)nodeId
                      vendorData:(NSData *)vendorData
                         isQuery:(BOOL)isisQuery
               useUnacknowledged:(BOOL)useUnacknowledged
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;

/// The custom channel that is enabled with the vendor commands.
/// @param nodeId The node ID.
/// @param opCode The operation code.
/// @param payload The metadata.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendCustomDataWithNodeId:(NSString *)nodeId
                          opCode:(int)opCode
                         payload:(NSData *)payload
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;

/// Sends DPs to a single device.
/// @param nodeId The node ID.
/// @param schemaArray The array of DP information.
/// @param dps The DPs.
/// @param pcc The size class label of the product.
/// @param useUnacknowledged Specifies whether a response is required. 
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDpsWithNodeId:(NSString *)nodeId
                 schemaArray:(NSArray<TuyaSmartSchemaModel *> *)schemaArray
                         dps:(NSDictionary *)dps
                         pcc:(NSString *)pcc
           useUnacknowledged:(BOOL)useUnacknowledged
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;

/// Returns the status of a device.
/// @param deviceModel The device model.
- (void)getDeviceStatusWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel;

/// Queries the device DPs.
/// @param deviceModel The device model.
/// @param dpIds The group of DP IDs to be queries.
- (void)queryDpsWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel dpIds:(NSArray<NSString *> *)dpIds;

@end

NS_ASSUME_NONNULL_END
