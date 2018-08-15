//
//  OakDocument.h
//  AckMate
//
//  Created by Annard Brouwer on 15/08/2018.
//  Copyright © 2018 Jetpack Pony. All rights reserved.
//

#ifndef OakDocument_h
#define OakDocument_h

@class OakDocument;

@interface OakDocument (TextMateImport)

+ (instancetype)documentWithPath:(NSString*)aPath;

- (NSString *)path;
- (NSString *)displayName;

@end

#endif /* OakDocument_h */
