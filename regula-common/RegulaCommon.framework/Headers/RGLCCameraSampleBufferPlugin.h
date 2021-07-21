//
//  RGLCCameraSampleBufferPlugin.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 6/12/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RGLCCameraSampleBufferPlugin : NSObject

@property(readwrite, nonatomic, copy, nullable) void (^onSampleBufferOutput)(CMSampleBufferRef);

- (void)captureOutput:(AVCaptureOutput *)output didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection;

@end

NS_ASSUME_NONNULL_END
