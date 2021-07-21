//
//  RFSMatchFacesRequest.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 5/19/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RFSImage;

/// `RFSMatchFacesRequest` compares two or more images with faces on them to find out the similarity of pairs.
///
/// The request is used as a parameter to `-[RFSFaceSDK matchFaces:completion:]`.
NS_SWIFT_NAME(MatchFacesRequest)
@interface RFSMatchFacesRequest : NSObject

/// The threshold value of the similarity of faces. Defaults to `0.75`.
/// If the similarity of faces is greater or equal than the threshold, faces will be written to the `matchedFaces` array, otherwise to the `unmatchedFaces` one.
@property(readwrite, nonatomic, strong, nonnull) NSNumber *similarityThreshold;

/// Images with faces to match.
@property(readonly, nonatomic, copy, nonnull) NSArray<RFSImage *> *images;

/// Custom metadata. It can include a collection of information like age, male, country and etc. Default: nil.
@property(readwrite, nonatomic, strong, nullable) NSDictionary *customMetadata;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// Creates MatchFacesRequest to match input `images` for similarity with `similarityThreshold` threshold value.
- (instancetype)initWithImages:(nonnull NSArray<RFSImage *> *)images NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
