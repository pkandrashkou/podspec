//
//  RGLCCameraMetadataPlugin.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 6/12/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AVCaptureVideoPreviewLayer;

@interface RGLCCameraMetadataPlugin : NSObject

@property(readonly, nonatomic, strong, nullable) AVCaptureVideoPreviewLayer *previewLayer;
@property(readwrite, nonatomic, copy, nullable) void (^onMetadataOutput)(NSArray<AVMetadataObject *> *_Nonnull);

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithPreviewLayer:(nullable AVCaptureVideoPreviewLayer *)previewLayer;

- (void)captureOutput:(AVCaptureOutput *)output didOutputMetadataObjects:(NSArray<AVMetadataObject *> *)metadataObjects fromConnection:(AVCaptureConnection *)connection;

@end

NS_ASSUME_NONNULL_END
