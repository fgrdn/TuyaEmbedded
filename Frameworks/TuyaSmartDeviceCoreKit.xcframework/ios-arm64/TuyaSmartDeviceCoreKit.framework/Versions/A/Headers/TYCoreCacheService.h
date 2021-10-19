//
// TYCoreCacheService.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The delegate of the TYCoreCacheService class provides the callback of device or group status.
@protocol TYCoreCacheServiceDelegate <NSObject>

- (void)deviceDidAdd:(TuyaSmartDeviceModel *)deviceModel;
- (void)deviceListDidAdd:(NSArray<TuyaSmartDeviceModel *> *)deviceList;
- (void)deviceDidRemove:(NSString *)devId;

- (void)groupDidAdd:(TuyaSmartGroupModel *)groupModel;
- (void)groupDidRemove:(long long)groupId;

@end

/// @brief The devices and group core cache classes allow you to add, modify, and delete data models. You can also subscribe to MQTT messages.
@interface TYCoreCacheService : NSObject

TYSDK_SINGLETON;

@property (nonatomic, weak) id<TYCoreCacheServiceDelegate> delegate;

/// The device cache.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, TuyaSmartDeviceModel *> *deviceData;

/// The group caching.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, TuyaSmartGroupModel *> *groupData;

/// The group product information cache.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSDictionary *> *groupProductData;

/// The group device relationship cache.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSMutableArray<NSString *> *> *groupDeviceRelation;

/// The mesh information.
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, TuyaSmartBleMeshModel *> *meshData;

/// The mesh group information.
@property (nonatomic, strong, readonly) NSMutableDictionary *meshGroupAddData;

/// Sets the queue for processing the cached data.
///
/// @param queue The queue.
- (void)setCacheHandlerQueue:(dispatch_queue_t)queue;


/// Clears the cached data.
/// The asynchronous queue.
- (void)reset;

#pragma mark - device

/// Returns the device by device ID to synchronize device information.
/// The synchronous queue.
///
/// @param devId The device ID.
- (TuyaSmartDeviceModel *)getDeviceInfoWithDevId:(NSString *)devId;


/// Adds a device to the cache.
///
/// After you add the device to the cache, subscribe to the topic of the device's MQTT messages. Make sure that the local key and protocol version are both configured.
/// After the device is added, you can accept callbacks by implementing `deviceDidAdd:` of `TYCoreCacheServiceDelegate`.
/// The tasks to add devices, subscribe to messages, and execute callbacks are run in the asynchronous thread.
/// The asynchronous queue.
///
/// @param deviceModel The model of the device to be added.
- (void)addDeviceModel:(TuyaSmartDeviceModel *)deviceModel;


/// Adds a device to the cache.
///
/// After you add the device to the cache, subscribe to the topic of the device's MQTT messages. Make sure that the local key and protocol version are both configured.
/// During the process, you can set the completion block or implement the `deviceDidAdd:` of the proxy `TYCoreCacheServiceDelegate` to handle the result of the event.
/// The completion block is called and followed by the delegate.
/// The tasks to add devices, subscribe to messages, block, and execute callbacks are run in the asynchronous thread.
/// The asynchronous queue.
///
/// @param deviceModel The device model to be added.
/// @param completion The callback after the completion of the join block.
- (void)addDeviceModel:(TuyaSmartDeviceModel *)deviceModel completion:(nullable void (^)(TuyaSmartDeviceModel *device))completion;


/// Adds multiple devices to the cache in an operation.
///
/// After you add the device to the cache, subscribe to the topic of each device's MQTT messages. Make sure that the local key and protocol version are both configured.
/// After the device is added, you can accept callbacks by implementing `deviceListDidAdd:` of `TYCoreCacheServiceDelegate`.
/// The tasks to add devices, subscribe to messages, and execute callbacks are run in the asynchronous thread.
/// The asynchronous queue.
///
/// @param deviceModelList The group of devices to be added
- (void)addDeviceModelList:(NSArray<TuyaSmartDeviceModel *> *)deviceModelList;


