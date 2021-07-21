//
//  RGLCLogger.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 5/4/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#if LOGGING_ENABLED

#define RGLCLog(level, format, ...) \
    [RGLCLogger logLevel:(level) filename:__FILE_NAME__ line:__LINE__ message:format, ##__VA_ARGS__]

#define RGLCLogDebug(format, ...) \
    RGLCLog(RGLCLoggerLevelDebug, format, ##__VA_ARGS__)

#define RGLCLogVerbose(format, ...) \
    RGLCLog(RGLCLoggerLevelVerbose, format, ##__VA_ARGS__)

#define RGLCLogInfo(format, ...) \
    RGLCLog(RGLCLoggerLevelInfo, format, ##__VA_ARGS__)

#define RGLCLogWarning(format, ...) \
    RGLCLog(RGLCLoggerLevelWarning, format, ##__VA_ARGS__)

#define RGLCLogError(format, ...) \
    RGLCLog(RGLCLoggerLevelError, format, ##__VA_ARGS__)

#define RGLCLogCritical(format, ...) \
    RGLCLog(RGLCLoggerLevelCritical, format, ##__VA_ARGS__)

#define RGLCThrottleLog(level, timeoutSeconds, format, ...) \
    [RGLCLogger logLevel:(level) timeout:(timeoutSeconds) filename:__FILE_NAME__ line:__LINE__ message:format, ##__VA_ARGS__]

#else

#define RGLCLog(level, fmt, ...)
#define RGLCLogDebug(fmt, ...)
#define RGLCLogVerbose(fmt, ...)
#define RGLCLogInfo(fmt, ...)
#define RGLCLogWarning(fmt, ...)
#define RGLCLogError(fmt, ...)
#define RGLCLogCritical(fmt, ...)

#define RGLCThrottleLog(level, timeoutSeconds, format, ...)

#endif

#if INTERNAL
#define RGLCLogInternal(fmt, ...) \
    [RGLCLogger logLevel:RGLCLoggerLevelInfo filename:__FILE_NAME__ line:__LINE__ message:(@"[INTERNAL] " fmt), ##__VA_ARGS__]
#else
#define RGLCLogInternal(fmt, ...)
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RGLCLoggerLevel) {
    RGLCLoggerLevelDebug,
    RGLCLoggerLevelVerbose,
    RGLCLoggerLevelInfo,
    RGLCLoggerLevelWarning,
    RGLCLoggerLevelError,
    RGLCLoggerLevelCritical,
};

@interface RGLCLogger : NSObject

+ (void)logLevel:(RGLCLoggerLevel)level
         timeout:(CFTimeInterval)timeout
        filename:(const char *)filename
            line:(int)line
         message:(NSString *)format, ...;

+ (void)logLevel:(RGLCLoggerLevel)level
        filename:(const char *)filename
            line:(int)line
         message:(NSString *)format, ...;

@end

NS_ASSUME_NONNULL_END
