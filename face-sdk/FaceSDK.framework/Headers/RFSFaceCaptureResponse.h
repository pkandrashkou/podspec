//
//  RFSFaceCaptureResponse.h
//  FaceSDK
//
//  Created by Dmitry Smolyakov on 18.01.21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RFSImage;

NS_ASSUME_NONNULL_BEGIN

/// `RFSFaceCaptureErrorDomain` indicates an error related to the Face Capture. For error codes see `RFSFaceCaptureError`.
extern NSErrorDomain const RFSFaceCaptureErrorDomain NS_SWIFT_NAME(FaceCaptureErrorDomain);

/// Error codes for the `RFSFaceCaptureResponse` errors.
typedef NS_ERROR_ENUM(RFSFaceCaptureErrorDomain, RFSFaceCaptureError) {
    RFSFaceCaptureErrorCancelled = 600
} NS_SWIFT_NAME(FaceCaptureDomain);

/// The response from the Face Capture module. This object contains either an image or an error.
NS_SWIFT_NAME(FaceCaptureResponse)
@interface RFSFaceCaptureResponse : NSObject

/// The captured image.
@property(readonly, nonatomic, strong, nullable) RFSImage *image;

/// The error describes a failed face capture and contains `RFSFaceCaptureError` codes.
/// This error belongs to the `RFSFaceCaptureErrorDomain`.
@property(readonly, nonatomic, strong, nullable) NSError *error;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
