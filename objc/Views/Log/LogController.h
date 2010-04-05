// Created by Satoshi Nakagawa.
// You can redistribute it and/or modify it under the Ruby's license or the GPL2.

#import <Cocoa/Cocoa.h>
#import "LogView.h"
#import "LogPolicy.h"
#import "LogScriptEventSink.h"
#import "LogLine.h"
#import "MarkedScroller.h"


@class IRCWorld;
@class IRCClient;
@class IRCChannel;


@interface LogController : NSObject
{
	LogView* view;
	LogPolicy* policy;
	LogScriptEventSink* sink;
	MarkedScroller* scroller;
	WebScriptObject* js;

	IRCWorld* world;
	IRCClient* client;
	IRCChannel* channel;
	NSMenu* menu;
	NSMenu* urlMenu;
	NSMenu* addrMenu;
	NSMenu* chanMenu;
	NSMenu* memberMenu;
	id keyword;
	id theme;
	id overrideFont;
	int maxLines;
	BOOL console;
	NSColor* initialBackgroundColor;
	
	BOOL bottom;
	NSMutableArray* lines;
	int lineNumber;
	int count;
	BOOL loaded;
	NSMutableArray* highlightedLineNumbers;
	int loadingImages;
	NSString* prevNickInfo;
	NSString* html;
	BOOL scrollBottom;
	int scrollTop;
}

@property (nonatomic, readonly) LogView* view;
@property (nonatomic, assign) IRCWorld* world;
@property (nonatomic, assign) IRCClient* client;
@property (nonatomic, assign) IRCChannel* channel;
@property (nonatomic, retain) NSMenu* menu;
@property (nonatomic, retain) NSMenu* urlMenu;
@property (nonatomic, retain) NSMenu* addrMenu;
@property (nonatomic, retain) NSMenu* chanMenu;
@property (nonatomic, retain) NSMenu* memberMenu;
@property (nonatomic, retain) id keyword;
@property (nonatomic, retain) id theme;
@property (nonatomic, retain) id overrideFont;
@property (nonatomic, assign) BOOL console;
@property (nonatomic, retain) NSColor* initialBackgroundColor;
@property (nonatomic, assign) int maxLines;
@property (nonatomic, readonly) BOOL viewingBottom;
@property (nonatomic, readonly) NSString* contentString;

- (void)setUp;

- (void)moveToTop;
- (void)moveToBottom;

- (void)mark;
- (void)unmark;
- (void)goToMark;
- (void)reloadTheme;
- (void)clear;
- (void)changeTextSize:(BOOL)bigger;

- (BOOL)print:(LogLine*)line useKeyword:(BOOL)useKeyword;

@end