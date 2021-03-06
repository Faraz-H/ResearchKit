/*
 Copyright (c) 2015, Apple Inc. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 
 1.  Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2.  Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.
 
 3.  Neither the name of the copyright holder(s) nor the names of any contributors
 may be used to endorse or promote products derived from this software without
 specific prior written permission. No license is granted to the trademarks of
 the copyright holders even if such marks are included in this software.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


@import UIKit;
#import <ResearchKit/ORKTypes.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ORKPicker;
@class ORKUnitTextField;
@class ORKFormItem;
@class ORKFormItemCell;

ORK_CLASS_AVAILABLE
@protocol ORKFormItemCellDelegate <NSObject>

@required
- (void)formItemCell:(ORKFormItemCell *)cell answerDidChangeTo:(nullable id)answer;
- (void)formItemCellDidBecomeFirstResponder:(ORKFormItemCell *)cell;
- (void)formItemCellDidResignFirstResponder:(ORKFormItemCell *)cell;
- (void)formItemCell:(ORKFormItemCell *)cell invalidInputAlertWithMessage:(NSString *)input;
- (void)formItemCell:(ORKFormItemCell *)cell invalidInputAlertWithTitle:(NSString *)title message:(NSString *)message;

@end

ORK_CLASS_AVAILABLE
@interface ORKFormItemCell : UITableViewCell

/**
 * The form item associated with this cell
 */
-(ORKFormItem*)formItem;

/**
 * Notify the form item cell that value has been changed outside this class
 */
- (void)inputValueDidChange NS_REQUIRES_SUPER;

/**
 * Notify the form item cell that value has been cleared outside this class
 */
- (void)inputValueDidClear NS_REQUIRES_SUPER;

/**
 * Notify the form item cell that the default answer has been changed outside this class
 */
- (void)defaultAnswerDidChange NS_REQUIRES_SUPER;

/**
 * Notify the form item cell that the answer has been changed outside this class
 */
- (void)answerDidChange;

- (instancetype)initWithReuseIdentifier:(NSString *)reuseIdentifier
                               formItem:(ORKFormItem *)formItem
                                 answer:(nullable id)answer
                          maxLabelWidth:(CGFloat)maxLabelWidth
                               delegate:(id<ORKFormItemCellDelegate>)delegate;

@property (nonatomic, weak, readonly) id<ORKFormItemCellDelegate> delegate;
@property (nonatomic, copy, nullable) id answer;
@property (nonatomic, strong) ORKFormItem *formItem;
@property (nonatomic, copy, nullable) id defaultAnswer;
@property (nonatomic) CGFloat maxLabelWidth;
@property (nonatomic) CGFloat expectedLayoutWidth;
@property (nonatomic) NSDictionary *savedAnswers;

@end

ORK_CLASS_AVAILABLE
@interface ORKFormItemTextFieldBasedCell : ORKFormItemCell <UITextFieldDelegate>
/**
 * The textfield that is associated with this form item cell
 */
- (ORKUnitTextField *)textField;
@end

ORK_CLASS_AVAILABLE
@interface ORKFormItemTextFieldCell : ORKFormItemTextFieldBasedCell
/**
 * Notify the form item cell that value has been changed outside this class
 */
- (void)inputValueDidChange;
@end


@interface ORKFormItemConfirmTextCell : ORKFormItemTextFieldCell

@end


@interface ORKFormItemNumericCell : ORKFormItemTextFieldBasedCell

@end


@interface ORKFormItemTextCell : ORKFormItemCell <UITextViewDelegate>

@end


@interface ORKFormItemImageSelectionCell : ORKFormItemCell

@end

ORK_CLASS_AVAILABLE
@interface ORKFormItemPickerCell : ORKFormItemTextFieldBasedCell

/**
 * The ORKPicker that is associated with this form item cell
 */
- (id<ORKPicker>)picker;

/**
 * Notify the form item cell that value has been changed outside this class
 */
- (void)inputValueDidChange;

@end


@interface ORKFormItemScaleCell : ORKFormItemCell

@end


@interface ORKFormItemLocationCell : ORKFormItemCell

@end

NS_ASSUME_NONNULL_END
