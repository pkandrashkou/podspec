//
//  RFSMatchFacesResponse.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 5/19/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RFSComparedFacesPair;
@class RFSComparedFace;

/// `RFSMatchFacesErrorDomain` indicates an error related to the `RFSMatchFacesRequest`. For error codes see `RFSMatchFacesError`.
extern NSErrorDomain const RFSMatchFacesErrorDomain NS_SWIFT_NAME(MatchFacesErrorDomain);

/// Error codes for the `RFSMatchFacesResponse` errors.
typedef NS_ERROR_ENUM(RFSMatchFacesErrorDomain, RFSMatchFacesError) {
    RFSMatchFacesErrorImageEmpty,
    RFSMatchFacesErrorFaceNotDetected,
    RFSMatchFacesErrorLandmarksNotDetected,
    RFSMatchFacesErrorFaceAlignerFailed,
    RFSMatchFacesErrorDescriptorExtractorError,
    RFSMatchFacesErrorNoLicense,
    RFSMatchFacesErrorNotInitialized,
    RFSMatchFacesErrorCommandNotSupported,
    RFSMatchFacesErrorCommandParamsReadError,
    /// MatchFaces API call failed due to networking error or backend internal error.
    RFSMatchFacesErrorAPICallFailed,
    /// MatchFaces processing failed.
    RFSMatchFacesErrorProcessingFailed,
} NS_SWIFT_NAME(MatchFacesError);

/// The response from the `RFSMatchFacesRequest`.
NS_SWIFT_NAME(MatchFacesResponse)
@interface RFSMatchFacesResponse : NSObject

/// The error describes a failed match faces request and contains `RFSMatchFacesError` codes.
/// This error belongs to the `RFSMatchFacesErrorDomain`.
@property(readonly, nonatomic, strong, nullable) NSError *error;

/// Matched pairs of faces with similarity is greater or equal than the value of `similarityThreshold`.
@property(readonly, nonatomic, copy, nonnull) NSArray<RFSComparedFacesPair *> *matchedFaces;

/// Unmatched pairs of faces which similarity is less than the value of `similarityThreshold`.
@property(readonly, nonatomic, copy, nonnull) NSArray<RFSComparedFacesPair *> *unmatchedFaces;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
