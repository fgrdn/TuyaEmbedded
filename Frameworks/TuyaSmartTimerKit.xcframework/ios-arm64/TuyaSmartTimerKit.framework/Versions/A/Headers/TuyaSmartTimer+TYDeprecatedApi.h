//
// TuyaSmartTimer+TYDeprecatedApi.h
// TuyaSmartTimerKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartTimer_TYDeprecatedApi_h
#define TuyaSmartTimer_TYDeprecatedApi_h

#import "TuyaSmartTimer.h"

/// @deprecated The old timer api, deprecated.
///
/// Can use TuyaSmartTimer.h to set timer
///
@interface TuyaSmartTimer (TYDeprecatedApi)

/// Add a new task for timer.
/// @param task The name of task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID for which the timer task needs to run on.
/// @param time The specific time to trigger this task.
/// @param dps The data point dictionary.
/// @param timeZone The timezone of the device.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartTimer::addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure: instead.
- (void)addTimerWithTask:(NSString *)task
                   loops:(NSString *)loops
                   devId:(NSString *)devId
                    time:(NSString *)time
                     dps:(NSDictionary *)dps
                timeZone:(NSString *)timeZone
                 success:(TYSuccessHandler)success
                 failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartTimer addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure:] instead");


/// Add timed tasks.
/// @param task The name of the task.
/// @param loops Number of cycles.
/// @param devId The device ID.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00, if the phone time zone is not taken.
/// @param isAppPush A Boolean value indicates whether to turn on the push notification.
/// @param aliasName The remark for the task.
/// @param success  Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartTimer::addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure: instead.
- (void)addTimerWithTask:(NSString *)task
                   loops:(NSString *)loops
                   devId:(NSString *)devId
                    time:(NSString *)time
                     dps:(NSDictionary *)dps
                timeZone:(NSString *)timeZone
               isAppPush:(BOOL)isAppPush
               aliasName:(NSString *)aliasName
                 success:(TYSuccessHandler)success
                 failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartTimer addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure:] instead");


/// Update timer task status.
/// @param task The name of the task.
/// @param devId The device ID.
/// @param status Timing group status.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartTimer::updateTimerStatusWithTask:bizId:bizType:status:success:failure: instead instead.
- (void)updateTimerTaskStatusWithTask:(NSString *)task
                                devId:(NSString *)devId
                               status:(NSInteger)status
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartTimer updateTimerStatusWithTask:bizId:bizType:status:success:failure:] instead");


/// Update timeclock status.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param status Timing clock status.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartTimer::updateTimerStatusWithTimerId:bizId:bizType:status:success:failure: instead instead.
- (void)updateTimerStatusWithTask:(NSString *)task
                            devId:(NSString *)devId
                          timerId:(NSString *)timerId
                           status:(NSInteger)status
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartTimer updateTimerStatusWithTimerId:bizId:bizType:status:success:failure:] instead");


/// Delete time clock.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartTimer::removeTimerWithTimerId:bizId:bizType:success:failure: instead.
- (void)removeTimerWithTask:(NSString *)task
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartTimer removeTimerWithTimerId:bizId:bizType:success:failure:] instead");


/// Update the timer.
/// @param task The name of the timer task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartTimer::updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure: instead.
- (void)updateTimerWithTask:(NSString *)task
                      loops:(NSString *)loops
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                       time:(NSString *)time
                        dps:(NSDictionary *)dps
                   timeZone:(NSString *)timeZone
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartTimer updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure:] instead");


/// Update the timer.
/// @param task The name of the timer task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00.
/// @param isAppPush A Boolean value indicates whether to turn on the push notification.
/// @param aliasName The remark for the task.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartTimer::updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure: instead.
- (void)updateTimerWithTask:(NSString *)task
                      loops:(NSString *)loops
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                       time:(NSString *)time
                        dps:(NSDictionary *)dps
                   timeZone:(NSString *)timeZone
                  isAppPush:(BOOL)isAppPush
                  aliasName:(NSString *)aliasName
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartTimer updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure:] instead");


/// Get all timer clocks under timer task.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartTimer::getTimerListWithTask:bizId:bizType:success:failure: instead.
- (void)getTimerWithTask:(NSString *)task
                   devId:(NSString *)devId
                 success:(void(^)(NSArray<TYTimerModel *> *list))success
                 failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartTimer getTimerListWithTask:bizId:bizType:success:failure:] instead");


@end


#endif /* TuyaSmartTimer_TYDeprecatedApi_h */
