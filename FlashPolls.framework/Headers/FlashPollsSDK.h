//
//  FlashPollsSDK.h
//  FlashPollsSDK
//
//  Copyright © 2016 Life Before Us, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FlashPollsSDK : NSObject

/**
 *  @abstract This method must be called when the app is launched.
 *
 *  @discussion During execution of - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 *              please call this method along with the app token for your app, which can be obtained at http://publisher.flashpolls.com/dashboard/
 *
 *  Example:
 *
 *  `[FlashPollsSDK initWithAppToken:@"3cc4ab03-86c4-4b13-853b-bea0ceba566a" launchOptions:launchOptions];`
 *
 */
+ (void)initWithAppToken:(NSString *)appToken launchOptions:(NSDictionary *)launchOptions;

/**
 *  @abstract An optional initializer that allows to disable method swizzling.
 *
 *  @discussion When disabling swizzling, the following methods should be called manually:
 *              1. `[FlashPollsSDK setDeviceToken:deviceToken];`
 *              2. `[FlashPollsSDK handleRemoteNotification:userInfo];`
 *              3. `[FlashPollsSDK handleActionWithIdentifier:identifier userInfo:userInfo];`
 *
 *  Example:
 *
 *  `[FlashPollsSDK initWithAppToken:@"3cc4ab03-86c4-4b13-853b-bea0ceba566a" launchOptions:launchOptions swizzling:NO];`
 *
 */
+ (void)initWithAppToken:(NSString *)appToken launchOptions:(NSDictionary *)launchOptions swizzling:(BOOL)swizzling;

/**
 *  @abstract Displays native iOS dialog for push notifications permission, only if was not presented before.
 *
 *  @discussion It is recommended to present the push permission dialog at a relevant time rather than right
 *              away when the user opens the app.
 *
 *  Example:
 *
 *  `[FlashPollsSDK askUserForPushPermissions];`
 *
 */
+ (void)askUserForPushPermissions;

/**
 *  @abstract Set current user information.
 *
 *  @discussion Allows to attach user information that will be linked to each vote.
 *              The information about the user is from your app and can be anything.
 *
 *  Example:
 *
 *  `[FlashPollsSDK setUserInfo:@{@"first_name": self.user.firstName}];`
 *
 */
+ (void)setUserInfo:(NSDictionary *)userInfo;

/**
 *  @abstract Set device (push) token manually, in case swizzling is disabled.
 *
 *  @discussion This method is called automatically by default, when swizzling is enabled.
 *
 *  Example:
 *
 *  `[FlashPollsSDK setDeviceToken:deviceToken];`
 *
 */
+ (void)setDeviceToken:(NSData *)deviceToken;

/**
 *  @abstract If push is a poll present it, this method is called automatically by default.
 *
 *  @discussion This method checks if the push came from Flash Polls and only handles if it did.
 *              If push is a poll, it is presented to the user.
 *
 *  Example:
 *
 *  - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
 *        [FlashPollsSDK handleRemoteNotification:userInfo];
 *  }
 *
 */
+ (void)handleRemoteNotification:(NSDictionary *)userInfo;

/**
 *  @abstract Handle user pressing a push notification action button, this method is called automatically by default.
 *
 *  Example:
 *
 *  - (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void (^)())completionHandler
 *        [FlashPollsSDK handleActionWithIdentifier:identifier userInfo:userInfo];
 *        completionHandler();
 *  }
 *
 */
+ (void)handleActionWithIdentifier:(NSString *)identifier userInfo:(NSDictionary *)userInfo;

/**
 *  @abstract Toggles log messages. Default: YES
 */
+ (void)setDebug:(BOOL)flag;

@end
