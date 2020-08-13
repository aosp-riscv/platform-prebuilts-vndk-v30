#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_PROVIDER_V2_5_ICAMERAPROVIDER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_PROVIDER_V2_5_ICAMERAPROVIDER_H

#include <android/hardware/camera/provider/2.4/ICameraProvider.h>
#include <android/hardware/camera/provider/2.5/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace camera {
namespace provider {
namespace V2_5 {

/**
 * Camera provider HAL
 *
 * Version 2.5 adds support for the notifyDeviceStateChange method
 */
struct ICameraProvider : public ::android::hardware::camera::provider::V2_4::ICameraProvider {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef ::android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.camera.provider@2.5::ICameraProvider"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * setCallback:
     *
     * Provide a callback interface to the HAL provider to inform framework of
     * asynchronous camera events. The framework must call this function once
     * during camera service startup, before any other calls to the provider
     * (note that in case the camera service restarts, this method must be
     * invoked again during its startup).
     *
     * @param callback
     *     A non-null callback interface to invoke when camera events occur.
     * @return status
     *     Status code for the operation, one of:
     *     OK:
     *         On success
     *     INTERNAL_ERROR:
     *         An unexpected internal error occurred while setting the callbacks
     *     ILLEGAL_ARGUMENT:
     *         The callback argument is invalid (for example, null).
     *
     */
    virtual ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> setCallback(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProviderCallback>& callback) = 0;

    /**
     * Return callback for getVendorTags
     */
    using getVendorTags_cb = std::function<void(::android::hardware::camera::common::V1_0::Status status, const ::android::hardware::hidl_vec<::android::hardware::camera::common::V1_0::VendorTagSection>& sections)>;
    /**
     * getVendorTags:
     *
     * Retrieve all vendor tags supported by devices discoverable through this
     * provider. The tags are grouped into sections.
     *
     * @return status
     *     Status code for the operation, one of:
     *     OK:
     *         On success
     *     INTERNAL_ERROR:
     *         An unexpected internal error occurred while setting the callbacks
     * @return sections
     *     The supported vendor tag sections; empty if there are no supported
     *     vendor tags, or status is not OK.
     *
     */
    virtual ::android::hardware::Return<void> getVendorTags(getVendorTags_cb _hidl_cb) = 0;

    /**
     * Return callback for getCameraIdList
     */
    using getCameraIdList_cb = std::function<void(::android::hardware::camera::common::V1_0::Status status, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& cameraDeviceNames)>;
    /**
     * getCameraIdList:
     *
     * Returns the list of internal camera device interfaces known to this
     * camera provider. These devices can then be accessed via the hardware
     * service manager.
     *
     * External camera devices (camera facing EXTERNAL) must be reported through
     * the device status change callback, not in this list. Only devices with
     * facing BACK or FRONT must be listed here.
     *
     * @return status Status code for the operation, one of:
     *     OK:
     *         On a succesful generation of camera ID list
     *     INTERNAL_ERROR:
     *         A camera ID list cannot be created. This may be due to
     *         a failure to initialize the camera subsystem, for example.
     * @return cameraDeviceNames The vector of internal camera device
     *     names known to this provider.
     */
    virtual ::android::hardware::Return<void> getCameraIdList(getCameraIdList_cb _hidl_cb) = 0;

    /**
     * Return callback for isSetTorchModeSupported
     */
    using isSetTorchModeSupported_cb = std::function<void(::android::hardware::camera::common::V1_0::Status status, bool support)>;
    /**
     * isSetTorchModeSupported:
     *
     * Returns if the camera devices known to this camera provider support
     * setTorchMode API or not. If the provider does not support setTorchMode
     * API, calling to setTorchMode will return METHOD_NOT_SUPPORTED.
     *
     * Note that not every camera device has a flash unit, so even this API
     * returns true, setTorchMode call might still fail due to the camera device
     * does not have a flash unit. In such case, the returned status will be
     * OPERATION_NOT_SUPPORTED.
     *
     * @return status Status code for the operation, one of:
     *     OK:
     *         On a succesful call
     *     INTERNAL_ERROR:
     *         Torch API support cannot be queried. This may be due to
     *         a failure to initialize the camera subsystem, for example.
     * @return support Whether the camera devices known to this provider
     *     supports setTorchMode API or not. Devices launched with SDK
     *     level 29 or higher must return true.
     *
     */
    virtual ::android::hardware::Return<void> isSetTorchModeSupported(isSetTorchModeSupported_cb _hidl_cb) = 0;

