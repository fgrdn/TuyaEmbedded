//
//  TuyaSmartDefaultPanelKit.h
//  TuyaSmartDefaultPanelKit
//
//  Created by tuya on 2021/1/18.
//

#ifndef TuyaSmartDefaultPanelViewController_h
#define TuyaSmartDefaultPanelViewController_h

#import <UIKit/UIKit.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief This class is the default device control panel, support all type of tuya devices, designed for production use.
///
/// This ViewController can be used for all type of tuya devices.
/// Before your own device control panel developed, you can use this ViewController to preview the device functions.
/// After your own device control panel developed, you can still use this ViewController as an `else` option.
///
/// Usually we choose the specific device control panel by the following code:
///
/// if ([deviceModel.productId isEqualToString:PID_A]) {
///     UIViewController *vc = [[MyViewControllerA alloc] initWithDeviceId:deviceModel.devId];
///     [self.navigationController pushViewController:vc animated:YES];
/// } else if ([deviceModel.productId isEqualToString:PID_B]) {
///     UIViewController *vc = [[MyViewControllerB alloc] initWithDeviceId:deviceModel.devId];
///     [self.navigationController pushViewController:vc animated:YES];
/// } else {
///     UIViewController *vc = [[TuyaSmartDefaultPanelViewController alloc] initWithDeviceId:deviceModel.devId];
///     [self.navigationController pushViewController:vc animated:YES];
/// }
///
@interface TuyaSmartDefaultPanelViewController : UIViewController

- (nullable instancetype)initWithDeviceId:(NSString *)devId;

/// debug mode. defaults to NO.
@property (nonatomic, assign) BOOL debugMode;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartDefaultPanelViewController_h */
