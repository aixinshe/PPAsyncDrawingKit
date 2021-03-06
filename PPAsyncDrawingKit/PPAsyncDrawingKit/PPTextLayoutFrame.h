//
//  PPTextLayoutFrame.h
//  PPAsyncDrawingKit
//
//  Created by DSKcpp on 2016/10/14.
//  Copyright © 2016年 DSKcpp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>
#import <PPAsyncDrawingKit/PPTextLayoutLine.h>

@class PPTextLayout;

NS_ASSUME_NONNULL_BEGIN

@interface PPTextLayoutFrame : NSObject
@property (nonatomic, weak) PPTextLayout *layout;
@property (nonatomic, assign) CGSize layoutSize;
@property (nonatomic, assign) PPTextFontMetrics *baselineMetrics;
@property (nullable, nonatomic, strong) NSArray<PPTextLayoutLine *> *lineFragments;

- (instancetype)initWithCTFrame:(CTFrameRef)frame layout:(PPTextLayout *)layout;
- (void)setupWithCTFrame:(CTFrameRef)frame;
- (nullable CTLineRef)createTruncatedLine:(PPTextLayout *)layout lastLineStringRange:(CFRange)lastLineStringRange;
@end

@interface PPTextLayoutFrame (LayoutResult)
- (void)enumerateEnclosingRectsForCharacterRange:(NSRange)range usingBlock:(void(^)(CGRect rect, BOOL *stop))block;
- (void)enumerateLineFragmentsForCharacterRange:(NSRange)range usingBlock:(void(^)(CGRect rect, NSRange range, BOOL *stop))block;
@end

NS_ASSUME_NONNULL_END
