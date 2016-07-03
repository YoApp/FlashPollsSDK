//
//  FlashPollsSDK.h
//  FlashPollsSDK
//
//  Copyright © 2016 Life Before Us, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FlashPollsSDK : NSObject

/**
 *  @abstract This method needs to be called when the app is launched.
 *
 *  @discussion During execution of - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 *              please call this method along with the app token for your app, which can be obtained at http://publisher.flashpolls.com/dashboard/
 *
 *  Example:
 *
 *  `[FlashPollsSDK initWithAppToken:@"nadsi673yqwiuebn8732" launchOptions:launchOptions];`
 *
 */
+ (void)initWithAppToken:(NSString *)appToken launchOptions:(NSDictionary *)launchOptions;

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

+ (NSBundle *)frameworkBundle;

@end