    /**
     * Return callback for getCameraDeviceInterface_V1_x
     */
    using getCameraDeviceInterface_V1_x_cb = std::function<void(::android::hardware::camera::common::V1_0::Status status, const ::android::sp<::android::hardware::camera::device::V1_0::ICameraDevice>& device)>;
    /**
     * getCameraDeviceInterface_VN_x:
     *
     * Return a android.hardware.camera.device@N.x/ICameraDevice interface for
     * the requested device name. This does not power on the camera device, but
     * simply acquires the interface for querying the device static information,
     * or to additionally open the device for active use.
     *
     * A separate method is required for each major revision of the camera device
     * HAL interface, since they are not compatible with each other.
     *
     * Valid device names for this provider can be obtained via either
     * getCameraIdList(), or via availability callbacks from
     * ICameraProviderCallback::cameraDeviceStatusChange().
     *
     * The returned interface must be of the highest defined minor version for
     * the major version; it's the responsibility of the HAL client to ensure
     * they do not use methods/etc that are not valid for the actual minor
     * version of the device.
     *
     * @param cameraDeviceName the name of the device to get an interface to.
     * @return status Status code for the operation, one of:
     *     OK:
     *         On a succesful generation of camera ID list
     *     ILLEGAL_ARGUMENT:
     *         This device name is unknown, or has been disconnected
     *     OPERATION_NOT_SUPPORTED:
     *         The specified device does not support this major version of the
     *         HAL interface.
     *     INTERNAL_ERROR:
     *         A camera interface cannot be returned due to an unexpected
     *         internal error.
     * @return device The inteface to this camera device, or null in case of
     *     error.
     */
    virtual ::android::hardware::Return<void> getCameraDeviceInterface_V1_x(const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V1_x_cb _hidl_cb) = 0;

    /**
     * Return callback for getCameraDeviceInterface_V3_x
     */
    using getCameraDeviceInterface_V3_x_cb = std::function<void(::android::hardware::camera::common::V1_0::Status status, const ::android::sp<::android::hardware::camera::device::V3_2::ICameraDevice>& device)>;
    virtual ::android::hardware::Return<void> getCameraDeviceInterface_V3_x(const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V3_x_cb _hidl_cb) = 0;

    /**
     * notifyDeviceStateChange:
     *
     * Notify the HAL provider that the state of the overall device has
     * changed in some way that the HAL may want to know about.
     *
     * For example, a physical shutter may have been uncovered or covered,
     * or a camera may have been covered or uncovered by an add-on keyboard
     * or other accessory.
     *
     * The state is a bitfield of potential states, and some physical configurations
     * could plausibly correspond to multiple different combinations of state bits.
     * The HAL must ignore any state bits it is not actively using to determine
     * the appropriate camera configuration.
     *
     * For example, on some devices the FOLDED state could mean that
     * backward-facing cameras are covered by the fold, so FOLDED by itself implies
     * BACK_COVERED. But other devices may support folding but not cover any cameras
     * when folded, so for those FOLDED would not imply any of the other flags.
     * Since these relationships are very device-specific, it is difficult to specify
     * a comprehensive policy.  But as a recommendation, it is suggested that if a flag
     * necessarily implies other flags are set as well, then those flags should be set.
     * So even though FOLDED would be enough to infer BACK_COVERED on some devices, the
     * BACK_COVERED flag should also be set for clarity.
     *
     * This method may be invoked by the HAL client at any time. It must not
     * cause any active camera device sessions to be closed, but may dynamically
     * change which physical camera a logical multi-camera is using for its
     * active and future output.
     *
     * The method must be invoked by the HAL client at least once before the
     * client calls ICameraDevice::open on any camera device interfaces listed
     * by this provider, to establish the initial device state.
     *
     * @param newState
     *    The new state of the device.
     */
    virtual ::android::hardware::Return<void> notifyDeviceStateChange(::android::hardware::hidl_bitfield<::android::hardware::camera::provider::V2_5::DeviceState> newState) = 0;

