//
//  AppDelegate.m
//  Demo
//
//  Created by mac on 7/1/16.
//  Copyright © 2016 Life Before Us. All rights reserved.
//

#import "AppDelegate.h"
#import <FlashPolls/FlashPollsSDK.h>

#define FLASH_POLLS_APP_TOKEN @"1234542234234"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [FlashPollsSDK initWithAppToken:FLASH_POLLS_APP_TOKEN launchOptions:launchOptions];
    [FlashPollsSDK askUserForPushPermissions];
    
    return YES;
}

@end
