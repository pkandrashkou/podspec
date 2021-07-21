//
//  RFSComparedFacesPair.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 5/19/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RFSComparedFace;

/// `RFSComparedFacesPairErrorDomain` indicates an error related to the `RFSMatchFacesRequest`. For error codes see `RFSComparedFacesPairError`.
extern NSErrorDomain const RFSComparedFacesPairErrorDomain NS_SWIFT_NAME(ComparedFacesPairErrorDomain);

/// Error codes for the `RFSComparedFacesPair` errors.
typedef NS_ERROR_ENUM(RFSComparedFacesPairErrorDomain, RFSComparedFacesPairError) {
    RFSComparedFacesPairErrorImageEmpty,
    RFSComparedFacesPairErrorFaceNotDetected,
    RFSComparedFacesPairErrorLandmarksNotDetected,
    RFSComparedFacesPairErrorFaceAlignerFailed,
    RFSComparedFacesPairErrorDescriptorExtractorError,
    /// MatchFaces API call failed due to networking error or backend internal error.
    RFSComparedFacesPairErrorAPICallFailed,
} NS_SWIFT_NAME(ComparedFacesPairError);

/// `RFSComparedFacesPair` represents a result of the `RFSMatchFacesRequest` attempt to compare input images.
///
/// This class provides either a `similarity` value or an `error` describing what went wrong.
NS_SWIFT_NAME(ComparedFacesPair)
@interface RFSComparedFacesPair : NSObject

/// The first face in the comparison pair.
@property(readonly, nonatomic, strong, nonnull) RFSComparedFace *first;

/// The second face in the comparison pair.
@property(readonly, nonatomic, strong, nonnull) RFSComparedFace *second;

/// Similarity of the faces pair. Floating point value from 0 to 1.
@property(readonly, nonatomic, strong, nonnull) NSNumber *similarity;

/// The error describes a failed pair comparison and contains `RFSComparedFacesPairError` codes.
/// This error belongs to the `RFSComparedFacesPairErrorDomain`
@property(readonly, nonatomic, strong, nullable) NSError *error;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
