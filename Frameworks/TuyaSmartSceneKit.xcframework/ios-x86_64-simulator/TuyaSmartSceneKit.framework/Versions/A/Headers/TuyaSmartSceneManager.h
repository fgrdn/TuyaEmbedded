//
//  TuyaSmartSceneManager.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>
#import "TuyaSmartCityModel.h"
#import "TuyaSmartSceneDPModel.h"
#import "TuyaSmartSceneModel.h"
#import "TuyaSmartSceneLogModel.h"
#import "TuyaSmartSceneLogDetailModel.h"

@class TuyaSmartSceneManager;

/// The protocol provides delegate methods to receive changes to the scene enable or disable state.
@protocol TuyaSmartSceneManagerDelegate<NSObject>

@optional

/// Called when the state of the scene changes.
///
/// @param manager The scene manager.
/// @param state   The scene state, eg: "disable、"enable".
/// @param sceneId The scene ID.
- (void)sceneManager:(TuyaSmartSceneManager *)manager state:(NSString *)state sceneId:(NSString *)sceneId;

@end

/// @brief The TuyaSmartSceneManager class provides many methods for developers getting the list of scenes, getting the list of conditions, getting the list of tasks, the list of cities, the list of scene log, etc.
@interface TuyaSmartSceneManager : NSObject

/// Returns the singleton of the TuyaSmartSceneManager class.
///
/// @return The TuyaSmartSceneManager instance.
+ (instancetype)sharedInstance;

/// The delegate will be notified when the scene's contents change. @see TuyaSmartSceneManagerDelegate.
@property (nonatomic, weak) id<TuyaSmartSceneManagerDelegate> delegate;

/// Get a list of scenes, including tap-to-run and automation. We can judge tap-to-run and automation scene by the entityType of conditions property in TuyaSmartSceneModel, The scene is tap-to-run when the entityType equal AutoTypeManual, otherwise it's automation.
///
/// @see For more information about the entityType, you can see TuyaSmartSceneConditionModel class.
///
/// @param homeId  The current home ID.
/// @param success When successfully get the scene list, this block will be called and return TuyaSmartSceneModel list.
/// @param failure When error occurred, this block will be called and return TYFailureError.
- (void)getSceneListWithHomeId:(long long)homeId
                       success:(void(^)(NSArray<TuyaSmartSceneModel *> *list))success
                       failure:(TYFailureError)failure;

/// Get a simple list of scenes, including tap-to-run and automation. We can judge tap-to-run and automation scene by the entityType of conditions property in TuyaSmartSceneModel, The scene is tap-to-run when the entityType equal AutoTypeManual, otherwise it's automation.
///
/// @note The different between the simple scene list and scene list is less json data returned by the server.
///
/// @param homeId  The current home ID.
/// @param success When successfully get the scene list, this block will be called and return TuyaSmartSceneModel list.
/// @param failure When error occurred, this block will be called and return TYFailureError.
- (void)getSimpleSceneListWithHomeId:(long long)homeId
                       success:(void(^)(NSArray<TuyaSmartSceneModel *> *list))success
                       failure:(TYFailureError)failure;

/// Get scene detail information according to the specify homeId and sceneId.
///
/// @param homeId  The home ID.
/// @param sceneId The scene ID.
/// @param success When successfully get scene detail, this block will be called and return TuyaSmartSceneModel object.
/// @param failure When error occurred, this block will be called and return TYFailureError.
- (void)getSceneDetailWithHomeId:(long long)homeId
                         sceneId:(NSString *)sceneId
                         success:(void(^)(TuyaSmartSceneModel *scene))success
                         failure:(TYFailureError)failure;

/// Get recommend scene list with the specify homeId.
///
/// @param homeId  The home ID.
/// @param success When success, return TuyaSmartSceneModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getRecommendedSceneListWithHomeId:(long long)homeId
                       success:(void(^)(NSArray<TuyaSmartSceneModel *> *list))success
                       failure:(TYFailureError)failure;

