#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_2_BNHWMEDIACASSERVICE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_2_BNHWMEDIACASSERVICE_H

#include <android/hardware/cas/1.2/IHwMediaCasService.h>

namespace android {
namespace hardware {
namespace cas {
namespace V1_2 {

struct BnHwMediaCasService : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwMediaCasService(const ::android::sp<IMediaCasService> &_hidl_impl);
    explicit BnHwMediaCasService(const ::android::sp<IMediaCasService> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwMediaCasService();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IMediaCasService Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IMediaCasService> getImpl() { return _hidl_mImpl; }

private:
    // Methods from ::android::hardware::cas::V1_0::IMediaCasService follow.

    // Methods from ::android::hardware::cas::V1_1::IMediaCasService follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IMediaCasService> _hidl_mImpl;
};

}  // namespace V1_2
}  // namespace cas
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_2_BNHWMEDIACASSERVICE_H
