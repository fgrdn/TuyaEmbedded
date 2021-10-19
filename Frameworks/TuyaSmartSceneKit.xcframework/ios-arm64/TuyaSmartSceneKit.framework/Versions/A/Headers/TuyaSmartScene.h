//
//  TuyaSmartScene.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TuyaSmartSceneModel.h"
#import "TuyaSmartSceneActionModel.h"
#import "TuyaSmartSceneConditionModel.h"

/// @brief TuyaSmartScene is used to add, edit delete and execute scenes. 
@interface TuyaSmartScene : NSObject

/// Class method for initialize TuyaSmartScene by TuyaSmartSceneModel.
///
/// @param sceneModel scene model.
/// @return instance of TuyaSmartScene.
+ (instancetype)sceneWithSceneModel:(TuyaSmartSceneModel *)sceneModel;

/// Instance method for initialize TuyaSmartScene by TuyaSmartSceneModel.
///
/// @param sceneModel scene model.
/// @return instance of TuyaSmartScene.
- (instancetype)initWithSceneModel:(TuyaSmartSceneModel *)sceneModel;

/// Don't initialize an instance with init method.
///
/// @return    This method will return an unavailable instance.
- (instancetype)init NS_UNAVAILABLE;

/// Add a scene by all param
///
/// @param name               The scene name.
/// @param homeId            The home id.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param preConditionList       preconditions, like valid time period.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return TuyaSmartSceneModel.
/// @param failure            When failure return TYFailureError.
+ (void)addNewSceneWithName:(NSString *)name
                     homeId:(long long)homeId
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
           preConditionList:(NSArray<TuyaSmartScenePreConditionModel*> *)preConditionList
              conditionList:(NSArray<TuyaSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<TuyaSmartSceneActionModel*> *)actionList
                  matchType:(TuyaSmartConditionMatchType)matchType
                    success:(void (^)(TuyaSmartSceneModel *sceneModel))success
                    failure:(TYFailureError)failure;

/// Add a new scene.Use a sceneModel with complete information of a scene.
///
/// @param sceneModel     TuyaSmartSceneModel
/// @param homeId              The home id.
/// @param success            When success return TuyaSmartSceneModel.
/// @param failure            When failure return TYFailureError.
+ (void)addNewSceneWithSceneModel:(TuyaSmartSceneModel *)sceneModel
                           homeId:(long long)homeId
                          success:(void (^)(TuyaSmartSceneModel *sceneModel))success
                          failure:(TYFailureError)failure;

/// Edit a existed scene with all param
///
/// @param name               The scene name.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param preConditionList       preconditions, like valid time period.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)modifySceneWithName:(NSString *)name
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
           preConditionList:(NSArray<TuyaSmartScenePreConditionModel*> *)preConditionList
              conditionList:(NSArray<TuyaSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<TuyaSmartSceneActionModel*> *)actionList
                  matchType:(TuyaSmartConditionMatchType)matchType
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;

/// Edit a existed scene.Use a sceneModel with complete information of a scene.
///
/// @param sceneModel     TuyaSmartSceneModel
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)modifySceneWithSceneModel:(TuyaSmartSceneModel *)sceneModel
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;

/// Delete a existed scene.
///
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)deleteSceneWithSuccess:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;

/// Execute a scene.
///
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)executeSceneWithSuccess:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Disable an automation, which will not executed automatically.
///
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)disableSceneWithSuccess:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Enable an automation, which will be executed while the conditions are matched.
///
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)enableSceneWithSuccess:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;

/// Cancel the request being executed.
- (void)cancelRequest;

#pragma mark - Recommend scene

/// Execute a recommended scene.
///
/// @param homeId              The home id.
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)triggerRecommendSceneWithHomeId:(long long)homeId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Delete a recommended scene.
///
/// @param homeId              The home id.
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)removeRecommendSceneWithHomeId:(long long)homeId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Save a recommended scene, this scene can be modified by user. this scene will become a normal scene after save successfully, and the recommended scene will not show anymore.
///
/// @param homeId              The home id.
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
- (void)saveRecommendSceneWithHomeId:(long long)homeId success:(void (^)(TuyaSmartSceneModel *sceneModel))success failure:(TYFailureError)failure;

#pragma mark - Deprecated

/// Add a scene by all param, (deprecated).
///
/// @param name               The scene name.
/// @param homeId            The home id.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return TuyaSmartSceneModel.
/// @param failure            When failure return TYFailureError.
///
/// @deprecated This method is deprecated, Use -[TuyaSmartScene addNewSceneWithName:homeId:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead
+ (void)addNewSceneWithName:(NSString *)name
                     homeId:(long long)homeId
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
              conditionList:(NSArray<TuyaSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<TuyaSmartSceneActionModel*> *)actionList
                  matchType:(TuyaSmartConditionMatchType)matchType
                    success:(void (^)(TuyaSmartSceneModel *sceneModel))success
                    failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartScene addNewSceneWithName:homeId:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead");

/// Edit an existed scene with all param, (deprecated).
///
/// @param name               The scene name.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return TYSuccessHandler.
/// @param failure            When failure return TYFailureError.
///
/// @deprecated This method is deprecated, Use -[TuyaSmartScene modifySceneWithName:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead.
- (void)modifySceneWithName:(NSString *)name
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
              conditionList:(NSArray<TuyaSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<TuyaSmartSceneActionModel*> *)actionList
                  matchType:(TuyaSmartConditionMatchType)matchType
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartScene modifySceneWithName:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead");
@end
