// Copyright (c) 2010 Trevor Squires. All Rights Reserved.
// See License.txt for full license.

#import <Cocoa/Cocoa.h>

@class JPAckResultSource;
extern NSString * const JPAckProcessComplete;

extern const enum {
    ackInitial        = 0,
    ackStdOutClosed   = 1<<0,
    ackStdErrClosed   = 1<<1,
    ackTerminated     = 1<<2,
    ackComplete       = (ackStdOutClosed | ackStdErrClosed | ackTerminated)
} ackStates;

@interface JPAckProcess : NSObject {
  NSMutableData* trailing;
  NSMutableData* errorData;
  JPAckResultSource* ackResult;
  NSTask* ackTask;
  NSInteger ackState;
}

- (id)initWithResultHolder:(JPAckResultSource*)resultHolder;
- (void)invokeWithTerm:(NSString*)term
                  path:(NSString*)path
          searchFolder:(NSString*)searchFolder
                 useAg:(BOOL)useAg
               literal:(BOOL)literal
                nocase:(BOOL)nocase
                 words:(BOOL)words
               context:(BOOL)context
              symlinks:(BOOL)symlinks
         folderPattern:(NSString*)folderPattern
               options:(NSArray*)options;

- (void)parseData:(NSData*)data;
- (void)saveTrailing:(char*)bytes
              length:(NSUInteger)length;

- (void)terminateImmediately:(BOOL)immediately;

@end
