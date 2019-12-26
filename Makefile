ARCHS = arm64 arm64e
FINALPACKAGE = 1

THEOS_DEVICE_IP = 10.0.0.151

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = CustomSounds13
$(TWEAK_NAME)_FILES = $(wildcard *.xm *.m)
$(TWEAK_NAME)_FRAMEWORKS = UIKit CoreGraphics AVFoundation AudioToolbox
$(TWEAK_NAME)_LDFLAGS += -lCSPreferencesProvider
$(TWEAK_NAME)_CFLAGS = -Wno-error -Wno-return-type -Wno-objc-method-access -Wno-objc-property-no-attribute -Wno-deprecated -Wno-deprecated-declarations -Wno-incomplete-umbrella

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"
SUBPROJECTS += customsounds13
include $(THEOS_MAKE_PATH)/aggregate.mk