/// Get recommend scene list with the specify homeId and deviceId.
/// @param homeId The home ID.
/// @param deviceId The device ID.
/// @param count The request count.
/// @param success When success, return TuyaSmartSceneModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getRecommendedSceneListWithHomeId:(long long)homeId
                                 deviceId:(NSString *)deviceId
                                    count:(NSInteger)count
                                  success:(void(^)(NSArray<TuyaSmartSceneModel *> *list))success
                                  failure:(TYFailureError)failure;

/// Get collection scene list with the specify homeId.
///
/// @param homeId  The home ID.
/// @param success When success, return TuyaSmartSceneModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getCollectionSceneListWithHomeId:(long long)homeId
                                 success:(TYSuccessList)success
                                 failure:(TYFailureError)failure;

/// Get all condition list for automation conditions with the specify temperature scale type, speed unit and homeId.
///
/// @param fahrenheit If YES, indicate the temperature unit is Fahrenheit, otherwise Celsius.
/// @param speedUnit  The speed unit description.
/// @param homeId     The current home ID.
/// @param success    When success, return  map object, including envConditions and devConditions object.
/// @param failure    When error occurred, return TYFailureError.
- (void)getAllConditionListWithFahrenheit:(BOOL)fahrenheit
                            windSpeedUnit:(NSString *)speedUnit
                                   homeId:(long long)homeId
                                  success:(void(^)(NSDictionary *dict))success
                                  failure:(TYFailureError)failure;

/// Get action device list in the scene with specify the current home id.
///
/// @param homeId  The current home ID.
/// @param success When success, return TuyaSmartDeviceModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getActionDeviceListWithHomeId:(long long)homeId
                              success:(void(^)(NSArray<TuyaSmartDeviceModel *> *list))success
                              failure:(TYFailureError)failure;

/// Get action device list in the current room with the specify room id.
///
/// @param roomId The room ID.
///
/// @retrun The TuyaSmartDeviceModel list, the more information you can see TuyaSmartDeviceModel class.
- (NSArray<TuyaSmartDeviceModel *> *)getActionDeviceListWithRoomId:(long long)roomId;


/// Get condition device list in the scene with specify the current home id
///
/// @param homeId  The home ID.
/// @param success When success, return TuyaSmartDeviceModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getConditionDeviceListWithHomeId:(long long)homeId
                                 success:(void(^)(NSArray<TuyaSmartDeviceModel *> *list))success
                                 failure:(TYFailureError)failure;

/// Get condition device list for the current room in the scene with specify room id.
///
/// @param roomId The room ID.
///
/// @return The TuyaSmartDeviceModel list, the more information you can see TuyaSmartDeviceModel class.
- (NSArray<TuyaSmartDeviceModel *> *)getConditionDeviceListWithRoomId:(long long)roomId;

/// Get device list for recognize face condition type with specify current home id.
///
/// @param homeId  The home ID.
/// @param success When success, return TuyaSmartDeviceModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getFaceDeviceListWithHomeId:(long long)homeId success:(void(^)(NSArray<TuyaSmartDeviceModel *> *list))success failure:(TYFailureError)failure;

/// Get device list for the member lock condition type with specify current home id.
///
/// @param homeId  The home ID.
/// @param success When success, return TuyaSmartDeviceModel list for member lock condition.
/// @param failure When error occurred, return TYFailureError.
- (void)getLockDeviceListWithHomeId:(long long)homeId
                            success:(void(^)(NSArray<TuyaSmartDeviceModel *> *list))success
                            failure:(TYFailureError)failure;

/// Get group list for action in the scene with specify the current room id.
///
/// @param roomId The room ID.
///
/// @return The TuyaSmartGroupModel list for action in the scene, more information you can see TuyaSmartGroupModel class.
- (NSArray<TuyaSmartGroupModel *> *)getActionGroupListWithRoomId:(long long)roomId;

