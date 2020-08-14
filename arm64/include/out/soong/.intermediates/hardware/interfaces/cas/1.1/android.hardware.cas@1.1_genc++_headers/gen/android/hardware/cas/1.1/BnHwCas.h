#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_1_BNHWCAS_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_1_BNHWCAS_H

#include <android/hardware/cas/1.1/IHwCas.h>

namespace android {
namespace hardware {
namespace cas {
namespace V1_1 {

struct BnHwCas : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwCas(const ::android::sp<ICas> &_hidl_impl);
    explicit BnHwCas(const ::android::sp<ICas> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwCas();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ICas Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ICas> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::cas::V1_1::ICas follow.
    static ::android::status_t _hidl_sendSessionEvent(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::cas::V1_0::ICas follow.

    // Methods from ::android::hardware::cas::V1_1::ICas follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ICas> _hidl_mImpl;
};

}  // namespace V1_1
}  // namespace cas
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_1_BNHWCAS_H
