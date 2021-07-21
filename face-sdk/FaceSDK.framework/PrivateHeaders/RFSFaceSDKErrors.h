//
//  RFSFaceSDKErrors.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 5/3/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Backend errors. Error codes match service error codes.
extern NSErrorDomain const RFSBackendErrorDomain NS_SWIFT_NAME(BackendErrorDomain);
typedef NS_ERROR_ENUM(RFSBackendErrorDomain, RFSBackendError) {
    /// Service is missing a valid license file.
    RFSBackendErrorNoLicense = 200,
    /// Undefined backend error.
    RFSBackendErrorUndefined = -1,
} NS_SWIFT_NAME(BackendError);

/// Errors for APIService.
extern NSErrorDomain const RFSAPIServiceErrorDomain NS_SWIFT_NAME(APIServiceErrorDomain);
typedef NS_ERROR_ENUM(RFSAPIServiceErrorDomain, RFSAPIServiceError) {
    /// Service responded with empty payload.
    RFSAPIServiceErrorEmptyResponse,
    /// Backend error. Check for the underlying error as a `RFSBackendError`.
    RFSAPIServiceErrorBackend,
    /// Some error occured. Check the underlying error.
    RFSAPIServiceErrorUnderlying,
} NS_SWIFT_NAME(APIServiceError);

/// Errors for LivenessService.
extern NSErrorDomain const RFSLivenessServiceErrorDomain NS_SWIFT_NAME(LivenessServiceErrorDomain);
typedef NS_ERROR_ENUM(RFSLivenessServiceErrorDomain, RFSLivenessServiceError) {
    /// Liveness process cancelled.
    RFSLivenessServiceErrorCancelled,
    /// Timeout between normal and scaled inputs.
    RFSLivenessServiceErrorTimeout,
    /// Attempt number exceeded given attemptsCount. Underlying error contains last `RFSLivenessServiceError` describing why attempt has failed.
    RFSLivenessServiceErrorAllAttemptsFailed,
    /// Service received the attempt but it failed to pass Liveness. There could be more information in underlying error.
    RFSLivenessServiceErrorAttemptFailed,
    /// API service call failed. Check underlyingError.
    RFSLivenessServiceErrorAPIFailed,
    /// Application changed state to inactive causing the liveness process to fail current attempt.
    RFSLivenessServiceErrorAppInactive,
    /// Server response mapping failed
    RFSLivenessServiceErrorMappingFailed,
} NS_SWIFT_NAME(LivenessServiceError);

NS_ASSUME_NONNULL_END