/// Adds multiple devices to the cache in an operation.
///
/// After you add the device to the cache, subscribe to the topic of each device's MQTT messages. Make sure that the local key and protocol version are both configured.
/// During the process, you can set the completion block or implement the `deviceListDidAdd:` of the proxy `TYCoreCacheServiceDelegate` to handle the result of the event.
/// The completion block is called and followed by the delegate.
/// The tasks to add devices, subscribe to messages, and execute callbacks are run in the asynchronous thread.
/// The asynchronous queue.
///
/// @param deviceModelList The group of devices to be added.
/// @param completion The callback after the completion of the join block.
- (void)addDeviceModelList:(NSArray<TuyaSmartDeviceModel *> *)deviceModelList completion:(nullable void (^)(NSArray<TuyaSmartDeviceModel *> *deviceList))completion;


/// Deletes the cached data of the device by device ID.
///
/// If the data is already deleted, the deletion task is not run to avoid duplicate operations.
/// After the deletion, the subscription to the MQTT topic of the device is canceled.
/// During the deletion process, you can handle the result of the event by implementing `deviceDidRemove:` of `TYCoreCacheServiceDelegate`.
/// The tasks to delete devices, unsubscribe from messages, and execute callbacks are run in the asynchronous thread.
/// The asynchronous queue.
///
/// @param devId The ID of the device to be removed.
- (void)removeDeviceWithDevId:(NSString *)devId;


/// Delete the cached data of the device by device ID.
///
/// If the data is already deleted, the deletion task is not run to avoid duplicate operations.
/// After deletion, the subscription to the MQTT topic of the device is canceled.
/// During the deletion process, you can set the completion block or implement `deviceDidRemove:` as a proxy for `TYCoreCacheServiceDelegate` to handle the result of the event.
/// The completion block is called and followed by the delegate.
/// The tasks to add devices, subscribe to messages, block, and execute callbacks are run in the asynchronous thread.
/// The asynchronous queue.
///
/// @param devId The device ID to be deleted.
/// @param completion The callback block after the completion of the deletion.
- (void)removeDeviceWithDevId:(NSString *)devId completion:(nullable void (^)(NSString *devId))completion;


/// Returns all devices in the cache.
/// The synchronous queue.
- (NSArray <TuyaSmartDeviceModel *> *)getAllDeviceList;

#pragma mark - device ota

/// Updates the over-the-air (OTA) information.
/// @param otaList A list of device OTA information.
- (void)updateDeviceOtaInfoWithList:(NSArray<TuyaSmartDeviceOTAModel *> *)otaList;

/// Returns a device OTA information.
/// @param devId The device ID.
- (TuyaSmartDeviceOTAModel *)getDeviceOtaInfoWithDevId:(NSString *)devId;

- (void)updateDeviceOtaMode:(TuyaSmartDeviceOTAModel *)otaModel;

#pragma mark - group


/// Returns the group cache information by group ID.
/// The synchronous queue.
///
/// @param groupId The group ID.
- (TuyaSmartGroupModel *)getGroupInfoWithGroupId:(long long)groupId;


/// Adds a group to the cache.
///
/// After you add the group to the cache, subscribe to the topic of the group's MQTT messages. Make sure that the local key and protocol version are both configured.
/// After the group is added, you can accept callbacks by implementing `groupDidAdd:` of `TYCoreCacheServiceDelegate`.
/// The tasks to add groups, subscribe to messages, and execute callbacks are run in the asynchronous threads.
/// The asynchronous queue.
///
/// @param groupModel The group model to be added.
- (void)addGroupModel:(TuyaSmartGroupModel *)groupModel;


//// Adds a group to the cache.
///
/// After you add the group to the cache, subscribe to the topic of the group's MQTT messages. Make sure that the local key and protocol version are both configured.
/// During the process, you can set the completion block or implement the proxy `groupDidAdd:` of `TYCoreCacheServiceDelegate` to handle the result of the event.
/// The completion block is called and followed by the delegate.
/// The tasks to add devices, subscribe to messages, and execute callbacks are run in the asynchronous thread.
/// The asynchronous queue.
///
/// @param groupModel The group model to be joined.
/// @param completion Callback after the completion of the join block.
- (void)addGroupModel:(TuyaSmartGroupModel *)groupModel completion:(nullable void (^)(TuyaSmartGroupModel *group))completion;


