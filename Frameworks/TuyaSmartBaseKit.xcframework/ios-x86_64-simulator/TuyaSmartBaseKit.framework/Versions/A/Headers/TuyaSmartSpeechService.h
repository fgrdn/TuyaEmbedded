//
// TuyaSpeechService.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartSpeechService_h
#define TuyaSmartSpeechService_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief TuyaSmartSpeechService is used for voice control.
///
/// There's two main functions:
///     1. Audio to text. Convert voice data into text strings.
///     2. Execute text command. Device related commands can be done through this API.
///
@interface TuyaSmartSpeechService : NSObject


/// Converts from audio to text.
/// @param audioData The audio data.
/// @param audioRate The audio rate.
/// @param audioType The audio type.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)convertToTextWithAudioData:(NSData *)audioData
                         audioRate:(NSString *)audioRate
                         audioType:(NSString *)audioType
                            homeId:(long long)homeId
                           success:(nullable TYSuccessString)success
                           failure:(nullable TYFailureError)failure;


/// Runs audio commands.
/// @param speechText The voice text.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)executeCommandWithSpeechText:(NSString *)speechText
                              homeId:(long long)homeId
                             success:(nullable TYSuccessDict)success
                             failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartSpeechService_h */
