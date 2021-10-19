//
// TYBLEMeshCommand.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TYBLEMeshCommandType.h"

/// The mesh command protocol that is used to confirm and implement certain commands.
@protocol TYBLEMeshCommandProtocol <NSObject>

/// Converts to the Bluetooth command.
/// @return The Bluetooth command.
- (NSData *)command;

/// Converts to the raw command that is used by a gateway.
/// @return The raw command.
- (NSString *)raw;

@end

/// @brief The Bluetooth mesh protocol for certain commands.
@interface TYBLEMeshCommand : NSObject <TYBLEMeshCommandProtocol>

/// The command type.
@property (nonatomic, assign) TYBLEMeshCommandType commandType;

/// In each product category code (PCC), a small category is followed by a major category. For example, the PCC of a cool white and colored light (RGBC) is `0401`. In this case, `04` represents a cool white and colored light (RGBC) and `01` represents the major category of lights.
@property (nonatomic, strong) NSString *pcc;

/// The address of a device or a group. Valid values of a device address: 1 to 255. Valid values of a group address: 0x8001 and 0x8008.
@property (nonatomic, assign) uint32_t address;

/// Specifies whether a group command is used.
@property (nonatomic, assign) BOOL isGroup;

/// For more information about the command data, see the documentation.
@property (nonatomic, strong) NSArray<NSString *> *dataParams;

/// The output of secondary log files.
@property (nonatomic, strong) NSString *logDescription;

@end
