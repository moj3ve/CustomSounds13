#import <AudioToolbox/AudioServices.h>

#define prefs [CSProvider sharedProvider]

static bool kEnabled;
static bool kCustomCharge;
static bool kCustomKeyboard;
static bool kCustomLock;
static bool kCustomPasscode;

int soundCount = 1;

NSString *kChargeSound;
NSString *kKeyboardSound;
NSString *kLockSound;
NSString *kPasscodeSound;
NSString *deleteKey = [[NSBundle bundleWithPath:@"/System/Library/Audio/UISounds/"] pathForResource:@"key_press_delete" ofType:@"caf"];

SystemSoundID chargeSound;
SystemSoundID keyboardSound;
SystemSoundID lockSound;
SystemSoundID passcodeSound;

@interface SBUIController : NSObject
	+ (id)sharedInstance;
	- (BOOL)isOnAC;
	- (void)resetCount;
@end

@interface SBLockScreenViewControllerBase : UIViewController
	- (BOOL)isAuthenticated;
@end

@interface SBLockScreenManager : NSObject
	+ (SBLockScreenManager *)sharedInstance;
	- (SBLockScreenViewControllerBase *)lockScreenViewController;
	- (BOOL)isUILocked;
@end

@interface UIKBTree : NSObject
	@property (nonatomic, strong, readwrite) NSString * name;
	+ (id)sharedInstance;
	+ (id)key;
@end

@interface UIKeyboardLayoutStar : UIView
	@property (nonatomic, copy) NSString * localizedInputKey;
	- (void)setPlayKeyClickSoundOn:(int)arg1;
@end
