//
//  RGLCCameraSessionPreset.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 7/3/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RGLCCameraSessionPreset : NSObject

@property(readonly, nonatomic, assign) AVCaptureSessionPreset value;

- (instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWith:(AVCaptureSessionPreset)value NS_DESIGNATED_INITIALIZER;

+ (NSArray<RGLCCameraSessionPreset *> *)presets;
+ (NSArray<RGLCCameraSessionPreset *> *)compatibleWith:(AVCaptureSession *)session;

@end

NS_ASSUME_NONNULL_END
