//
//  RFSImage.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 5/19/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

/// The image type of `RFSImage` influences matching results and provides the information about the source of the image.
typedef NS_ENUM(NSInteger, RFSImageType) {
    /// The image contains a printed portrait of a person.
    RFSImageTypePrinted = 1,
    /// The image contains a portrait of a person and is taken from the RFID chip.
    RFSImageTypeRFID = 2,
    /// The image is taken from the camera.
    RFSImageTypeLive = 3,
    /// The image contains a document with a portrait of a person.
    RFSImageTypeLiveWithDoc = 4,
} NS_SWIFT_NAME(ImageType);

/// The Image class wraps regular `UIImage` and provides more information to the input and output data.
NS_SWIFT_NAME(Image)
@interface RFSImage : NSObject

/// Unique identifier for Image object.
@property(readonly, nonatomic, nonnull) NSString *identifier;

/// The string that is used for objects tagging.
/// Use this field to match the output and input data.
@property(readwrite, nonatomic, copy, nullable) NSString *tag;

/// The image type.
/// The imageType influences matching results, therefore this field is required.
@property(readonly, nonatomic, assign) RFSImageType imageType;

/// The underlying image.
@property(readonly, nonatomic, strong, nonnull) UIImage *image;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithImage:(nonnull UIImage *)image type:(RFSImageType)imageType NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
