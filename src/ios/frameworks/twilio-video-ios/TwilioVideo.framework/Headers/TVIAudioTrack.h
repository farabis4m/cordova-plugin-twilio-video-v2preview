//
//  TVIAudioTrack.h
//  TwilioVideo
//
//  Copyright © 2016-2017 Twilio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TVITrack.h"

@protocol TVIAudioSink;

/**
 *  `TVIAudioTrack` represents a local or remote audio track.
 */
@interface TVIAudioTrack : TVITrack
/**
 *  @brief Developers shouldn't initialize this class directly.
 *
 *  @discussion Tracks cannot be created explicitly.
 */
- (null_unspecified instancetype)init __attribute__((unavailable("Tracks cannot be created explicitly.")));

/**
 *  @brief An array of sinks that are currently attached to the `TVIAudioTrack`.
 *
 *  @note Use the 'addSink:' and 'removeSink:' methods to manipulate this collection.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray<id<TVIAudioSink>> *sinks;

/**
 *  @brief Adds a sink to the Track.
 *
 *  @discussion Sinks consume raw audio samples for further processing or storage.
 *
 *  @param sink An object or Swift struct that implements the `TVIAudioSink` protocol.
 */
- (void)addSink:(nonnull id<TVIAudioSink>)sink;

/**
 *  @brief Removes a sink from the Track.
 *
 *  @param sink An object or Swift struct that implements the `TVIAudioSink` protocol.
 */
- (void)removeSink:(nonnull id<TVIAudioSink>)sink;

@end

@class TVIAudioOptions;

/**
 *  `TVILocalAudioTrack` represents an audio track where the content is captured from your device's audio subsystem.
 */
@interface TVILocalAudioTrack : TVIAudioTrack

/**
 *  @brief The `TVIAudioOptions` that were provided when the track was added to `TVILocalMedia`.
 */
@property (nonatomic, strong, readonly, nullable) TVIAudioOptions *options;

/**
 *  @brief Indicates if the track content is enabled.
 *
 *  @discussion It is possible to enable and disable local tracks. The results of this operation are signaled to other 
 *  Participants in the same Room. When an audio track is disabled, silence is sent in place of normal audio.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/**
 *  @brief Developers shouldn't initialize this class directly.
 *
 *  @discussion Tracks cannot be created explicitly.
 */
- (null_unspecified instancetype)init __attribute__((unavailable("Tracks cannot be created explicitly.")));

/**
 *  @brief Creates a `TVILocalAudioTrack` with the default settings.
 *
 *  @discussion This method uses the default `TVIAudioOptions`, and produces an enabled Track.
 *
 *  @return A Track which is ready to be shared with Participants in a Room, or `nil` if an error occurs.
 */
+ (null_unspecified instancetype)track;

/**
 *  @brief Creates a `TVILocalAudioTrack` with `TVIAudioOptions` and an enabled setting.
 *
 *  @discussion This method allows you to provide specific `TVIAudioOptions`, and produce a disabled Track if you wish.
 *
 *  @param options An instance of `TVIAudioOptions` to configure the Track.
 *  @param enabled Determines if the Track is enabled at creation time.
 *
 *  @return A Track which is ready to be shared with Participants in a Room, or `nil` if an error occurs.
 */
+ (null_unspecified instancetype)trackWithOptions:(nullable TVIAudioOptions *)options
                                          enabled:(BOOL)enabled;

@end