    /**
     * Return callback for interfaceChain
     */
    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     ["android.hardware.foo@1.0::IChild",
     *      "android.hardware.foo@1.0::IParent"
     *      "android.hidl.base@1.0::IBase"]
     *
     * @return descriptors a vector of descriptors of the run-time type of the
     *         object.
     */
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    /*
     * Emit diagnostic information to the given file.
     *
     * Optionally overriden.
     *
     * @param fd      File descriptor to dump data to.
     *                Must only be used for the duration of this call.
     * @param options Arguments for debugging.
     *                Must support empty for default debug information.
     */
    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    /**
     * Return callback for interfaceDescriptor
     */
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceDescriptor on an IChild object must yield
     *     "android.hardware.foo@1.0::IChild"
     *
     * @return descriptor a descriptor of the run-time type of the
     *         object (the first element of the vector returned by
     *         interfaceChain())
     */
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    /**
     * Return callback for getHashChain
     */
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    /*
     * Returns hashes of the source HAL files that define the interfaces of the
     * runtime type information on the object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     [(hash of IChild.hal),
     *      (hash of IParent.hal)
     *      (hash of IBase.hal)].
     *
     * SHA-256 is used as the hashing algorithm. Each hash has 32 bytes
     * according to SHA-256 standard.
     *
     * @return hashchain a vector of SHA-1 digests
     */
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    /*
     * This method trigger the interface to enable/disable instrumentation based
     * on system property hal.instrumentation.enable.
     */
    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    /*
     * Registers a death recipient, to be called when the process hosting this
     * interface dies.
     *
     * @param recipient a hidl_death_recipient callback object
     * @param cookie a cookie that must be returned with the callback
     * @return success whether the death recipient was registered successfully.
     */
    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    /*
     * Provides way to determine if interface is running without requesting
     * any functionality.
     */
    virtual ::android::hardware::Return<void> ping() override;

    /**
     * Return callback for getDebugInfo
     */
    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    /*
     * Get debug information on references on this interface.
     * @return info debugging information. See comments of DebugInfo.
     */
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    /*
     * This method notifies the interface that one or more system properties
     * have changed. The default implementation calls
     * (C++)  report_sysprop_change() in libcutils or
     * (Java) android.os.SystemProperties.reportSyspropChanged,
     * which in turn calls a set of registered callbacks (eg to update trace
     * tags).
     */
    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    /*
     * Unregisters the registered death recipient. If this service was registered
     * multiple times with the same exact death recipient, this unlinks the most
     * recently registered one.
     *
     * @param recipient a previously registered hidl_death_recipient callback
     * @return success whether the death recipient was unregistered successfully.
     */
    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    // cast static functions
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_5::ICameraProvider>> castFrom(const ::android::sp<::android::hardware::camera::provider::V2_5::ICameraProvider>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_5::ICameraProvider>> castFrom(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProvider>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::camera::provider::V2_5::ICameraProvider>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    // helper methods for interactions with the hwservicemanager
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is currently not available or not in the VINTF manifest on a Trebilized
     * device, this will return nullptr. This is useful when you don't want to block
     * during device boot. If getStub is true, this will try to return an unwrapped
     * passthrough implementation in the same process. This is useful when getting an
     * implementation from the same partition/compilation group.
     *
     * In general, prefer getService(std::string,bool)
     */
    static ::android::sp<ICameraProvider> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ICameraProvider> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ICameraProvider> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ICameraProvider> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ICameraProvider> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ICameraProvider> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ICameraProvider> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ICameraProvider> getService(bool getStub) { return getService("default", getStub); }
    /**
     * Registers a service with the service manager. For Trebilized devices, the service
     * must also be in the VINTF manifest.
     */
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    /**
     * Registers for notifications for when a service is registered.
     */
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

//
// type declarations for package
//

static inline std::string toString(const ::android::sp<::android::hardware::camera::provider::V2_5::ICameraProvider>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::camera::provider::V2_5::ICameraProvider>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::camera::provider::V2_5::ICameraProvider::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_5
}  // namespace provider
}  // namespace camera
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_PROVIDER_V2_5_ICAMERAPROVIDER_H
