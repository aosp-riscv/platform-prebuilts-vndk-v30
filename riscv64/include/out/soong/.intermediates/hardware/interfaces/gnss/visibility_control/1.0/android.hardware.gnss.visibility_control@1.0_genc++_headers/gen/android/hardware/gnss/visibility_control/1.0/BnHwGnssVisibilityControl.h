#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_VISIBILITY_CONTROL_V1_0_BNHWGNSSVISIBILITYCONTROL_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_VISIBILITY_CONTROL_V1_0_BNHWGNSSVISIBILITYCONTROL_H

#include <android/hardware/gnss/visibility_control/1.0/IHwGnssVisibilityControl.h>

namespace android {
namespace hardware {
namespace gnss {
namespace visibility_control {
namespace V1_0 {

struct BnHwGnssVisibilityControl : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwGnssVisibilityControl(const ::android::sp<IGnssVisibilityControl> &_hidl_impl);
    explicit BnHwGnssVisibilityControl(const ::android::sp<IGnssVisibilityControl> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwGnssVisibilityControl();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IGnssVisibilityControl Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IGnssVisibilityControl> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl follow.
    static ::android::status_t _hidl_enableNfwLocationAccess(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_setCallback(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControl follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IGnssVisibilityControl> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace visibility_control
}  // namespace gnss
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_VISIBILITY_CONTROL_V1_0_BNHWGNSSVISIBILITYCONTROL_H
