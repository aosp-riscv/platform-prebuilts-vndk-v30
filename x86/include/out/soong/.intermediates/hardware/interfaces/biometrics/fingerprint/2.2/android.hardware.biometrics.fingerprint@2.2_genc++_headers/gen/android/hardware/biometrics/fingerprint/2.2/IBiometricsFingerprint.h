#ifndef HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_V2_2_IBIOMETRICSFINGERPRINT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_V2_2_IBIOMETRICSFINGERPRINT_H

#include <android/hardware/biometrics/fingerprint/2.1/IBiometricsFingerprint.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace biometrics {
namespace fingerprint {
namespace V2_2 {

/**
 * The HAL interface for biometric fingerprint authentication.
 *
 * This interface is required because all top-level interfaces need to be
 * updated in a minor uprev.
 */
struct IBiometricsFingerprint : public ::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef ::android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.biometrics.fingerprint@2.2::IBiometricsFingerprint"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Set notification callback:
     * Registers a user function that must receive notifications from the HAL
     * This call must block if the HAL state machine is in busy state until HAL
     * leaves the busy state.
     *
     * @return deviceId is a unique handle for this fingerprint device
     */
    virtual ::android::hardware::Return<uint64_t> setNotify(const ::android::sp<::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& clientCallback) = 0;

    /**
     * Fingerprint pre-enroll enroll request:
     * Generates a unique token to upper layers to indicate the start of
     * an enrollment transaction. pre-enroll and post-enroll specify
     * a pin/password cleared time window where enrollment is allowed.
     * Pre-enroll only generates a challenge, a full hardwareAuthToken is
     * generated by trustzone after verifying a pin/password/swipe. This is to
     * ensure adding a new fingerprint template was preceded by some kind of
     * credential confirmation (e.g. device password).
     *
     * @return 0 if function failed, a uint64_t of challenge otherwise.
     */
    virtual ::android::hardware::Return<uint64_t> preEnroll() = 0;

    /**
     * Fingerprint enroll request:
     * Switches the HAL state machine to collect and store a new fingerprint
     * template. Switches back as soon as enroll is complete, signalled by
     * (fingerprintMsg.type == FINGERPRINT_TEMPLATE_ENROLLING &&
     *  fingerprintMsg.data.enroll.samplesRemaining == 0)
     * or after timeoutSec seconds.
     * The fingerprint template must be assigned to the group gid.
     *
     * @param hat a valid Hardware Authentication Token (HAT), generated
     * as a result of a preEnroll() call.
     * @param gid a framework defined fingerprint set (group) id.
     * @param timeoutSec a timeout in seconds.
     *
     * @return debugErrno is a value the framework logs in case it is not 0.
     *
     * A notify() function may be called with a more detailed error structure.
     */
    virtual ::android::hardware::Return<::android::hardware::biometrics::fingerprint::V2_1::RequestStatus> enroll(const ::android::hardware::hidl_array<uint8_t, 69>& hat, uint32_t gid, uint32_t timeoutSec) = 0;

    /**
     * Finishes the enroll operation and invalidates the preEnroll() generated
     * challenge. This must be called at the end of a multi-finger enrollment
     * session to indicate that no more fingers may be added.
     *
     * @return debugErrno is a value the framework logs in case it is not 0.
     */
    virtual ::android::hardware::Return<::android::hardware::biometrics::fingerprint::V2_1::RequestStatus> postEnroll() = 0;

    /**
     * getAuthenticatorId:
     * Returns a token associated with the current fingerprint set. This value
     * must change whenever a new fingerprint is enrolled, thus creating a new
     * fingerprint set.
     *
     * @return getAuthenticatorIdRet current authenticator id, 0 if function
     * failed.
     */
    virtual ::android::hardware::Return<uint64_t> getAuthenticatorId() = 0;

    /**
     * Cancel pending enroll or authenticate, sending FINGERPRINT_ERROR_CANCELED
     * to all running clients. Switches the HAL state machine back to the idle
     * state. Unlike enrollDone() doesn't invalidate the preEnroll() challenge.
     *
     * @return debugErrno is a value the framework logs in case it is not 0.
     */
    virtual ::android::hardware::Return<::android::hardware::biometrics::fingerprint::V2_1::RequestStatus> cancel() = 0;

    /**
     * Enumerate all the fingerprint templates found in the directory set by
     * setActiveGroup():
     * For each template found a notify() must be called with:
     * fingerprintMsg.type == FINGERPRINT_TEMPLATE_ENUMERATED
     * fingerprintMsg.data.enumerated.finger indicating a template id
     * fingerprintMsg.data.enumerated.remainingTemplates indicating how many more
     * enumeration messages to expect.
     *
     * @return debugErrno is a value the framework logs in case it is not 0.
     */
    virtual ::android::hardware::Return<::android::hardware::biometrics::fingerprint::V2_1::RequestStatus> enumerate() = 0;

    /**
     * Fingerprint remove request:
     * Deletes fingerprint template(s).
     * Works only within the path set by setActiveGroup().
     * For each template found a notify() must be called with:
     * fingerprintMsg.type == FINGERPRINT_TEMPLATE_REMOVED
     * fingerprintMsg.data.removed.finger indicating the template id deleted
     * fingerprintMsg.data.removed.remainingTemplates indicating how many more
     * templates must be deleted by this operation.
     *
     * @param gid group id must match the last group set by setActiveGroup().
     * @param fid template id to delete or 0 to delete all templates within the
     * current group.
     *
     * @return debugErrno is a value the framework logs in case it is not 0.
     */
    virtual ::android::hardware::Return<::android::hardware::biometrics::fingerprint::V2_1::RequestStatus> remove(uint32_t gid, uint32_t fid) = 0;

    /**
     * Restricts the HAL operation to a set of fingerprints belonging to a group
     * provided. The caller must provide a path to a storage location within the
     * user's data directory.
     *
     * @param gid the fingerprint group (set) id.
     * @param storePath filesystem path to the template storage directory.
     *
     * @return debugErrno is a value the framework logs in case it is not 0.
     */
    virtual ::android::hardware::Return<::android::hardware::biometrics::fingerprint::V2_1::RequestStatus> setActiveGroup(uint32_t gid, const ::android::hardware::hidl_string& storePath) = 0;

    /**
     * Authenticates an operation identified by operationId
     *
     * @param operationId operation id.
     * @param gid fingerprint group id.
     *
     * @return debugErrno is a value the framework logs in case it is not 0.
     */
    virtual ::android::hardware::Return<::android::hardware::biometrics::fingerprint::V2_1::RequestStatus> authenticate(uint64_t operationId, uint32_t gid) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::biometrics::fingerprint::V2_2::IBiometricsFingerprint>> castFrom(const ::android::sp<::android::hardware::biometrics::fingerprint::V2_2::IBiometricsFingerprint>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::biometrics::fingerprint::V2_2::IBiometricsFingerprint>> castFrom(const ::android::sp<::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::biometrics::fingerprint::V2_2::IBiometricsFingerprint>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IBiometricsFingerprint> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBiometricsFingerprint> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBiometricsFingerprint> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBiometricsFingerprint> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBiometricsFingerprint> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBiometricsFingerprint> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBiometricsFingerprint> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBiometricsFingerprint> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::biometrics::fingerprint::V2_2::IBiometricsFingerprint>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::biometrics::fingerprint::V2_2::IBiometricsFingerprint>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::biometrics::fingerprint::V2_2::IBiometricsFingerprint::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_2
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_V2_2_IBIOMETRICSFINGERPRINT_H
