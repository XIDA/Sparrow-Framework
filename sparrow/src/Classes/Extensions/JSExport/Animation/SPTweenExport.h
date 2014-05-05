//
//  SPTweenExport.h
//  Sparrow
//
//  Created by Shilo White on 5/5/14.
//
//

#import <Foundation/Foundation.h>
#import <JavascriptCore/JavascriptCore.h>
#import <Sparrow/SPEventDispatcherExport.h>

@protocol SPTweenExport <SPEventDispatcherExport, JSExport>

/// --------------------
/// @name Initialization
/// --------------------

/// Initializes a tween with a target, duration (in seconds) and a transition function.
/// _Designated Initializer_.
- (instancetype)initWithTarget:(id)target time:(double)time transition:(NSString *)transition;

/// Initializes a tween with a target, a time (in seconds) and a linear transition
/// (`SPTransitionLinear`).
- (instancetype)initWithTarget:(id)target time:(double)time;

/// Factory method.
+ (instancetype)tweenWithTarget:(id)target time:(double)time transition:(NSString *)transition;

/// Factory method.
+ (instancetype)tweenWithTarget:(id)target time:(double)time;

/// -------------
/// @name Methods
/// -------------

/// Animates the property of an object to a target value. You can call this method multiple times
/// on one tween.
- (void)animateProperty:(NSString *)property targetValue:(float)value;

/// Animates the `x` and `y` properties of an object simultaneously.
- (void)moveToX:(float)x y:(float)y;

/// Animates the `scaleX` and `scaleY` properties of an object simultaneously.
- (void)scaleTo:(float)scale;

/// Animates the `alpha` property.
- (void)fadeTo:(float)alpha;

/// ----------------
/// @name Properties
/// ----------------

/// The target object that is animated.
@property (nonatomic, readonly) id target;

/// The transition method used for the animation.
@property (weak, nonatomic, readonly) NSString *transition;

/// The total time the tween will take (in seconds).
@property (nonatomic, readonly) double totalTime;

/// The time that has passed since the tween was started (in seconds).
@property (nonatomic, readonly) double currentTime;

/// Indicates if the total time has passed and the tweened properties have finished.
@property (nonatomic, readonly) BOOL isComplete;

/// The delay before the tween is started.
@property (nonatomic, assign) double delay;

/// The number of times the tween will be executed. Set to 0 to tween indefinitely. (Default: 1)
@property (nonatomic, assign) int repeatCount;

/// The number seconds to wait between repeat cycles. (Default: 0)
@property (nonatomic, assign) double repeatDelay;

/// Indicates if the tween should be reversed when it is repeating. If enabled,
/// every second repetition will be reversed. (Default: `NO`)
@property (nonatomic, assign) BOOL reverse;

/// A block that will be called when the tween starts (after a possible delay).
@property (nonatomic, copy) SPCallbackBlock onStart;

/// A block that will be called each time the tween is advanced.
@property (nonatomic, copy) SPCallbackBlock onUpdate;

/// A block that will be called each time the tween finishes one repetition
/// (except the last, which will trigger 'onComplete').
@property (nonatomic, copy) SPCallbackBlock onRepeat;

/// A block that will be called when the tween is complete.
@property (nonatomic, copy) SPCallbackBlock onComplete;

@end
