#import <Foundation/Foundation.h>

@interface XDNSExtensions : NSObject

//XIDA Override
//we dont want the scalefactor based on the filename
//instead we want it based if the ipad has a retina display or not
+ (float)contentScaleFactorWithString:(NSString *)string;

@end