/// Get all device list and group list for action in the scene with specify the current home id.
///
/// @param homeId  The home ID.
/// @param success When success, return map object, including deviceList、groupList and extendsDictionary object.
/// @param failure When error occurred, return TYFailureError.
- (void)getActionGroupListAndDeviceListWithHomeId:(long long)homeId
                                          success:(void(^)(NSDictionary *dict))success
                                          failure:(TYFailureError)failure;

/// Get device data point list for action in the scene with specify the device id.
///
/// @param devId   The device ID.
/// @param success When success, return TuyaSmartSceneDPModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getActionDeviceDPListWithDevId:(NSString *)devId
                               success:(void(^)(NSArray<TuyaSmartSceneDPModel *> *list))success
                               failure:(TYFailureError)failure;

/// Get device dp list for condition in the scene with specify the device id.
///
/// @param devId   The device ID.
/// @param success When success, return TuyaSmartSceneDPModel list. The TuyaSmartSceneDPModel object describes the datapoint data of the device.
/// @param failure When error occurred, return TYFailureError.
- (void)getCondicationDeviceDPListWithDevId:(NSString *)devId
                                    success:(void(^)(NSArray<TuyaSmartSceneDPModel *> *list))success
                                    failure:(TYFailureError)failure;

/// Get group datapoint list for action in the scene with specify the current group id.
///
/// @param groupId The group ID.
/// @param success When success, return TuyaSmartSceneDPModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getActionGroupDPListWithGroupId:(NSString *)groupId
                                success:(void(^)(NSArray<TuyaSmartSceneDPModel *> *list))success
                                failure:(TYFailureError)failure;

/// Get city list with specify the current country code. If you are out of China, we suggest you use latitude and longitude to get the city information.
///
/// @param countryCode The country code.
/// @param success     When success, return TuyaSmartCityModel list.
/// @param failure     When error occurred, return TYFailureError.
- (void)getCityListWithCountryCode:(NSString *)countryCode
                           success:(void(^)(NSArray<TuyaSmartCityModel *> *list))success
                           failure:(TYFailureError)failure;

/// Get city detail information with specify the latitude and longitude.
///
/// @param latitude  The latitude.
/// @param longitude The longitude.
/// @param success   When success, return TuyaSmartCityModel list.
/// @param failure   When error occurred, return TYFailureError.
- (void)getCityInfoWithLatitude:(NSString *)latitude
                      longitude:(NSString *)longitude
                        success:(void(^)(TuyaSmartCityModel *model))success
                        failure:(TYFailureError)failure;

/// Get city detail information with specify the city id.
///
/// @param cityId  The city ID.
/// @param success When success, return TuyaSmartCityModel list.
/// @param failure When error occurred, return TYFailureError.
- (void)getCityInfoWithCityId:(NSString *)cityId
                      success:(void(^)(TuyaSmartCityModel *model))success
                      failure:(TYFailureError)failure;

/// Sort the scene list by the current home id.
///
/// @param homeId      The home ID.
/// @param sceneIdList The scene list that to be sorted.
/// @param success     When success, return TYSuccessHandler.
/// @param failure     When error occurred, return TYFailureError.
- (void)sortSceneWithHomeId:(long long)homeId
                sceneIdList:(NSArray<NSString *> *)sceneIdList
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;

/// Get scene background icons URL list.
///
/// @param success When success, return URL list.
/// @param failure When error occurred, return TYFailureError.
- (void)getSmartSceneBackgroundCoverWithsuccess:(TYSuccessList)success failure:(TYFailureError)failure;

/// Get scene custom style resource list, including color、icon and background. The return result map object, contain coverColors、coverIconList and coverPics.
///
/// @param success When success, return map object, including coverColors、coverIconList and coverPics object.
/// @param failure When error occurred, return TYFailureError.
- (void)getSmartSceneCustomStyleListWithSuccess:(TYSuccessDict)success failure:(TYFailureError)failure;

