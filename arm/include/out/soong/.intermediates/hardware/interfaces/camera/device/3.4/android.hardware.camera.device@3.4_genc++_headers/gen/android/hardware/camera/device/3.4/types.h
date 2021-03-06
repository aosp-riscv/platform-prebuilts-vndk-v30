#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_4_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_4_TYPES_H

#include <android/hardware/camera/device/3.2/types.h>
#include <android/hardware/camera/device/3.3/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_4 {

// Forward declaration for forward reference support:
struct Stream;
struct StreamConfiguration;
struct HalStream;
struct HalStreamConfiguration;
struct PhysicalCameraSetting;
struct CaptureRequest;
struct PhysicalCameraMetadata;
struct CaptureResult;

/**
 * Stream:
 *
 * A descriptor for a single camera input or output stream. A stream is defined
 * by the framework by its buffer resolution and format, and additionally by the
 * HAL with the gralloc usage flags and the maximum in-flight buffer count.
 *
 * This version extends the @3.2 Stream with the physicalCameraId and bufferSize field.
 */
struct Stream final {
    /**
     * The definition of Stream from the prior version
     */
    ::android::hardware::camera::device::V3_2::Stream v3_2 __attribute__ ((aligned(8)));
    /**
     * The physical camera id this stream belongs to.
     *
     * If the camera device is not a logical multi camera, or if the camera is a logical
     * multi camera but the stream is not a physical output stream, this field will point to a
     * 0-length string.
     *
     * A logical multi camera is a camera device backed by multiple physical cameras that
     * are also exposed to the application. And for a logical multi camera, a physical output
     * stream is an output stream specifically requested on an underlying physical camera.
     *
     * A logical camera is a camera device backed by multiple physical camera
     * devices. And a physical stream is a stream specifically requested on a
     * underlying physical camera device.
     *
     * For an input stream, this field is guaranteed to be a 0-length string.
     *
     * When not empty, this field is the <id> field of one of the full-qualified device
     * instance names returned by getCameraIdList().
     */
    ::android::hardware::hidl_string physicalCameraId __attribute__ ((aligned(8)));
    /**
     * The size of a buffer from this Stream, in bytes.
     *
     * For non PixelFormat::BLOB formats, this entry must be 0 and HAL should use
     * android.hardware.graphics.mapper lockYCbCr API to get buffer layout.
     *
     * For BLOB format with dataSpace Dataspace::DEPTH, this must be zero and and HAL must
     * determine the buffer size based on ANDROID_DEPTH_MAX_DEPTH_SAMPLES.
     *
     * For BLOB format with dataSpace Dataspace::JFIF, this must be non-zero and represent the
     * maximal size HAL can lock using android.hardware.graphics.mapper lock API.
     *
     */
    uint32_t bufferSize __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_4::Stream, v3_2) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::Stream, physicalCameraId) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::Stream, bufferSize) == 56, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_4::Stream) == 64, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_4::Stream) == 8, "wrong alignment");

/**
 * StreamConfiguration:
 *
 * Identical to @3.2::StreamConfiguration, except that it contains session
 * parameters, and the streams vector contains @3.4::Stream.
 */
struct StreamConfiguration final {
    /**
     * An array of camera stream pointers, defining the input/output
     * configuration for the camera HAL device.
     */
    ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::Stream> streams __attribute__ ((aligned(8)));
    /**
     * The definition of operation mode from prior version.
     *
     */
    ::android::hardware::camera::device::V3_2::StreamConfigurationMode operationMode __attribute__ ((aligned(4)));
    /**
     * Session wide camera parameters.
     *
     * The session parameters contain the initial values of any request keys that were
     * made available via ANDROID_REQUEST_AVAILABLE_SESSION_KEYS. The Hal implementation
     * can advertise any settings that can potentially introduce unexpected delays when
     * their value changes during active process requests. Typical examples are
     * parameters that trigger time-consuming HW re-configurations or internal camera
     * pipeline updates. The field is optional, clients can choose to ignore it and avoid
     * including any initial settings. If parameters are present, then hal must examine
     * their values and configure the internal camera pipeline accordingly.
     */
    ::android::hardware::hidl_vec<uint8_t> sessionParams __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_4::StreamConfiguration, streams) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::StreamConfiguration, operationMode) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::StreamConfiguration, sessionParams) == 24, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_4::StreamConfiguration) == 40, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_4::StreamConfiguration) == 8, "wrong alignment");

