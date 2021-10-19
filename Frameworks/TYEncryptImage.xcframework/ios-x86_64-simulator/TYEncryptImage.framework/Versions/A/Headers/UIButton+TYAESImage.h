//
//  UIButton+TYAESImage.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2021/1/5.
//

#import "TYEncryptWebImageCompat.h"

#if TY_EI_UIKIT
 
#import "TYEncryptImageDefine.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Web image methods for UIButton.
 */
@interface UIButton (TYAESImage)

#pragma mark - image

/**
 Current image URL for the specified state.
 @return The image URL, or nil.
 */
- (nullable NSURL *)ty_imageURLForState:(UIControlState)state;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 */
- (void)ty_setImageWithURL:(nullable NSURL *)imageURL
                  forState:(UIControlState)state
               placeholder:(nullable UIImage *)placeholder;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL The image url (remote or local file path).
 @param state    The state that uses the specified image.
 */
- (void)ty_setImageWithURL:(nullable NSURL *)imageURL
                  forState:(UIControlState)state;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)ty_setImageWithURL:(nullable NSURL *)imageURL
                  forState:(UIControlState)state
               placeholder:(nullable UIImage *)placeholder
                completion:(nullable TYEncryptWebImageCompletionBlock)completion;

/**
 Set the button's image with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)ty_setImageWithURL:(nullable NSURL *)imageURL
                  forState:(UIControlState)state
               placeholder:(nullable UIImage *)placeholder
                  progress:(nullable TYEncryptWebImageProgressBlock)progress
                completion:(nullable TYEncryptWebImageCompletionBlock)completion;

/**
 Cancel the current image request for a specified state.
 @param state The state that uses the specified image.
 */
- (void)ty_cancelImageRequestForState:(UIControlState)state;

#pragma mark - encrypt image

/**
 Set the button's image with a specified URL and encrypt key for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param encryptKey  The encrypt key of the specified encrypted image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)ty_setAESImageWithURL:(nullable NSURL *)imageURL
                     forState:(UIControlState)state
                   encryptKey:(nullable NSString *)encryptKey
                  placeholder:(nullable UIImage *)placeholder
                     progress:(nullable TYEncryptWebImageProgressBlock)progress
                   completion:(nullable TYEncryptWebImageCompletionBlock)completion;

#pragma mark - background image

/**
 Current backgroundImage URL for the specified state.
 @return The image URL, or nil.
 */
- (nullable NSURL *)ty_backgroundImageURLForState:(UIControlState)state;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 */
- (void)ty_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                            forState:(UIControlState)state
                         placeholder:(nullable UIImage *)placeholder;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL The image url (remote or local file path).
 @param state    The state that uses the specified image.
 */
- (void)ty_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                            forState:(UIControlState)state;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)ty_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                            forState:(UIControlState)state
                         placeholder:(nullable UIImage *)placeholder
                          completion:(nullable TYEncryptWebImageCompletionBlock)completion;

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)ty_setBackgroundImageWithURL:(nullable NSURL *)imageURL
                            forState:(UIControlState)state
                         placeholder:(nullable UIImage *)placeholder
                            progress:(nullable TYEncryptWebImageProgressBlock)progress
                          completion:(nullable TYEncryptWebImageCompletionBlock)completion;

/**
 Cancel the current backgroundImage request for a specified state.
 @param state The state that uses the specified image.
 */
- (void)ty_cancelBackgroundImageRequestForState:(UIControlState)state;

#pragma mark - encrypt background image

/**
 Set the button's backgroundImage with a specified URL for the specified state.
 
 @param imageURL    The image url (remote or local file path).
 @param state       The state that uses the specified image.
 @param encryptKey  The encrypt key of the specified encrypted image.
 @param placeholder The image to be set initially, until the image request finishes.
 @param progress    The block invoked (on main thread) during image request.
 @param completion  The block invoked (on main thread) when image request completed.
 */
- (void)ty_setAESBackgroundImageWithURL:(nullable NSURL *)imageURL
                               forState:(UIControlState)state
                             encryptKey:(nullable NSString *)encryptKey
                            placeholder:(nullable UIImage *)placeholder
                               progress:(nullable TYEncryptWebImageProgressBlock)progress
                             completion:(nullable TYEncryptWebImageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END

#endif
