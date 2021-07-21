//
//  RGLCCameraPreviewView.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 6/2/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVCaptureVideoPreviewLayer.h>

NS_ASSUME_NONNULL_BEGIN

@class AVCaptureSession;

@interface RGLCCameraPreviewView : UIView

@property(readonly, nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;
@property(nonatomic, strong) AVCaptureSession *session;

@end

NS_ASSUME_NONNULL_END