/**
 * HalStream:
 *
 * The camera HAL's response to each requested stream configuration.
 *
 * This version extends the @3.3 HalStream with the physicalCameraId
 * field
 */
struct HalStream final {
    /**
     * The definition of HalStream from the prior version.
     */
    ::android::hardware::camera::device::V3_3::HalStream v3_3 __attribute__ ((aligned(8)));
    /**
     * The physical camera id the current Hal stream belongs to.
     *
     * If current camera device isn't a logical camera, or the Hal stream isn't
     * from a physical camera of the logical camera, this must be an empty
     * string.
     *
     * A logical camera is a camera device backed by multiple physical camera
     * devices.
     *
     * When not empty, this field is the <id> field of one of the full-qualified device
     * instance names returned by getCameraIdList().
     */
    ::android::hardware::hidl_string physicalCameraId __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_4::HalStream, v3_3) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::HalStream, physicalCameraId) == 40, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_4::HalStream) == 56, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_4::HalStream) == 8, "wrong alignment");

/**
 * HalStreamConfiguration:
 *
 * Identical to @3.3::HalStreamConfiguration, except that it contains @3.4::HalStream entries.
 *
 */
struct HalStreamConfiguration final {
    ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::HalStream> streams __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_4::HalStreamConfiguration, streams) == 0, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_4::HalStreamConfiguration) == 16, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_4::HalStreamConfiguration) == 8, "wrong alignment");

/**
 * PhysicalCameraSetting:
 *
 * Individual camera settings for logical camera backed by multiple physical devices.
 * Clients are allowed to pass separate settings for each physical device that has
 * corresponding configured HalStream and the respective stream id is present in the
 * output buffers of the capture request.
 */
struct PhysicalCameraSetting final {
    /**
     * If non-zero, read settings from request queue instead
     * (see ICameraDeviceSession.getCaptureRequestMetadataQueue).
     * If zero, read settings from .settings field.
     *
     * The v3_2 settings metadata is read first from the FMQ, followed by
     * the physical cameras' settings metadata starting from index 0.
     */
    uint64_t fmqSettingsSize __attribute__ ((aligned(8)));
    /**
     * Contains the physical device camera id. Any settings passed by client here
     * should be applied for this physical device. In case the physical id is invalid or
     * it is not present among the last configured streams, Hal should fail the process
     * request and return Status::ILLEGAL_ARGUMENT.
     */
    ::android::hardware::hidl_string physicalCameraId __attribute__ ((aligned(8)));
    /**
     * If fmqSettingsSize is zero, the settings buffer contains the capture and
     * processing parameters for the physical device with id 'physicalCameraId'.
     * As a special case, an empty settings buffer indicates that the
     * settings are identical to the most-recently submitted capture request.
     * An empty buffer cannot be used as the first submitted request after
     * a configureStreams() call.
     *
     * This field must be used if fmqSettingsSize is zero. It must not be used
     * if fmqSettingsSize is non-zero.
     */
    ::android::hardware::hidl_vec<uint8_t> settings __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting, fmqSettingsSize) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting, physicalCameraId) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting, settings) == 24, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting) == 40, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting) == 8, "wrong alignment");

