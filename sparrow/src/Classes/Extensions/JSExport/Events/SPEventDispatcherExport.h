//
//  SPEventDispatcherExport.h
//  Sparrow
//
//  Created by Shilo White on 5/5/14.
//
//

#import <Foundation/Foundation.h>
#import <JavascriptCore/JavascriptCore.h>
#import <Sparrow/NSObjectExport.h>

typedef void (^SPEventBlock)(id event);

@protocol SPEventDispatcherExport <NSObjectExport, JSExport>

/// -------------
/// @name Methods
/// -------------

/// Registers an event listener which is implemented through a block.
- (void)addEventListenerForType:(NSString *)eventType block:(SPEventBlock)block;

/// Registers an event listener at a certain object.
- (void)addEventListener:(SEL)selector atObject:(id)object forType:(NSString *)eventType;

/// Removes an event listener from an object.
- (void)removeEventListener:(SEL)selector atObject:(id)object forType:(NSString *)eventType;

/// Removes all event listeners from an object that have a certain type.
- (void)removeEventListenersAtObject:(id)object forType:(NSString *)eventType;

/// Removes an event listener that was implemented through a block. Be careful in MRC mode:
/// you have to pass the same copy of the block to both 'addEventListener...' and
/// 'removeEventListener...'. If you pass a stack block to either or both, removing won't work.
- (void)removeEventListenerForType:(NSString *)eventType block:(SPEventBlock)block;

/// Dispatches an event to all objects that have registered for events of the same type.
- (void)dispatchEvent:(SPEvent *)event;

/// Creates a new (non-bubbling) event object and dispatches it.
- (void)dispatchEventWithType:(NSString *)type;

/// Creates a new event object and dispatches it.
- (void)dispatchEventWithType:(NSString *)type bubbles:(BOOL)bubbles;

/// Returns if there are listeners registered for a certain event type.
- (BOOL)hasEventListenerForType:(NSString *)eventType;

@end
