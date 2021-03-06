//
//  QMPlaceHolderTextView.h
//  QMChatViewController
//
//  Created by Andrey Ivanov on 13.05.15.
//  Copyright (c) 2015 QuickBlox Team. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Quickblox/Quickblox.h>

@protocol QMPlaceHolderTextViewPasteDelegate;

/**
 *  Input field with placeholder.
 */
@interface QMPlaceHolderTextView : UITextView

/**
 *  The object that acts as the paste delegate of the text view.
 */
@property (weak, nonatomic, nullable) id<QMPlaceHolderTextViewPasteDelegate> pasteDelegate;

/**
 *  The text to be displayed when the text view is empty. The default value is `nil`.
 */
@property (copy, nonatomic, QB_NULLABLE) IBInspectable NSString *placeHolder;

/**
 *  The color of the place holder text. The default value is `[UIColor lightGrayColor]`.
 */
@property (strong, nonatomic, QB_NONNULL) IBInspectable UIColor *placeHolderColor;

/**
 *  Determines whether or not the text view contains text after trimming white space
 *  from the front and back of its string.
 *
 *  @return `YES` if the text view contains text, `NO` otherwise.
 */
- (BOOL)hasText;

/**
 *  Determines whether or not the text view contains image as NSTextAttachment
 *
 *
 *  @return `YES` if the text view contains attachment, `NO` otherwise.
 */
- (BOOL)hasTextAttachment;


- (void)setDefaultSettings;

@end

@protocol QMPlaceHolderTextViewPasteDelegate <NSObject>

@optional
/**
 *  Asks the delegate whether or not the `textView` should use the original implementation of `-[UITextView paste]`.
 *
 *  @discussion Use this delegate method to implement custom pasting behavior.
 *  You should return `NO` when you want to handle pasting.
 *  Return `YES` to defer functionality to the `textView`.
 */
- (BOOL)placeHolderTextView:(QB_NONNULL QMPlaceHolderTextView *)textView shouldPasteWithSender:(QB_NONNULL id)sender;


@end