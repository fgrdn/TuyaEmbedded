//
//  TuyaSmartPTZManager.h
//  TuyaSmartCameraKit
//
//  Created by Wen Jun on 2021/5/24.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>

/// PTZ direction enumeration
typedef NS_ENUM(NSUInteger, TuyaSmartPTZControlDirection) {
    TuyaSmartPTZControlDirectionUp = 0,
    TuyaSmartPTZControlDirectionRightUp,
    TuyaSmartPTZControlDirectionRight,
    TuyaSmartPTZControlDirectionRightDown,
    TuyaSmartPTZControlDirectionDown,
    TuyaSmartPTZControlDirectionLeftDown,
    TuyaSmartPTZControlDirectionLeft,
    TuyaSmartPTZControlDirectionLeftUp
};

/// Cruise mode enumeration
typedef NS_ENUM(NSUInteger, TuyaSmartPTZControlCruiseMode) {
    TuyaSmartPTZControlCruiseModePanoramic = 0,// Panoramic cruise
    TuyaSmartPTZControlCruiseModeCollectionPoint // Collection point cruise
};

/// Cruise time mode enumeration
typedef NS_ENUM(NSUInteger, TuyaSmartPTZControlCruiseTimeMode) {
    TuyaSmartPTZControlCruiseTimeModeAllDay = 0,// Full day cruise
    TuyaSmartPTZControlCruiseTimeModeCustom // Custom time cruise
};

/// Cruise status enumeration
typedef NS_ENUM(NSUInteger, TuyaSmartPTZControlCruiseState) {
    TuyaSmartPTZControlCruiseStatePanoramic = 0,// Panoramic cruising
    TuyaSmartPTZControlCruiseStateCollectionPoint,// Collection point cruising
    TuyaSmartPTZControlCruiseStateNone // Not in cruising
};

NS_ASSUME_NONNULL_BEGIN

/// Collection point model
@interface TYCameraCollectionPointModel : NSObject
/// Device id
@property (nonatomic, strong) NSString *devId;
/// Collection point id
@property (nonatomic, strong) NSString *pointId;
/// Unique id in the device, generated by the device
@property (nonatomic, strong) NSString *mpId;
/// Collection point name
@property (nonatomic, strong) NSString *name;
/// The address of the picture
@property (nonatomic, strong) NSString *pic;
/// Collection point location information
@property (nonatomic, strong) NSString *pos;
/// Picture decryption key
@property (nonatomic, strong) NSString *encryption;

/// Generate a collection point model array
/// @param dictArray Collection point diction array
+ (NSArray *)modelsWithDictArray:(NSArray *)dictArray;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartPTZManager;
@protocol TuyaSmartPTZManagerDeletate <NSObject>

@optional

/// Did execute collectionPoint action
/// @param manager PTZ management class
/// @param type value:1, add collectionPoint; 2, remove collectionPoint; 3、 jump to specific collectionPoint
- (void)collectionPointAction:(TuyaSmartPTZManager *)manager actionType:(NSInteger)type;

/// Cruise switch state changed
/// @param manager PTZ management class
/// @param isOpen Cruise switch open state, YES, is opened; NO, is closed
- (void)didUpdateCruiseSwitchState:(TuyaSmartPTZManager *)manager isOpen:(BOOL)isOpen;

/// Cruise mode changed
/// @param manager PTZ management class
/// @param currentCruiseMode Current cruise mode. TuyaSmartPTZControlCruiseModePanoramic, panoramic mode; TuyaSmartPTZControlCruiseModeCollectionPoint, collectionPoint mode
- (void)didUpdateCruiseMode:(TuyaSmartPTZManager *)manager currentCruiseMode:(TuyaSmartPTZControlCruiseMode)currentCruiseMode;

/// Cruise time mode changed
/// @param manager PTZ management class
/// @param currentTimeMode The current cruise time mode. Value is a TuyaSmartPTZControlCruiseTimeMode enum.
- (void)didUpdateCruiseTimeMode:(TuyaSmartPTZManager *)manager currentTimeMode:(TuyaSmartPTZControlCruiseTimeMode)currentTimeMode;

/// Cruise time mode - Cruise time updated
/// @param manager PTZ management class
/// @param startTime The time to start cruising. Format:"HH:mm"
/// @param endTime The time to end cruising.Format:"HH:mm"
- (void)didUpdateCruiseTimeModeTime:(TuyaSmartPTZManager *)manager startTime:(NSString *)startTime endTime:(NSString *)endTime;

/// The switch state of mobile tracking has changed
/// @param manager PTZ management class
/// @param isOpen The latest value of open state
- (void)didUpdateMotionTrackingState:(TuyaSmartPTZManager *)manager isOpen:(BOOL)isOpen;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartPTZManager : NSObject

@property (nonatomic, weak) id<TuyaSmartPTZManagerDeletate> delegate;

/// Initialization
/// @param devId Device id
- (instancetype)initWithDeviceId:(NSString *)devId;

/// Is support PTZ control
- (BOOL)isSupportPTZControl;

/// Get all supported directions
/// Eg, ["0","1","2","3","4","5","6","7"]
- (NSArray *)requestSupportedPTZControlDirections;

/// Start PTZ control
/// @param direction Direction enumeration
/// @param success Successful callback
/// @param failure Failed callback
/// error.code, 8，Already reached the limit；9，It is being calibrated, please wait
- (void)startPTZWithDirection:(TuyaSmartPTZControlDirection)direction
         success:(TYSuccessID)success
         failure:(TYFailureError)failure;

