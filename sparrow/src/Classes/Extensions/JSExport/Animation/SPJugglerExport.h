//
//  SPJugglerExport.h
//  Sparrow
//
//  Created by Shilo White on 5/5/14.
//
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <Sparrow/NSObjectExport.h>

@protocol SPJugglerExport <NSObjectExport, JSExport>

/// --------------------
/// @name Initialization
/// --------------------

/// Factory method.
+ (instancetype)juggler;

/// -------------
/// @name Methods
/// -------------

/// Adds an object to the juggler.
- (void)addObject:(id<SPAnimatable>)object;

/// Removes an object from the juggler.
- (void)removeObject:(id<SPAnimatable>)object;

/// Removes all objects at once.
- (void)removeAllObjects;

/// Removes all objects with a `target` property referencing a certain object (e.g. tweens or
/// delayed invocations).
- (void)removeObjectsWithTarget:(id)object;

/// Determines if an object has been added to the juggler.
- (BOOL)containsObject:(id<SPAnimatable>)object;

/// Delays the execution of a certain method. Returns a proxy object on which to call the method
/// instead. Execution will be delayed until `time` has passed.
- (id)delayInvocationAtTarget:(id)target byTime:(double)time;

/// Delays the execution of a block by a certain time in seconds.
- (id)delayInvocationByTime:(double)time block:(SPCallbackBlock)block;

/// ----------------
/// @name Properties
/// ----------------

/// The total life time of the juggler.
@property (nonatomic, readonly) double elapsedTime;

/// The speed factor adjusts how fast a juggler's animatables run.
/// For example, a speed factor of 2.0 means the juggler runs twice as fast.
@property (nonatomic, assign) float speed;

@end
