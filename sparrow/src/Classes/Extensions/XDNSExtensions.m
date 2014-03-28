#import <Sparrow/XDNSExtensions.h>
#import <UIKit/UIKit.h>

//XIDA
#define SCALE_FOR_RETINA @"XIDA_ScaleImagesUpForRetina"

static BOOL _retinaDisplayChecked;
static float _scaleFactor;

@implementation XDNSExtensions

//XIDA Override
//we dont want the scalefactor based on the filename
//instead we want it based if the ipad has a retina display or not

+ (float)contentScaleFactorWithString:(NSString *)string {
    if(!_retinaDisplayChecked) {
        _retinaDisplayChecked = true;
        if ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] &&
            ([UIScreen mainScreen].scale == 2.0)) {
            NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
            if([[infoDict objectForKey:SCALE_FOR_RETINA] boolValue]) {
                _scaleFactor = 1.0f;
            } else {
                _scaleFactor = 2.0f;
            }
        } else {
            _scaleFactor = 1.0f;
        }
    }
    return _scaleFactor;
}

@end
