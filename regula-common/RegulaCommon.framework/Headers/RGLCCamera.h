//
//  RGLCCamera.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 6/2/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "RGLCCameraMetadataObject.h"

@class RGLCCameraPreviewView;
@class RGLCCameraDevice;
@class RGLCCameraSampleBufferPlugin;
@class RGLCCameraMetadataPlugin;
@class RGLCCameraSessionPreset;

NS_ASSUME_NONNULL_BEGIN

typedef void (^RGLCCapturePhotoCompletion)(UIImage * _Nullable, NSError * _Nullable);

extern NSErrorDomain const RGLCCameraErrorDomain;
typedef NS_ERROR_ENUM(RGLCCameraErrorDomain, RGLCCameraError) {
    cameraPermissionNotAuthorized,
    cameraPermissionNotDetermined,
    unknown
};

@interface RGLCCamera : NSObject

@property(readonly, nonatomic, strong) AVCaptureSession *session;
@property(readonly, nonatomic, strong) RGLCCameraPreviewView *previewView;
@property(readwrite, nonatomic, assign) AVCaptureDevicePosition currentDevicePosition;
@property(readonly, nonatomic, strong, nonnull) RGLCCameraDevice *cameraDevice;

@property(readwrite, nonatomic, assign) AVCaptureTorchMode torchMode;
@property(readwrite, nonatomic, assign, getter=isRotationEnabled) BOOL rotationEnabled;
@property(readwrite, nonatomic, assign) RGLCCameraMetadataObjectType detectingObjectType;
@property(readwrite, nonatomic, assign) AVCaptureSessionPreset presetType;
@property(readwrite, nonatomic, assign) CGFloat scaleFactor;

@property(readonly, nonatomic, copy, nonnull) NSArray<RGLCCameraSessionPreset *> *compatiblePresets;
@property(readonly, nonatomic, strong, nullable) RGLCCameraSessionPreset *highestPresets;


/// Called when an unexpected error occurs while an AVCaptureSession instance is running.
@property(readwrite, nonatomic, copy, nullable) void (^didRecieveRuntimeError)(RGLCCamera * _Nonnull, NSError * _Nonnull);


/// An instance of AVCaptureSession starts running. Will be also called after interruptionEnded.
@property(readwrite, nonatomic, copy, nullable) void (^didStartRunning)(RGLCCamera * _Nonnull);

/// An AVCaptureSession instance may stop running automatically due to external system conditions,
/// such as the device going to sleep, or being locked by a user.
/// Will be also called after wasInterrupted.
@property(readwrite, nonatomic, copy, nullable) void (^didStopRunning)(RGLCCamera * _Nonnull);


/// An AVCaptureSession may be interrupted, for example, by an incoming phone call, or alarm, or another application taking control of needed hardware resources. When appropriate, the AVCaptureSession instance will stop running automatically in response to an interruption.
/// Contains an AVCaptureSessionInterruptionReasonKey indicating the reason for the interruption.
@property(readwrite, nonatomic, copy, nullable) void (^wasInterrupted)(RGLCCamera * _Nonnull, AVCaptureSessionInterruptionReason);


/// An AVCaptureSession ceases to be interrupted, for example, when a phone call ends, and hardware resources needed to run the session are again available. When appropriate, the AVCaptureSession instance that was previously stopped in response to an interruption will automatically restart once the interruption ends.
@property(readwrite, nonatomic, copy, nullable) void (^interruptionEnded)(RGLCCamera * _Nonnull);

- (nonnull instancetype)init;

- (BOOL)start:(NSError * _Nullable *)error;
- (void)stop;
- (void)setCaptureDeviceFormat:(AVCaptureDeviceFormat *)format;
- (void)setCaptureDeviceFormatForVideoSize:(CGSize)size;

- (void)toggleDevicePosition;
- (void)focusAt:(CGPoint)point;
- (void)updateScaleFactor:(CGFloat)scaleFactor animated:(BOOL)animated completion:(dispatch_block_t)completion;

- (void)capturePhoto:(AVCapturePhotoSettings *)settings completion:(RGLCCapturePhotoCompletion)completion API_AVAILABLE(ios(10.0));
- (void)capturePhoto:(RGLCCapturePhotoCompletion)completion;

/// Calculates object height in points relative to the previewView bounds based on given distance from the camera to the object,
/// real object height and active device format used for capture.
/// @param distance Distance to the real object. Units must match @p objectHeight (e.g. cm)
/// @param objectHeight Real object height. Units must match @p distance (e.g. cm)
/// @param focalLength Focal length of currently active @c AVCaptureDeviceFormat
/// @param cameraScale Zoom or scaleFactor of the camere
- (CGFloat)objectHeightOnPreviewForDistance:(float)distance
                           realObjectHeight:(float)objectHeight
                                focalLength:(float)focalLength
                                cameraScale:(float)cameraScale;

/// Calculates zoom or scaleFactor for camera to fit given object height in objectPreviewHeight given real object height and distance from the camera to the object,
/// real object height and active device format used for capture.
/// @param distance Distance to the real object. Units must match @p objectHeight (e.g. cm)
/// @param objectPreviewHeight object height in points relative to the previewView bounds
/// @param realObjectHeight Real object height. Units must match @p distance (e.g. cm)
/// @param focalLengthMM Focal length of currently active @c AVCaptureDeviceFormat.
- (CGFloat)cameraZoomForDistance:(float)distance
             objectPreviewHeight:(float)objectPreviewHeight
                realObjectHeight:(float)realObjectHeight
                     focalLength:(float)focalLengthMM;

- (void)setSampleBufferPlugin:(nonnull RGLCCameraSampleBufferPlugin *)plugin forKey:(nonnull NSString *)key;
- (void)removeSampleBufferPluginForKey:(nonnull NSString *)key;

- (void)setMetadataPlugin:(nonnull RGLCCameraMetadataPlugin *)plugin forKey:(nonnull NSString *)key;
- (void)removeMetadataPluginForKey:(nonnull NSString *)key;

+ (BOOL)cameraPermissionGranted;
+ (void)requestCameraPermission:(void (^)(BOOL granted))completionBlock;
//+ (void)requestMicrophonePermission:(void (^)(BOOL granted))completionBlock;

@end

NS_ASSUME_NONNULL_END
