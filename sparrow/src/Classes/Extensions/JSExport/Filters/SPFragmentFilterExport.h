//
//  SPFragmentFilterExport.h
//  Sparrow
//
//  Created by Shilo White on 5/5/14.
//
//

#import <Foundation/Foundation.h>
#import <JavascriptCore/JavascriptCore.h>
#import <Sparrow/NSObjectExport.h>
@class SPTexture;

// Filter Mode
typedef NS_ENUM(uint, SPFragmentFilterMode)
{
    SPFragmentFilterModeBelow,
    SPFragmentFilterModeReplace,
    SPFragmentFilterModeAbove
};

@protocol SPFragmentFilterExport <NSObjectExport, JSExport>

/// --------------------
/// @name Initialization
/// --------------------

/// Initializes a fragment filter with the specified number of passes and resolution.
/// This initializer must only be called by the initializer of a subclass.
/// _Designated Initializer_.
- (instancetype)initWithNumPasses:(int)numPasses resolution:(float)resolution;

/// Initializes a fragment filter with the specified number of passes and a resolution of 1.0f.
/// This initializer must only be called by the initializer of a subclass.
//- (instancetype)initWithNumPasses:(int)numPasses;

/// Initializes a fragment filter with 1 pass and a resolution of 1.0f.
/// This initializer must only be called by the initializer of a subclass.
//- (instancetype)init;

/// -------------
/// @name Methods
/// -------------

/// Caches the filter output into a SPTexture. An uncached filter is rendered in every frame; a
/// cached filter only once. However, if the filtered object or the filter settings change, it has
/// to be updated manually; to do that, call "cache" again.
- (void)cache;

/// Clears the cached output of the filter. After calling this method, the filter will be executed
/// once per frame again.
- (void)clearCache;

/// Applies the filter on a certain display object, rendering the output into the current render
/// target. This method is called automatically by Sparrow's rendering system for the object the
/// filter is attached to.
- (void)renderObject:(SPDisplayObject *)object support:(SPRenderSupport *)support;

/// ----------------
/// @name Properties
/// ----------------

/// Indicates if the filter is cached (via the "cache" method).
@property (nonatomic, assign) BOOL cached;

/// The resolution of the filter texture. "1" means stage resolution, "0.5" half the stage
/// resolution. A lower resolution saves memory and execution time(depending on the GPU), but
/// results in a lower output quality. Values greater than 1 are allowed; such values might make
/// sense for a cached filter when it is scaled up. @default 1
@property (nonatomic, assign) float resolution;

/// The filter mode, which is one of the constants defined in the 'SPFragmentFilterMode' enum.
/// (default: SPFragmentFilterModeReplace)
@property (nonatomic, assign) SPFragmentFilterMode mode;

/// Use the x-offset to move the filter output to the right or left.
@property (nonatomic, assign) float offsetX;

/// Use the y-offset to move the filter output to the top or bottom.
@property (nonatomic, assign) float offsetY;

@end
