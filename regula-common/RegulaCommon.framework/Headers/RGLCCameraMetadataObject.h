//
//  RGLCCameraMetadataObject.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 6/11/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, RGLCCameraMetadataObjectType) {
    RGLCCameraMetadataObjectTypeFace,
    RGLCCameraMetadataObjectTypeQR,
    RGLCCameraMetadataObjectTypeBarCode,
    RGLCCameraMetadataObjectTypeNone
};

@interface RGLCCameraMetadataObject : NSObject

@property(readonly, nonatomic, assign) RGLCCameraMetadataObjectType value;

- (nonnull instancetype)initWith:(RGLCCameraMetadataObjectType)value NS_DESIGNATED_INITIALIZER;

- (NSArray<AVMetadataObjectType> *)AVMetadataObjectType;

@end

NS_ASSUME_NONNULL_END
