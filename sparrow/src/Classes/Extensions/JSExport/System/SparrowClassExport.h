//
//  SparrowClassExport.h
//  Sparrow
//
//  Created by Shilo White on 5/5/14.
//
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <Sparrow/NSObjectExport.h>

@protocol SparrowClassExport <NSObjectExport, JSExport>

/// The currently active SPViewController.
+ (SPViewController *)currentController;

/// The currently active OpenGL context.
+ (SPContext *)context;

/// A juggler that is advanced once per frame by the current view controller.
+ (SPJuggler *)juggler;

/// The stage that is managed by the current view controller.
+ (SPStage *)stage;

/// The root object of your game, i.e. an instance of the class you passed to the 'startWithRoot:'
/// method of SPViewController.
+ (SPDisplayObject *)root;

/// The content scale factor of the current view controller.
+ (float)contentScaleFactor;

@end