/// Stop PTZ control
/// @param success Successful callback
/// @param failure Failed callback
- (void)stopPTZWithSuccess:(TYSuccessID)success
                   failure:(TYFailureError)failure;


/// Is support zoom action
- (BOOL)isSupportZoomAction;

/// Start zooming
/// @param isEnlarge YES，Get bigger；NO，Get smaller
/// @param success Successful callback
/// @param failure Failed callback
- (void)startPTZZoomWithIsEnlarge:(BOOL)isEnlarge
         success:(TYSuccessID)success
         failure:(TYFailureError)failure;

/// Stop zooming
/// @param success Successful callback
/// @param failure Failed callback
- (void)stopZoomActionWithSuccess:(TYSuccessID)success
                          failure:(TYFailureError)failure;


/// Is support collection point
- (BOOL)isSupportCollectionPoint;

/// Could operate collection point.
/// Only in non-cruise mode, can operate collection point
- (BOOL)couldOperateCollectionPoint;

/// Get collection points
/// @param success Successful callback
/// In the list is some TYCameraCollectionPointModels
/// @param failure Failed callback
- (void)requestCollectionPointListWithSuccess:(TYSuccessList)success failure:(TYFailureError)failure;

/// Add collection point
/// @param name Collection point name
/// @param success Successful callback
/// @param failure Failed callback
- (void)addCollectionPointWithName:(NSString *)name success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Delete collection points
/// @param models The collection point model array you want to remove
/// @param success Successful callback
/// @param failure Failed callback
- (void)deleteCollectionPoints:(NSArray<TYCameraCollectionPointModel *> *)models success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Modify collection point name
/// @param model Collection point model
/// @param name New name
/// @param success Successful callback
/// @param failure Failed callback
- (void)renameCollectionPoint:(TYCameraCollectionPointModel *)model name:(NSString *)name success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// View collection point
/// @param model Collection point model
/// @param success Successful callback
/// @param failure Failed callback
- (void)viewCollectionPoint:(TYCameraCollectionPointModel *)model success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Is support cruise
- (BOOL)isSupportCruise;

/// Get current cruise open state
- (BOOL)isOpenCruise;

/// Get current cruise mode
/// 0, Panoramic cruise; 1, Preset point cruise
- (TuyaSmartPTZControlCruiseMode)getCurrentCruiseMode;

/// Get current cruise time mode
/// 0, Full day cruise; 1, Custom time cruise
- (TuyaSmartPTZControlCruiseTimeMode)getCurrentCruiseTimeMode;

/// Get current cruise state
/// 0，Panoramic cruising；1，Collection point cruising；2，Not in cruising
- (TuyaSmartPTZControlCruiseState)getCurrentCruiseState;

/// Get current cruise time
/// Format：startTime-endTime，eg, "09:00-18:00"
- (NSString *)getCurrentCruiseTime;

/// Open or close cruise switch
/// @param isOpen YES，open；NO，close
/// @param success Successful callback
/// @param failure Failed callback
- (void)setCruiseOpen:(BOOL)isOpen success:(TYSuccessID)success failure:(TYFailureError)failure;

/// Set cruise mode
/// @param mode Cruise mode, 0, Panoramic cruise; 1, Preset point cruise
/// @param success Successful callback
/// @param failure Failed callback
- (void)setCruiseMode:(TuyaSmartPTZControlCruiseMode)mode success:(TYSuccessID)success failure:(TYFailureError)failure;

/// Set cruise time mode
/// @param timeMode Cruise time mode，0、Full day cruise; 1、Custom time cruise
/// @param success Successful callback
/// @param failure Failed callback
- (void)setCruiseTimeMode:(TuyaSmartPTZControlCruiseTimeMode)timeMode success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Set cruise state
/// @param state cruise state，0, Panoramic cruise; 1, Collection point cruise; 2, Not in cruise
/// @param success Successful callback
/// @param failure Failed callback
- (void)setCruiseState:(TuyaSmartPTZControlCruiseState)state success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Set custom time for cruise
/// @param startTime Format "00:00"
/// @param endTime Format "00:00"
/// @param success Successful callback
/// @param failure Failed callback
- (void)setCruiseCustomWithStartTime:(NSString *)startTime endTime:(NSString *)endTime success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Is support motionTracking
- (BOOL)isSupportMotionTracking;

/// Is open motionTracking
- (BOOL)isOpenMotionTracking;

/// Open or close motionTracking
/// @param isOpen YES，open action；NO，is close action
/// @param success Successful callback
/// @param failure Failed callback
- (void)setMotionTrackingState:(BOOL)isOpen success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Is support preset point
- (BOOL)isSupportPresetPoint;

/// Get preset points, eg, ["1","2","3","4"]
- (NSArray *)requestSupportedPresetPoints;

/// View the preset point at Index
/// @param index Enumeration value of preset point, which is get from requestSupportedPresetPoints api
/// @param success Successful callback
/// @param failure Failed callback
- (void)viewPresetPointWithIndex:(NSInteger)index success:(TYSuccessID)success failure:(TYFailureError)failure;

/// Set the preset point at index
/// @param index Enumeration value of preset point, which is get from requestSupportedPresetPoints api
/// @param success Successful callback
/// @param failure Failed callback
- (void)setPresetPointWithIndex:(NSInteger)index success:(TYSuccessID)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
