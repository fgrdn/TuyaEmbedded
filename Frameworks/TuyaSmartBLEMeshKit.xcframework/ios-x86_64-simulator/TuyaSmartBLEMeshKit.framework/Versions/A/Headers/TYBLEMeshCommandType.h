//
// TYBLEMeshCommandType.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TYBLEMeshCommandType_h
#define TYBLEMeshCommandType_h

/// The type of Bluetooth mesh command.
typedef NS_ENUM(NSUInteger, TYBLEMeshCommandType) {
    
    /// Modifies the device address.
    TYBLEMeshSetDeviceAddressCommand = 0xAA,
    
    /// The group operations. For example, a group can be added or deleted, and devices can be added to a group.
    TYBLEMeshGroupHandlingCommand,
    
    /// Returns the address of the device group.
    TYBLEMeshFetchGroupAddressCommand,
    
    /// Kicks the device out of the network.
    TYBLEMeshKickedOutCommand,
    
    /// Returns the IDs of all devices in the group.
    TYBLEMeshFetchAllDeviceIdFromGroupCommand,
    
    /// Requests the authorization key.
    TYBLEMeshRequestAuthKeyCommand,
    
    /// Sends the switch command.
    TYBLEMeshTurnOnAndOffCommand,
    
    /// Returns the status of all devices in a mesh network.
    TYBLEMeshFetchAllStateCommand,
    
    /// Sets the brightness value.
    TYBLEMeshSetBrightnessValueCommand,
    
    /// Sets the RGBWCL value.
    TYBLEMeshSetRGBWCLCommand,
    
    /// Sets the light mode, such as the colored light and cool and warm white light.
    TYBLEMeshSetLightModelCommand,
    
    /// Controls the sub power strip.
    TYBLEMeshControlSubSwitchCommand,
    
    /// Sets the countdown.
    TYBLEMeshSetCountDownCommand,
    
    /// Reads the countdown.
    TYBLEMeshFetchCountDownCommand,
    
    /// Reads the sensor value.
    TYBLEMeshFetchSensorValueCommand,
    
    /// Sends the DPs.
    TYBLEMeshSendDPSCommand,
    
    /// Returns one or two state values.
    TYBLEMeshFetchStateCommand,
    
    /// Modifies the mode of the current mesh light scene.
    TYBLEMeshSetLightSceneModelCommand,
    
    /// Returns the mode of the current mesh light scene.
    TYBLEMeshGetLightSceneModelCommand,
    
    /// Synchronizes time.
    TYBLEMeshTimeSynchronizationCommand,
    
    /// Sets the timing data.
    TYBLEMeshSetTimerCommand,
    
    /// Reads the timing data.
    TYBLEMeshGetTimerCommand,
    
};

#endif /* TYBLEMeshCommandType_h */