/**
 * CaptureRequest:
 *
 * A single request for image capture/buffer reprocessing, sent to the Camera
 * HAL device by the framework in processCaptureRequest().
 *
 * The request contains the settings to be used for this capture, and the set of
 * output buffers to write the resulting image data in. It may optionally
 * contain an input buffer, in which case the request is for reprocessing that
 * input buffer instead of capturing a new image with the camera sensor. The
 * capture is identified by the frameNumber.
 *
 * In response, the camera HAL device must send a CaptureResult
 * structure asynchronously to the framework, using the processCaptureResult()
 * callback.
 *
 * Identical to @3.2::CaptureRequest, except that it contains
 * @3.4::physCamSettings vector.
 *
 * With 3.4 CaptureRequest, there can be multiple sources of metadata settings.
 * The @3.2::CaptureRequest v3_2 and each of the PhysicalCameraSetting in
 * physicalCameraSettings can contain settings, and each buffer may have
 * metadata settings from a different source.
 *
 * For both @3.2::CaptureRequest and PhysicalCameraSetting, the settings can be
 * passed from framework to HAL using either hwbinder or FMQ; both of the
 * structs have the fields fmqSettingsSize and settings to pass the metadata.
 * When metadata settings are passed using hwbinder, fmqSettingsSize == 0 and
 * settings field contains the metadata for the HAL to read. When metadata
 * settings comes from FMQ, fmqSettingsSize > 0 and HAL reads metadata from FMQ.
 * For the purposes of selecting which settings to use, it does not matter
 * whether it comes from hwbinder or FMQ. When the below specifications say that
 * v3_2 has settings or a PhysicalCameraSetting has settings, it could refer to
 * either hwbinder or FMQ, whichever is specified in the struct.
 *
 * Below is the logic that the HAL must follow for applying the metadata
 * settings when it receives a CaptureRequest request in
 * processCaptureRequest_3_4. Note that HAL must be capable of storing both the
 * request.v3_2 settings and the PhysicalCameraSetting settings for each
 * physical device.
 * - Case 1 - request.v3_2 has settings, request.physicalCameraSettings vector
 *   is empty:
 *   - Store the request.v3_2 settings, overwriting the previously stored
 *     request.v3_2 settings and clearing all previously stored physical device
 *     settings.
 *   - Apply the settings from the request.v3_2 to all buffers.
 * - Case 2 - request.v3_2 has settings, request.physicalCameraSettings vector
 *   is not empty:
 *   - Store the request.v3_2 settings, overwriting the previously stored
 *     request.v3_2 settings.
 *   - Each PhysicalCameraSetting in request.physicalCameraSettings must have
 *     settings; if not, return error.
 *   - For each PhysicalCameraSetting in request.physicalCameraSettings, store
 *     the settings, overwriting the previously stored settings for this
 *     physical camera; apply these settings to the buffers belonging to the
 *     stream for this device.
 *   - If there are any stored physical camera settings which do not correspond
 *     to one of the PhysicalCameraSetting in this request, clear them.
 *   - Apply the request.v3_2 settings to all buffers belonging to streams not
 *     covered by one of the PhysicalCameraSetting in this request.
 * - Case 3 - request.v3_2 does not have settings,
 *   request.physicalCameraSettings vector is empty:
 *   - Clear all previously stored physical device settings.
 *   - Apply the stored request.v3_2 settings to all buffers. If there is no
 *     stored request.v3_2 settings, return error.
 * - Case 4 - request.v3_2 does not have settings,
 *   request.physicalCameraSettings vector is not empty:
 *   - If request.physicalCameraSettings does not have the same set of physical
 *     cameras as the stored physical camera settings, return error.
 *   - Each PhysicalCameraSetting in request.physicalCameraSettings must not
 *     have settings; if any do have settings, return error.
 *   - For each PhysicalCameraSetting in request.physicalCameraSettings, apply
 *     the previously stored settings for this physical camera to the buffers
 *     belonging to the stream for this device.
 *   - Apply the stored request.v3_2 settings to all buffers belonging to
 *     streams not covered by one of the PhysicalCameraSetting in this request.
 *     If there is no stored request.v3_2 settings, return error.
 *
 * For the first request received by the HAL, only Case 1 and Case 2 are
 * allowed.
 */
struct CaptureRequest final {
    /**
     * The definition of CaptureRequest from prior version.
     */
    ::android::hardware::camera::device::V3_2::CaptureRequest v3_2 __attribute__ ((aligned(8)));
    /**
     * A vector containing individual camera settings for logical camera backed by multiple physical
     * devices. In case the vector is empty, Hal should use the settings field in 'v3_2'. The
     * individual settings should only be honored for physical devices that have respective Hal
     * stream. Physical devices that have a corresponding Hal stream but don't have attached
     * settings here should use the settings field in 'v3_2'.
     * If any of the physical settings in the array are applied on one or more devices, then the
     * visual effect on any Hal streams attached to the logical camera is undefined.
     */
    ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::PhysicalCameraSetting> physicalCameraSettings __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_4::CaptureRequest, v3_2) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::CaptureRequest, physicalCameraSettings) == 120, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_4::CaptureRequest) == 136, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_4::CaptureRequest) == 8, "wrong alignment");

/**
 * PhysicalCameraMetadata:
 *
 * Individual camera metadata for a physical camera as part of a logical
 * multi-camera. Camera HAL should return one such metadata for each physical
 * camera being requested on.
 */
