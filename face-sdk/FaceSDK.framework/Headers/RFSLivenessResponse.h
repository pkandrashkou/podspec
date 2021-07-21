//
//  RFSLivenessResponse.h
//  FaceSDK
//
//  Created by Dmitry Smolyakov on 10/21/20.
//  Copyright © 2020 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

/// `RFSLivenessErrorDomain` indicates an error related to the Liveness. For error codes see `RFSLivenessError`.
extern NSErrorDomain const RFSLivenessErrorDomain NS_SWIFT_NAME(LivenessErrorDomain);

/// Error codes for the `RFSLivenessResponse` errors.
typedef NS_ERROR_ENUM(RFSLivenessErrorDomain, RFSLivenessError) {
    /// User cancelled liveness processing.
    RFSLivenessErrorCancelled,
    /// Processing finished by timeout.
    RFSLivenessErrorProcessingTimeout,
    /// Processing failed.
    RFSLivenessErrorProcessingFailed,
    /// Liveness API call failed due to networking error or backend internal error.
    RFSLivenessErrorAPICallFailed,
    /// Reached the number of possible attempts. See `RFSLivenessConfiguration.attemptsCount` for more information.
    RFSLivenessErrorProcessingAttemptsEnded,
    /// There is no valid license on the service.
    RFSLivenessErrorNoLicense,
} NS_SWIFT_NAME(LivenessError);

/// The status of the Liveness processing.
typedef NS_ENUM(NSUInteger, RFSLivenessStatus) {
    /// The liveness check is passed successfully.
    RFSLivenessStatusPassed,
    /// The liveness check result is unknown.
    RFSLivenessStatusUnknown
} NS_SWIFT_NAME(LivenessStatus);

/// The response from the Liveness module.
NS_SWIFT_NAME(LivenessResponse)
@interface RFSLivenessResponse : NSObject

/// The input image used to determine the liveness.
@property(readonly, nonatomic, strong, nullable) UIImage *image;

/// The status of the Liveness processing.
@property(readonly, nonatomic, assign) RFSLivenessStatus liveness;

/// The error describes a failed liveness check and contains `RFSLivenessError` codes.
/// This error belongs to the `RFSLivenessErrorDomain`.
@property(readonly, nonatomic, strong, nullable) NSError *error;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
