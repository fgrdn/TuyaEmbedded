//
// TuyaSmartHomeManager.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

#import "TuyaSmartHomeModel.h"

@class TuyaSmartHomeManager;


@protocol TuyaSmartHomeManagerDelegate <NSObject>

@optional

/// The delegate that is instantiated when a home is added.
///
/// @param manager  The instance.
/// @param home     The home model.
- (void)homeManager:(TuyaSmartHomeManager *)manager didAddHome:(TuyaSmartHomeModel *)home;

/// The delegate that is instantiated when an existing home is removed.
///
/// @param manager  The instance.
/// @param homeId   The home ID.
- (void)homeManager:(TuyaSmartHomeManager *)manager didRemoveHome:(long long)homeId;

/// MQTT service connection success callback.
- (void)serviceConnectedSuccess;


@end

@interface TuyaSmartHomeManager : NSObject

@property (nonatomic, weak) id <TuyaSmartHomeManagerDelegate> delegate;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartHomeModel *> *homes;


/// Returns a list of homes. To get home details, initialize a home and call getHomeDetailWithSuccess: failure:.
///
/// @param success Called when the task is finished. A list of TuyaSmartHomeModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomeListWithSuccess:(void(^)(NSArray <TuyaSmartHomeModel *> *homes))success
                       failure:(TYFailureError)failure;


/// Adds a home.
///
/// @param homeName    The home name.
/// @param geoName     The city name.
/// @param rooms       The rooms list.
/// @param latitude    The latitude.
/// @param longitude   The longitude.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addHomeWithName:(NSString *)homeName
                geoName:(NSString *)geoName
                  rooms:(NSArray <NSString *>*)rooms
               latitude:(double)latitude
              longitude:(double)longitude
                success:(TYSuccessLongLong)success
                failure:(TYFailureError)failure;


/// Sorts the homes.
///
/// @param homeList    A list of homes.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)sortHomeList:(NSArray <TuyaSmartHomeModel *> *)homeList
             success:(TYSuccessHandler)success
             failure:(TYFailureError)failure;

#pragma mark - deprecated

/// Accepts or rejects to share a home.
///
/// @param homeId       The home ID.
/// @param isAccept     Specifies whether to accept the invitation.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHome::joinFamilyWithAccept:success:failure: instead.
- (void)joinFamilyWithHomeId:(long long)homeId
                      action:(BOOL)isAccept
                     success:(TYSuccessBOOL)success
                     failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHome - (void)joinFamilyWithAccept:success:failure:] instead");

@end
