# FlashPollsSDK

![](http://cl.ly/0H180G2C142p/ios9-lockscreen.gif)
![](http://cl.ly/3V1R1H370z2F/ios10-lockscreen.gif)

## Usage

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Installation

FlashPollsSDK is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "FlashPollsSDK"
```

In your `AppDelegate`:

```
#import <FlashPolls/FlashPollsSDK.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [FlashPollsSDK initWithAppToken:@"<your_app_token>" launchOptions:launchOptions];
    return YES;
}
```

If your app has already asked the user for push notifications permission than your all done!
Otherwise enter this line when you are ready to ask the user use this line:
```
[FlashPollsSDK askUserForPushPermissions];
```
