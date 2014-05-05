//
//  SPDisplayObjectExport.h
//  Sparrow
//
//  Created by Shilo White on 5/5/14.
//
//

#import <Foundation/Foundation.h>
#import <JavascriptCore/JavascriptCore.h>
#import <Sparrow/SPEventDispatcherExport.h>
@class SPRenderSupport;
@class SPDisplayObject;
@class SPMatrix;
@class SPRectangle;
@class SPPoint;
@class SPDisplayObjectContainer;
@class SPStage;
@class SPFragmentFilter;

@protocol SPDisplayObjectExport <SPEventDispatcherExport, JSExport>

/// -------------
/// @name Methods
/// -------------

/// Renders the display object with the help of a support object.
- (void)render:(SPRenderSupport *)support;

/// Removes the object from its parent, if it has one.
- (void)removeFromParent;

/// Moves the pivot point to the center of the object.
- (void)alignPivotToCenter;

/// Moves the pivot point to a certain position within the local coordinate system of the object.
- (void)alignPivotX:(SPHAlign)hAlign pivotY:(SPVAlign)vAlign;

/// Creates a matrix that represents the transformation from the local coordinate system to another.
- (SPMatrix *)transformationMatrixToSpace:(SPDisplayObject *)targetSpace;

/// Returns a rectangle that completely encloses the object as it appears in another coordinate system.
- (SPRectangle *)boundsInSpace:(SPDisplayObject *)targetSpace;

/// Transforms a point from the local coordinate system to global (stage) coordinates.
- (SPPoint *)localToGlobal:(SPPoint *)localPoint;

/// Transforms a point from global (stage) coordinates to the local coordinate system.
- (SPPoint *)globalToLocal:(SPPoint *)globalPoint;

/// Returns the object that is found topmost on a point in local coordinates, or nil if the test fails.
- (SPDisplayObject *)hitTestPoint:(SPPoint *)localPoint;

/// Dispatches an event on all children (recursively). The event must not bubble. */
- (void)broadcastEvent:(SPEvent *)event;

/// Creates an event and dispatches it on all children (recursively). */
- (void)broadcastEventWithType:(NSString *)type;

/// ----------------
/// @name Properties
/// ----------------

/// The x coordinate of the object relative to the local coordinates of the parent.
@property (nonatomic, assign) float x;

/// The y coordinate of the object relative to the local coordinates of the parent.
@property (nonatomic, assign) float y;

/// The x coordinate of the object's origin in its own coordinate space (default: 0).
@property (nonatomic, assign) float pivotX;

/// The y coordinate of the object's origin in its own coordinate space (default: 0).
@property (nonatomic, assign) float pivotY;

/// The horizontal scale factor. "1" means no scale, negative values flip the object.
@property (nonatomic, assign) float scaleX;

/// The vertical scale factor. "1" means no scale, negative values flip the object.
@property (nonatomic, assign) float scaleY;

/// The horizontal skew angle in radians.
@property (nonatomic, assign) float skewX;

/// The vertical skew angle in radians.
@property (nonatomic, assign) float skewY;

/// The width of the object in points.
@property (nonatomic, assign) float width;

/// The height of the object in points.
@property (nonatomic, assign) float height;

/// The rotation of the object in radians. (In Sparrow, all angles are measured in radians.)
@property (nonatomic, assign) float rotation;

/// The opacity of the object. 0 = transparent, 1 = opaque.
@property (nonatomic, assign) float alpha;

/// The visibility of the object. An invisible object will be untouchable.
@property (nonatomic, assign) BOOL visible;

/// Indicates if this object (and its children) will receive touch events.
@property (nonatomic, assign) BOOL touchable;

/// The bounds of the object relative to the local coordinates of the parent.
@property (weak, nonatomic, readonly) SPRectangle *bounds;

/// The display object container that contains this display object.
@property (weak, nonatomic, readonly) SPDisplayObjectContainer *parent;

/// The root object the display object is connected to (i.e. an instance of the class
/// that was passed to `[SPViewController startWithRoot:]`), or nil if the object is not connected
/// to it.
@property (weak, nonatomic, readonly) SPDisplayObject *root;

/// The stage the display object is connected to, or nil if it is not connected to a stage.
@property (weak, nonatomic, readonly) SPStage *stage;

/// The topmost object in the display tree the object is part of.
@property (weak, nonatomic, readonly) SPDisplayObject *base;

/// The transformation matrix of the object relative to its parent.
/// @returns CAUTION: not a copy, but the actual object!
@property (nonatomic, copy) SPMatrix *transformationMatrix;

/// The name of the display object (default: nil). Used by `childByName:` of display object containers.
@property (nonatomic, copy) NSString *name;

/// The filter that is attached to the display object. Beware that you should NOT use the same
/// filter on more than one object (for performance reasons).
@property (nonatomic, strong) SPFragmentFilter *filter;

/// The blend mode determines how the object is blended with the objects underneath. Default: AUTO
@property (nonatomic, assign) uint blendMode;

/// Indicates if an object occupies any visible area. (Which is the case when its `alpha`,
/// `scaleX` and `scaleY` values are not zero, and its `visible` property is enabled.)
@property (nonatomic, readonly) BOOL hasVisibleArea;

/// The physics body associated with the display object. Sparrow does not provide physics on its
/// own, but this property may be used by any physics library to link an object to its physical
/// body.
@property (nonatomic, strong) id physicsBody;

@end