/// Get all scene linkage logs, including reminder of successful or failed scene execution、push information and so on.
///
/// @param homeId         The home ID.
/// @param startTime      The start date.
/// @param endTime        The end date.
/// @param size           The number of items to be queried.
/// @param lastId         The id of the last query item.
/// @param lastRecordTime The record date of the last query item.
/// @param success        When success, return TuyaSmartSceneLogModel list.
/// @param failure        When error occurred, return TYFailureError.
- (void)getSmartSceneLogWithHomeId:(long long)homeId
                         startTime:(long long)startTime
                           endTime:(long long)endTime
                              size:(NSInteger)size
                            lastId:(NSString *)lastId
                    lastRecordTime:(long long)lastRecordTime
                           success:(void(^)(TuyaSmartSceneLogModel *logModel))success
                           failure:(TYFailureError)failure;

/// Get scene linkage log list of specified device.
///
/// @param devId          The device ID.
/// @param homeId         The home ID.
/// @param startTime      The start date.
/// @param endTime        The end date.
/// @param size           The number of items to be queried.
/// @param lastId         The id of the last query item.
/// @param lastRecordTime The record date of the last query item.
/// @param success        When success, return TuyaSmartSceneLogModel list.
/// @param failure        When error occurred, return TYFailureError.
- (void)getSmartSceneLogOfDeviceWithDevId:(NSString *)devId
                                   homeId:(long long)homeId
                                startTime:(long long)startTime
                                  endTime:(long long)endTime
                                     size:(NSInteger)size
                                   lastId:(NSString *)lastId
                           lastRecordTime:(long long)lastRecordTime
                                  success:(void(^)(TuyaSmartSceneLogModel *logModel))success
                                  failure:(TYFailureError)failure;

/// Get scene log detail information by the homeId, eventId, startTime, endTime, returnType.
///
/// @param homeId     The home ID.
/// @param eventId    The event ID.
/// @param startTime  The start date.
/// @param endTime    The end date.
/// @param returnType The return type.
/// @param success    When success, return TuyaSmartSceneLogDetailModel list.
/// @param failure    When error occurred, return TYFailureError.
- (void)getSmartSceneLogDetailWithHomeId:(long long)homeId
                                 eventId:(NSString *)eventId
                               startTime:(long long)startTime
                                 endTime:(long long)endTime
                              returnType:(long long)returnType
                                 success:(void(^)(NSArray <TuyaSmartSceneLogDetailModel *>*items))success
                                 failure:(TYFailureError)failure;

/// Remove all geofence registered in the apple system for automation scene when user logout.
- (void)removeAllGeoFence;

/// Cancel the request being executed.
- (void)cancelRequest;

#pragma mark - Deprecated

/// Get a weather condition list for automation conditions with the specify temperature scale type. If Fahrenheit is YES, indicates that the temperature unit you use is Fahrenheit, otherwise you use is Celsius.
///
/// @param fahrenheit If YES, indicate the temperature unit is Fahrenheit, otherwise Celsius.
/// @param success    When success, return TuyaSmartSceneDPModel list.
/// @param failure    When error occurred, return TYFailureError.
///
/// @deprecated This method is deprecated, Use getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead.
- (void)getConditionListWithFahrenheit:(BOOL)fahrenheit
                               success:(void(^)(NSArray<TuyaSmartSceneDPModel *> *list))success
                               failure:(TYFailureError)failure __deprecated_msg("use -getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead");

/// Get all condition list for automation conditions, including weather condition、device condition and so on.
///
/// @param fahrenheit If YES, indicate the temperature unit is Fahrenheit, otherwise Celsius.
/// @param homeId     The current home ID.
/// @param success    When success, return map object, including envConditions and devConditions object.
/// @param failure    When error occurred, return TYFailureError.
///
/// @deprecated This method is deprecated, Use getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead.
- (void)getAllConditionListWithFahrenheit:(BOOL)fahrenheit
                                   homeId:(long long)homeId
                                  success:(void(^)(NSDictionary *dict))success
                                  failure:(TYFailureError)failure __deprecated_msg("use -getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead");

@end