struct PhysicalCameraMetadata final {
    /**
     * If non-zero, read metadata from result metadata queue instead
     * (see ICameraDeviceSession.getCaptureResultMetadataQueue).
     * If zero, read metadata from .metadata field.
     *
     * The v3_2 CaptureResult metadata is read first from the FMQ, followed by
     * the physical cameras' metadata starting from index 0.
     */
    uint64_t fmqMetadataSize __attribute__ ((aligned(8)));
    /**
     * Contains the physical device camera id. As long as the corresponding
     * processCaptureRequest requests on a particular physical camera stream,
     * the metadata for that physical camera should be generated for the capture
     * result.
     */
    ::android::hardware::hidl_string physicalCameraId __attribute__ ((aligned(8)));
    /**
     * If fmqMetadataSize is zero, the metadata buffer contains the metadata
     * for the physical device with physicalCameraId.
     */
    ::android::hardware::hidl_vec<uint8_t> metadata __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata, fmqMetadataSize) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata, physicalCameraId) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata, metadata) == 24, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata) == 40, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata) == 8, "wrong alignment");

/**
 * CaptureResult:
 *
 * Identical to @3.2::CaptureResult, except that it contains a list of
 * physical camera metadata.
 *
 * Physical camera metadata needs to be generated if and only if a
 * request is pending on a stream from that physical camera. For example,
 * if the processCaptureRequest call doesn't request on physical camera
 * streams, the physicalCameraMetadata field of the CaptureResult being returned
 * should be an 0-size vector. If the processCaptureRequest call requests on
 * streams from one of the physical camera, the physicalCameraMetadata field
 * should contain one metadata describing the capture from that physical camera.
 *
 * For a CaptureResult that contains physical camera metadata, its
 * partialResult field must be android.request.partialResultCount. In other
 * words, the physicalCameraMetadata must only be contained in a final capture
 * result.
 */
struct CaptureResult final {
    /**
     * The definition of CaptureResult from the prior version.
     */
    ::android::hardware::camera::device::V3_2::CaptureResult v3_2 __attribute__ ((aligned(8)));
    /**
     * The physical metadata for logical multi-camera.
     */
    ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::PhysicalCameraMetadata> physicalCameraMetadata __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_4::CaptureResult, v3_2) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_4::CaptureResult, physicalCameraMetadata) == 128, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_4::CaptureResult) == 144, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_4::CaptureResult) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::camera::device::V3_4::Stream& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_4::Stream& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::camera::device::V3_4::Stream& lhs, const ::android::hardware::camera::device::V3_4::Stream& rhs);
static inline bool operator!=(const ::android::hardware::camera::device::V3_4::Stream& lhs, const ::android::hardware::camera::device::V3_4::Stream& rhs);

static inline std::string toString(const ::android::hardware::camera::device::V3_4::StreamConfiguration& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_4::StreamConfiguration& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::camera::device::V3_4::StreamConfiguration& lhs, const ::android::hardware::camera::device::V3_4::StreamConfiguration& rhs);
static inline bool operator!=(const ::android::hardware::camera::device::V3_4::StreamConfiguration& lhs, const ::android::hardware::camera::device::V3_4::StreamConfiguration& rhs);

static inline std::string toString(const ::android::hardware::camera::device::V3_4::HalStream& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_4::HalStream& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::camera::device::V3_4::HalStream& lhs, const ::android::hardware::camera::device::V3_4::HalStream& rhs);
static inline bool operator!=(const ::android::hardware::camera::device::V3_4::HalStream& lhs, const ::android::hardware::camera::device::V3_4::HalStream& rhs);

static inline std::string toString(const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& lhs, const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& rhs);
static inline bool operator!=(const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& lhs, const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& rhs);

static inline std::string toString(const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& lhs, const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& rhs);
static inline bool operator!=(const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& lhs, const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& rhs);

static inline std::string toString(const ::android::hardware::camera::device::V3_4::CaptureRequest& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_4::CaptureRequest& o, ::std::ostream*);
// operator== and operator!= are not generated for CaptureRequest

static inline std::string toString(const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& lhs, const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& rhs);
static inline bool operator!=(const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& lhs, const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& rhs);

