//
//  RFSComparedFace.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 5/19/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RFSImage.h"

NS_ASSUME_NONNULL_BEGIN

/// `RFSComparedFace` represents a reference position of the input images provided to the request `-[RFSMatchFacesRequest initWithImages:]`.
NS_SWIFT_NAME(ComparedFace)
@interface RFSComparedFace : NSObject

/// The string that is used for objects tagging.
/// Use this field to match the output and the input data.
@property(readonly, nonatomic, copy, nullable) NSString *tag;

/// The image type.
@property(readonly, nonatomic, assign) RFSImageType imageType;

/// The index of a ComparedFace object in the images array.
@property(readonly, nonatomic, strong, nullable) NSNumber *position;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