//// Deletes the cached data of a group by group ID.
///
/// If the group is already deleted, the deletion task is not run to avoid duplicate operations.
/// After deletion, the subscription to the MQTT topic of the device is canceled.
/// During the deletion process, you can handle the result of the event by implementing `groupDidRemove:` of `TYCoreCacheServiceDelegate`.
/// The tasks to delete groups, unsubscribe from messages, and execute callbacks are run in the asynchronous thread.
/// The asynchronous queue.
///
/// @param groupId The device ID to be removed.
- (void)removeGroupWithGroupId:(long long)groupId;

/// Returns all groups in the cache.
/// The synchronous queue.
- (NSArray <TuyaSmartGroupModel *> *)getAllGroupList;


#pragma mark - group product

/// Returns the group product information by product ID.
/// The synchronous queue.
///
/// @param productId The product ID.
- (NSDictionary *)getGroupProductWithProductId:(NSString *)productId;


/// Returns a list of devices in a group.
/// The synchronous queue.
///
/// @param groupId The group ID.
- (NSArray <TuyaSmartDeviceModel *> *)getDeviceListWithGroupId:(long long)groupId;


/// Updates information about multiple products in an operation.
/// The asynchronous queue.
///
/// @param groupProductList A list of product information in the JSON format.
- (void)updateGroupProductList:(NSArray <NSDictionary *> *)groupProductList;


#pragma mark - [group - device] relation

/// The batch update group allows you to update device information relationships.
/// The asynchronous queue.
///
/// @param deviceList The device list.
/// @param groupId The group ID.
- (void)updateDeviceGroupRelationWithDeviceList:(NSArray *)deviceList groupId:(long long)groupId;


/// The batch update group allows you to update device information relationships.
/// The asynchronous queue.
///
/// @param deviceList The device list.
/// @param groupId The group ID.
/// @param shouldNotify Specifies whether to send notifications. If the value is set to `yes`, `kNotificationGroupUpdate` is sent.
- (void)updateDeviceGroupRelationWithDeviceList:(NSArray *)deviceList groupId:(long long)groupId shouldNotify:(BOOL)shouldNotify;


#pragma mark - shared device and group

/// Returns a list of shared devices.
/// The synchronous queue.
- (NSArray <TuyaSmartDeviceModel *> *)getSharedDeviceList;


/// Returns a list of shared groups.
/// The synchronous queue.
- (NSArray <TuyaSmartGroupModel *> *)getSharedGroupList;


/// Updates the device sharing list.
/// The asynchronous queue.
///
/// @param deviceList The device sharing list.
- (void)updateSharedDeviceList:(NSArray <TuyaSmartDeviceModel *> *)deviceList;


/// Updates the group sharing list.
/// The asynchronous queue.
///
/// @param groupList The group sharing list.
- (void)updateSharedGroupList:(NSArray <TuyaSmartGroupModel *> *)groupList;

/// This is a type of device that supports special sharing, such as sharing the home and sharing the device at the same time.
- (NSArray <NSString *> *)getSpecialSharedDevIds;

- (NSArray <TuyaSmartDeviceModel *> *)getDeviceListWithHomeId:(long long)homeId;

#pragma mark - mesh

/// Returns the mesh information.
/// The synchronous queue.
///
/// @param meshId The mesh ID.
- (TuyaSmartBleMeshModel *)getMeshModelWithMeshId:(NSString *)meshId;

/// Updates mesh information.
/// The synchronous queue.
///
/// @param meshModel The mesh information.
- (void)updateMeshModel:(TuyaSmartBleMeshModel *)meshModel;

- (NSArray<TuyaSmartBleMeshModel *> *)getAllMeshList;
- (NSInteger)getMeshGroupAddressFromLocalWithMeshId:(NSString *)meshId;
- (NSInteger)getMeshGroupCountFromLocalWithMeshId:(NSString *)meshId;
- (void)removeMeshGroupWithAddress:(NSInteger)address meshId:(NSString *)meshId;

@end

NS_ASSUME_NONNULL_END