static inline std::string toString(const ::android::hardware::camera::device::V3_4::CaptureResult& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_4::CaptureResult& o, ::std::ostream*);
// operator== and operator!= are not generated for CaptureResult

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::camera::device::V3_4::Stream& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v3_2 = ";
    os += ::android::hardware::camera::device::V3_2::toString(o.v3_2);
    os += ", .physicalCameraId = ";
    os += ::android::hardware::toString(o.physicalCameraId);
    os += ", .bufferSize = ";
    os += ::android::hardware::toString(o.bufferSize);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_4::Stream& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::camera::device::V3_4::Stream& lhs, const ::android::hardware::camera::device::V3_4::Stream& rhs) {
    if (lhs.v3_2 != rhs.v3_2) {
        return false;
    }
    if (lhs.physicalCameraId != rhs.physicalCameraId) {
        return false;
    }
    if (lhs.bufferSize != rhs.bufferSize) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::camera::device::V3_4::Stream& lhs, const ::android::hardware::camera::device::V3_4::Stream& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::camera::device::V3_4::StreamConfiguration& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".streams = ";
    os += ::android::hardware::toString(o.streams);
    os += ", .operationMode = ";
    os += ::android::hardware::camera::device::V3_2::toString(o.operationMode);
    os += ", .sessionParams = ";
    os += ::android::hardware::toString(o.sessionParams);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_4::StreamConfiguration& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::camera::device::V3_4::StreamConfiguration& lhs, const ::android::hardware::camera::device::V3_4::StreamConfiguration& rhs) {
    if (lhs.streams != rhs.streams) {
        return false;
    }
    if (lhs.operationMode != rhs.operationMode) {
        return false;
    }
    if (lhs.sessionParams != rhs.sessionParams) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::camera::device::V3_4::StreamConfiguration& lhs, const ::android::hardware::camera::device::V3_4::StreamConfiguration& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::camera::device::V3_4::HalStream& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v3_3 = ";
    os += ::android::hardware::camera::device::V3_3::toString(o.v3_3);
    os += ", .physicalCameraId = ";
    os += ::android::hardware::toString(o.physicalCameraId);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_4::HalStream& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::camera::device::V3_4::HalStream& lhs, const ::android::hardware::camera::device::V3_4::HalStream& rhs) {
    if (lhs.v3_3 != rhs.v3_3) {
        return false;
    }
    if (lhs.physicalCameraId != rhs.physicalCameraId) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::camera::device::V3_4::HalStream& lhs, const ::android::hardware::camera::device::V3_4::HalStream& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".streams = ";
    os += ::android::hardware::toString(o.streams);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& lhs, const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& rhs) {
    if (lhs.streams != rhs.streams) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& lhs, const ::android::hardware::camera::device::V3_4::HalStreamConfiguration& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".fmqSettingsSize = ";
    os += ::android::hardware::toString(o.fmqSettingsSize);
    os += ", .physicalCameraId = ";
    os += ::android::hardware::toString(o.physicalCameraId);
    os += ", .settings = ";
    os += ::android::hardware::toString(o.settings);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& lhs, const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& rhs) {
    if (lhs.fmqSettingsSize != rhs.fmqSettingsSize) {
        return false;
    }
    if (lhs.physicalCameraId != rhs.physicalCameraId) {
        return false;
    }
    if (lhs.settings != rhs.settings) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& lhs, const ::android::hardware::camera::device::V3_4::PhysicalCameraSetting& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::camera::device::V3_4::CaptureRequest& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v3_2 = ";
    os += ::android::hardware::camera::device::V3_2::toString(o.v3_2);
    os += ", .physicalCameraSettings = ";
    os += ::android::hardware::toString(o.physicalCameraSettings);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_4::CaptureRequest& o, ::std::ostream* os) {
    *os << toString(o);
}

// operator== and operator!= are not generated for CaptureRequest

static inline std::string toString(const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".fmqMetadataSize = ";
    os += ::android::hardware::toString(o.fmqMetadataSize);
    os += ", .physicalCameraId = ";
    os += ::android::hardware::toString(o.physicalCameraId);
    os += ", .metadata = ";
    os += ::android::hardware::toString(o.metadata);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& lhs, const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& rhs) {
    if (lhs.fmqMetadataSize != rhs.fmqMetadataSize) {
        return false;
    }
    if (lhs.physicalCameraId != rhs.physicalCameraId) {
        return false;
    }
    if (lhs.metadata != rhs.metadata) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& lhs, const ::android::hardware::camera::device::V3_4::PhysicalCameraMetadata& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::camera::device::V3_4::CaptureResult& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v3_2 = ";
    os += ::android::hardware::camera::device::V3_2::toString(o.v3_2);
    os += ", .physicalCameraMetadata = ";
    os += ::android::hardware::toString(o.physicalCameraMetadata);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_4::CaptureResult& o, ::std::ostream* os) {
    *os << toString(o);
}

// operator== and operator!= are not generated for CaptureResult


}  // namespace V3_4
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_4_TYPES_H
